/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include "as09.h"
#include "decb.h"

// command line switches
const char * g_szOutputFilename = "a.out";
int g_bDebug        = FALSE;
int g_bSyncROM      = TRUE;
int g_bROM          = FALSE;
int g_bSystemV      = FALSE;
int g_bBinaryRom    = FALSE;
int g_bCompactFile  = FALSE;
int g_bHexFile      = FALSE;
int g_bSymbols      = FALSE;
int g_bUnreferenced = FALSE;
int g_bListingFile  = FALSE;

// parser tracking
int lineno = 1;
int err_count = 0;
int warn_count = 0;

// assembler input and output files
FILE *yyin = NULL;
FILE *fout = NULL;

// code segment
uint16_t addr = 0;
uint8_t code[MAX_CODE];
uint16_t direct_page_addr = 0;
uint16_t origin_addr = 0;
uint16_t start_addr = 0;

// symbol table
Symbol_t symbols[MAX_SYMBOLS];
int symbol_count = 0;

// fixups
Fixup_t fixups[MAX_FIXUPS];         // list of address fixups
int fixup_count = 0;                // count of address fixups
int fixup_pending_index = FP_NONE;  // index of currently pending fixup 

// listing file support
Listing_t listing[MAX_LISTING];     // listing entries
int listing_count = 0;              // count of listing entries
char line_buf[LINE_BUF_SIZE];       // buffer for current source line
int line_buf_pos = 0;               // current position in line buffer
uint16_t line_start_addr = 0;       // address at start of current line 

// instruction buffer
uint8_t inst_buf[INB_SIZE];
int inst_ptr = 0;

// file descriptor stack
#define MAX_FILE_STACK 50

int file_stack_ptr = 0;
FileNode file_nodes[MAX_FILE_STACK];

#define LAST_SYMBOL       symbols[symbol_count - 1]
#define CURRENT_FILE      file_nodes[file_stack_ptr].filename
#define CURRENT_LINENO    file_nodes[file_stack_ptr].yylineno

const char *fixup_names[] =
{
    "FIXUP_NOCHANGE",
    "FIXUP_IMM8",
    "FIXUP_IMM16",
    "FIXUP_REL8",
    "FIXUP_REL16",
};

Opcodes opcodes[] = 
{
    // Immediate, Direct, Indexed, Extended
    {0x89, 0x99, 0xA9, 0xB9},   // ADCA
    {0xC9, 0xD9, 0xE9, 0xF9},   // ADCB
    {0x8B, 0x9B, 0xAB, 0xBB},   // ADDA
    {0xCB, 0xDB, 0xEB, 0xFB},   // ADDB
    {0xC3, 0xD3, 0xE3, 0xF3},   // ADDD
    {0x84, 0x94, 0xA4, 0xB4},   // ANDA
    {0xC4, 0xD4, 0xE4, 0xF4},   // ANDB
    {0x00, 0x08, 0x68, 0x78},   // ASL
    {0x00, 0x07, 0x67, 0x77},   // ASR
    {0x85, 0x95, 0xA5, 0xB5},   // BITA
    {0xC5, 0xD5, 0xE5, 0xF5},   // BITB
    {0x00, 0x0F, 0x6F, 0x7F},   // CLR
    {0x81, 0x91, 0xA1, 0xB1},   // CMPA
    {0xC1, 0xD1, 0xE1, 0xF1},   // CMPB
    {0x83, 0x93, 0xA3, 0xB3},   // CMPD
    {0x8C, 0x9C, 0xAC, 0xBC},   // CMPS
    {0x00, 0x03, 0x63, 0x73},   // COM
    {0x00, 0x0A, 0x6A, 0x7A},   // DEC
    {0x88, 0x98, 0xA8, 0xB8},   // EORA
    {0xC8, 0xD8, 0xE8, 0xF8},   // EORB
    {0x00, 0x0C, 0x6C, 0x7C},   // INC
    {0x00, 0x0E, 0x6E, 0x7E},   // JMP
    {0x00, 0x9D, 0xAD, 0xBD},   // JSR
    {0x86, 0x96, 0xA6, 0xB6},   // LDA
    {0xC6, 0xD6, 0xE6, 0xF6},   // LDB
    {0xCC, 0xDC, 0xEc, 0xFC},   // LDD
    {0xCE, 0xDE, 0xEE, 0xFE},   // LDU
    {0x8E, 0x9E, 0xAE, 0xBE},   // LDX
    {0x00, 0x00, 0x30, 0x00},   // LEAX
    {0x00, 0x00, 0x31, 0x00},   // LEAY
    {0x00, 0x00, 0x32, 0x00},   // LEAS
    {0x00, 0x00, 0x33, 0x00},   // LEAU
    {0x00, 0x08, 0x68, 0x78},   // LSL
    {0x00, 0x04, 0x64, 0x74},   // LSR
    {0x00, 0x00, 0x60, 0x70},   // NEG
    {0x8A, 0x9A, 0xAA, 0xBA},   // ORA
    {0xCA, 0xDA, 0xEA, 0xFA},   // ORB
    {0x00, 0x09, 0x69, 0x79},   // ROL
    {0x00, 0x06, 0x66, 0x76},   // ROR
    {0x82, 0x92, 0xA2, 0xB2},   // SBCA
    {0xC2, 0xD2, 0xE2, 0xF2},   // SBCB
    {0x00, 0x97, 0xA7, 0xB7},   // STA
    {0x00, 0xD7, 0xE7, 0xF7},   // STB
    {0x00, 0xDD, 0xED, 0xFD},   // STD
    {0x00, 0xDF, 0xEF, 0xFF},   // STS
    {0x00, 0xDF, 0xEF, 0xFF},   // STU
    {0x00, 0x9F, 0xAF, 0xBF},   // STX
    {0x00, 0x9F, 0xAF, 0xBF},   // STY
    {0x80, 0x90, 0xA0, 0xB0},   // SUBA
    {0xC0, 0xD0, 0xE0, 0xF0},   // SUBB
    {0x83, 0x93, 0xA3, 0xB3},   // SUBD
    {0x00, 0x0D, 0x6D, 0x7D}    // TST
};

//-----------------------------------
// Verilog vs. SystemVerilog strings
//-----------------------------------
char *input_wire    = "input wire";
char *output_reg    = "output reg";
char *always_ff     = "always @(posedge clk)";
char *always_comb   = "always @*";
char *reg           = "reg";

//------------------------
// error routine
//------------------------
void yyerror(char *s)
{
    fprintf(stderr, "ERROR: '%s' in file '%s' near line %d\n", s, CURRENT_FILE, CURRENT_LINENO);
    err_count++;
}

//------------------------
// error routine
//------------------------
void yywarning(char *s)
{
    fprintf(stderr, "WARNING: '%s' in file '%s' near line %d\n", s, CURRENT_FILE, CURRENT_LINENO);
    warn_count++;
}

//-----------------------------------
// logging function
//-----------------------------------
void LOG(const char *fmt, ...)
{
    if (!g_bDebug)
    {
        return;
    }
    
	char buf[BUF_SIZE];
	va_list valist;

	va_start(valist, fmt);
	vsnprintf(buf, BUF_SIZE - 1, fmt, valist);
	va_end(valist);

	fputs(buf, stdout);
}

//-----------------------------------
// push new input file onto the stack
//-----------------------------------
void push_file_stack(const char *filename)
{
    if (file_stack_ptr + 1 > MAX_FILE_STACK)
        yyerror("too many includes!");

    FILE *fptr = fopen(filename, "rt");
    if (!fptr)
        yyerror("include file not found");

    file_stack_ptr++;
    file_nodes[file_stack_ptr].fptr = fptr;
    file_nodes[file_stack_ptr].filename = strdup(filename);
    file_nodes[file_stack_ptr].yylineno = 1;
    file_nodes[file_stack_ptr].column = 1;

    yyin = fptr;
    LOG("Push '%s' onto parser input stack (depth = %d)\n", filename, file_stack_ptr);
}

//-----------------------------------
// pop input file off the stack
//-----------------------------------
void pop_file_stack()
{
    if (file_stack_ptr <= 0)
        yyerror("file stack underflow!");

    LOG("Popping '%s' from parser input stack (depth = %d)\n", file_nodes[file_stack_ptr].filename, file_stack_ptr-1);

    free(file_nodes[file_stack_ptr].filename);
    fclose(file_nodes[file_stack_ptr].fptr);

    file_stack_ptr--;
    yyin = file_nodes[file_stack_ptr].fptr;
}

//-----------------------------------
// next next char from input stream
//-----------------------------------
int getch()
{
    int c = fgetc(yyin);
    
    // buffer the line for listing file
    if (g_bListingFile && c != EOF && line_buf_pos < LINE_BUF_SIZE - 1)
    {
        if (c == '\n')
        {
            line_buf[line_buf_pos] = '\0';
        }
        else if (c != '\r')  // skip carriage returns
        {
            line_buf[line_buf_pos++] = c;
        }
    }
    
    return c;
}

//-----------------------------------
// put char back to input stream
//-----------------------------------
int ungetch(int c)
{
    return ungetc(c, yyin);
}

//----------------------------------------------
// helper function to accumulate generated code
//----------------------------------------------
void emit(uint8_t v)
{
    code[addr] = v;
    addr++;
}

//----------------------------------------------
// helper function to accumulate word values
//----------------------------------------------
void emit_word(uint16_t v)
{
    emit(HIBYTE(v));
    emit(LOBYTE(v));
}

//----------------------------------------------
// helper function to queue generated code
//----------------------------------------------
void emit_buf(uint8_t v)
{
    if (inst_ptr >= INB_SIZE)
    {
        yyerror("instruction buffer overflow");
        return;
    }
    inst_buf[inst_ptr++] = v;
}

//----------------------------------------------
// helper function to queue a code word
//----------------------------------------------
void emit_buf_word(uint16_t v)
{
    emit_buf(HIBYTE(v));
    emit_buf(LOBYTE(v));
}

//----------------------------------------------
// helper function to emit a string
//----------------------------------------------
void emit_str(const char *s)
{
    for (int i = 0; i < strlen(s); i++)
        emit(s[i]);
}

//----------------------------------------------
// helper function to emit queued code
//----------------------------------------------
void write_inb()
{
    // emit queued instruction codes
    for (int i = 0; i < inst_ptr; i++)
        emit(inst_buf[i]);

    // mark instruction queue as empty
    inst_ptr = 0;
}

//------------------------
// save listing entry
//------------------------
void save_listing_entry()
{
    if (!g_bListingFile)
        return;
        
    if (listing_count >= MAX_LISTING)
    {
        yyerror("listing buffer overflow");
        return;
    }
    
    // Save the listing entry
    Listing_t *entry = &listing[listing_count++];
    entry->lineno = lineno - 1;  // lineno was already incremented for next line
    entry->addr = origin_addr + line_start_addr;
    entry->code_len = addr - line_start_addr;
    
    // Limit to max 16 bytes per line
    if (entry->code_len > 16)
        entry->code_len = 16;
        
    // Copy the code bytes
    for (int i = 0; i < entry->code_len; i++)
        entry->code_bytes[i] = code[line_start_addr + i];
    
    // Copy the source line
    strncpy(entry->source, line_buf, LINE_BUF_SIZE - 1);
    entry->source[LINE_BUF_SIZE - 1] = '\0';
    
    // Reset for next line
    line_buf_pos = 0;
    line_buf[0] = '\0';
    line_start_addr = addr;
}

//------------------------
// convert int to int5
//------------------------
int8_t to_int5(int val)
{
    int8_t i5 = val & 0xF;
    if (val < 0)
        i5 |= 0x10;

    return i5;
}

//------------------------
// convert int to int8
//------------------------
int8_t to_int8(int val)
{
    int8_t i8 = val & 0x7F;
    if (val < 0)
        i8 |= 0x80;

    return i8;
}

//------------------------
// convert int to int8
//------------------------
int16_t to_int16(int val)
{
    int16_t i16 = val & 0x7FFF;
    if (val < 0)
        i16 |= 0x8000;

    return i16;
}

//----------------------------------------------------
// compute postbyte for direct addressing with offset
//----------------------------------------------------
void constant_offset_direct(int16_t offset, int index_reg)
{
    if (offset == 0)
    {
        if (fixup_pending_index != FP_NONE)
        {
            yyerror("unexpected pending fixup in addressing mode");
            return;
        }
        emit_buf(0x84 | (index_reg << 5));
    }
    else if (offset >= -16 && offset <= 15)
    {
        // compute 5-bit signed value
        char byte_offset = offset & 0xF;
        if (offset < 0)
            byte_offset |= 0x10;

        if (fixup_pending_index != FP_NONE)
        {
            yyerror("unexpected pending fixup in addressing mode");
            return;
        }
        emit_buf(byte_offset | (index_reg << 5));
    }
    else if (offset >= -128 && offset <= 127)
    {
        // compute 8-bit signed value
        char byte_offset = offset & 0x7F;
        if (offset < 0)
            byte_offset |= 0x80;

        emit_buf(0x88 | (index_reg << 5));
        emit_buf(byte_offset);
    }
    else
    {
        emit_buf(0x89 | (index_reg << 5));
        emit_buf_word(offset);
    }
}

//------------------------------------------------------
// compute postbyte for indirect addressing with offset
//------------------------------------------------------
void constant_offset_indirect(int16_t offset, int index_reg)
{
    if (offset == 0)
    {
        if (fixup_pending_index != FP_NONE)
        {
            yyerror("unexpected pending fixup in addressing mode");
            return;
        }
        emit_buf(0x94 | (index_reg << 5));
    }
    else if (offset >= -128 && offset <= 127)
    {
        // compute 8-bit signed value
        char byte_offset = offset & 0x7F;
        if (offset < 0)
            byte_offset |= 0x80;

        emit_buf(0x98 | (index_reg << 5));
        emit_buf(byte_offset);
    }
    else
    {
        emit_buf(0x99 | (index_reg << 5));
        emit_buf_word(offset);
    }
}

//----------------------------------------------------------------
// compute postbyte for direct addressing offset from accumulator
//----------------------------------------------------------------
void accumulator_offset_direct(int accumulator, int index_reg)
{
    switch(accumulator)
    {
    case 0: // A
        emit_buf(0x86 | (index_reg << 5));
        break;

    case 1: // B
        emit_buf(0x85 | (index_reg << 5));
        break;

    case 2: // D
        emit_buf(0x8B | (index_reg << 5));
        break;

    default:
        yyerror("invalid accumulator value");
    }
}

