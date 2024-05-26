# as09
![GitHub License](https://img.shields.io/github/license/mseminatore/as09)
[![CMake](https://github.com/mseminatore/as09/actions/workflows/cmake.yml/badge.svg)](https://github.com/mseminatore/as09/actions/workflows/cmake.yml)

This project is an MC6809 cross assembler. It is written in portable C using
yacc/bison for the parser and a handwritten lexical analyzer.

The goal of this project was to create a cross assembler compatible with 
EDTASM+ syntax for the TRS-80 Color Computer. To that end the assembler can 
create binary output files compatible with the TRS-80 Disk Extended Color Basic loader using the `-b` command line option.

> While many such cross assemblers already exist, I wanted to retain the option
> to extend the assembler for my own purposes.

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



