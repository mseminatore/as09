# as09
![GitHub License](https://img.shields.io/github/license/mseminatore/as09)
[![CMake](https://github.com/mseminatore/as09/actions/workflows/cmake.yml/badge.svg)](https://github.com/mseminatore/as09/actions/workflows/cmake.yml)
[![CodeQL](https://github.com/mseminatore/as09/actions/workflows/github-code-scanning/codeql/badge.svg)](https://github.com/mseminatore/as09/actions/workflows/github-code-scanning/codeql)

This project is an MC6809 cross assembler. It is written in portable C using
yacc/bison for the parser and a handwritten lexical analyzer. The code is 
parsed in a single-pass using a fixup mechanism to back-patch forward 
references to symbols.

The main goal of this project was to create a cross assembler compatible with 
EDTASM+ syntax for the TRS-80 Color Computer. To that end the assembler can 
create binary output files compatible with the TRS-80 Disk Extended Color Basic
loader using the `-b` command line option.

> While many such cross assemblers already exist, I wanted to retain the option
> to extend the assembler for my own purposes.

A secondary goal of this project was to enable the generation of output files
to enable FPGA emulation of the 6809. Using the `-r` command line option a
Verilog synchronous ROM file. Using the `-a` option will generate an async
ROM file in verilog. The `-s` option will generate a file that uses System
Verilog. Finally, the `-x` option will generate an Intel format `.hex` file.

The assembler is routinely built and tested on Windows, Mac, Linux and RPi. It
has been proven through compilation and execution of significant assembly 
language code bases on both the [XROAR](https://colorcomputerarchive.com/xroar-online/) emulator and working CoCo 1 machines.

> If you find any code generation bugs please report them!

This project pairs with my [dsktools](https://www.github.com/mseminatore/dsktools) project. The `dsktools` application enables creation of RS-DOS compatible virtual disk (.DSK) files which can be loaded in CoCo emulators like XROAR or physical machines via CoCo SDC.

# 6809 Assembly

The as09 assembler follows the Motorola MC6809 and EDTASM+ syntax which you can
find documented [here](https://colorcomputerarchive.com/repo/Documents/Books/Motorola%206809%20and%20Hitachi%206309%20Programming%20Reference%20(Darren%20Atkinson).pdf).

There are some portions of Disk EDTASM+ that are not supported. Specifically:

- Line numbers
- Labels require a following ':'
- Save and load commands
- Conditional compilation
- Emulation and debugging

## Assembler extensions

as09 adds several optional instruction extensions for convenience. They are:

Mnemonic | Description
-------- | -----------
BNZ | equivalent to BNE
BZ | equivalent to BEQ
CLRC | Clear carry flag, equivalent to ANDCC #$FE
CLRZ | Clear zero flag, equivalent to ANDCC #$FC
FCZ string | Declares a null terminated string
INCLUDE string | Includes file in assembly
SETC | Set carry flag, equivalent to ORCC #$01
SETZ | Set zero flag, equivalent to ORCC #$04

The parser for as09 enables a few modern features like C-style backslash
character processing in strings. For example, use `\r` in a string to
include a carriage-return.

Other C-style operators that can be used in expressions include the bitwise 
AND `&`, OR `|` and NOT `~` operators.

# Using as09

Using the assembler is straightforward. Here is a small example program for 
the TRS-80 CoCo that prints out a string on the screen.

```asm
;---------------------------------------------------
; Hello World for the TRS-80 CoCo in MC6809 assembly
;---------------------------------------------------
CHARIN EQU $A000
CHAROUT EQU $A002
STRING: FCC 'Hello World!' FCB 0

START:
  LDX #STRING    ; get ptr to string

LOOP:
  LDA ,X+        ; get next character
  BEQ DONE       ; if null terminator then done

  JSR [CHAROUT]  ; print out next char
  BRA LOOP       ; do it again

DONE:
  JSR [CHARIN]   ; poll keyboard
  BEQ DONE       ; wait for keypress
  SWI            ; quit
END START
```

Save that code to a file called hello.asm and assemble it as follows:

```console
% as09 hello.asm
as09 v0.4.0 - an MC6809 assembler by Mark Seminatore (c) 2024
as09 assembled 33 bytes, 23 total lines of code to 'a.out'
```

To generate a binary file ready to execute on the CoCo use the `-b` option
along with `-o` to name the file. For example

```console
% as09 -b -o hello.bin hello.asm
as09 v0.4.1 - an MC6809 cross-assembler by Mark Seminatore (c) 2024
as09 assembled 33 bytes, 23 total lines of code to 'hello.bin'
```

# Building as09

You can build as09 using either Makefile or CMake. For makefile builds use:

```console
% make
```

For CMake builds:

```console
% mkdir build
% cd build
% cmake ..
% cmake --build .
```

# Installing as09

For Unix-like systems a shell script is provided that will install a link to 
the as09 binary in the `/usr/bin/local` folder. You can invoke this using Make
or by running the file links.sh directly.

```console
% make install
```

OR

```console
% sudo ./links.sh
```

# Testing as09

If you make modifications to as09, particularly ones that change the code 
generation you must run the test cases. These compare the hex file output
of the `test.asm` file vs. the baseline file `test.hex`. If there are any
changes then a code generation error may have been introduced.

The tests can be run via Make or CMake. For makefile usage:

```console
% make test
```

Or for Cmake projects:

```console
% cd build
% ctest
```