//------------------------------------------------------------------
// compute postbyte for indirect addressing offset from accumulator
//------------------------------------------------------------------
void accumulator_offset_indirect(int accumulator, int index_reg)
{
    switch(accumulator)
    {
    case 0: // A
        emit_buf(0x96 | (index_reg << 5));
        break;

    case 1: // B
        emit_buf(0x95 | (index_reg << 5));
        break;

    case 2: // D
        emit_buf(0x9B | (index_reg << 5));
        break;

    default:
        yyerror("invalid accumulator value");
    }
}

//----------------------------------------------------
// compute postbyte for PC relative direct addressing
//----------------------------------------------------
void pcr_direct(int16_t num)
{
    int16_t offset = num - (addr + origin_addr + 3);

    if (offset >= -128 && offset <= 127)
    {
        // compute 8-bit signed value
        char byte_offset = offset & 0x7F;
        if (offset < 0)
            byte_offset |= 0x80;

        emit_buf(0x8C);
        emit_buf(byte_offset);
    }
    else
    {
        emit_buf(0x8D);
        emit_buf_word(offset - 1);
    }
}

//------------------------------------------------------
// compute postbyte for PC relative indirect addressing
//------------------------------------------------------
void pcr_indirect(int16_t num)
{
    int16_t offset = num - (addr + origin_addr + 3);

    if (offset >= -128 && offset <= 127)
    {
        // compute 8-bit signed value
        char byte_offset = offset & 0x7F;
        if (offset < 0)
            byte_offset |= 0x80;

        emit_buf(0x9C);
        emit_buf(byte_offset);
    }
    else
    {
        emit_buf(0x9D);
        emit_buf_word(offset - 1);
    }
}

//----------------------------------------------------
// alter the type of fixup and potentially adjust addr
//----------------------------------------------------
void adjust_fixup(FIXUP_TYPE fixup_type, int adjustment)
{
    // see if we need to adjust a fixup based on address mode
    if (fixup_pending_index != FP_NONE)
    {
        if (fixup_type != FIXUP_NOCHANGE)
            fixups[fixup_pending_index].type = fixup_type;

        fixups[fixup_pending_index].addr += adjustment;
        LOG("Updating fixup type to %s and addr by %d to %d\n", fixup_names[fixup_type], adjustment, fixups[fixup_pending_index].addr);
    }
}

//----------------------------------------------------
// compute relative branch offset
//----------------------------------------------------
void rel_branch(BRANCH_TYPE branch_dist, int op, int dest_addr)
{
    int rel_offset = dest_addr - (addr + origin_addr);

    if (branch_dist == BR_SHORT)
    {
        if (fixup_pending_index != FP_NONE)
        {
            adjust_fixup(FIXUP_REL8, 0);
            rel_offset = 0;
        }
        else
        {
            rel_offset -= 2;        
        }

        if (rel_offset < -128 || rel_offset > 127)
        {
            printf("offset is %d\n", rel_offset);
            yyerror("BYTE OVERFLOW");
            return;
        } else
        {
            // compute 8-bit signed value
            char byte_offset = rel_offset & 0x7F;
            if (rel_offset < 0)
                byte_offset |= 0x80;

            emit(op); 
            emit(LOBYTE(byte_offset));
        }
    } else  // Long branch
    {
        if (fixup_pending_index != FP_NONE)
        {
            adjust_fixup(FIXUP_REL16, 0 + ((branch_dist != BR_LONG_NOPREFIX) ? 1 : 0));
            rel_offset = 0;
        }
        else
        {
            rel_offset -=4;
        }
        
        if (branch_dist != BR_LONG_NOPREFIX)
            emit(0x10);
        else
            rel_offset++;

        emit(op);
        emit_word(rel_offset);
    }
}



# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "as09.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_3_ = 3,                         /* '!'  */
  YYSYMBOL_4_ = 4,                         /* '~'  */
  YYSYMBOL_5_ = 5,                         /* '&'  */
  YYSYMBOL_6_ = 6,                         /* '|'  */
  YYSYMBOL_7_ = 7,                         /* '+'  */
  YYSYMBOL_8_ = 8,                         /* '-'  */
  YYSYMBOL_9_ = 9,                         /* '*'  */
  YYSYMBOL_10_ = 10,                       /* '/'  */
  YYSYMBOL_EQU = 11,                       /* EQU  */
  YYSYMBOL_INCLUDE = 12,                   /* INCLUDE  */
  YYSYMBOL_SET = 13,                       /* SET  */
  YYSYMBOL_ID = 14,                        /* ID  */
  YYSYMBOL_STRING = 15,                    /* STRING  */
  YYSYMBOL_CHAR = 16,                      /* CHAR  */
  YYSYMBOL_ABX = 17,                       /* ABX  */
  YYSYMBOL_ASLA = 18,                      /* ASLA  */
  YYSYMBOL_ASLB = 19,                      /* ASLB  */
  YYSYMBOL_ASRA = 20,                      /* ASRA  */
  YYSYMBOL_ASRB = 21,                      /* ASRB  */
  YYSYMBOL_CLRA = 22,                      /* CLRA  */
  YYSYMBOL_CLRB = 23,                      /* CLRB  */
  YYSYMBOL_COMA = 24,                      /* COMA  */
  YYSYMBOL_COMB = 25,                      /* COMB  */
  YYSYMBOL_CWAI = 26,                      /* CWAI  */
  YYSYMBOL_DAA = 27,                       /* DAA  */
  YYSYMBOL_DECA = 28,                      /* DECA  */
  YYSYMBOL_DECB = 29,                      /* DECB  */
  YYSYMBOL_INCA = 30,                      /* INCA  */
  YYSYMBOL_INCB = 31,                      /* INCB  */
  YYSYMBOL_LSLA = 32,                      /* LSLA  */
  YYSYMBOL_LSLB = 33,                      /* LSLB  */
  YYSYMBOL_LSRA = 34,                      /* LSRA  */
  YYSYMBOL_LSRB = 35,                      /* LSRB  */
  YYSYMBOL_MUL = 36,                       /* MUL  */
  YYSYMBOL_NEGA = 37,                      /* NEGA  */
  YYSYMBOL_NEGB = 38,                      /* NEGB  */
  YYSYMBOL_NOP = 39,                       /* NOP  */
  YYSYMBOL_ROLA = 40,                      /* ROLA  */
  YYSYMBOL_ROLB = 41,                      /* ROLB  */
  YYSYMBOL_RORA = 42,                      /* RORA  */
  YYSYMBOL_RORB = 43,                      /* RORB  */
  YYSYMBOL_RTI = 44,                       /* RTI  */
  YYSYMBOL_RTS = 45,                       /* RTS  */
  YYSYMBOL_SEX = 46,                       /* SEX  */
  YYSYMBOL_SWI = 47,                       /* SWI  */
  YYSYMBOL_SWI2 = 48,                      /* SWI2  */
  YYSYMBOL_SWI3 = 49,                      /* SWI3  */
  YYSYMBOL_SYNC = 50,                      /* SYNC  */
  YYSYMBOL_TSTA = 51,                      /* TSTA  */
  YYSYMBOL_TSTB = 52,                      /* TSTB  */
  YYSYMBOL_TST = 53,                       /* TST  */
  YYSYMBOL_ADCA = 54,                      /* ADCA  */
  YYSYMBOL_ADCB = 55,                      /* ADCB  */
  YYSYMBOL_ADDA = 56,                      /* ADDA  */
  YYSYMBOL_ADDB = 57,                      /* ADDB  */
  YYSYMBOL_ADDD = 58,                      /* ADDD  */
  YYSYMBOL_ANDA = 59,                      /* ANDA  */
  YYSYMBOL_ANDB = 60,                      /* ANDB  */
  YYSYMBOL_ANDCC = 61,                     /* ANDCC  */
  YYSYMBOL_ASL = 62,                       /* ASL  */
  YYSYMBOL_ASR = 63,                       /* ASR  */
  YYSYMBOL_BCC = 64,                       /* BCC  */
  YYSYMBOL_BCS = 65,                       /* BCS  */
  YYSYMBOL_BEQ = 66,                       /* BEQ  */
  YYSYMBOL_BGE = 67,                       /* BGE  */
  YYSYMBOL_BGT = 68,                       /* BGT  */
  YYSYMBOL_BHI = 69,                       /* BHI  */
  YYSYMBOL_BHS = 70,                       /* BHS  */
  YYSYMBOL_BITA = 71,                      /* BITA  */
  YYSYMBOL_BITB = 72,                      /* BITB  */
  YYSYMBOL_BLE = 73,                       /* BLE  */
  YYSYMBOL_BLO = 74,                       /* BLO  */
  YYSYMBOL_BLS = 75,                       /* BLS  */
  YYSYMBOL_BLT = 76,                       /* BLT  */
  YYSYMBOL_BMI = 77,                       /* BMI  */
  YYSYMBOL_BNE = 78,                       /* BNE  */
  YYSYMBOL_BPL = 79,                       /* BPL  */
  YYSYMBOL_BRA = 80,                       /* BRA  */
  YYSYMBOL_BRN = 81,                       /* BRN  */
  YYSYMBOL_BSR = 82,                       /* BSR  */
  YYSYMBOL_BVC = 83,                       /* BVC  */
  YYSYMBOL_BVS = 84,                       /* BVS  */
  YYSYMBOL_CLR = 85,                       /* CLR  */
  YYSYMBOL_CMPA = 86,                      /* CMPA  */
  YYSYMBOL_CMPB = 87,                      /* CMPB  */
  YYSYMBOL_CMPD = 88,                      /* CMPD  */
  YYSYMBOL_CMPS = 89,                      /* CMPS  */
  YYSYMBOL_CMPU = 90,                      /* CMPU  */
  YYSYMBOL_CMPX = 91,                      /* CMPX  */
  YYSYMBOL_CMPY = 92,                      /* CMPY  */
  YYSYMBOL_COM = 93,                       /* COM  */
  YYSYMBOL_DEC = 94,                       /* DEC  */
  YYSYMBOL_EORA = 95,                      /* EORA  */
  YYSYMBOL_EORB = 96,                      /* EORB  */
  YYSYMBOL_EXG = 97,                       /* EXG  */
  YYSYMBOL_INC = 98,                       /* INC  */
  YYSYMBOL_JMP = 99,                       /* JMP  */
  YYSYMBOL_JSR = 100,                      /* JSR  */
  YYSYMBOL_TFR = 101,                      /* TFR  */
  YYSYMBOL_LBCC = 102,                     /* LBCC  */
  YYSYMBOL_LBCS = 103,                     /* LBCS  */
  YYSYMBOL_LBEQ = 104,                     /* LBEQ  */
  YYSYMBOL_LBGE = 105,                     /* LBGE  */
  YYSYMBOL_LBGT = 106,                     /* LBGT  */
  YYSYMBOL_LBHI = 107,                     /* LBHI  */
  YYSYMBOL_LBHS = 108,                     /* LBHS  */
  YYSYMBOL_LBLE = 109,                     /* LBLE  */
  YYSYMBOL_LBLO = 110,                     /* LBLO  */
  YYSYMBOL_LBLS = 111,                     /* LBLS  */
  YYSYMBOL_LBLT = 112,                     /* LBLT  */
  YYSYMBOL_LBMI = 113,                     /* LBMI  */
  YYSYMBOL_LBNE = 114,                     /* LBNE  */
  YYSYMBOL_LBPL = 115,                     /* LBPL  */
  YYSYMBOL_LBRA = 116,                     /* LBRA  */
  YYSYMBOL_LBRN = 117,                     /* LBRN  */
  YYSYMBOL_LBSR = 118,                     /* LBSR  */
  YYSYMBOL_LBVC = 119,                     /* LBVC  */
  YYSYMBOL_LBVS = 120,                     /* LBVS  */
  YYSYMBOL_LDA = 121,                      /* LDA  */
  YYSYMBOL_LDB = 122,                      /* LDB  */
  YYSYMBOL_LDD = 123,                      /* LDD  */
  YYSYMBOL_LDS = 124,                      /* LDS  */
  YYSYMBOL_LDU = 125,                      /* LDU  */
  YYSYMBOL_LDX = 126,                      /* LDX  */
  YYSYMBOL_LDY = 127,                      /* LDY  */
  YYSYMBOL_LEAX = 128,                     /* LEAX  */
  YYSYMBOL_LEAY = 129,                     /* LEAY  */
  YYSYMBOL_LEAS = 130,                     /* LEAS  */
  YYSYMBOL_LEAU = 131,                     /* LEAU  */
  YYSYMBOL_LSL = 132,                      /* LSL  */
  YYSYMBOL_LSR = 133,                      /* LSR  */
  YYSYMBOL_NEG = 134,                      /* NEG  */
  YYSYMBOL_ORA = 135,                      /* ORA  */
  YYSYMBOL_ORB = 136,                      /* ORB  */
  YYSYMBOL_ORCC = 137,                     /* ORCC  */
  YYSYMBOL_PSHS = 138,                     /* PSHS  */
  YYSYMBOL_PSHU = 139,                     /* PSHU  */
  YYSYMBOL_PULS = 140,                     /* PULS  */
  YYSYMBOL_PULU = 141,                     /* PULU  */
  YYSYMBOL_SBCA = 142,                     /* SBCA  */
  YYSYMBOL_SBCB = 143,                     /* SBCB  */
  YYSYMBOL_ROL = 144,                      /* ROL  */
  YYSYMBOL_ROR = 145,                      /* ROR  */
  YYSYMBOL_STA = 146,                      /* STA  */
  YYSYMBOL_STB = 147,                      /* STB  */
  YYSYMBOL_STD = 148,                      /* STD  */
  YYSYMBOL_STX = 149,                      /* STX  */
  YYSYMBOL_STY = 150,                      /* STY  */
  YYSYMBOL_STS = 151,                      /* STS  */
  YYSYMBOL_STU = 152,                      /* STU  */
  YYSYMBOL_SUBA = 153,                     /* SUBA  */
  YYSYMBOL_SUBB = 154,                     /* SUBB  */
  YYSYMBOL_SUBD = 155,                     /* SUBD  */
  YYSYMBOL_NUMBER = 156,                   /* NUMBER  */
  YYSYMBOL_A = 157,                        /* A  */
  YYSYMBOL_B = 158,                        /* B  */
  YYSYMBOL_D = 159,                        /* D  */
  YYSYMBOL_X = 160,                        /* X  */
  YYSYMBOL_Y = 161,                        /* Y  */
  YYSYMBOL_U = 162,                        /* U  */
  YYSYMBOL_S = 163,                        /* S  */
  YYSYMBOL_PC = 164,                       /* PC  */
  YYSYMBOL_CC = 165,                       /* CC  */
  YYSYMBOL_DP = 166,                       /* DP  */
  YYSYMBOL_PCR = 167,                      /* PCR  */
  YYSYMBOL_SETDP = 168,                    /* SETDP  */
  YYSYMBOL_ORG = 169,                      /* ORG  */
  YYSYMBOL_FCB = 170,                      /* FCB  */
  YYSYMBOL_FDB = 171,                      /* FDB  */
  YYSYMBOL_FCC = 172,                      /* FCC  */
  YYSYMBOL_RMB = 173,                      /* RMB  */
  YYSYMBOL_END = 174,                      /* END  */
  YYSYMBOL_FCZ = 175,                      /* FCZ  */
  YYSYMBOL_SETC = 176,                     /* SETC  */
  YYSYMBOL_CLRC = 177,                     /* CLRC  */
  YYSYMBOL_SETZ = 178,                     /* SETZ  */
  YYSYMBOL_CLRZ = 179,                     /* CLRZ  */
  YYSYMBOL_CLRD = 180,                     /* CLRD  */
  YYSYMBOL_ASLD = 181,                     /* ASLD  */
  YYSYMBOL_ASRD = 182,                     /* ASRD  */
  YYSYMBOL_183_ = 183,                     /* ':'  */
  YYSYMBOL_184_ = 184,                     /* '('  */
  YYSYMBOL_185_ = 185,                     /* ')'  */
  YYSYMBOL_186_ = 186,                     /* '#'  */
  YYSYMBOL_187_ = 187,                     /* '>'  */
  YYSYMBOL_188_ = 188,                     /* '<'  */
  YYSYMBOL_189_ = 189,                     /* '['  */
  YYSYMBOL_190_ = 190,                     /* ']'  */
  YYSYMBOL_191_ = 191,                     /* ','  */
  YYSYMBOL_YYACCEPT = 192,                 /* $accept  */
  YYSYMBOL_file = 193,                     /* file  */
  YYSYMBOL_end = 194,                      /* end  */
  YYSYMBOL_lines = 195,                    /* lines  */
  YYSYMBOL_line = 196,                     /* line  */
  YYSYMBOL_label = 197,                    /* label  */
  YYSYMBOL_byte_expr = 198,                /* byte_expr  */
  YYSYMBOL_word_expr = 199,                /* word_expr  */
  YYSYMBOL_const_expr = 200,               /* const_expr  */
  YYSYMBOL_imm8 = 201,                     /* imm8  */
  YYSYMBOL_imm16 = 202,                    /* imm16  */
  YYSYMBOL_op8 = 203,                      /* op8  */
  YYSYMBOL_op16 = 204,                     /* op16  */
  YYSYMBOL_direct_indexed_extended = 205,  /* direct_indexed_extended  */
  YYSYMBOL_indexed = 206,                  /* indexed  */
  YYSYMBOL_instruction = 207,              /* instruction  */
  YYSYMBOL_strings = 208,                  /* strings  */
  YYSYMBOL_bytes = 209,                    /* bytes  */
  YYSYMBOL_words = 210,                    /* words  */
  YYSYMBOL_push_registers = 211,           /* push_registers  */
  YYSYMBOL_push_register = 212,            /* push_register  */
  YYSYMBOL_register = 213,                 /* register  */
  YYSYMBOL_index_register = 214,           /* index_register  */
  YYSYMBOL_accumulator = 215               /* accumulator  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   711

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  192
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  258
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  443

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   429


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     2,   186,     2,     2,     5,     2,
     184,   185,     9,     7,   191,     8,     2,    10,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   183,     2,
     188,     2,   187,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   189,     2,   190,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     6,     2,     4,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   677,   677,   680,   681,   682,   685,   686,   689,   690,
     691,   692,   693,   696,   699,   700,   701,   702,   703,   704,
     705,   706,   707,   710,   711,   712,   713,   714,   715,   716,
     717,   718,   719,   722,   723,   724,   725,   726,   727,   728,
     729,   730,   731,   734,   735,   736,   739,   740,   743,   744,
     747,   748,   751,   752,   753,   754,   755,   758,   759,   760,
     761,   762,   763,   764,   765,   766,   767,   768,   769,   770,
     771,   774,   775,   776,   777,   778,   779,   780,   781,   782,
     783,   784,   785,   786,   787,   788,   789,   790,   791,   792,
     793,   794,   795,   796,   797,   798,   799,   800,   801,   802,
     803,   804,   805,   806,   807,   808,   809,   810,   811,   813,
     814,   815,   816,   817,   818,   819,   820,   821,   822,   823,
     824,   825,   826,   827,   828,   829,   830,   831,   832,   833,
     834,   835,   836,   837,   838,   839,   840,   841,   842,   843,
     844,   845,   846,   847,   848,   849,   850,   851,   852,   853,
     854,   855,   856,   857,   858,   859,   860,   861,   862,   863,
     864,   865,   866,   867,   868,   869,   870,   871,   872,   873,
     874,   875,   876,   877,   878,   879,   880,   881,   882,   883,
     884,   885,   886,   887,   888,   889,   890,   891,   892,   893,
     894,   895,   896,   897,   898,   899,   900,   901,   902,   903,
     904,   905,   906,   907,   908,   909,   910,   911,   912,   913,
     914,   915,   916,   917,   918,   919,   920,   922,   923,   924,
     925,   926,   927,   928,   931,   932,   935,   936,   939,   940,
     943,   944,   947,   948,   949,   950,   951,   952,   953,   954,
     955,   956,   958,   959,   960,   961,   962,   963,   964,   965,
     966,   967,   970,   971,   972,   973,   976,   977,   978
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "'!'", "'~'", "'&'",
  "'|'", "'+'", "'-'", "'*'", "'/'", "EQU", "INCLUDE", "SET", "ID",
  "STRING", "CHAR", "ABX", "ASLA", "ASLB", "ASRA", "ASRB", "CLRA", "CLRB",
  "COMA", "COMB", "CWAI", "DAA", "DECA", "DECB", "INCA", "INCB", "LSLA",
  "LSLB", "LSRA", "LSRB", "MUL", "NEGA", "NEGB", "NOP", "ROLA", "ROLB",
  "RORA", "RORB", "RTI", "RTS", "SEX", "SWI", "SWI2", "SWI3", "SYNC",
  "TSTA", "TSTB", "TST", "ADCA", "ADCB", "ADDA", "ADDB", "ADDD", "ANDA",
  "ANDB", "ANDCC", "ASL", "ASR", "BCC", "BCS", "BEQ", "BGE", "BGT", "BHI",
  "BHS", "BITA", "BITB", "BLE", "BLO", "BLS", "BLT", "BMI", "BNE", "BPL",
  "BRA", "BRN", "BSR", "BVC", "BVS", "CLR", "CMPA", "CMPB", "CMPD", "CMPS",
  "CMPU", "CMPX", "CMPY", "COM", "DEC", "EORA", "EORB", "EXG", "INC",
  "JMP", "JSR", "TFR", "LBCC", "LBCS", "LBEQ", "LBGE", "LBGT", "LBHI",
  "LBHS", "LBLE", "LBLO", "LBLS", "LBLT", "LBMI", "LBNE", "LBPL", "LBRA",
  "LBRN", "LBSR", "LBVC", "LBVS", "LDA", "LDB", "LDD", "LDS", "LDU", "LDX",
  "LDY", "LEAX", "LEAY", "LEAS", "LEAU", "LSL", "LSR", "NEG", "ORA", "ORB",
  "ORCC", "PSHS", "PSHU", "PULS", "PULU", "SBCA", "SBCB", "ROL", "ROR",
  "STA", "STB", "STD", "STX", "STY", "STS", "STU", "SUBA", "SUBB", "SUBD",
  "NUMBER", "A", "B", "D", "X", "Y", "U", "S", "PC", "CC", "DP", "PCR",
  "SETDP", "ORG", "FCB", "FDB", "FCC", "RMB", "END", "FCZ", "SETC", "CLRC",
  "SETZ", "CLRZ", "CLRD", "ASLD", "ASRD", "':'", "'('", "')'", "'#'",
  "'>'", "'<'", "'['", "']'", "','", "$accept", "file", "end", "lines",
  "line", "label", "byte_expr", "word_expr", "const_expr", "imm8", "imm16",
  "op8", "op16", "direct_indexed_extended", "indexed", "instruction",
  "strings", "bytes", "words", "push_registers", "push_register",
  "register", "index_register", "accumulator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-229)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-35)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -229,     6,   330,  -229,     8,    13,  -229,  -229,  -229,  -229,
    -229,  -229,  -229,  -229,  -229,     3,  -229,  -229,  -229,  -229,
    -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,
    -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,
    -229,  -229,     3,     3,     3,     3,     3,    11,     3,     3,
    -172,    47,    47,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
       3,     3,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    47,     3,     3,    11,    11,    11,
      11,    11,    47,    47,     3,     3,   376,    47,    47,    47,
     376,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
       3,     3,    11,    11,    11,    11,    11,    69,    69,    69,
      69,    47,    47,    47,     3,     3,  -170,   413,   413,   413,
     413,     3,     3,    47,    47,    47,    47,    47,    47,    47,
      47,    47,     3,     3,    11,    53,  -129,    53,   149,    40,
      -1,    44,    40,  -229,  -229,  -229,  -229,  -229,  -229,  -229,
    -229,  -229,  -229,  -229,  -229,   149,   149,  -229,   162,  -229,
      80,   106,  -229,  -229,  -229,   162,    53,   149,   149,    93,
     118,   307,   115,  -229,  -229,  -229,  -229,  -131,  -229,  -229,
    -229,  -229,  -229,   149,  -229,  -229,  -229,  -229,    53,  -229,
    -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,
    -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,
    -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,
    -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,
    -229,  -229,  -229,  -229,  -229,  -229,  -123,  -229,  -229,  -229,
    -120,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,
    -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,
    -229,  -229,  -229,  -229,  -229,  -229,  -229,    -1,  -229,  -229,
      -1,   105,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,
    -229,    53,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,
    -229,  -229,  -119,  -229,  -119,  -119,  -119,  -229,  -229,  -229,
    -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,
    -229,    53,  -229,  -229,  -229,    53,   319,  -229,  -229,   319,
    -117,   149,   149,   307,  -110,  -229,  -109,   329,  -229,  -109,
     307,   307,   307,   329,    33,    70,   319,   307,   307,   141,
      86,   131,  -107,   148,  -229,  -229,  -229,  -229,    55,   149,
     149,   149,   149,   149,   149,    -1,    -1,    -1,    -1,    -1,
      -1,  -113,   -62,   307,   319,   376,   376,   319,   413,   319,
     138,    53,    53,    53,    53,    53,    53,    53,   149,    88,
    -229,  -229,    97,    -2,  -229,   -97,   -62,   -62,  -229,    99,
     120,   120,     1,     1,  -229,  -229,   165,   165,    35,    35,
    -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,   170,
     170,    43,    43,  -229,  -229,   319,   307,  -229,   -62,   101,
    -229,   -80,   -73,   -72,  -229,  -229,   -58,   -57,  -229,  -229,
    -229,  -229,  -229
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       6,     0,     3,     1,     0,     0,    71,    72,    73,    75,
      76,    78,    79,    81,    82,     0,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     0,   196,   117,   195,   118,    80,    74,    77,
       2,     7,     8,     9,    12,     0,     0,    13,     0,    24,
      47,    46,   256,   257,   258,     0,     0,     0,     0,     0,
       0,    52,     0,    23,   151,    49,    56,     0,   216,   109,
     110,   111,   112,     0,   113,    51,   114,   115,     0,   119,
     120,    47,    46,   123,   124,   125,   126,   127,   128,   129,
     121,   122,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   152,   153,   154,   248,   249,   242,   243,
     244,   245,   246,   247,   250,   251,     0,   156,   157,   158,
       0,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   182,   181,   183,   184,     0,    34,    33,
       0,     0,   185,   186,   187,   188,   189,   190,   191,   192,
     193,     0,   233,   234,   235,   237,   238,   240,   239,   241,
     232,   236,   197,   230,   198,   199,   200,   203,   204,   201,
     202,   205,   206,   207,   210,   211,   208,   209,   212,   213,
     214,     0,    45,    44,    43,     0,   217,    14,   218,   226,
     219,     0,     0,   228,   220,   224,   221,   223,     5,   222,
      10,    11,    31,    41,     0,     0,    48,    53,    54,     0,
       0,     0,     0,     0,   252,   253,   254,   255,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,   116,     0,     0,   194,     0,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    42,     0,     0,    55,     0,     0,     0,    65,    63,
      29,    30,    25,    26,    27,    28,    39,    40,    35,    36,
      37,    38,    69,    59,    61,   155,   215,   231,    22,    19,
      20,    15,    16,    17,    18,   227,   229,   225,     0,     0,
      58,     0,     0,     0,    66,    64,     0,     0,    70,    60,
      62,    67,    68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -229,  -229,  -229,  -229,  -229,  -229,  -139,  -147,  -146,  -229,
     602,   471,   414,   510,   150,  -229,   -10,  -229,  -229,   -94,
    -228,   -90,   172,  -177
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,   160,     2,   161,   162,   326,   181,   182,   327,
     183,   184,   194,   185,   186,   163,   336,   330,   334,   302,
     303,   246,   358,   187
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     250,   333,   352,   277,   337,   429,     3,   168,   329,   201,
     363,   364,   169,   278,   198,   168,   291,   170,   340,   341,
     169,   342,   343,   164,   165,   170,   166,   328,   344,   345,
     347,   348,   350,   351,   304,   305,   306,   346,   359,   360,
     361,   362,   363,   364,   369,   370,   373,   354,   355,   356,
     357,   168,   385,   386,   412,   335,   169,   321,   338,   374,
     372,   170,   399,   354,   355,   356,   357,   322,   375,   323,
     431,   376,   378,   277,   387,   365,   366,   367,   368,   369,
     370,   388,   389,   278,   396,   -34,   -34,   -34,   -34,   -34,
     -34,   359,   360,   361,   362,   363,   364,   168,   354,   355,
     356,   357,   169,   427,   352,   428,   435,   170,   437,   277,
     438,   -33,   -33,   -33,   -33,   -33,   -33,   439,   440,   278,
     365,   366,   367,   368,   369,   370,   353,   361,   362,   363,
     364,   343,   441,   442,   345,   351,   365,   366,   367,   368,
     369,   370,   339,   381,   382,   383,   384,   385,   386,   392,
     417,   202,   377,   331,     0,   279,   397,     0,   169,   171,
     172,   173,   174,   201,     0,     0,   168,   171,   172,   173,
     174,   169,   367,   368,   369,   370,   170,   383,   384,   385,
     386,     0,   379,   280,   342,   344,   380,   175,   430,   176,
     177,   178,   179,     0,   180,   175,   167,   193,   177,   178,
     179,     0,   180,   171,   172,   173,   174,     0,     0,   324,
       0,     0,   400,   401,   402,   403,   404,   405,   390,   406,
     407,   408,   409,   410,   411,   279,   172,   173,   174,     0,
       0,   175,     0,     0,   177,   178,   179,   325,   180,     0,
       0,   426,   419,   420,   421,   422,   423,   424,   425,   171,
     172,   173,   174,   280,     0,   391,     0,     0,   281,     0,
     180,   279,   172,   173,   174,   -34,     0,   282,   283,   284,
     285,   -34,     0,     0,     0,     0,   394,   175,   354,   355,
     356,   357,     0,     0,   349,   415,   416,     0,     0,   280,
       0,   -33,     0,     0,     0,     0,   349,   -33,     0,     0,
       0,   354,   355,   356,   357,   202,   371,     0,   354,   355,
     356,   357,   359,   360,   361,   362,   363,   364,   171,     0,
       0,     0,   395,   418,   381,   382,   383,   384,   385,   386,
       0,     0,     0,   332,   365,   366,   367,   368,   369,   370,
       0,     0,     4,     0,     5,     0,   175,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,     0,     0,     0,     0,
       0,   227,   228,   229,   230,   231,     0,     0,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   188,   189,   190,   191,   192,     0,   196,
     197,   393,     0,     0,     0,   398,   272,   273,   274,   275,
     276,   210,   211,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   413,   414,     0,   225,   226,     0,     0,
       0,     0,     0,     0,     0,   234,   235,   195,   320,     0,
       0,   199,   200,     0,     0,     0,     0,   432,   433,   434,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
       0,   270,   271,     0,   224,     0,     0,   195,   195,   195,
     195,   195,   232,   233,     0,   289,   290,   247,   248,   249,
     436,     0,   307,   308,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   318,   319,     0,     0,     0,     0,     0,
       0,     0,   195,   195,   195,   195,   195,     0,     0,     0,
       0,   286,   287,   288,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   309,   310,   311,   312,   313,   314,   315,
     316,   317,     0,     0,   195,   203,   204,   205,   206,   207,
     208,   209,     0,     0,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269
};

static const yytype_int16 yycheck[] =
{
      90,   148,   179,     4,   150,     7,     0,     4,   147,    14,
       9,    10,     9,    14,   186,     4,   186,    14,   165,   166,
       9,   168,   168,    15,    11,    14,    13,   156,   175,   175,
     177,   178,   179,   179,   128,   129,   130,   176,     5,     6,
       7,     8,     9,    10,     9,    10,   193,   160,   161,   162,
     163,     4,     9,    10,   167,    15,     9,     4,    14,   198,
     191,    14,     7,   160,   161,   162,   163,    14,   191,    16,
     167,   191,   191,     4,   191,     5,     6,     7,     8,     9,
      10,   191,   191,    14,   191,     5,     6,     7,     8,     9,
      10,     5,     6,     7,     8,     9,    10,     4,   160,   161,
     162,   163,     9,    15,   281,     8,     7,    14,     7,     4,
     190,     5,     6,     7,     8,     9,    10,   190,   190,    14,
       5,     6,     7,     8,     9,    10,     8,     7,     8,     9,
      10,   277,   190,   190,   280,   281,     5,     6,     7,     8,
       9,    10,   152,     5,     6,     7,     8,     9,    10,     8,
     378,   156,   291,     4,    -1,   156,     8,    -1,     9,   156,
     157,   158,   159,    14,    -1,    -1,     4,   156,   157,   158,
     159,     9,     7,     8,     9,    10,    14,     7,     8,     9,
      10,    -1,   321,   184,   331,   332,   325,   184,   190,   186,
     187,   188,   189,    -1,   191,   184,   183,   186,   187,   188,
     189,    -1,   191,   156,   157,   158,   159,    -1,    -1,   156,
      -1,    -1,   359,   360,   361,   362,   363,   364,   185,   365,
     366,   367,   368,   369,   370,   156,   157,   158,   159,    -1,
      -1,   184,    -1,    -1,   187,   188,   189,   184,   191,    -1,
      -1,   388,   381,   382,   383,   384,   385,   386,   387,   156,
     157,   158,   159,   184,    -1,   185,    -1,    -1,   189,    -1,
     191,   156,   157,   158,   159,   185,    -1,   117,   118,   119,
     120,   191,    -1,    -1,    -1,    -1,   190,   184,   160,   161,
     162,   163,    -1,    -1,   191,   375,   376,    -1,    -1,   184,
      -1,   185,    -1,    -1,    -1,    -1,   191,   191,    -1,    -1,
      -1,   160,   161,   162,   163,   156,   191,    -1,   160,   161,
     162,   163,     5,     6,     7,     8,     9,    10,   156,    -1,
      -1,    -1,   191,   185,     5,     6,     7,     8,     9,    10,
      -1,    -1,    -1,   184,     5,     6,     7,     8,     9,    10,
      -1,    -1,    12,    -1,    14,    -1,   184,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    80,    81,    -1,    -1,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    42,    43,    44,    45,    46,    -1,    48,
      49,   349,    -1,    -1,    -1,   353,   112,   113,   114,   115,
     116,    60,    61,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   371,   372,    -1,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    85,    47,   144,    -1,
      -1,    51,    52,    -1,    -1,    -1,    -1,   395,   396,   397,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      -1,   110,   111,    -1,    74,    -1,    -1,    77,    78,    79,
      80,    81,    82,    83,    -1,   124,   125,    87,    88,    89,
     428,    -1,   131,   132,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,    -1,    -1,    -1,
      -1,   121,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,    -1,   144,    53,    54,    55,    56,    57,
      58,    59,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   193,   195,     0,    12,    14,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     194,   196,   197,   207,    15,    11,    13,   183,     4,     9,
      14,   156,   157,   158,   159,   184,   186,   187,   188,   189,
     191,   199,   200,   202,   203,   205,   206,   215,   203,   203,
     203,   203,   203,   186,   204,   205,   203,   203,   186,   205,
     205,    14,   156,   202,   202,   202,   202,   202,   202,   202,
     203,   203,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   205,   203,   203,   204,   204,   204,
     204,   204,   205,   205,   203,   203,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   213,   205,   205,   205,
     213,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     203,   203,   204,   204,   204,   204,   204,     4,    14,   156,
     184,   189,   206,   206,   206,   206,   205,   205,   205,   203,
     203,   186,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   211,   212,   211,   211,   211,   203,   203,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   203,   203,
     204,     4,    14,    16,   156,   184,   198,   201,   156,   198,
     209,     4,   184,   199,   210,    15,   208,   200,    14,   208,
     199,   199,   199,   200,   199,   200,   198,   199,   199,   191,
     199,   200,   215,     8,   160,   161,   162,   163,   214,     5,
       6,     7,     8,     9,    10,     5,     6,     7,     8,     9,
      10,   191,   191,   199,   198,   191,   191,   198,   191,   198,
     198,     5,     6,     7,     8,     9,    10,   191,   191,   191,
     185,   185,     8,   214,   190,   191,   191,     8,   214,     7,
     199,   199,   199,   199,   199,   199,   200,   200,   200,   200,
     200,   200,   167,   214,   214,   213,   213,   212,   185,   198,
     198,   198,   198,   198,   198,   198,   199,    15,     8,     7,
     190,   167,   214,   214,   214,     7,   214,     7,   190,   190,
     190,   190,   190
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   192,   193,   194,   194,   194,   195,   195,   196,   196,
     196,   196,   196,   197,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   201,   201,   201,   202,   202,   203,   203,
     204,   204,   205,   205,   205,   205,   205,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   208,   208,   209,   209,   210,   210,
     211,   211,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   214,   214,   214,   214,   215,   215,   215
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     2,     0,     2,     1,     1,
       3,     3,     2,     2,     1,     3,     3,     3,     3,     3,
       3,     2,     3,     1,     1,     3,     3,     3,     3,     3,
       3,     2,     3,     1,     1,     3,     3,     3,     3,     3,
       3,     2,     3,     1,     1,     1,     1,     1,     2,     1,
       2,     1,     1,     2,     2,     3,     1,     2,     4,     3,
       5,     3,     5,     3,     4,     3,     4,     6,     6,     3,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     3,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     4,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     1,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     4,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 5: /* end: END ID  */
                { if (symbols[(yyvsp[0].symbol)].type != ST_LABEL) yyerror("undefined label"); symbols[(yyvsp[0].symbol)].refd++; start_addr = /*origin_addr +*/ symbols[(yyvsp[0].symbol)].value; LOG("start addr set to '%s' ($%04X)\n", symbols[(yyvsp[0].symbol)].name, start_addr);}
    break;

  case 7: /* lines: lines line  */
                        { yyerrok; }
    break;

  case 9: /* line: instruction  */
                        { fixup_pending_index = FP_NONE; }
    break;

  case 10: /* line: ID EQU word_expr  */
                        { if (symbols[(yyvsp[-2].symbol)].type != ST_UNDEF) yyerror("equate already defined"); symbols[(yyvsp[-2].symbol)].value = (yyvsp[0].ival); symbols[(yyvsp[-2].symbol)].type = ST_EQU; }
    break;

  case 11: /* line: ID SET word_expr  */
                        { symbols[(yyvsp[-2].symbol)].value = (yyvsp[0].ival); symbols[(yyvsp[-2].symbol)].type = ST_SET; }
    break;

  case 12: /* line: INCLUDE STRING  */
                        { push_file_stack(symbols[(yyvsp[0].symbol)].name); symbols[(yyvsp[0].symbol)].refd++;}
    break;

  case 13: /* label: ID ':'  */
                { if (symbols[(yyvsp[-1].symbol)].type != ST_UNDEF) yyerror("label already defined"); symbols[(yyvsp[-1].symbol)].value = origin_addr + addr; symbols[(yyvsp[-1].symbol)].type = ST_LABEL; }
    break;

  case 15: /* byte_expr: byte_expr '+' byte_expr  */
                                { if ((yyvsp[-2].ival) == SA_UNDEF || (yyvsp[0].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[-2].ival) + (yyvsp[0].ival); }
    break;

  case 16: /* byte_expr: byte_expr '-' byte_expr  */
                                { if ((yyvsp[-2].ival) == SA_UNDEF || (yyvsp[0].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[-2].ival) - (yyvsp[0].ival); }
    break;

  case 17: /* byte_expr: byte_expr '*' byte_expr  */
                                { if ((yyvsp[-2].ival) == SA_UNDEF || (yyvsp[0].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[-2].ival) * (yyvsp[0].ival); }
    break;

  case 18: /* byte_expr: byte_expr '/' byte_expr  */
                                { if ((yyvsp[-2].ival) == SA_UNDEF || (yyvsp[0].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[-2].ival) / (yyvsp[0].ival); }
    break;

  case 19: /* byte_expr: byte_expr '&' byte_expr  */
                                { if ((yyvsp[-2].ival) == SA_UNDEF || (yyvsp[0].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[-2].ival) & (yyvsp[0].ival); }
    break;

  case 20: /* byte_expr: byte_expr '|' byte_expr  */
                                { if ((yyvsp[-2].ival) == SA_UNDEF || (yyvsp[0].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[-2].ival) | (yyvsp[0].ival); }
    break;

  case 21: /* byte_expr: '~' byte_expr  */
                                { if ((yyvsp[0].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = ~(yyvsp[0].ival);}
    break;

  case 22: /* byte_expr: '(' byte_expr ')'  */
                                { if ((yyvsp[-1].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[-1].ival); }
    break;

  case 24: /* word_expr: '*'  */
                                { (yyval.ival) = addr + origin_addr; }
    break;

  case 25: /* word_expr: word_expr '+' word_expr  */
                                { if ((yyvsp[-2].ival) == SA_UNDEF || (yyvsp[0].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[-2].ival) + (yyvsp[0].ival); }
    break;

  case 26: /* word_expr: word_expr '-' word_expr  */
                                { if ((yyvsp[-2].ival) == SA_UNDEF || (yyvsp[0].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[-2].ival) - (yyvsp[0].ival); }
    break;

  case 27: /* word_expr: word_expr '*' word_expr  */
                                { if ((yyvsp[-2].ival) == SA_UNDEF || (yyvsp[0].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[-2].ival) * (yyvsp[0].ival); }
    break;

  case 28: /* word_expr: word_expr '/' word_expr  */
                                { if ((yyvsp[-2].ival) == SA_UNDEF || (yyvsp[0].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[-2].ival) / (yyvsp[0].ival); }
    break;

  case 29: /* word_expr: word_expr '&' word_expr  */
                                { if ((yyvsp[-2].ival) == SA_UNDEF || (yyvsp[0].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[-2].ival) & (yyvsp[0].ival); }
    break;

  case 30: /* word_expr: word_expr '|' word_expr  */
                                { if ((yyvsp[-2].ival) == SA_UNDEF || (yyvsp[0].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[-2].ival) | (yyvsp[0].ival); }
    break;

  case 31: /* word_expr: '~' word_expr  */
                                { if ((yyvsp[0].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = ~(yyvsp[0].ival);}
    break;

  case 32: /* word_expr: '(' word_expr ')'  */
                                { if ((yyvsp[-1].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs");(yyval.ival) = (yyvsp[-1].ival); }
    break;

  case 34: /* const_expr: ID  */
                                    { if (symbols[(yyvsp[0].symbol)].type != ST_EQU && symbols[(yyvsp[0].symbol)].type != ST_SET) yyerror("non const in const expr"); (yyval.ival) = symbols[(yyvsp[0].symbol)].value; symbols[(yyvsp[0].symbol)].refd++;}
    break;

  case 35: /* const_expr: const_expr '+' const_expr  */
                                    { (yyval.ival) = (yyvsp[-2].ival) + (yyvsp[0].ival); }
    break;

  case 36: /* const_expr: const_expr '-' const_expr  */
                                    { (yyval.ival) = (yyvsp[-2].ival) - (yyvsp[0].ival); }
    break;

  case 37: /* const_expr: const_expr '*' const_expr  */
                                    { (yyval.ival) = (yyvsp[-2].ival) * (yyvsp[0].ival); }
    break;

  case 38: /* const_expr: const_expr '/' const_expr  */
                                    { (yyval.ival) = (yyvsp[-2].ival) / (yyvsp[0].ival); }
    break;

  case 39: /* const_expr: const_expr '&' const_expr  */
                                    { (yyval.ival) = (yyvsp[-2].ival) & (yyvsp[0].ival); }
    break;

  case 40: /* const_expr: const_expr '|' const_expr  */
                                    { (yyval.ival) = (yyvsp[-2].ival) | (yyvsp[0].ival); }
    break;

  case 41: /* const_expr: '~' const_expr  */
                                    { (yyval.ival) = ~(yyvsp[0].ival); }
    break;

  case 42: /* const_expr: '(' const_expr ')'  */
                                    { (yyval.ival) = (yyvsp[-1].ival); }
    break;

  case 43: /* imm8: NUMBER  */
                { if (HIBYTE((yyvsp[0].ival)) && ((yyvsp[0].ival) < -128 || (yyvsp[0].ival) > 127)) yyerror("byte value expected"); (yyval.ival) = LOBYTE((yyvsp[0].ival)); }
    break;

  case 45: /* imm8: ID  */
                { if (symbols[(yyvsp[0].symbol)].type == ST_UNDEF) { fixup_pending_index = add_fixup((yyvsp[0].symbol), addr + 1, FIXUP_IMM8); (yyval.ival) = SA_UNDEF; } else (yyval.ival) = symbols[(yyvsp[0].symbol)].value; symbols[(yyvsp[0].symbol)].refd++;}
    break;

  case 47: /* imm16: ID  */
                { if (symbols[(yyvsp[0].symbol)].type == ST_UNDEF) { fixup_pending_index = add_fixup((yyvsp[0].symbol), addr + 1, FIXUP_IMM16); (yyval.ival) = SA_UNDEF; } else (yyval.ival) = symbols[(yyvsp[0].symbol)].value; symbols[(yyvsp[0].symbol)].refd++;}
    break;

  case 48: /* op8: '#' byte_expr  */
                                        { emit_buf((yyvsp[0].ival)); (yyval.ival) = AM_IMM; }
    break;

  case 50: /* op16: '#' word_expr  */
                                        { emit_buf_word((yyvsp[0].ival)); (yyval.ival) = AM_IMM; }
    break;

  case 52: /* direct_indexed_extended: word_expr  */
                                        { if (SA_UNDEF != (yyvsp[0].ival) && direct_page_addr == HIBYTE((yyvsp[0].ival))) { emit_buf(LOBYTE((yyvsp[0].ival))); (yyval.ival) = AM_DIRECT; } else { emit_buf_word((yyvsp[0].ival)); (yyval.ival) = AM_EXTENDED; } }
    break;

  case 53: /* direct_indexed_extended: '>' word_expr  */
                                        { emit_buf_word((yyvsp[0].ival)); (yyval.ival) = AM_EXTENDED; }
    break;

  case 54: /* direct_indexed_extended: '<' word_expr  */
                                        { if (HIBYTE((yyvsp[0].ival)) == direct_page_addr) { emit_buf(LOBYTE((yyvsp[0].ival))); (yyval.ival) = AM_DIRECT; } else yyerror("Direct page mismatch"); }
    break;

  case 55: /* direct_indexed_extended: '[' word_expr ']'  */
                                        { emit_buf(0x9F); emit_buf_word((yyvsp[-1].ival)); adjust_fixup(FIXUP_IMM16, 2); (yyval.ival) = AM_INDEXED; }
    break;

  case 57: /* indexed: ',' index_register  */
                                            { emit_buf(0x84 | ((yyvsp[0].ival) << 5)); (yyval.ival) = AM_INDEXED; }
    break;

  case 58: /* indexed: '[' ',' index_register ']'  */
                                            { emit_buf(0x94 | ((yyvsp[-1].ival) << 5)); (yyval.ival) = AM_INDEXED; }
    break;

  case 59: /* indexed: const_expr ',' index_register  */
                                                { constant_offset_direct((yyvsp[-2].ival), (yyvsp[0].ival)); (yyval.ival) = AM_INDEXED; }
    break;

  case 60: /* indexed: '[' const_expr ',' index_register ']'  */
                                                { constant_offset_indirect((yyvsp[-3].ival), (yyvsp[-1].ival)); (yyval.ival) = AM_INDEXED; }
    break;

  case 61: /* indexed: accumulator ',' index_register  */
                                            { accumulator_offset_direct((yyvsp[-2].ival), (yyvsp[0].ival)); (yyval.ival) = AM_INDEXED; }
    break;

  case 62: /* indexed: '[' accumulator ',' index_register ']'  */
                                                { accumulator_offset_indirect((yyvsp[-3].ival), (yyvsp[-1].ival)); (yyval.ival) = AM_INDEXED; }
    break;

  case 63: /* indexed: ',' index_register '+'  */
                                            { emit_buf(0x80 | ((yyvsp[-1].ival) << 5)); (yyval.ival) = AM_INDEXED; }
    break;

  case 64: /* indexed: ',' index_register '+' '+'  */
                                            { emit_buf(0x81 | ((yyvsp[-2].ival) << 5)); (yyval.ival) = AM_INDEXED; }
    break;

  case 65: /* indexed: ',' '-' index_register  */
                                            { emit_buf(0x82 | ((yyvsp[0].ival) << 5)); (yyval.ival) = AM_INDEXED; }
    break;

  case 66: /* indexed: ',' '-' '-' index_register  */
                                            { emit_buf(0x83 | ((yyvsp[0].ival) << 5)); (yyval.ival) = AM_INDEXED; }
    break;

  case 67: /* indexed: '[' ',' '-' '-' index_register ']'  */
                                            { emit_buf(0x93 | ((yyvsp[-1].ival) << 5)); (yyval.ival) = AM_INDEXED; }
    break;

  case 68: /* indexed: '[' ',' index_register '+' '+' ']'  */
                                            { emit_buf(0x91 | ((yyvsp[-3].ival) << 5)); (yyval.ival) = AM_INDEXED; }
    break;

  case 69: /* indexed: const_expr ',' PCR  */
                                                { pcr_direct((yyvsp[-2].ival)); (yyval.ival) = AM_INDEXED; }
    break;

  case 70: /* indexed: '[' const_expr ',' PCR ']'  */
                                                { pcr_indirect((yyvsp[-3].ival)); (yyval.ival) = AM_INDEXED; }
    break;

  case 71: /* instruction: ABX  */
                    { emit(0x3A); }
    break;

  case 72: /* instruction: ASLA  */
                    { emit(0x48); }
    break;

  case 73: /* instruction: ASLB  */
                    { emit(0x58); }
    break;

  case 74: /* instruction: ASLD  */
                    { emit(0x58); emit(0x49); }
    break;

  case 75: /* instruction: ASRA  */
                    { emit(0x47); }
    break;

  case 76: /* instruction: ASRB  */
                    { emit(0x57); }
    break;

  case 77: /* instruction: ASRD  */
                    { emit(0x47); emit(0x56); }
    break;

  case 78: /* instruction: CLRA  */
                    { emit(0x4F); }
    break;

  case 79: /* instruction: CLRB  */
                    { emit(0x5F); }
    break;

  case 80: /* instruction: CLRD  */
                    { emit(0x4F); emit(0x5F); }
    break;

  case 81: /* instruction: COMA  */
                    { emit(0x43); }
    break;

  case 82: /* instruction: COMB  */
                    { emit(0x53); }
    break;

  case 83: /* instruction: DAA  */
                    { emit(0x19); }
    break;

  case 84: /* instruction: DECA  */
                    { emit(0x4A); }
    break;

  case 85: /* instruction: DECB  */
                    { emit(0x5A); }
    break;

  case 86: /* instruction: INCA  */
                    { emit(0x4C); }
    break;

  case 87: /* instruction: INCB  */
                    { emit(0x5C); }
    break;

  case 88: /* instruction: LSLA  */
                    { emit(0x48); }
    break;

  case 89: /* instruction: LSLB  */
                    { emit(0x58); }
    break;

  case 90: /* instruction: LSRA  */
                    { emit(0x44); }
    break;

  case 91: /* instruction: LSRB  */
                    { emit(0x54); }
    break;

  case 92: /* instruction: MUL  */
                    { emit(0x3D); }
    break;

  case 93: /* instruction: NEGA  */
                    { emit(0x40); }
    break;

  case 94: /* instruction: NEGB  */
                    { emit(0x50); }
    break;

  case 95: /* instruction: NOP  */
                    { emit(0x12); }
    break;

  case 96: /* instruction: ROLA  */
                    { emit(0x49); }
    break;

  case 97: /* instruction: ROLB  */
                    { emit(0x59); }
    break;

  case 98: /* instruction: RORA  */
                    { emit(0x46); }
    break;

  case 99: /* instruction: RORB  */
                    { emit(0x56); }
    break;

  case 100: /* instruction: RTI  */
                    { emit(0x3B); }
    break;

  case 101: /* instruction: RTS  */
                    { emit(0x39); }
    break;

  case 102: /* instruction: SEX  */
                    { emit(0x1D); }
    break;

  case 103: /* instruction: SWI  */
                    { emit(0x3F); }
    break;

  case 104: /* instruction: SWI2  */
                    { emit(0x10); emit(0x3F); }
    break;

  case 105: /* instruction: SWI3  */
                    { emit(0x11); emit(0x3F); }
    break;

  case 106: /* instruction: SYNC  */
                    { emit(0x13); }
    break;

  case 107: /* instruction: TSTA  */
                    { emit(0x4D); }
    break;

  case 108: /* instruction: TSTB  */
                    { emit(0x5D); }
    break;

  case 109: /* instruction: ADCA op8  */
                { emit(opcodes[OP_ADCA].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 110: /* instruction: ADCB op8  */
                { emit(opcodes[OP_ADCB].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 111: /* instruction: ADDA op8  */
                { emit(opcodes[OP_ADDA].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 112: /* instruction: ADDB op8  */
                { emit(opcodes[OP_ADDB].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 113: /* instruction: ADDD op16  */
                { emit(opcodes[OP_ADDD].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 114: /* instruction: ANDA op8  */
                { emit(opcodes[OP_ANDA].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 115: /* instruction: ANDB op8  */
                { emit(opcodes[OP_ANDB].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 116: /* instruction: ANDCC '#' byte_expr  */
                          { emit(0x1C); emit(LOBYTE((yyvsp[0].ival))); }
    break;

  case 117: /* instruction: CLRC  */
                { emit(0x1C); emit(0xFE); }
    break;

  case 118: /* instruction: CLRZ  */
                { emit(0x1C); emit(0xFB); }
    break;

  case 119: /* instruction: ASL direct_indexed_extended  */
                                    { emit(opcodes[OP_ASL].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 120: /* instruction: ASR direct_indexed_extended  */
                                    { emit(opcodes[OP_ASR].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 121: /* instruction: BITA op8  */
                { emit(opcodes[OP_BITA].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 122: /* instruction: BITB op8  */
                { emit(opcodes[OP_BITB].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 123: /* instruction: BCC imm16  */
                 { rel_branch(BR_SHORT, 0x24, (yyvsp[0].ival)); }
    break;

  case 124: /* instruction: BCS imm16  */
                 { rel_branch(BR_SHORT, 0x25, (yyvsp[0].ival)); }
    break;

  case 125: /* instruction: BEQ imm16  */
                 { rel_branch(BR_SHORT, 0x27, (yyvsp[0].ival)); }
    break;

  case 126: /* instruction: BGE imm16  */
                 { rel_branch(BR_SHORT, 0x2C, (yyvsp[0].ival)); }
    break;

  case 127: /* instruction: BGT imm16  */
                 { rel_branch(BR_SHORT, 0x2E, (yyvsp[0].ival)); }
    break;

  case 128: /* instruction: BHI imm16  */
                 { rel_branch(BR_SHORT, 0x22, (yyvsp[0].ival)); }
    break;

  case 129: /* instruction: BHS imm16  */
                 { rel_branch(BR_SHORT, 0x24, (yyvsp[0].ival)); }
    break;

  case 130: /* instruction: BLE imm16  */
                 { rel_branch(BR_SHORT, 0x2F, (yyvsp[0].ival)); }
    break;

  case 131: /* instruction: BLO imm16  */
                 { rel_branch(BR_SHORT, 0x25, (yyvsp[0].ival)); }
    break;

  case 132: /* instruction: BLS imm16  */
                 { rel_branch(BR_SHORT, 0x23, (yyvsp[0].ival)); }
    break;

  case 133: /* instruction: BLT imm16  */
                 { rel_branch(BR_SHORT, 0x2D, (yyvsp[0].ival)); }
    break;

  case 134: /* instruction: BMI imm16  */
                 { rel_branch(BR_SHORT, 0x2B, (yyvsp[0].ival)); }
    break;

  case 135: /* instruction: BNE imm16  */
                 { rel_branch(BR_SHORT, 0x26, (yyvsp[0].ival)); }
    break;

  case 136: /* instruction: BPL imm16  */
                 { rel_branch(BR_SHORT, 0x2A, (yyvsp[0].ival)); }
    break;

  case 137: /* instruction: BRA imm16  */
                 { rel_branch(BR_SHORT, 0x20, (yyvsp[0].ival)); }
    break;

  case 138: /* instruction: BRN imm16  */
                 { rel_branch(BR_SHORT, 0x21, (yyvsp[0].ival)); }
    break;

  case 139: /* instruction: BSR imm16  */
                 { rel_branch(BR_SHORT, 0x8D, (yyvsp[0].ival)); }
    break;

  case 140: /* instruction: BVC imm16  */
                 { rel_branch(BR_SHORT, 0x28, (yyvsp[0].ival)); }
    break;

  case 141: /* instruction: BVS imm16  */
                 { rel_branch(BR_SHORT, 0x29, (yyvsp[0].ival)); }
    break;

  case 142: /* instruction: CLR direct_indexed_extended  */
                                    { emit(opcodes[OP_CLR].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 143: /* instruction: CMPA op8  */
                { emit(opcodes[OP_CMPA].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 144: /* instruction: CMPB op8  */
                { emit(opcodes[OP_CMPB].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 145: /* instruction: CMPD op16  */
                { emit(0x10); emit(opcodes[OP_CMPD].ops[(yyvsp[0].ival)]); write_inb(); adjust_fixup(FIXUP_NOCHANGE, 1); }
    break;

  case 146: /* instruction: CMPS op16  */
                { emit(0x11); emit(opcodes[OP_CMPS].ops[(yyvsp[0].ival)]); write_inb(); adjust_fixup(FIXUP_NOCHANGE, 1); }
    break;

  case 147: /* instruction: CMPU op16  */
                { emit(0x11); emit(opcodes[OP_CMPD].ops[(yyvsp[0].ival)]); write_inb(); adjust_fixup(FIXUP_NOCHANGE, 1); }
    break;

  case 148: /* instruction: CMPX op16  */
                { emit(opcodes[OP_CMPS].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 149: /* instruction: CMPY op16  */
                { emit(0x10); emit(opcodes[OP_CMPS].ops[(yyvsp[0].ival)]); write_inb(); adjust_fixup(FIXUP_NOCHANGE, 1); }
    break;

  case 150: /* instruction: COM direct_indexed_extended  */
                                    { emit(opcodes[OP_COM].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 151: /* instruction: CWAI op8  */
                { emit(0x3C); write_inb(); }
    break;

  case 152: /* instruction: DEC direct_indexed_extended  */
                                    { emit(opcodes[OP_DEC].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 153: /* instruction: EORA op8  */
                { emit(opcodes[OP_EORA].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 154: /* instruction: EORB op8  */
                { emit(opcodes[OP_EORB].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 155: /* instruction: EXG register ',' register  */
                                { emit(0x1E); emit(((yyvsp[-2].ival) << 4) | (yyvsp[0].ival)); }
    break;

  case 156: /* instruction: INC direct_indexed_extended  */
                                    { emit(opcodes[OP_INC].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 157: /* instruction: JMP direct_indexed_extended  */
                                    { emit(opcodes[OP_JMP].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 158: /* instruction: JSR direct_indexed_extended  */
                                    { emit(opcodes[OP_JSR].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 159: /* instruction: LBCC imm16  */
                    { rel_branch(BR_LONG, 0x24, (yyvsp[0].ival)); }
    break;

  case 160: /* instruction: LBCS imm16  */
                    { rel_branch(BR_LONG, 0x25, (yyvsp[0].ival)); }
    break;

  case 161: /* instruction: LBEQ imm16  */
                    { rel_branch(BR_LONG, 0x27, (yyvsp[0].ival)); }
    break;

  case 162: /* instruction: LBGE imm16  */
                    { rel_branch(BR_LONG, 0x2C, (yyvsp[0].ival)); }
    break;

  case 163: /* instruction: LBGT imm16  */
                    { rel_branch(BR_LONG, 0x2E, (yyvsp[0].ival)); }
    break;

  case 164: /* instruction: LBHI imm16  */
                    { rel_branch(BR_LONG, 0x22, (yyvsp[0].ival)); }
    break;

  case 165: /* instruction: LBHS imm16  */
                    { rel_branch(BR_LONG, 0x24, (yyvsp[0].ival)); }
    break;

  case 166: /* instruction: LBLE imm16  */
                    { rel_branch(BR_LONG, 0x2F, (yyvsp[0].ival)); }
    break;

  case 167: /* instruction: LBLO imm16  */
                    { rel_branch(BR_LONG, 0x25, (yyvsp[0].ival)); }
    break;

  case 168: /* instruction: LBLS imm16  */
                    { rel_branch(BR_LONG, 0x23, (yyvsp[0].ival)); }
    break;

  case 169: /* instruction: LBLT imm16  */
                    { rel_branch(BR_LONG, 0x2D, (yyvsp[0].ival)); }
    break;

  case 170: /* instruction: LBMI imm16  */
                    { rel_branch(BR_LONG, 0x2B, (yyvsp[0].ival)); }
    break;

  case 171: /* instruction: LBNE imm16  */
                    { rel_branch(BR_LONG, 0x26, (yyvsp[0].ival)); }
    break;

  case 172: /* instruction: LBPL imm16  */
                    { rel_branch(BR_LONG, 0x2A, (yyvsp[0].ival)); }
    break;

  case 173: /* instruction: LBRA imm16  */
                    { rel_branch(BR_LONG_NOPREFIX, 0x16, (yyvsp[0].ival)); }
    break;

  case 174: /* instruction: LBRN imm16  */
                    { rel_branch(BR_LONG, 0x21, (yyvsp[0].ival)); }
    break;

  case 175: /* instruction: LBSR imm16  */
                    { rel_branch(BR_LONG_NOPREFIX, 0x17, (yyvsp[0].ival)); }
    break;

  case 176: /* instruction: LBVC imm16  */
                    { rel_branch(BR_LONG, 0x28, (yyvsp[0].ival)); }
    break;

  case 177: /* instruction: LBVS imm16  */
                    { rel_branch(BR_LONG, 0x29, (yyvsp[0].ival)); }
    break;

  case 178: /* instruction: LDA op8  */
                    { emit(opcodes[OP_LDA].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 179: /* instruction: LDB op8  */
                    { emit(opcodes[OP_LDB].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 180: /* instruction: LDD op16  */
                    { emit(opcodes[OP_LDD].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 181: /* instruction: LDU op16  */
                    { emit(opcodes[OP_LDU].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 182: /* instruction: LDS op16  */
                    { emit(0x10); emit(opcodes[OP_LDU].ops[(yyvsp[0].ival)]); write_inb(); adjust_fixup(FIXUP_NOCHANGE, 1);}
    break;

  case 183: /* instruction: LDX op16  */
                    { emit(opcodes[OP_LDX].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 184: /* instruction: LDY op16  */
                    { emit(0x10); emit(opcodes[OP_LDX].ops[(yyvsp[0].ival)]); write_inb(); adjust_fixup(FIXUP_NOCHANGE, 1); }
    break;

  case 185: /* instruction: LEAX indexed  */
                    { emit(opcodes[OP_LEAX].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 186: /* instruction: LEAY indexed  */
                    { emit(opcodes[OP_LEAY].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 187: /* instruction: LEAS indexed  */
                    { emit(opcodes[OP_LEAS].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 188: /* instruction: LEAU indexed  */
                    { emit(opcodes[OP_LEAU].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 189: /* instruction: LSL direct_indexed_extended  */
                                    { emit(opcodes[OP_LSL].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 190: /* instruction: LSR direct_indexed_extended  */
                                    { emit(opcodes[OP_LSR].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 191: /* instruction: NEG direct_indexed_extended  */
                                    { emit(opcodes[OP_NEG].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 192: /* instruction: ORA op8  */
                                    { emit(opcodes[OP_ORA].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 193: /* instruction: ORB op8  */
                                    { emit(opcodes[OP_ORB].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 194: /* instruction: ORCC '#' byte_expr  */
                                    { emit(0x1A); emit(LOBYTE((yyvsp[0].ival))); }
    break;

  case 195: /* instruction: SETZ  */
                                    { emit(0x1A); emit(4); }
    break;

  case 196: /* instruction: SETC  */
                                    { emit(0x1A); emit(1); }
    break;

  case 197: /* instruction: PSHS push_registers  */
                                    { emit(0x34); emit((yyvsp[0].ival)); }
    break;

  case 198: /* instruction: PSHU push_registers  */
                                    { emit(0x36); emit((yyvsp[0].ival)); }
    break;

  case 199: /* instruction: PULS push_registers  */
                                    { emit(0x35); emit((yyvsp[0].ival)); }
    break;

  case 200: /* instruction: PULU push_registers  */
                                    { emit(0x37); emit((yyvsp[0].ival)); }
    break;

  case 201: /* instruction: ROL direct_indexed_extended  */
                                    { emit(opcodes[OP_ROL].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 202: /* instruction: ROR direct_indexed_extended  */
                                    { emit(opcodes[OP_ROR].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 203: /* instruction: SBCA op8  */
                                    { emit(opcodes[OP_SBCA].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 204: /* instruction: SBCB op8  */
                                    { emit(opcodes[OP_SBCB].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 205: /* instruction: STA direct_indexed_extended  */
                                    { emit(opcodes[OP_STA].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 206: /* instruction: STB direct_indexed_extended  */
                                    { emit(opcodes[OP_STB].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 207: /* instruction: STD direct_indexed_extended  */
                                    { emit(opcodes[OP_STD].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 208: /* instruction: STS direct_indexed_extended  */
                                    { emit(0x10); emit(opcodes[OP_STS].ops[(yyvsp[0].ival)]); write_inb(); adjust_fixup(FIXUP_NOCHANGE, 1); }
    break;

  case 209: /* instruction: STU direct_indexed_extended  */
                                    { emit(opcodes[OP_STU].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 210: /* instruction: STX direct_indexed_extended  */
                                    { emit(opcodes[OP_STX].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 211: /* instruction: STY direct_indexed_extended  */
                                    { emit(0x10); emit(opcodes[OP_STY].ops[(yyvsp[0].ival)]); write_inb(); adjust_fixup(FIXUP_NOCHANGE, 1); }
    break;

  case 212: /* instruction: SUBA op8  */
                                    { emit(opcodes[OP_SUBA].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 213: /* instruction: SUBB op8  */
                                    { emit(opcodes[OP_SUBB].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 214: /* instruction: SUBD op16  */
                                    { emit(opcodes[OP_SUBD].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 215: /* instruction: TFR register ',' register  */
                                    { emit(0x1F); emit(((yyvsp[-2].ival) << 4) | (yyvsp[0].ival)); }
    break;

  case 216: /* instruction: TST op8  */
                                    { emit(opcodes[OP_TST].ops[(yyvsp[0].ival)]); write_inb(); }
    break;

  case 217: /* instruction: SETDP byte_expr  */
                        { direct_page_addr = (yyvsp[0].ival); LOG("DP set to $%02X\n", direct_page_addr); }
    break;

  case 218: /* instruction: ORG NUMBER  */
                        { if (origin_addr != 0) yyerror("origin already set"); start_addr = origin_addr = (yyvsp[0].ival); LOG("ORG set to $%04X\n", origin_addr); }
    break;

  case 220: /* instruction: FDB words  */
                        {  }
    break;

  case 222: /* instruction: FCZ strings  */
                        { emit(0); }
    break;

  case 223: /* instruction: RMB const_expr  */
                        { addr += (yyvsp[0].ival); }
    break;

  case 224: /* strings: STRING  */
                            { symbols[(yyval.symbol)].type = ST_STRING; emit_str(symbols[(yyval.symbol)].name); }
    break;

  case 225: /* strings: strings ',' STRING  */
                            { symbols[(yyvsp[0].symbol)].type = ST_STRING; emit_str(symbols[(yyvsp[0].symbol)].name); }
    break;

  case 226: /* bytes: byte_expr  */
                               { if ((yyval.ival) > 255) yyerror("byte value expected"); emit(LOBYTE((yyval.ival))); }
    break;

  case 227: /* bytes: bytes ',' byte_expr  */
                               { if ((yyvsp[0].ival) > 255) yyerror("byte value expected"); emit(LOBYTE((yyvsp[0].ival))); }
    break;

  case 228: /* words: word_expr  */
                             { adjust_fixup(FIXUP_NOCHANGE, -1); emit_word((yyval.ival)); }
    break;

  case 229: /* words: words ',' word_expr  */
                             { adjust_fixup(FIXUP_NOCHANGE, -1); emit_word((yyvsp[0].ival)); }
    break;

  case 231: /* push_registers: push_registers ',' push_register  */
                                        { (yyval.ival) = (yyvsp[-2].ival) | (yyvsp[0].ival); }
    break;

  case 232: /* push_register: CC  */
                    { (yyval.ival) = 1; }
    break;

  case 233: /* push_register: A  */
            { (yyval.ival) = 2; }
    break;

  case 234: /* push_register: B  */
            { (yyval.ival) = 4; }
    break;

  case 235: /* push_register: D  */
            { (yyval.ival) = 6; }
    break;

  case 236: /* push_register: DP  */
            { (yyval.ival) = 8; }
    break;

  case 237: /* push_register: X  */
            { (yyval.ival) = 16; }
    break;

  case 238: /* push_register: Y  */
            { (yyval.ival) = 32; }
    break;

  case 239: /* push_register: S  */
            { (yyval.ival) = 64; }
    break;

  case 240: /* push_register: U  */
            { (yyval.ival) = 64; }
    break;

  case 241: /* push_register: PC  */
            { (yyval.ival) = 128; }
    break;

  case 242: /* register: D  */
                { (yyval.ival) = 0;}
    break;

  case 243: /* register: X  */
                { (yyval.ival) = 1;}
    break;

  case 244: /* register: Y  */
                { (yyval.ival) = 2;}
    break;

  case 245: /* register: U  */
                { (yyval.ival) = 3;}
    break;

  case 246: /* register: S  */
                { (yyval.ival) = 4;}
    break;

  case 247: /* register: PC  */
                { (yyval.ival) = 5;}
    break;

  case 248: /* register: A  */
                { (yyval.ival) = 8;}
    break;

  case 249: /* register: B  */
                { (yyval.ival) = 9;}
    break;

  case 250: /* register: CC  */
                { (yyval.ival) = 10;}
    break;

  case 251: /* register: DP  */
                { (yyval.ival) = 11;}
    break;

  case 252: /* index_register: X  */
                    { (yyval.ival) = 0; }
    break;

  case 253: /* index_register: Y  */
                    { (yyval.ival) = 1; }
    break;

  case 254: /* index_register: U  */
                    { (yyval.ival) = 2; }
    break;

  case 255: /* index_register: S  */
                    { (yyval.ival) = 3; }
    break;

  case 256: /* accumulator: A  */
                { (yyval.ival) = 0; }
    break;

  case 257: /* accumulator: B  */
                { (yyval.ival) = 1; }
    break;

  case 258: /* accumulator: D  */
                { (yyval.ival) = 2; }
    break;



      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}



// define our keyword token table
Tokens tokens[] =
{
    {"ABX", ABX},
    {"ADCA", ADCA},
    {"ADCB", ADCB},
    {"ADDA", ADDA},
    {"ADDB", ADDB},
    {"ADDD", ADDD},
    {"ANDA", ANDA},
    {"ANDB", ANDB},
    {"ANDCC", ANDCC},
    {"ASL", ASL},
    {"ASR", ASR},
    {"BCC", BCC},
    {"BCS", BCS},
    {"BEQ", BEQ},
    {"BGE", BGE},
    {"BGT", BGT},
    {"BHI", BHI},
    {"BHS", BHS},
    {"BITA", BITA},
    {"BITB", BITB},
    {"BLE", BLE},
    {"BLO", BLO},
    {"BLS", BLS},
    {"BLT", BLT},
    {"BMI", BMI},
    {"BNE", BNE},
    {"BPL", BPL},
    {"BRA", BRA},
    {"BRN", BRN},
    {"BSR", BSR},
    {"BVC", BVC},
    {"BVS", BVS},
    {"CLR", CLR},
    {"CMPA", CMPA},
    {"CMPB", CMPB},
    {"CMPD", CMPD},
    {"CMPS", CMPS},
    {"CMPU", CMPU},
    {"CMPX", CMPX},
    {"CMPY", CMPY},
    {"COM", COM},
    {"DEC", DEC},
    {"EORA", EORA},
    {"EORB", EORB},
    {"EXG", EXG},
    {"INC", INC},
    {"JMP", JMP},
    {"JSR", JSR},
    {"LBCC", LBCC},
    {"LBCS", LBCS},
    {"LBEQ", LBEQ},
    {"LBGE", LBGE},
    {"LBGT", LBGT},
    {"LBHI", LBHI},
    {"LBHS", LBHS},
    {"LBLE", LBLE},
    {"LBLO", LBLO},
    {"LBLS", LBLS},
    {"LBLT", LBLT},
    {"LBMI", LBMI},
    {"LBNE", LBNE},
    {"LBPL", LBPL},
    {"LBRA", LBRA},
    {"LBRN", LBRN},
    {"LBSR", LBSR},
    {"LBVC", LBVC},
    {"LBVS", LBVS},
    {"LDA", LDA},
    {"LDB", LDB},
    {"LDD", LDD},
    {"LDU", LDU},
    {"LDS", LDS},
    {"LDX", LDX},
    {"LDY", LDY},
    {"LEAX", LEAX},
    {"LEAY", LEAY},
    {"LEAS", LEAS},
    {"LEAU", LEAU},
    {"LSL", LSL},
    {"LSR", LSR},
    {"NEG", NEG},
    {"ORA", ORA},
    {"ORB", ORB},
    {"ORCC", ORCC},
    {"PSHS", PSHS},
    {"PSHU", PSHU},
    {"PULS", PULS},
    {"PULU", PULU},
    {"ROL", ROL},
    {"ROR", ROR},
    {"SBCA", SBCA},
    {"SBCB", SBCB},
    {"STA", STA},
    {"STB", STB},
    {"STD", STD},
    {"STS", STS},
    {"STU", STU},
    {"STX", STX},
    {"STY", STY},
    {"SUBA", SUBA},
    {"SUBB", SUBB},
    {"SUBD", SUBD},

    {"TFR", TFR},

    {"ASLA", ASLA},
    {"ASLB", ASLB},
    {"ASLD", ASLD},
    {"ASRA", ASRA},
    {"ASRB", ASRB},
    {"ASRD", ASRD},
    {"CLRA", CLRA},
    {"CLRB", CLRB},
    {"CLRD", CLRD},
    {"COMA", COMA},
    {"COMB", COMB},
    {"CWAI", CWAI},
    {"DAA", DAA},
    {"DECA", DECA},
    {"DECB", DECB},
    {"INCA", INCA},
    {"INCB", INCB},
    {"LSLA", LSLA},
    {"LSLB", LSLB},
    {"LSRA", LSRA},
    {"LSRB", LSRB},
    {"MUL", MUL},
    {"NEGA", NEGA},
    {"NEGB", NEGB},
    {"NOP", NOP},
    {"ROLA", ROLA},
    {"ROLB", ROLB},
    {"RORA", RORA},
    {"RORB", RORB},
    {"RTI", RTI},
    {"RTS", RTS},
    {"SEX", SEX},
    {"SWI", SWI},
    {"SWI2", SWI2},
    {"SWI3", SWI3},
    {"SYNC", SYNC},
    {"TSTA", TSTA},
    {"TSTB", TSTB},
    {"TST", TST},

    // registers
    {"A", A},
    {"B", B},
    {"D", D},
    {"X", X},
    {"Y", Y},
    {"U", U},
    {"S", S},
    {"PC", PC},
    {"PCR", PCR},
    {"CC", CC},
    {"DP", DP},

    // instruction extensions
    {"SETC", SETC},
    {"CLRC", CLRC},
    {"SETZ", SETZ},
    {"CLRZ", CLRZ},

    // pseudo instructions
    {"BNZ", BNE},
    {"BZ", BEQ},
    {"ORG", ORG},
    {"SETDP", SETDP},
    {"FCB", FCB},
    {"FDB", FDB},
    {"FCC", FCC},
    {"RMB", RMB},
    {"EQU", EQU},
    {"END", END},
    {"SET", SET},
    {"FCZ", FCZ},
    {"INCLUDE", INCLUDE},

    { NULL, 0}
};

//-----------------------------------
// get options from the command line
//-----------------------------------
int getopt(int n, char *args[])
{
	int i;
    
	for (i = 1; args[i] && args[i][0] == '-'; i++)
	{
        // flag for enabling verbose logging
		if (args[i][1] == 'v')
			g_bDebug = TRUE;

        if (args[i][1] == 'c')
            g_bCompactFile = TRUE;

        if (args[i][1] == 'x')
            g_bHexFile = TRUE;
        
        // flag for parser debugging
        if (args[i][1] == 'd')
            yydebug = 1;

        // flag for outputing binary .rom file
        if (args[i][1] == 'b')
            g_bBinaryRom = TRUE;

        // flag for unreferenced symbols
        if (args[i][1] == 'u')
            g_bUnreferenced = TRUE;

        // flag for generating Verilog rom
        if (args[i][1] == 'r')
            g_bROM = TRUE;

        // flag for generating SystemVerilog rom
        if (args[i][1] == 's')
        {
            g_bROM      = TRUE;
            g_bSystemV  = TRUE;
            input_wire  = "logic";
            output_reg  = "logic";
            reg         = "logic";
            always_comb = "always_comb";
            always_ff   = "always_ff";
        }

        // flag for generating an async rom
        if (args[i][1] == 'a')
        {
            g_bROM      = TRUE;
            g_bSyncROM  = FALSE;
        }

        // flag for setting output file name
		if (args[i][1] == 'o')
		{
			g_szOutputFilename = args[i + 1];
			i++;
		}

        // flag for taking input from stdio
        if (args[i][1] == 'i')
            yyin = stdin;

        // flag for symbols
        if (args[i][1] == 't')
            g_bSymbols = TRUE;

        // flag for listing file
        if (args[i][1] == 'l')
            g_bListingFile = TRUE;
	}

	return i;
}

//------------------------
// add a fixup
//------------------------
int add_fixup(int symbol, int addr, FIXUP_TYPE type)
{
    if (fixup_count >= MAX_FIXUPS)
    {
        yyerror("fixup table overflow");
        return -1;
    }

    LOG("adding %s fixup for %s @ addr %d\n", fixup_names[type], symbols[symbol].name, addr);

    fixups[fixup_count].symbol      = symbol;
    fixups[fixup_count].addr        = addr;
    fixups[fixup_count].type        = type;
    fixups[fixup_count].filename    = strdup(CURRENT_FILE);
    fixups[fixup_count].lineno      = CURRENT_LINENO;

    fixup_count++;
    return fixup_count - 1;
}

//------------------------
// apply fixups
//------------------------
void apply_fixups()
{
    LOG("Address fixups %04d found.\n", fixup_count);
    int offset = 0;

    // process all the fixups
    for (int i = 0; i < fixup_count; i++)
    {
        // get next fixup
        Fixup_t f = fixups[i];

        LOG("fixing up %s reference to '%s' @ $%04X\n", fixup_names[f.type], symbols[fixups[i].symbol].name, fixups[i].addr);

        // check that the symbols was defined
        if (symbols[f.symbol].type == ST_UNDEF)
        {
            fprintf(stderr, "ERROR: undefined symbol '%s' in file %s, line %d\n", symbols[f.symbol].name, symbols[f.symbol].filename, symbols[f.symbol].lineno);
            err_count++;
            continue;
        }

        // handle the specific fixup type
        switch(f.type)
        {
        case FIXUP_IMM8:
            code[f.addr] = LOBYTE(symbols[f.symbol].value);
            break;

        case FIXUP_IMM16:
            code[f.addr] = HIBYTE(symbols[f.symbol].value);
            code[f.addr + 1] = LOBYTE(symbols[f.symbol].value);
            break;

        case FIXUP_REL8:
            offset = symbols[f.symbol].value - (f.addr + origin_addr) + 1 - 2;
            if (offset < -128 || offset > 127)
            {
                fprintf(stderr, "ERROR: rel branch BYTE OVERFLOW in file '%s' near line %d\n", f.filename, f.lineno);
                err_count++;
                continue;
            }

            code[f.addr] = to_int8(offset);
            
            break;

        case FIXUP_REL16:
            offset = symbols[f.symbol].value - (f.addr + origin_addr) + 1 - 3;
            if (offset < -32768 || offset > 32767)
            {
                fprintf(stderr, "ERROR: relative branch WORD OVERFLOW in file '%s' near line %d\n", f.filename, f.lineno);
                err_count++;
                continue;
            }

            code[f.addr] = HIBYTE(offset);
            code[f.addr + 1] = LOBYTE(offset);
            break;

        default:
            fprintf(stderr, "ERROR: unknown fixup type!\n");
            err_count++;
            break;
        }
    }
}

//------------------------
// lookup a symbol
//------------------------
int lookup_symbol(const char *name)
{
    for (int i = 0; i < symbol_count; i++)
    {
        if (!strcasecmp(name, symbols[i].name))
            return i;
    }

    // symbol not found!
    return -1;
}

//-----------------------------------------
// add a new symbols, return symbol number
//-----------------------------------------
int add_symbol(const char *name, int lineno)
{
    if (symbol_count >= MAX_SYMBOLS)
    {
        yyerror("symbol table overflow");
        return -1;
    }

    // error if symbol already exists
    if (lookup_symbol(name) > 0)
        return -1;

    symbols[symbol_count].name      = strdup(name);
    symbols[symbol_count].lineno    = CURRENT_LINENO;
    symbols[symbol_count].filename  = strdup(CURRENT_FILE);
    symbols[symbol_count].type      = ST_UNDEF;
    symbols[symbol_count].value     = -1;
    symbols[symbol_count].refd      = 0;

    symbol_count++;
    return symbol_count - 1;
}

//------------------------
// symbol comparison fn
//------------------------
int compare_fn(const void *a, const void *b)
{
    Symbol_t *s1 = (Symbol_t*)a;
    Symbol_t *s2 = (Symbol_t*)b;

    return strcasecmp(s1->name, s2->name);
}

//------------------------
// cleanup allocated memory
//------------------------
void cleanup_symbols()
{
    for (int i = 0; i < symbol_count; i++)
    {
        free((void*)symbols[i].name);
        free((void*)symbols[i].filename);
    }
}

//------------------------
// print out symbols
//------------------------
void dump_symbols()
{
    // alpha sort symbols
    qsort(symbols, symbol_count, sizeof(Symbol_t), compare_fn);

    puts("\nSymbol table");
    for (int i = 0; i < symbol_count; i++)
    {
        if (symbols[i].type == ST_LABEL)
            printf("%10s\t%04X\n", symbols[i].name, symbols[i].value);
    }
}

//-------------------------------
// print out unreferenced symbols
//-------------------------------
void dump_unrefd_symbols()
{
    // alpha sort symbols
    // qsort(symbols, symbol_count, sizeof(Symbol_t), compare_fn);

    puts("\nUnferenced Symbols");
    for (int i = 0; i < symbol_count; i++)
    {
        if (symbols[i].refd == 0 && symbols[i].type == ST_LABEL)
            printf("%10s\t%04X\n", symbols[i].name, symbols[i].value);
    }
}

//------------------------
// discard input to EOL
//------------------------
void skipToEOL(void)
{
	int c;

	// skip to EOL
	do {
		c = getch();
	} while (c != '\n' && c != EOF);

	// put last character back
	ungetch(c);
}

//----------------------------------
// Conditionally return token value
//----------------------------------
int follow(int expect, int ifyes, int ifno)
{
	int chr;

	chr = getch();
	if (chr == expect)
		return ifyes;

	ungetch(chr);
	return ifno;
}

//------------------------
// match a number token
//------------------------
int getNumber()
{
	int c;
	char buf[BUF_SIZE];
	char *bufptr = buf;
	int base = 10;

	// look for hex numbers
 	c = getch();

    if (c == '-' || c == '+')
    {
		*bufptr++ = c;
        c = getch();
    }

	if (c == '$' || (c == '0' && (follow('X', 1, 0) || follow('x', 1, 0))))
		base = 16;
	else
		ungetch(c);

	if (base == 16)
	{
		while (isxdigit(c = getch()))
			*bufptr++ = c;
	}
	else
	{
		while (isdigit((c = getch())) || c == '.')
			*bufptr++ = c;
	}
	
	// need to put back the last character
	ungetch(c);

	// make sure string is asciiz
	*bufptr = '\0';

    yylval.ival = strtol(buf, NULL, base);
    return NUMBER;
}

//-------------------------------
// translate backslash characters
//-------------------------------
int backslash(int c)
{
	static char translation_tab[] = "b\bf\fn\nr\rt\t";

	if (c != '\\')
		return c;

	c = getch();
	if (islower(c) && strchr(translation_tab, c))
		return strchr(translation_tab, c)[1];

	return c;
}

//------------------------
// match a string literal
//------------------------
int getString(int delim)
{
    int c;
    char buf[BUF_SIZE], *cptr = buf;

    c = getch();

    while (c != delim && cptr < &buf[sizeof(buf)])
    {
        if (c == '\n' || c == EOF)
            yyerror("missing end quote");

        *cptr++ = backslash(c);
        c = getch();
    }
    
    *cptr = 0;

    // lookup symbol and return if exists
    int sym_num = lookup_symbol(buf);
    if (sym_num != -1)
    {
        yylval.symbol = sym_num;
        LOG("Existing symbol: '%s' (index = %d)\n", buf, sym_num);
        return STRING;
    }

    sym_num = add_symbol(buf, lineno);

    yylval.symbol = sym_num;
    LOG("New symbol: '%s' (index = %d)\n", buf, sym_num);

    return STRING;
}

//------------------------
// see if we match a token
//------------------------
int isToken(const char *s)
{
    Tokens *pTokens = tokens;

    for (; pTokens->lexeme != NULL; pTokens++)
    {
        if (!strcasecmp(s, pTokens->lexeme))
            return pTokens->token;
    }

    return FALSE;
}

//------------------------
// lexical analyzer
//------------------------
int yylex()
{
    int c;

yylex01:
    // skip leading whitespace
    while ((c = getch()) == ' ' || c == '\t');

    // see if input is empty
    if (c == EOF)
    {
        if (file_stack_ptr > 1)
        {
            pop_file_stack();
            goto yylex01;
        }

        return DONE;
    }

    // look for asm style comments
    if (/*c == '*' || */ c == ';')
    {
        skipToEOL();
        goto yylex01;
    }

    // look for char literals
    if (c == '\'')
    {
        c = getch();
        if (follow('\'', 1, 0))
        {
            yylval.ival = backslash(c);
            return CHAR;
        }

        ungetch(c);
        return getString('\'');
    }

    // look for string literals
    if (c == '"')
    {
        return getString('"');
    }

	// look for a number value
	if (isdigit(c) || c == '-' || c == '+' || c == '$')
	{
        if (c == '-' || c == '+')
        {
            int n = getch();
            ungetch(n);

            if (n != '$' && !isdigit(n))
                return c;
        }

		ungetch(c);
		return getNumber();
	}

    // look for start of a token
    if (isalpha(c)) 
    {
        char buf[BUF_SIZE], *p = buf;

        do {
            *p++ = c;
        } while ((c=getch()) != EOF && (c == '_' || isalnum(c)));
        
        // put back the last character!
        ungetch(c);

        // be sure to null terminate the string
        *p = 0;

        int token = isToken(buf);
        if (token)
        {
            return token;
        }
        
        // lookup symbol and return if exists
        int sym_num = lookup_symbol(buf);
        if (sym_num != -1)
        {
            yylval.symbol = sym_num;
            LOG("Existing symbol: '%s' (index = %d)\n", buf, sym_num);
            return ID;
        }

        sym_num = add_symbol(buf, lineno);

        yylval.symbol = sym_num;
        LOG("New symbol: '%s' (index = %d)\n", buf, sym_num);
    
        return ID;
    }

    // track line numbers
    if (c == '\n')
    {
        save_listing_entry();
        lineno++;
        CURRENT_LINENO++;
        goto yylex01;
    }

    // return single character tokens
    return c;
}

//------------------------
// write out code ascii
//------------------------
void write_file()
{
    for (int i = 0; i < addr; i++)
        fprintf(fout, "%02X\n", code[i]);
}

//-------------------------
// write compact code ascii
//-------------------------
void write_compact_file()
{
    for (int i = 0; i < addr; i++)
    {
        fprintf(fout, "%02X", code[i]);
        if (i != 0 && ((i+1) % 16) == 0)
            fputc('\n', fout);
    }
}

//------------------------
// write Intel hex file
//------------------------
void write_hex_file()
{
    int rows = addr /16;
    int rem = addr % 16;
    uint8_t crc_sum;
    int hex_addr;

    // write out all the full rows
    for (int row = 0; row < rows; row++)
    {
        crc_sum = 16;
        hex_addr = row * 16 + origin_addr;
        crc_sum += HIBYTE(hex_addr);
        crc_sum += LOBYTE(hex_addr);

        fprintf(fout, ":10%04X00", hex_addr);
        for (int i = 0; i < 16; i++)
        {
            fprintf(fout, "%02X", code[row * 16 + i]);
            crc_sum += code[row * 16 + i];
        }

        fprintf(fout, "%02X\n", (uint8_t)((~crc_sum) + 1));
    }

    crc_sum = rem;
    hex_addr = rows * 16 + origin_addr;
    crc_sum += HIBYTE(hex_addr);
    crc_sum += LOBYTE(hex_addr);
    fprintf(fout, ":%02X%04X00", rem, hex_addr);

    // write out the last partial row
    for (int i = 0; i < rem; i++)
    {
        fprintf(fout, "%02X", code[rows * 16 + i]);
        crc_sum += code[rows * 16 + i];
    }

    fprintf(fout, "%02X\n", (uint8_t)((~crc_sum) + 1));

    // write out end of file record
    fprintf(fout, ":00000001FF\n");
}

//-------------------------
// write out DECB .bin file
//-------------------------
void write_bin_file()
{
    BinFileHeader pre;
    BinFileTail post;

    pre.zeros = 0;
    pre.length = htons(addr);
    pre.start = htons(origin_addr);

    post.ones = 255;
    post.zeros = 0;
    post.exec = htons(start_addr);

    // write out the header
    if (fwrite(&pre, sizeof(pre), 1, fout) != 1)
    {
        fprintf(stderr, "ERROR: failed to write binary header\n");
        return;
    }

    // write out the code bytes
    if (fwrite(&code, addr, 1, fout) != 1)
    {
        fprintf(stderr, "ERROR: failed to write binary code data\n");
        return;
    }

    // write out the tail
    if (fwrite(&post, sizeof(post), 1, fout) != 1)
    {
        fprintf(stderr, "ERROR: failed to write binary trailer\n");
        return;
    }
}

//--------------------------------
// write out listing file (.LST)
//--------------------------------
void write_listing_file(const char *input_filename)
{
    // Generate listing filename from input filename
    char listing_filename[512];
    const char *dot = strrchr(input_filename, '.');
    
    if (dot)
    {
        int len = dot - input_filename;
        strncpy(listing_filename, input_filename, len);
        listing_filename[len] = '\0';
    }
    else
    {
        strcpy(listing_filename, input_filename);
    }
    strcat(listing_filename, ".lst");
    
    FILE *lst = fopen(listing_filename, "w");
    if (!lst)
    {
        fprintf(stderr, "ERROR: failed to open listing file '%s'\n", listing_filename);
        return;
    }
    
    // Write header
    fprintf(lst, "%s v%s - MC6809 Cross-Assembler\n", APP_NAME, APP_VER);
    fprintf(lst, "Listing file for: %s\n\n", input_filename);
    fprintf(lst, "Line Addr Code                             Source\n");
    fprintf(lst, "---- ---- --------------------------------- -------\n");
    
    // Write listing entries
    for (int i = 0; i < listing_count; i++)
    {
        Listing_t *entry = &listing[i];
        
        // Format: Line number (4 digits), Address (4 hex digits)
        fprintf(lst, "%04d %04X ", entry->lineno, entry->addr);
        
        // Print code bytes (up to 8 per line for readability)
        int bytes_to_show = entry->code_len < 8 ? entry->code_len : 8;
        for (int j = 0; j < bytes_to_show; j++)
        {
            fprintf(lst, "%02X ", entry->code_bytes[j]);
        }
        
        // Pad to align source column (8 bytes * 3 chars per byte = 24 chars)
        for (int j = bytes_to_show; j < 8; j++)
        {
            fprintf(lst, "   ");
        }
        
        // Print source line
        fprintf(lst, " %s\n", entry->source);
        
        // If more than 8 bytes, print continuation lines
        if (entry->code_len > 8)
        {
            for (int j = 8; j < entry->code_len; j += 8)
            {
                fprintf(lst, "     %04X ", entry->addr + j);
                
                int remaining = entry->code_len - j;
                bytes_to_show = remaining < 8 ? remaining : 8;
                
                for (int k = 0; k < bytes_to_show; k++)
                {
                    fprintf(lst, "%02X ", entry->code_bytes[j + k]);
                }
                fprintf(lst, "\n");
            }
        }
    }
    
    // Write footer with summary
    fprintf(lst, "\n");
    fprintf(lst, "---- ---- --------------------------------- -------\n");
    fprintf(lst, "Assembly complete: %d bytes, %d lines\n", addr, listing_count);
    fprintf(lst, "Errors: %d, Warnings: %d\n", err_count, warn_count);
    
    fclose(lst);
    
    printf("Listing file written to '%s'\n", listing_filename);
}

//------------------------
// usage banner
//------------------------
void usage()
{
    printf("%s v%s - an MC6809 cross-assembler by Mark Seminatore (c) 2024\n", APP_NAME, APP_VER);
	printf("\nusage: %s [options] filename\n", APP_NAME);
    puts("-a\tgenerate asynchronous Verilog rom");
    puts("-b\toutput .bin file");
//    puts("-d\tdebug parsing");
    puts("-i\tget input from stdin");
    puts("-l\tgenerate listing file");
	puts("-o file\tset output filename");
    puts("-r\tgenerate Verilog rom file");
    puts("-s\tuse System Verilog");
    puts("-t\tdump symbol table");
    puts("-u\tdump unreferenced symbols");
	puts("-v\tverbose output");
    puts("-x\tgenerate Intel hex file\n");
	exit(0);
}

//----------------------------
// generate template prologue
//----------------------------
void prologue(const char *filename, FILE *f, int addr_bits, int data_bits) 
{
    fprintf(f, "`timescale 1ns / 1ps\n\n");
    fprintf(f, "//////////////////////////////////////////////////////////////////\n");
    fprintf(f, "// Verilog ROM file auto-generated from %s\n", filename);
    fprintf(f, "//\n");
    fprintf(f, "// Using as09, see https://github.com/mseminatore/as09\n");
    fprintf(f, "//////////////////////////////////////////////////////////////////\n");
    fprintf(f, "module rom\n");
    fprintf(f, "(\n");

    if (g_bSyncROM)
        fprintf(f, "\t%s clk,\n", input_wire);

    fprintf(f, "\t%s [%d : 0] addr,\n"
        "\t%s [%d : 0] data\n"
        ");\n\n",
        input_wire,
        addr_bits - 1,
        output_reg,
        data_bits - 1
    );

    if (g_bSyncROM)
        fprintf(f, "\t// internal address register\n"
            "\t%s [%d : 0] addr_reg;\n\n"
            "\t//--------------------\n"
            "\t// Sequential logic\n"
            "\t//--------------------\n"
            "\t%s\n"
            "\t\taddr_reg <= addr;\n\n",
            reg,
            addr_bits - 1,
            always_ff
        );

    fprintf(f, "\t//--------------------\n"
        "\t// Combinational logic\n"
        "\t//--------------------\n"
        "\t%s\n",
        always_comb
    );

    if (g_bSyncROM)
        fprintf(f, "\t\tcase (addr_reg)\n");
    else
        fprintf(f, "\t\tcase (addr)\n");
}

//-------------------------
// generate template epilog
//-------------------------
void epilog(FILE *f) 
{
    fputs("\t\tendcase\n", f);
    fputs("endmodule\n", f);
}

//------------------------
// generate ROM data
//------------------------
void romgen(const char *filename, FILE *fout, int addr_bits, int data_bits)
{
    int num;

    prologue(filename, fout, addr_bits, data_bits);

    // loop over the code and output Verilog
    for (int i = 0; i < addr; i++)
    {
        num = code[i];
        fprintf(fout, "\t\t\t%d'd%d: data = %d'h%X;\t// decimal: %d\n", addr_bits, i, data_bits, num, num);
    }
    
    fprintf(fout, "\t\t\tdefault: data = %d'd0;\n", data_bits);

    epilog(fout);
}

//------------------------
// main entry point
//------------------------
int main(int argc, char *argv[])
{
    char infile[BUF_SIZE] = "stdin";

    // show usage if no arguments given
    if (argc == 1)
		usage();

    printf("%s v%s - an MC6809 cross-assembler by Mark Seminatore (c) 2024\n", APP_NAME, APP_VER);

	int iFirstArg = getopt(argc, argv);

    if (yyin != stdin)
    {
        push_file_stack(argv[iFirstArg]);
        snprintf(infile, sizeof(infile) - 1, "%s", argv[iFirstArg]);
    }

    fout = fopen(g_szOutputFilename, "wb");
    if (!fout)
    {
        fprintf(stderr, "ERROR: cannot open output file '%s' for writing\n", g_szOutputFilename);
        return 1;
    }

    // parse the input file
    yyparse();

    // fixup any forward references
    apply_fixups();

    // output hex code or rom file
    if (0 == err_count)
    {
        if (g_bROM)
            romgen(infile, fout, ADDRESS_BITS, INSTRUCTION_BITS);
        else if (g_bBinaryRom)
            write_bin_file();
        else if (g_bCompactFile)
            write_compact_file();
        else if (g_bHexFile)
            write_hex_file();
        else
            write_file();

        printf("%s assembled %d bytes, %d total lines of code to '%s'\n\n", APP_NAME, addr, lineno, g_szOutputFilename);
    }

    fclose(fout);

    // report any warnings/errors
    if (warn_count || err_count)
        printf("\n%04d errors, %04d warnings found!\n\n", err_count, warn_count);

    // dump the symbol table if requested
    if (g_bSymbols)
        dump_symbols();

    if (g_bUnreferenced)
        dump_unrefd_symbols();

    // write listing file if requested
    if (g_bListingFile && 0 == err_count)
        write_listing_file(infile);

    // cleanup allocated memory
    cleanup_symbols();

    // return err count for make/test purposes
    return err_count;
}
