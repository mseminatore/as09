# Development Specification: A.OUT Object File Output Generation

## Overview

This specification outlines the design and implementation plan for extending the as09 MC6809 cross-assembler to generate valid Unix a.out object files as output. A.OUT format enables linking multiple assembled modules and provides symbol and relocation information, making it suitable for building larger multi-module 6809 programs.

## Objectives

- Generate valid a.out object files with proper structure
- Encode text, data, and bss segments
- Populate symbol table with label and global symbol definitions
- Generate relocation entries for forward references and external symbols
- Support entry point specification (program counter at assembly start)
- Maintain compatibility with existing output formats

## Background: A.OUT Format Overview

The a.out format (as implemented in the `aout` library) consists of:

1. **Header** (32 bytes): Metadata about segments and relocation/symbol sizes
2. **Text Segment**: Executable code bytes
3. **Data Segment**: Initialized data bytes
4. **Relocation Entries** (Text, then Data): Instructions for fixing up addresses
5. **Symbol Table**: Symbol name, type (TEXT/DATA/BSS/EXTERN/ABS), and value
6. **String Table**: Null-terminated symbol names

### Key Data Structures (from aout.h)

```c
typedef struct {
  int32_t a_magic;    // magic number
  int32_t a_text;     // text segment size (bytes)
  int32_t a_data;     // data segment size (bytes)
  int32_t a_bss;      // uninitialized data size (bytes)
  int32_t a_syms;     // symbol table size (bytes)
  int32_t a_entry;    // entry point address
  int32_t a_trsize;   // text relocation size
  int32_t a_drsize;   // data relocation size
} aout_header_t;

typedef struct {
  uint32_t address;        // offset within segment
  uint32_t index : 24;     // symbol table index or segment id
  uint32_t pcrel : 1;      // PC-relative?
  uint32_t length : 2;     // 0=1 byte, 1=2 bytes, 2=4 bytes, 3=8 bytes
  uint32_t external : 1;   // external symbol?
  uint32_t spare : 4;
} aout_relocation_entry_t;

typedef struct {
  uint32_t name_offset;    // offset in string table
  uint32_t type;           // AOUT_SET_TEXT, AOUT_SET_DATA, AOUT_SET_BSS, etc.
  uint32_t value;          // address offset in segment
} aout_symbol_t;
```

## Current Assembler Architecture

The as09 assembler is a single-pass parser with:

- **Symbol Table** (`Symbol_t[]`): Stores all labels and equates with their values and types
- **Code Buffer** (`code[MAX_CODE]`): Accumulates emitted instruction bytes (32KB max)
- **Address Tracking** (`addr` global): Current position in code segment
- **Fixup Mechanism** (`Fixup_t[]`): Records forward references for post-parse resolution
- **Output Generators**: Separate functions for each format (hex, binary, Verilog)

## Implementation Plan

### Phase 1: Infrastructure Setup

#### 1.1 CLI Option Addition
- Add `-n` or `--aout` flag to command-line argument parsing in `getopt()`
- Add global flag `g_bAoutFile` to control output generation
- Update usage banner to document new option

#### 1.2 Segment Classification
Extend the assembler to distinguish between:
- **Text segment**: Code (instructions) emitted by `emit()` calls
- **Data segment**: Initialized data from `FDB`, `FCC`, `FCB` directives
- **BSS segment**: Uninitialized space from `RMB` directives (no output bytes needed)

Currently, all output goes into a single code buffer. New approach:
- Create separate tracking for data vs. code generation
- Introduce `CURRENT_SEGMENT` enum to distinguish `SEG_TEXT`, `SEG_DATA`, `SEG_BSS`
- Modify `emit()` to route bytes to appropriate segment based on context

#### 1.3 A.OUT Object File Initialization
- Include `aout.h` header
- Create a global `aout_object_file_t *aout_obj` initialized early in `main()`
- Initialize segments via `aout_create()` before parsing begins

### Phase 2: Symbol Table Integration

#### 2.1 Symbol Type Mapping
Map as09 symbol types to a.out symbol entity types:

| as09 Type | a.out Type | Notes |
|-----------|-----------|-------|
| ST_LABEL  | AOUT_SET_TEXT or AOUT_SET_DATA | Determined by segment where label defined |
| ST_EQU    | AOUT_SET_ABS | Non-relocatable absolute symbol |
| ST_SET    | AOUT_SET_ABS | Non-relocatable, reassignable value |
| ST_STRING | (not exported) | String literals not typically exported |

