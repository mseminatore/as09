# Security & Memory Management Fixes

## Summary
Applied three critical security and stability improvements to as09 v0.5.3:

### 1. Safe String Operations ✓
**Files Modified**: [as09.y](as09.y)

#### vsprintf → vsnprintf (Line ~178)
- **Issue**: `vsprintf(buf, fmt, valist)` with fixed 512-byte buffer could overflow
- **Fix**: Changed to `vsnprintf(buf, BUF_SIZE - 1, fmt, valist)` with bounds enforcement
- **Impact**: Prevents debug log buffer overflow attacks

#### strcpy → snprintf (Line ~1834)  
- **Issue**: `strcpy(infile, argv[iFirstArg])` with 512-byte buffer could overflow on long paths
- **Fix**: Changed to `snprintf(infile, sizeof(infile) - 1, "%s", argv[iFirstArg])`
- **Impact**: Prevents command-line argument buffer overflow

### 2. File I/O Error Handling ✓
**Files Modified**: [as09.y](as09.y)

#### Output File Creation (Line ~1837)
- **Issue**: `fopen()` result not checked; subsequent write operations would fail silently
- **Fix**: Added explicit NULL check with error message
```c
fout = fopen(g_szOutputFilename, "wb");
if (!fout) {
    fprintf(stderr, "ERROR: cannot open output file '%s' for writing\n", g_szOutputFilename);
    return 1;
}
```
- **Impact**: Returns error code 1 on write failures instead of silently producing corrupted output

#### Binary File Writing (Lines ~1677-1703)
- **Issue**: `fwrite()` calls ignored return values, could fail silently
- **Fix**: All three fwrite() calls now validated:
```c
if (fwrite(&pre, sizeof(pre), 1, fout) != 1) {
    fprintf(stderr, "ERROR: failed to write binary header\n");
    return;
}
```
- **Impact**: Errors during binary output generation now reported

### 3. Memory Leak Prevention ✓
**Files Modified**: [as09.y](as09.y)

#### Symbol Table Cleanup (Line ~1302-1310)
- **Issue**: `Symbol_t` entries use `strdup()` for name and filename; 4096 entries not freed on exit
- **Fix**: Added `cleanup_symbols()` function:
```c
void cleanup_symbols() {
    for (int i = 0; i < symbol_count; i++) {
        free((void*)symbols[i].name);
        free((void*)symbols[i].filename);
    }
}
```
- **Called**: From `main()` before return (Line ~1884)
- **Impact**: All allocated symbol memory properly freed on shutdown

## Testing

✅ **Compilation**: Builds without warnings  
✅ **Functionality**: `test.asm` assembles to identical output  
✅ **Error Handling**: Properly rejects invalid output paths  
✅ **Binary Output**: Successfully generates DECB format with error checking  

## Verification Commands

```bash
# Build
make

# Test assembly
./as09 -x test.asm && diff a.out test.hex

# Test error handling (write to non-writable location)
./as09 -o /root/test.out -x test.asm 2>&1

# Test binary output
./as09 -b test.asm
```

## Recommendations for Further Hardening

1. Replace remaining `assert()` with runtime checks (e.g., `add_symbol()` at line 1275)
2. Add bounds checking on fixed arrays (`MAX_SYMBOLS`, `MAX_CODE`, `MAX_FIXUPS`)
3. Use hash table for symbol lookup (currently O(n), 4096 max symbols)
4. Consider dynamic allocation for code buffer instead of fixed 32KB
