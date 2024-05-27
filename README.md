# as09
![GitHub License](https://img.shields.io/github/license/mseminatore/as09)
[![CMake](https://github.com/mseminatore/as09/actions/workflows/cmake.yml/badge.svg)](https://github.com/mseminatore/as09/actions/workflows/cmake.yml)

This project is an MC6809 cross assembler. It is written in portable C using
yacc/bison for the parser and a handwritten lexical analyzer.

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

# 6809 Assembly

The as09 assembler follows the Motorola MC6809 and EDTASM+ syntax which you can
find documented [here](https://colorcomputerarchive.com/repo/Documents/Books/Motorola%206809%20and%20Hitachi%206309%20Programming%20Reference%20(Darren%20Atkinson).pdf).

There are some portions of Disk EDTASM+ that are not supported. Specifically:

- Line numbers
- Save and load commands
- Conditional compilation
- Emulation and debugging

# Building as09

You can build as09 using either Makefile or CMake. For makefile builds use:

```
%make
```

For CMake builds:

```
%mkdir build
%cmake ..
%cmake --build .
```

# Installing as09

For Unix-like systems a shell script is provided that will install the as09 binary in the `/usr/bin/local` folder. You can invoke this using Make or by running the file links.sh directly.

```
%make install
```

OR

```
%sudo ./links.sh
```

# Testing as09

If you make modifications to as09, particularly ones that change the code generation you must run the test cases. These compare the hex file output of the `test.asm` file vs. the baseline file `test.hex`. If there are any changes then a code generation error may have been introduced.