#### 2.2 Symbol Export at End of Parse
After fixup resolution, iterate through `symbols[]`:
- For each `ST_LABEL` symbol:
  - Determine its segment (TEXT/DATA/BSS) based on address ranges
  - Create `aout_symbol_t` structure
  - Call `aout_add_symbol()` with symbol name and type
- For `ST_EQU` symbols marked as global (future extension):
  - Add with `AOUT_SET_ABS` type

#### 2.3 Entry Point
- Store initial program counter value (from `ORG` or default `$0000`)
- Call `aout_set_entry_point(aout_obj, start_addr)` before file write

### Phase 3: Segment Population

#### 3.1 Text Segment
- During parsing, all instruction bytes emitted via `emit()` go to text segment
- Call `aout_add_text()` for each byte
- Track text segment size and base address

#### 3.2 Data Segment
Implement segment context switching:
- Add `current_segment` global variable
- Modify `emit()` to:
  ```c
  void emit(uint8_t v) {
    if (current_segment == SEG_TEXT)
      aout_add_text(aout_obj, v);
    else if (current_segment == SEG_DATA)
      aout_add_data(aout_obj, v);
    code[addr] = v;  // maintain backward compatibility
    addr++;
  }
  ```
- Add parser rules or directives to switch segments
- Suggested directive: `SECTION TEXT` / `SECTION DATA` / `SECTION BSS`

#### 3.3 BSS Segment
- Track BSS space allocated via `RMB` directives
- Call `aout_alloc_bss()` instead of emitting zeros
- Update label values to reflect BSS offsets

### Phase 4: Relocation Entry Generation

#### 4.1 Fixup-to-Relocation Mapping
After fixup resolution, convert each fixup record to a relocation entry:

```c
// For each unresolved fixup (external symbols or cross-module refs):
aout_relocation_entry_t reloc;
reloc.address = fixup.addr;
reloc.index = symbol_table_index;  // index of symbol being referenced
reloc.external = 1;                 // external reference
reloc.pcrel = (fixup.type == FIXUP_REL8 || fixup.type == FIXUP_REL16) ? 1 : 0;
reloc.length = (fixup.type == FIXUP_IMM16 || fixup.type == FIXUP_REL16) ? 1 : 0;

if (fixup.segment == SEG_TEXT)
  aout_add_text_relocation(aout_obj, &reloc);
else
  aout_add_data_relocation(aout_obj, &reloc);
```

#### 4.2 Relocation Type Mapping

| as09 Fixup Type | PC-Relative | Length | Notes |
|-----------------|-------------|--------|-------|
| FIXUP_IMM8      | 0           | 0      | 1-byte immediate |
| FIXUP_IMM16     | 0           | 1      | 2-byte immediate |
| FIXUP_REL8      | 1           | 0      | 1-byte relative branch |
| FIXUP_REL16     | 1           | 1      | 2-byte relative branch |

### Phase 5: Output Generation

#### 5.1 Output Function
Create new function in `as09.y`:

```c
void write_aout_file() {
  // Set entry point
  aout_set_entry_point(aout_obj, start_addr);
  
  // Export symbol table
  for (int i = 0; i < symbol_count; i++) {
    if (symbols[i].type == ST_LABEL) {
      aout_symbol_t sym;
      sym.type = determine_segment_type(symbols[i].value);
      sym.value = symbols[i].value;
      aout_add_symbol(aout_obj, symbols[i].name, &sym);
    }
  }
  
  // Validate and write
  if (aout_is_valid(aout_obj)) {
    aout_write_file_named(aout_obj, g_szOutputFilename);
  } else {
    fprintf(stderr, "ERROR: invalid a.out object file\n");
    err_count++;
  }
}
```

#### 5.2 Main Integration
In `main()` after parsing and fixup resolution:
```c
if (g_bAoutFile) {
  write_aout_file();
} else if (g_bBinaryRom) {
  write_bin_file();
} else if (g_bHexFile) {
  write_hex_file();
}
```

#### 5.3 Cleanup
In `main()` at program exit:
```c
aout_free(aout_obj);
```

## Testing Strategy

### Unit Tests (aout library)
The aout library already includes `test_aout.c`. Verify:
- Text/data/bss segment manipulation
- Symbol table operations
- Relocation entry creation
- File I/O (read/write round-trip)

### Integration Tests

#### Test 1: Simple Single-Module Program
```asm
START:
  LDA #$42
  STA $1000
  BRA START
END START
```
Expected output:
- Text segment: 5 bytes
- Entry point: $0000
- Symbols: START at $0000 (TEXT segment)

