# Runtime Assertion Replacements

## Overview
Replaced all 7 `assert()` statements with proper runtime error checking and reporting. This allows the assembler to handle overflow conditions gracefully instead of crashing.

## Changes Made

### 1. Instruction Buffer Overflow (Line ~263)
**Function**: `emit_buf()`
- **Before**: `assert(inst_ptr < INB_SIZE);`
- **After**: Runtime check that calls `yyerror()` and returns early
```c
if (inst_ptr >= INB_SIZE) {
    yyerror("instruction buffer overflow");
    return;
}
```
- **Impact**: Assembler reports error instead of crashing if queued instruction exceeds 32-byte limit

### 2. Unexpected Fixup in Addressing Mode - Direct 0 Offset (Line ~340)
**Function**: `constant_offset_direct()`
- **Before**: `assert(fixup_pending_index == FP_NONE);`
- **After**: Runtime validation with error reporting
```c
if (fixup_pending_index != FP_NONE) {
    yyerror("unexpected pending fixup in addressing mode");
    return;
}
```

### 3. Unexpected Fixup in Addressing Mode - Direct Small Offset (Line ~350)
**Function**: `constant_offset_direct()`
- **Before**: `assert(fixup_pending_index == FP_NONE);`
- **After**: Same runtime validation as #2

### 4. Unexpected Fixup in Addressing Mode - Indirect 0 Offset (Line ~377)
**Function**: `constant_offset_indirect()`
- **Before**: `assert(fixup_pending_index == FP_NONE);`
- **After**: Same runtime validation as #2

### 5. Fixup Table Overflow (Line ~1169)
**Function**: `add_fixup()`
- **Before**: `assert(fixup_count < MAX_FIXUPS);`
- **After**: Runtime check with error return
```c
if (fixup_count >= MAX_FIXUPS) {
    yyerror("fixup table overflow");
    return -1;
}
```
- **Impact**: Returns -1 and reports error instead of crashing when fixup table (4096 max) is full

### 6. Unknown Fixup Type (Line ~1247)
**Function**: `apply_fixups()` switch statement
- **Before**: `assert(FALSE);`
- **After**: Increments error count instead of crashing
```c
default:
    fprintf(stderr, "ERROR: unknown fixup type!\n");
    err_count++;
    break;
```
- **Impact**: Assembler continues and reports error code instead of crashing

### 7. Symbol Table Overflow (Line ~1272)
**Function**: `add_symbol()`
- **Before**: `assert(symbol_count < MAX_SYMBOLS);`
- **After**: Runtime check with error return
```c
if (symbol_count >= MAX_SYMBOLS) {
    yyerror("symbol table overflow");
    return -1;
}
```
- **Impact**: Returns -1 and reports error instead of crashing when symbol table (4096 max) is full

## Testing

✅ **Compilation**: No warnings or errors  
✅ **Functionality**: All tests pass, `test.asm` output identical  
✅ **Error Handling**: Graceful degradation instead of crashes  

## Benefits

1. **Production Ready**: No more crashes from runtime conditions
2. **Better Diagnostics**: Clear error messages for overflow conditions
3. **Error Recovery**: Parser continues and reports all errors in one pass
4. **Exit Code Handling**: Error count properly incremented for `make` integration
