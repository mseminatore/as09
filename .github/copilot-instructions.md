# as09 Assembler - AI Coding Agent Instructions

## Project Overview
as09 is an **MC6809 cross-assembler** written in portable C. It parses 6809 assembly (EDTASM+ compatible syntax) for the TRS-80 CoCo and generates multiple output formats: binary DECB, Intel HEX, Verilog ROMs (sync/async/SystemVerilog), and symbol tables.

**Key Architecture**: Single-pass parser using Yacc/Bison with a handwritten lexer, forward-reference resolution via fixup mechanism.

## Build & Test Workflow

### Build
- **CMake** (primary): `cmake --build . && ctest` 
- **Makefile** (alternative): `make` then `make test`
- Test compares generated HEX output against expected `test.hex`

### Key Commands
- `as09 -x input.asm` → Intel HEX output (default `a.out`)
- `as09 -b input.asm` → DECB binary (TRS-80 CoCo compatible)
- `as09 -r input.asm` → Verilog sync ROM
- `as09 -a input.asm` → Verilog async ROM  
- `as09 -s input.asm` → SystemVerilog ROM

### Debugging
Parser uses Bison with debug output. Look for `yyerror()` calls and the `err_count`/`warn_count` globals. Line tracking via `lineno` and `file_nodes[]` stack for INCLUDE support.

## Core Data Structures

**Symbol Table** ([as09.h](as09.h#L104-L112)): `Symbol_t` stores name, file origin, type (UNDEF/EQU/SET/LABEL/STRING), value, and reference count. Max 4096 symbols.

**Fixups** ([as09.h](as09.h#L114-L123)): `Fixup_t` resolves forward references post-parse. Types: IMM8/IMM16 (immediate), REL8/REL16 (relative branches).

**Code Buffer**: 32KB max (`MAX_CODE = 0x7FFF`), instruction buffer in `inst_buf[]`, address tracking via global `addr`.

## Code Flow & Patterns

1. **Lexical Analysis**: Handwritten lexer (in `as09.y`), recognizes mnemonics, operators, registers
2. **Parsing**: Yacc/Bison grammar processes lines → instructions/directives → populates symbol table and emits code
3. **Fixup Resolution**: Forward references collected, resolved after full parse, back-patched into code buffer
4. **Output Generation**: Multiple formatters write `code[]` buffer in different formats

## Assembly Syntax Specifics

- **Labels require colon**: `LABEL:` (EDTASM+ extension)
- **Pseudo-instructions** supported: ASLD, BNZ, CLRD, FCZ (null-term string), INCLUDE
- **C-style operators in expressions**: `&` (AND), `|` (OR), `~` (NOT), backslash escapes in strings (`\r`, `\n`)
- **Addressing modes**: Inherent, immediate, direct, indexed, extended (see addressing mode enum in [as09.h](as09.h#L95-L100))

## Important Files

- [as09.y](as09.y): Grammar rules, parser logic, instruction emission
- [as09.h](as09.h): Data structure definitions, constants, enum definitions
- [decb.h](decb.h): TRS-80 DECB format header/loader logic
- [test.asm](test.asm), [hello.asm](hello.asm): Example programs demonstrating various addressing modes

## Common Pitfalls

- **Forward references**: Always use fixup mechanism, don't assume symbols are defined before use
- **Symbol scope**: No scope nesting; all symbols global; watch for accidental redefinitions
- **Addressing mode detection**: Must infer from instruction context—some ops have 2-4 variants
- **File inclusion**: Uses `file_nodes[]` stack; ensure proper cleanup on INCLUDE directives

## When Extending

- Add new instructions: Define opcode enum in [as09.h](as09.h#L53-L62), add to `Opcodes` array in [as09.y](as09.y)
- Add output format: Implement new generator function, add CLI flag in main parsing section
- Symbol features: Update `SYMBOL_TYPE` enum and symbol resolution logic
- Test new features against `test.asm` framework