#### Test 2: Labels and Forward References
```asm
LOOP:
  INC
  CMP #10
  BNE LOOP
  RTS
END
```
Expected:
- Text segment: 6+ bytes
- Symbol: LOOP at correct offset
- Relocation: BNE relative reference

#### Test 3: Data Initialization (future)
```asm
DATA:
  FDB $1234
  FCC "Hello"
TEXT:
  LDX #DATA
END TEXT
```
Expected:
- Text segment: code bytes
- Data segment: $12, $34, 'H', 'e', 'l', 'l', 'o'
- Relocation: LDX immediate reference to DATA symbol

#### Test 4: Extern Symbols (future)
```asm
  JSR PRINT
END
```
Expected:
- Relocation entry: external, index pointing to PRINT symbol
- Symbol: PRINT with AOUT_SET_UNDEFINED type

### Verification Tools
- `od -x` or `hexdump`: Examine binary structure
- Custom dump utility using `aout_dump_*()` functions
- Linker test: Link multiple a.out files together (future phase)

## Segment and Address Space Considerations

### 16-bit Address Limit
The 6809 is a 16-bit processor with max 64K address space. Ensure:
- Total (TEXT + DATA + BSS) does not exceed 64K
- Add size check in `aout_is_valid()`
- Report error if combined segments exceed $FFFF

### Segment Base Addresses
Initialize:
- `aout_set_text_base(aout_obj, 0x0000)` - or from ORG directive
- `aout_set_data_base(aout_obj, text_size)` - follows text segment
- `aout_set_bss_base(aout_obj, text_size + data_size)` - follows data segment

## Future Extensions

### Phase 6: Global Symbol Export
- Extend syntax: `GLOBAL LABEL` to mark symbols as externally visible
- Set `AOUT_SET_EXTERN` flag for global symbols
- Enables linking and external references

### Phase 7: Linking Support
- Implement basic linker using aout library's `aout_relocate()` and `aout_concat()`
- Process multiple .o files and resolve cross-module references
- Produce final executable or library

### Phase 8: Debugging Support
- Preserve symbol information with line numbers
- Consider stabs or dwarf-like debug info (advanced)

## Code Organization

### Modified Files
1. **as09.y**: Main parser
   - Add `g_bAoutFile` flag
   - Add `-n` flag handling in `getopt()`
   - Add `write_aout_file()` function
   - Modify output dispatcher in `main()`
   - Add segment classification logic

2. **as09.h**: Header
   - Forward declare `aout_object_file_t`
   - Add segment enum if needed
   - Add extern global for aout object

3. **decb.h**: (No changes needed)

### New Include
- `#include "aout/aout.h"`

### Build Integration
- CMakeLists.txt: Link against aout library (already included)
- Makefile: Ensure aout/ directory is built

## Error Handling

### Validation Points
1. Symbol table overflow → AOUT symbol table limit
2. Segment size overflow → 16-bit address limit
3. Relocation entry format → Validate address and index ranges
4. String table management → Ensure no buffer overflows

### Error Messages
```c
if (text_size + data_size + bss_size > 0x10000) {
  fprintf(stderr, "ERROR: combined segment size exceeds 64K address space\n");
  err_count++;
}

if (!aout_is_valid(aout_obj)) {
  fprintf(stderr, "ERROR: invalid a.out object file generation\n");
  err_count++;
}
```

## Estimated Implementation Effort

| Phase | Complexity | Effort (hours) |
|-------|------------|---|
| Phase 1 (Infrastructure) | Low | 2-3 |
| Phase 2 (Symbol Table) | Medium | 3-4 |
| Phase 3 (Segments) | Medium | 4-5 |
| Phase 4 (Relocations) | High | 5-6 |
| Phase 5 (Output) | Low | 2-3 |
| Testing & Debug | Medium | 4-5 |
| **Total** | | **20-26** |

## Success Criteria

✓ Generate valid a.out files readable by standard tools  
✓ Include all assembled symbols in symbol table  
✓ Generate correct relocation entries for forward references  
✓ Set entry point correctly  
✓ Pass round-trip test (assemble → read → verify)  
✓ No regression in existing output formats (hex, binary, Verilog)  
✓ Handle edge cases (no symbols, all BSS, etc.)  

## References

- `aout/aout.h`: A.OUT API documentation
- `as09.h`: As09 data structure definitions
- `as09.y`: Parser grammar and code generation
- Unix a.out format specification (public domain)
