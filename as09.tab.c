/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     EQU = 258,
     INCLUDE = 259,
     SET = 260,
     ID = 261,
     STRING = 262,
     CHAR = 263,
     ABX = 264,
     ASLA = 265,
     ASLB = 266,
     ASRA = 267,
     ASRB = 268,
     CLRA = 269,
     CLRB = 270,
     COMA = 271,
     COMB = 272,
     CWAI = 273,
     DAA = 274,
     DECA = 275,
     DECB = 276,
     INCA = 277,
     INCB = 278,
     LSLA = 279,
     LSLB = 280,
     LSRA = 281,
     LSRB = 282,
     MUL = 283,
     NEGA = 284,
     NEGB = 285,
     NOP = 286,
     ROLA = 287,
     ROLB = 288,
     RORA = 289,
     RORB = 290,
     RTI = 291,
     RTS = 292,
     SEX = 293,
     SWI = 294,
     SWI2 = 295,
     SWI3 = 296,
     SYNC = 297,
     TSTA = 298,
     TSTB = 299,
     TST = 300,
     ADCA = 301,
     ADCB = 302,
     ADDA = 303,
     ADDB = 304,
     ADDD = 305,
     ANDA = 306,
     ANDB = 307,
     ANDCC = 308,
     ASL = 309,
     ASR = 310,
     BCC = 311,
     BCS = 312,
     BEQ = 313,
     BGE = 314,
     BGT = 315,
     BHI = 316,
     BHS = 317,
     BITA = 318,
     BITB = 319,
     BLE = 320,
     BLO = 321,
     BLS = 322,
     BLT = 323,
     BMI = 324,
     BNE = 325,
     BPL = 326,
     BRA = 327,
     BRN = 328,
     BSR = 329,
     BVC = 330,
     BVS = 331,
     CLR = 332,
     CMPA = 333,
     CMPB = 334,
     CMPD = 335,
     CMPS = 336,
     CMPU = 337,
     CMPX = 338,
     CMPY = 339,
     COM = 340,
     DEC = 341,
     EORA = 342,
     EORB = 343,
     EXG = 344,
     INC = 345,
     JMP = 346,
     JSR = 347,
     TFR = 348,
     LBCC = 349,
     LBCS = 350,
     LBEQ = 351,
     LBGE = 352,
     LBGT = 353,
     LBHI = 354,
     LBHS = 355,
     LBLE = 356,
     LBLO = 357,
     LBLS = 358,
     LBLT = 359,
     LBMI = 360,
     LBNE = 361,
     LBPL = 362,
     LBRA = 363,
     LBRN = 364,
     LBSR = 365,
     LBVC = 366,
     LBVS = 367,
     LDA = 368,
     LDB = 369,
     LDD = 370,
     LDS = 371,
     LDU = 372,
     LDX = 373,
     LDY = 374,
     LEAX = 375,
     LEAY = 376,
     LEAS = 377,
     LEAU = 378,
     LSL = 379,
     LSR = 380,
     NEG = 381,
     ORA = 382,
     ORB = 383,
     ORCC = 384,
     PSHS = 385,
     PSHU = 386,
     PULS = 387,
     PULU = 388,
     SBCA = 389,
     SBCB = 390,
     ROL = 391,
     ROR = 392,
     STA = 393,
     STB = 394,
     STD = 395,
     STX = 396,
     STY = 397,
     STS = 398,
     STU = 399,
     SUBA = 400,
     SUBB = 401,
     SUBD = 402,
     NUMBER = 403,
     A = 404,
     B = 405,
     D = 406,
     X = 407,
     Y = 408,
     U = 409,
     S = 410,
     PC = 411,
     CC = 412,
     DP = 413,
     PCR = 414,
     SETDP = 415,
     ORG = 416,
     FCB = 417,
     FDB = 418,
     FCC = 419,
     RMB = 420,
     END = 421,
     FCZ = 422,
     SETC = 423,
     CLRC = 424,
     SETZ = 425,
     CLRZ = 426
   };
#endif
/* Tokens.  */
#define EQU 258
#define INCLUDE 259
#define SET 260
#define ID 261
#define STRING 262
#define CHAR 263
#define ABX 264
#define ASLA 265
#define ASLB 266
#define ASRA 267
#define ASRB 268
#define CLRA 269
#define CLRB 270
#define COMA 271
#define COMB 272
#define CWAI 273
#define DAA 274
#define DECA 275
#define DECB 276
#define INCA 277
#define INCB 278
#define LSLA 279
#define LSLB 280
#define LSRA 281
#define LSRB 282
#define MUL 283
#define NEGA 284
#define NEGB 285
#define NOP 286
#define ROLA 287
#define ROLB 288
#define RORA 289
#define RORB 290
#define RTI 291
#define RTS 292
#define SEX 293
#define SWI 294
#define SWI2 295
#define SWI3 296
#define SYNC 297
#define TSTA 298
#define TSTB 299
#define TST 300
#define ADCA 301
#define ADCB 302
#define ADDA 303
#define ADDB 304
#define ADDD 305
#define ANDA 306
#define ANDB 307
#define ANDCC 308
#define ASL 309
#define ASR 310
#define BCC 311
#define BCS 312
#define BEQ 313
#define BGE 314
#define BGT 315
#define BHI 316
#define BHS 317
#define BITA 318
#define BITB 319
#define BLE 320
#define BLO 321
#define BLS 322
#define BLT 323
#define BMI 324
#define BNE 325
#define BPL 326
#define BRA 327
#define BRN 328
#define BSR 329
#define BVC 330
#define BVS 331
#define CLR 332
#define CMPA 333
#define CMPB 334
#define CMPD 335
#define CMPS 336
#define CMPU 337
#define CMPX 338
#define CMPY 339
#define COM 340
#define DEC 341
#define EORA 342
#define EORB 343
#define EXG 344
#define INC 345
#define JMP 346
#define JSR 347
#define TFR 348
#define LBCC 349
#define LBCS 350
#define LBEQ 351
#define LBGE 352
#define LBGT 353
#define LBHI 354
#define LBHS 355
#define LBLE 356
#define LBLO 357
#define LBLS 358
#define LBLT 359
#define LBMI 360
#define LBNE 361
#define LBPL 362
#define LBRA 363
#define LBRN 364
#define LBSR 365
#define LBVC 366
#define LBVS 367
#define LDA 368
#define LDB 369
#define LDD 370
#define LDS 371
#define LDU 372
#define LDX 373
#define LDY 374
#define LEAX 375
#define LEAY 376
#define LEAS 377
#define LEAU 378
#define LSL 379
#define LSR 380
#define NEG 381
#define ORA 382
#define ORB 383
#define ORCC 384
#define PSHS 385
#define PSHU 386
#define PULS 387
#define PULU 388
#define SBCA 389
#define SBCB 390
#define ROL 391
#define ROR 392
#define STA 393
#define STB 394
#define STD 395
#define STX 396
#define STY 397
#define STS 398
#define STU 399
#define SUBA 400
#define SUBB 401
#define SUBD 402
#define NUMBER 403
#define A 404
#define B 405
#define D 406
#define X 407
#define Y 408
#define U 409
#define S 410
#define PC 411
#define CC 412
#define DP 413
#define PCR 414
#define SETDP 415
#define ORG 416
#define FCB 417
#define FDB 418
#define FCC 419
#define RMB 420
#define END 421
#define FCZ 422
#define SETC 423
#define CLRC 424
#define SETZ 425
#define CLRZ 426




/* Copy the first part of user declarations.  */


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
	vsprintf(buf, fmt, valist);
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
    return fgetc(yyin);
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
    inst_buf[inst_ptr++] = v;
    assert(inst_ptr < INB_SIZE);
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
        assert(fixup_pending_index == FP_NONE);
        emit_buf(0x84 | (index_reg << 5));
    }
    else if (offset >= -16 && offset <= 15)
    {
        // compute 5-bit signed value
        char byte_offset = offset & 0xF;
        if (offset < 0)
            byte_offset |= 0x10;

        assert(fixup_pending_index == FP_NONE);
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
        assert(fixup_pending_index == FP_NONE);
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



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE

{
    int ival;
    int symbol;
    char *lexeme;
}
/* Line 193 of yacc.c.  */

	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */


#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   677

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  188
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  254
/* YYNRULES -- Number of states.  */
#define YYNSTATES  436

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   426

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     2,   182,     2,     2,     5,     2,
     180,   181,     9,     7,   187,     8,     2,    10,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     184,     2,   183,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   185,     2,   186,     2,     2,     2,     2,     2,     2,
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
     173,   174,   175,   176,   177,   178,   179
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,     9,    12,    13,    16,    18,
      20,    24,    28,    31,    33,    35,    39,    43,    47,    51,
      55,    59,    62,    66,    68,    70,    74,    78,    82,    86,
      90,    94,    97,   101,   103,   105,   109,   113,   117,   121,
     125,   129,   133,   135,   137,   139,   141,   143,   146,   148,
     151,   153,   155,   158,   161,   165,   167,   170,   175,   179,
     185,   189,   195,   199,   204,   208,   213,   220,   227,   231,
     237,   239,   241,   243,   245,   247,   249,   251,   253,   255,
     257,   259,   261,   263,   265,   267,   269,   271,   273,   275,
     277,   279,   281,   283,   285,   287,   289,   291,   293,   295,
     297,   299,   301,   303,   305,   307,   310,   313,   316,   319,
     322,   325,   328,   332,   334,   336,   339,   342,   345,   348,
     351,   354,   357,   360,   363,   366,   369,   372,   375,   378,
     381,   384,   387,   390,   393,   396,   399,   402,   405,   408,
     411,   414,   417,   420,   423,   426,   429,   432,   435,   438,
     441,   444,   449,   452,   455,   458,   461,   464,   467,   470,
     473,   476,   479,   482,   485,   488,   491,   494,   497,   500,
     503,   506,   509,   512,   515,   518,   521,   524,   527,   530,
     533,   536,   539,   542,   545,   548,   551,   554,   557,   560,
     563,   567,   569,   571,   574,   577,   580,   583,   586,   589,
     592,   595,   598,   601,   604,   607,   610,   613,   616,   619,
     622,   625,   630,   633,   636,   639,   642,   645,   648,   651,
     654,   656,   660,   662,   666,   668,   672,   674,   678,   680,
     682,   684,   686,   688,   690,   692,   694,   696,   698,   700,
     702,   704,   706,   708,   710,   712,   714,   716,   718,   720,
     722,   724,   726,   728,   730
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     189,     0,    -1,   191,   190,    -1,    -1,   174,    -1,   174,
      14,    -1,    -1,   191,   192,    -1,   193,    -1,   203,    -1,
      14,    11,   195,    -1,    14,    13,   195,    -1,    12,    15,
      -1,    14,    -1,   197,    -1,   194,     7,   194,    -1,   194,
       8,   194,    -1,   194,     9,   194,    -1,   194,    10,   194,
      -1,   194,     5,   194,    -1,   194,     6,   194,    -1,     4,
     194,    -1,   180,   194,   181,    -1,   198,    -1,     9,    -1,
     195,     7,   195,    -1,   195,     8,   195,    -1,   195,     9,
     195,    -1,   195,    10,   195,    -1,   195,     5,   195,    -1,
     195,     6,   195,    -1,     4,   195,    -1,   180,   195,   181,
      -1,   156,    -1,    14,    -1,   196,     7,   196,    -1,   196,
       8,   196,    -1,   196,     9,   196,    -1,   196,    10,   196,
      -1,   196,     5,   196,    -1,   196,     6,   196,    -1,   180,
     196,   181,    -1,   156,    -1,    16,    -1,    14,    -1,   156,
      -1,    14,    -1,   182,   194,    -1,   201,    -1,   182,   195,
      -1,   201,    -1,   195,    -1,   183,   195,    -1,   184,   195,
      -1,   185,   195,   186,    -1,   202,    -1,   187,   210,    -1,
     185,   187,   210,   186,    -1,   196,   187,   210,    -1,   185,
     196,   187,   210,   186,    -1,   211,   187,   210,    -1,   185,
     211,   187,   210,   186,    -1,   187,   210,     7,    -1,   187,
     210,     7,     7,    -1,   187,     8,   210,    -1,   187,     8,
       8,   210,    -1,   185,   187,     8,     8,   210,   186,    -1,
     185,   187,   210,     7,     7,   186,    -1,   196,   187,   167,
      -1,   185,   196,   187,   167,   186,    -1,    17,    -1,    18,
      -1,    19,    -1,    20,    -1,    21,    -1,    22,    -1,    23,
      -1,    24,    -1,    25,    -1,    27,    -1,    28,    -1,    29,
      -1,    30,    -1,    31,    -1,    32,    -1,    33,    -1,    34,
      -1,    35,    -1,    36,    -1,    37,    -1,    38,    -1,    39,
      -1,    40,    -1,    41,    -1,    42,    -1,    43,    -1,    44,
      -1,    45,    -1,    46,    -1,    47,    -1,    48,    -1,    49,
      -1,    50,    -1,    51,    -1,    52,    -1,    54,   199,    -1,
      55,   199,    -1,    56,   199,    -1,    57,   199,    -1,    58,
     200,    -1,    59,   199,    -1,    60,   199,    -1,    61,   182,
     194,    -1,   177,    -1,   179,    -1,    62,   201,    -1,    63,
     201,    -1,    71,   199,    -1,    72,   199,    -1,    64,   198,
      -1,    65,   198,    -1,    66,   198,    -1,    67,   198,    -1,
      68,   198,    -1,    69,   198,    -1,    70,   198,    -1,    73,
     198,    -1,    74,   198,    -1,    75,   198,    -1,    76,   198,
      -1,    77,   198,    -1,    78,   198,    -1,    79,   198,    -1,
      80,   198,    -1,    81,   198,    -1,    82,   198,    -1,    83,
     198,    -1,    84,   198,    -1,    85,   201,    -1,    86,   199,
      -1,    87,   199,    -1,    88,   200,    -1,    89,   200,    -1,
      90,   200,    -1,    91,   200,    -1,    92,   200,    -1,    93,
     201,    -1,    26,   199,    -1,    94,   201,    -1,    95,   199,
      -1,    96,   199,    -1,    97,   209,   187,   209,    -1,    98,
     201,    -1,    99,   201,    -1,   100,   201,    -1,   102,   198,
      -1,   103,   198,    -1,   104,   198,    -1,   105,   198,    -1,
     106,   198,    -1,   107,   198,    -1,   108,   198,    -1,   109,
     198,    -1,   110,   198,    -1,   111,   198,    -1,   112,   198,
      -1,   113,   198,    -1,   114,   198,    -1,   115,   198,    -1,
     116,   198,    -1,   117,   198,    -1,   118,   198,    -1,   119,
     198,    -1,   120,   198,    -1,   121,   199,    -1,   122,   199,
      -1,   123,   200,    -1,   125,   200,    -1,   124,   200,    -1,
     126,   200,    -1,   127,   200,    -1,   128,   202,    -1,   129,
     202,    -1,   130,   202,    -1,   131,   202,    -1,   132,   201,
      -1,   133,   201,    -1,   134,   201,    -1,   135,   199,    -1,
     136,   199,    -1,   137,   182,   194,    -1,   178,    -1,   176,
      -1,   138,   207,    -1,   139,   207,    -1,   140,   207,    -1,
     141,   207,    -1,   144,   201,    -1,   145,   201,    -1,   142,
     199,    -1,   143,   199,    -1,   146,   201,    -1,   147,   201,
      -1,   148,   201,    -1,   151,   201,    -1,   152,   201,    -1,
     149,   201,    -1,   150,   201,    -1,   153,   199,    -1,   154,
     199,    -1,   155,   200,    -1,   101,   209,   187,   209,    -1,
      53,   199,    -1,   168,   194,    -1,   169,   156,    -1,   170,
     205,    -1,   171,   206,    -1,   172,   204,    -1,   175,   204,
      -1,   173,   196,    -1,    15,    -1,   204,   187,    15,    -1,
     194,    -1,   205,   187,   194,    -1,   195,    -1,   206,   187,
     195,    -1,   208,    -1,   207,   187,   208,    -1,   165,    -1,
     157,    -1,   158,    -1,   159,    -1,   166,    -1,   160,    -1,
     161,    -1,   163,    -1,   162,    -1,   164,    -1,   159,    -1,
     160,    -1,   161,    -1,   162,    -1,   163,    -1,   164,    -1,
     157,    -1,   158,    -1,   165,    -1,   166,    -1,   160,    -1,
     161,    -1,   162,    -1,   163,    -1,   157,    -1,   158,    -1,
     159,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   600,   600,   603,   604,   605,   608,   609,   612,   613,
     614,   615,   616,   619,   622,   623,   624,   625,   626,   627,
     628,   629,   630,   633,   634,   635,   636,   637,   638,   639,
     640,   641,   642,   645,   646,   647,   648,   649,   650,   651,
     652,   653,   656,   657,   658,   661,   662,   665,   666,   669,
     670,   673,   674,   675,   676,   677,   680,   681,   682,   683,
     684,   685,   686,   687,   688,   689,   690,   691,   692,   693,
     696,   697,   698,   699,   700,   701,   702,   703,   704,   705,
     706,   707,   708,   709,   710,   711,   712,   713,   714,   715,
     716,   717,   718,   719,   720,   721,   722,   723,   724,   725,
     726,   727,   728,   729,   730,   732,   733,   734,   735,   736,
     737,   738,   739,   740,   741,   742,   743,   744,   745,   746,
     747,   748,   749,   750,   751,   752,   753,   754,   755,   756,
     757,   758,   759,   760,   761,   762,   763,   764,   765,   766,
     767,   768,   769,   770,   771,   772,   773,   774,   775,   776,
     777,   778,   779,   780,   781,   782,   783,   784,   785,   786,
     787,   788,   789,   790,   791,   792,   793,   794,   795,   796,
     797,   798,   799,   800,   801,   802,   803,   804,   805,   806,
     807,   808,   809,   810,   811,   812,   813,   814,   815,   816,
     817,   818,   819,   820,   821,   822,   823,   824,   825,   826,
     827,   828,   829,   830,   831,   832,   833,   834,   835,   836,
     837,   838,   839,   841,   842,   843,   844,   845,   846,   847,
     850,   851,   854,   855,   858,   859,   862,   863,   866,   867,
     868,   869,   870,   871,   872,   873,   874,   875,   877,   878,
     879,   880,   881,   882,   883,   884,   885,   886,   889,   890,
     891,   892,   895,   896,   897
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'!'", "'~'", "'&'", "'|'", "'+'", "'-'",
  "'*'", "'/'", "EQU", "INCLUDE", "SET", "ID", "STRING", "CHAR", "ABX",
  "ASLA", "ASLB", "ASRA", "ASRB", "CLRA", "CLRB", "COMA", "COMB", "CWAI",
  "DAA", "DECA", "DECB", "INCA", "INCB", "LSLA", "LSLB", "LSRA", "LSRB",
  "MUL", "NEGA", "NEGB", "NOP", "ROLA", "ROLB", "RORA", "RORB", "RTI",
  "RTS", "SEX", "SWI", "SWI2", "SWI3", "SYNC", "TSTA", "TSTB", "TST",
  "ADCA", "ADCB", "ADDA", "ADDB", "ADDD", "ANDA", "ANDB", "ANDCC", "ASL",
  "ASR", "BCC", "BCS", "BEQ", "BGE", "BGT", "BHI", "BHS", "BITA", "BITB",
  "BLE", "BLO", "BLS", "BLT", "BMI", "BNE", "BPL", "BRA", "BRN", "BSR",
  "BVC", "BVS", "CLR", "CMPA", "CMPB", "CMPD", "CMPS", "CMPU", "CMPX",
  "CMPY", "COM", "DEC", "EORA", "EORB", "EXG", "INC", "JMP", "JSR", "TFR",
  "LBCC", "LBCS", "LBEQ", "LBGE", "LBGT", "LBHI", "LBHS", "LBLE", "LBLO",
  "LBLS", "LBLT", "LBMI", "LBNE", "LBPL", "LBRA", "LBRN", "LBSR", "LBVC",
  "LBVS", "LDA", "LDB", "LDD", "LDS", "LDU", "LDX", "LDY", "LEAX", "LEAY",
  "LEAS", "LEAU", "LSL", "LSR", "NEG", "ORA", "ORB", "ORCC", "PSHS",
  "PSHU", "PULS", "PULU", "SBCA", "SBCB", "ROL", "ROR", "STA", "STB",
  "STD", "STX", "STY", "STS", "STU", "SUBA", "SUBB", "SUBD", "NUMBER", "A",
  "B", "D", "X", "Y", "U", "S", "PC", "CC", "DP", "PCR", "SETDP", "ORG",
  "FCB", "FDB", "FCC", "RMB", "END", "FCZ", "SETC", "CLRC", "SETZ", "CLRZ",
  "'('", "')'", "'#'", "'>'", "'<'", "'['", "']'", "','", "$accept",
  "file", "end", "lines", "line", "label", "byte_expr", "word_expr",
  "const_expr", "imm8", "imm16", "op8", "op16", "direct_indexed_extended",
  "indexed", "instruction", "strings", "bytes", "words", "push_registers",
  "push_register", "register", "index_register", "accumulator", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    33,   126,    38,   124,    43,    45,    42,
      47,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
      40,    41,    35,    62,    60,    91,    93,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   188,   189,   190,   190,   190,   191,   191,   192,   192,
     192,   192,   192,   193,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   197,   197,   197,   198,   198,   199,   199,   200,
     200,   201,   201,   201,   201,   201,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     204,   204,   205,   205,   206,   206,   207,   207,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   210,   210,
     210,   210,   211,   211,   211
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     2,     0,     2,     1,     1,
       3,     3,     2,     1,     1,     3,     3,     3,     3,     3,
       3,     2,     3,     1,     1,     3,     3,     3,     3,     3,
       3,     2,     3,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     2,     1,     2,
       1,     1,     2,     2,     3,     1,     2,     4,     3,     5,
       3,     5,     3,     4,     3,     4,     6,     6,     3,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     3,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     4,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       3,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     4,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     3,     1,     0,    13,    70,    71,    72,    73,
      74,    75,    76,    77,    78,     0,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     4,     0,   192,   113,   191,   114,     2,     7,     8,
       9,    12,     0,     0,     0,    24,    46,    45,   252,   253,
     254,     0,     0,     0,     0,     0,     0,    51,     0,    23,
     147,    48,    55,     0,   212,   105,   106,   107,   108,     0,
     109,    50,   110,   111,     0,   115,   116,    46,    45,   119,
     120,   121,   122,   123,   124,   125,   117,   118,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   148,
     149,   150,   244,   245,   238,   239,   240,   241,   242,   243,
     246,   247,     0,   152,   153,   154,     0,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   178,
     177,   179,   180,    34,    33,     0,     0,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   229,   230,   231,
     233,   234,   236,   235,   237,   228,   232,   193,   226,   194,
     195,   196,   199,   200,   197,   198,   201,   202,   203,   206,
     207,   204,   205,   208,   209,   210,     0,    44,    43,    42,
       0,   213,    14,   214,   222,   215,     0,   224,   216,   220,
     217,   219,     5,   218,    10,    11,    31,     0,     0,    47,
      52,    53,     0,     0,     0,     0,     0,   248,   249,   250,
     251,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    49,   112,     0,     0,
     190,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    41,     0,     0,    54,     0,     0,
       0,    64,    62,    29,    30,    25,    26,    27,    28,    39,
      40,    35,    36,    37,    38,    68,    58,    60,   151,   211,
     227,    22,    19,    20,    15,    16,    17,    18,   223,   225,
     221,     0,     0,    57,     0,     0,     0,    65,    63,     0,
       0,    69,    59,    61,    66,    67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   157,     2,   158,   159,   321,   177,   178,   322,
     179,   180,   190,   181,   182,   160,   330,   325,   328,   297,
     298,   242,   351,   183
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -181
static const yytype_int16 yypact[] =
{
    -181,    23,   299,  -181,    35,     7,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,     5,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,     5,     5,     5,     5,     5,    39,     5,     5,
    -160,    45,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,     5,     5,    39,    39,    39,
      39,    39,    45,    45,     5,     5,   -97,    45,    45,    45,
     -97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,     5,    39,    39,    39,    39,    39,   112,   112,   112,
     112,    45,    45,    45,     5,     5,  -130,   342,   342,   342,
     342,     5,     5,    45,    45,    45,    45,    45,    45,    45,
      45,    45,     5,     5,    39,   121,   -80,   121,    -2,    74,
      -8,    83,    74,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,    -2,    -2,    -2,  -181,    65,    72,  -181,  -181,
    -181,   124,   121,    -2,    -2,    86,    -3,   160,    31,  -181,
    -181,  -181,  -181,   -88,  -181,  -181,  -181,  -181,  -181,    -2,
    -181,  -181,  -181,  -181,   121,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,   -60,  -181,  -181,  -181,   -55,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,    -8,   128,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,   121,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,   -53,  -181,   -53,
     -53,   -53,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,   121,  -181,  -181,  -181,
     121,   509,  -181,  -181,   509,   -51,    -2,   160,   -48,  -181,
     -47,   531,  -181,   -47,   160,   160,   160,   102,   108,   509,
     160,   160,    13,    96,    78,   -46,    88,  -181,  -181,  -181,
    -181,   146,    -2,    -2,    -2,    -2,    -2,    -2,    -8,    -8,
      -8,    -8,    -8,    -8,  -116,   -17,   160,   509,   -97,   -97,
     509,   342,   509,   114,   121,   121,   121,   121,   121,   121,
     121,    -2,   141,  -181,  -181,   163,    -4,  -181,   -69,   -17,
     -17,  -181,   173,   142,   142,     1,     1,  -181,  -181,   247,
     247,    22,    22,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,   253,   253,    25,    25,  -181,  -181,   509,   160,
    -181,   -17,   176,  -181,     0,     8,    14,  -181,  -181,    34,
      41,  -181,  -181,  -181,  -181,  -181
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -181,  -181,  -181,  -181,  -181,  -181,  -139,  -147,  -146,  -181,
     568,   437,   380,   476,   345,  -181,    32,  -181,  -181,   -72,
    -180,   -90,   145,  -145
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -35
static const yytype_int16 yytable[] =
{
     246,   327,   164,   422,   331,   346,   273,   165,   324,   164,
     356,   357,   197,   197,   165,   334,   335,   336,   162,   166,
     163,   385,   194,     3,   337,   338,   340,   341,   343,   344,
     345,   362,   363,   339,   378,   379,   358,   359,   360,   361,
     362,   363,   366,   164,   347,   348,   349,   350,   165,   164,
     161,   405,   286,   166,   165,   367,   299,   300,   301,   166,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     -34,   -34,   -34,   -34,   -34,   -34,   323,   -33,   -33,   -33,
     -33,   -33,   -33,   358,   359,   360,   361,   362,   363,   329,
     164,   347,   348,   349,   350,   165,   390,   332,   424,   365,
     166,   352,   353,   354,   355,   356,   357,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   374,
     375,   376,   377,   378,   379,   316,   273,   368,   164,   338,
     344,   345,   369,   165,   371,   317,   380,   318,   166,   381,
     382,   389,   273,   347,   348,   349,   350,   370,   274,   354,
     355,   356,   357,   392,   198,   198,   420,   347,   348,   349,
     350,   167,   168,   169,   170,   352,   353,   354,   355,   356,
     357,   421,   275,   347,   348,   349,   350,   372,   326,   337,
     428,   373,   423,   430,   333,   171,   431,   172,   173,   174,
     175,   410,   176,     0,   432,   167,   168,   169,   170,     0,
     433,   167,   168,   169,   170,   393,   394,   395,   396,   397,
     398,     0,   399,   400,   401,   402,   403,   404,   364,   171,
     434,   189,   173,   174,   175,   171,   176,   435,   173,   174,
     175,     0,   176,     0,   419,   412,   413,   414,   415,   416,
     417,   418,   167,   168,   169,   170,   -34,     0,   347,   348,
     349,   350,   -34,   -33,   360,   361,   362,   363,     0,   -33,
     376,   377,   378,   379,     0,   388,   171,     0,   274,   168,
     169,   170,     0,   342,     0,     0,     0,   319,   408,   409,
     167,     0,   387,   383,   274,   168,   169,   170,     0,   384,
       0,     0,   275,     0,     0,   411,     0,   276,     0,   176,
       0,   320,     0,     0,   171,     0,     0,     0,   275,     0,
       0,     4,     0,     5,     0,   342,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
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
     140,   141,   142,   143,   144,     0,     0,   223,   224,   225,
     226,   227,   277,   278,   279,   280,     0,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   184,
     185,   186,   187,   188,     0,   192,   193,   386,     0,     0,
       0,   391,   268,   269,   270,   271,   272,   206,   207,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   406,
     407,     0,   221,   222,   374,   375,   376,   377,   378,   379,
       0,   230,   231,   191,   315,     0,     0,   195,   196,     0,
       0,     0,     0,   425,   426,   427,   358,   359,   360,   361,
     362,   363,     0,     0,     0,     0,     0,   266,   267,     0,
     220,     0,     0,   191,   191,   191,   191,   191,   228,   229,
       0,   284,   285,   243,   244,   245,   429,     0,   302,   303,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   313,
     314,     0,     0,     0,     0,     0,     0,     0,   191,   191,
     191,   191,   191,     0,     0,     0,     0,   281,   282,   283,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   304,
     305,   306,   307,   308,   309,   310,   311,   312,     0,     0,
     191,   199,   200,   201,   202,   203,   204,   205,     0,     0,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265
};

static const yytype_int16 yycheck[] =
{
      90,   148,     4,     7,   150,     8,    14,     9,   147,     4,
       9,    10,    14,    14,     9,   162,   163,   164,    11,    14,
      13,     8,   182,     0,   171,   171,   173,   174,   175,   175,
     175,     9,    10,   172,     9,    10,     5,     6,     7,     8,
       9,    10,   189,     4,   160,   161,   162,   163,     9,     4,
      15,   167,   182,    14,     9,   194,   128,   129,   130,    14,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
       5,     6,     7,     8,     9,    10,   156,     5,     6,     7,
       8,     9,    10,     5,     6,     7,     8,     9,    10,    15,
       4,   160,   161,   162,   163,     9,     8,    14,   167,   187,
      14,     5,     6,     7,     8,     9,    10,     5,     6,     7,
       8,     9,    10,     5,     6,     7,     8,     9,    10,     5,
       6,     7,     8,     9,    10,     4,    14,   187,     4,   275,
     276,   276,   187,     9,   187,    14,   187,    16,    14,   187,
     187,   187,    14,   160,   161,   162,   163,   286,   156,     7,
       8,     9,    10,     7,   156,   156,    15,   160,   161,   162,
     163,   156,   157,   158,   159,     5,     6,     7,     8,     9,
      10,     8,   180,   160,   161,   162,   163,   316,   180,   326,
       7,   320,   186,     7,   152,   180,   186,   182,   183,   184,
     185,   371,   187,    -1,   186,   156,   157,   158,   159,    -1,
     186,   156,   157,   158,   159,   352,   353,   354,   355,   356,
     357,    -1,   358,   359,   360,   361,   362,   363,   187,   180,
     186,   182,   183,   184,   185,   180,   187,   186,   183,   184,
     185,    -1,   187,    -1,   381,   374,   375,   376,   377,   378,
     379,   380,   156,   157,   158,   159,   181,    -1,   160,   161,
     162,   163,   187,   181,     7,     8,     9,    10,    -1,   187,
       7,     8,     9,    10,    -1,   187,   180,    -1,   156,   157,
     158,   159,    -1,   187,    -1,    -1,    -1,   156,   368,   369,
     156,    -1,   186,   181,   156,   157,   158,   159,    -1,   181,
      -1,    -1,   180,    -1,    -1,   181,    -1,   185,    -1,   187,
      -1,   180,    -1,    -1,   180,    -1,    -1,    -1,   180,    -1,
      -1,    12,    -1,    14,    -1,   187,    17,    18,    19,    20,
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
     151,   152,   153,   154,   155,    -1,    -1,    77,    78,    79,
      80,    81,   117,   118,   119,   120,    -1,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,    42,
      43,    44,    45,    46,    -1,    48,    49,   342,    -1,    -1,
      -1,   346,   112,   113,   114,   115,   116,    60,    61,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   364,
     365,    -1,    75,    76,     5,     6,     7,     8,     9,    10,
      -1,    84,    85,    47,   144,    -1,    -1,    51,    52,    -1,
      -1,    -1,    -1,   388,   389,   390,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,   110,   111,    -1,
      74,    -1,    -1,    77,    78,    79,    80,    81,    82,    83,
      -1,   124,   125,    87,    88,    89,   421,    -1,   131,   132,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,
     114,   115,   116,    -1,    -1,    -1,    -1,   121,   122,   123,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    -1,    -1,
     144,    53,    54,    55,    56,    57,    58,    59,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   189,   191,     0,    12,    14,    17,    18,    19,    20,
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
     173,   174,   175,   176,   177,   178,   179,   190,   192,   193,
     203,    15,    11,    13,     4,     9,    14,   156,   157,   158,
     159,   180,   182,   183,   184,   185,   187,   195,   196,   198,
     199,   201,   202,   211,   199,   199,   199,   199,   199,   182,
     200,   201,   199,   199,   182,   201,   201,    14,   156,   198,
     198,   198,   198,   198,   198,   198,   199,   199,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     201,   199,   199,   200,   200,   200,   200,   200,   201,   201,
     199,   199,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   209,   201,   201,   201,   209,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   199,   199,   200,   200,
     200,   200,   200,    14,   156,   180,   185,   202,   202,   202,
     202,   201,   201,   201,   199,   199,   182,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   207,   208,   207,
     207,   207,   199,   199,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   199,   199,   200,     4,    14,    16,   156,
     180,   194,   197,   156,   194,   205,   180,   195,   206,    15,
     204,   196,    14,   204,   195,   195,   195,   195,   196,   194,
     195,   195,   187,   195,   196,   211,     8,   160,   161,   162,
     163,   210,     5,     6,     7,     8,     9,    10,     5,     6,
       7,     8,     9,    10,   187,   187,   195,   194,   187,   187,
     194,   187,   194,   194,     5,     6,     7,     8,     9,    10,
     187,   187,   187,   181,   181,     8,   210,   186,   187,   187,
       8,   210,     7,   195,   195,   195,   195,   195,   195,   196,
     196,   196,   196,   196,   196,   167,   210,   210,   209,   209,
     208,   181,   194,   194,   194,   194,   194,   194,   194,   195,
      15,     8,     7,   186,   167,   210,   210,   210,     7,   210,
       7,   186,   186,   186,   186,   186
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:

    { if (symbols[(yyvsp[(2) - (2)].symbol)].type != ST_LABEL) yyerror("undefined label"); symbols[(yyvsp[(2) - (2)].symbol)].refd++; start_addr = /*origin_addr +*/ symbols[(yyvsp[(2) - (2)].symbol)].value; LOG("start addr set to '%s' ($%04X)\n", symbols[(yyvsp[(2) - (2)].symbol)].name, start_addr);;}
    break;

  case 7:

    { yyerrok; ;}
    break;

  case 9:

    { fixup_pending_index = FP_NONE; ;}
    break;

  case 10:

    { if (symbols[(yyvsp[(1) - (3)].symbol)].type != ST_UNDEF) yyerror("equate already defined"); symbols[(yyvsp[(1) - (3)].symbol)].value = (yyvsp[(3) - (3)].ival); symbols[(yyvsp[(1) - (3)].symbol)].type = ST_EQU; ;}
    break;

  case 11:

    { symbols[(yyvsp[(1) - (3)].symbol)].value = (yyvsp[(3) - (3)].ival); symbols[(yyvsp[(1) - (3)].symbol)].type = ST_SET; ;}
    break;

  case 12:

    { push_file_stack(symbols[(yyvsp[(2) - (2)].symbol)].name); symbols[(yyvsp[(2) - (2)].symbol)].refd++;;}
    break;

  case 13:

    { if (symbols[(yyvsp[(1) - (1)].symbol)].type != ST_UNDEF) yyerror("label already defined"); symbols[(yyvsp[(1) - (1)].symbol)].value = origin_addr + addr; symbols[(yyvsp[(1) - (1)].symbol)].type = ST_LABEL; ;}
    break;

  case 15:

    { if ((yyvsp[(1) - (3)].ival) == SA_UNDEF || (yyvsp[(3) - (3)].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[(1) - (3)].ival) + (yyvsp[(3) - (3)].ival); ;}
    break;

  case 16:

    { if ((yyvsp[(1) - (3)].ival) == SA_UNDEF || (yyvsp[(3) - (3)].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[(1) - (3)].ival) - (yyvsp[(3) - (3)].ival); ;}
    break;

  case 17:

    { if ((yyvsp[(1) - (3)].ival) == SA_UNDEF || (yyvsp[(3) - (3)].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[(1) - (3)].ival) * (yyvsp[(3) - (3)].ival); ;}
    break;

  case 18:

    { if ((yyvsp[(1) - (3)].ival) == SA_UNDEF || (yyvsp[(3) - (3)].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[(1) - (3)].ival) / (yyvsp[(3) - (3)].ival); ;}
    break;

  case 19:

    { if ((yyvsp[(1) - (3)].ival) == SA_UNDEF || (yyvsp[(3) - (3)].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[(1) - (3)].ival) & (yyvsp[(3) - (3)].ival); ;}
    break;

  case 20:

    { if ((yyvsp[(1) - (3)].ival) == SA_UNDEF || (yyvsp[(3) - (3)].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[(1) - (3)].ival) | (yyvsp[(3) - (3)].ival); ;}
    break;

  case 21:

    { if ((yyvsp[(2) - (2)].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = ~(yyvsp[(2) - (2)].ival);;}
    break;

  case 22:

    { if ((yyvsp[(2) - (3)].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[(2) - (3)].ival); ;}
    break;

  case 24:

    { (yyval.ival) = addr + origin_addr; ;}
    break;

  case 25:

    { if ((yyvsp[(1) - (3)].ival) == SA_UNDEF || (yyvsp[(3) - (3)].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[(1) - (3)].ival) + (yyvsp[(3) - (3)].ival); ;}
    break;

  case 26:

    { if ((yyvsp[(1) - (3)].ival) == SA_UNDEF || (yyvsp[(3) - (3)].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[(1) - (3)].ival) - (yyvsp[(3) - (3)].ival); ;}
    break;

  case 27:

    { if ((yyvsp[(1) - (3)].ival) == SA_UNDEF || (yyvsp[(3) - (3)].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[(1) - (3)].ival) * (yyvsp[(3) - (3)].ival); ;}
    break;

  case 28:

    { if ((yyvsp[(1) - (3)].ival) == SA_UNDEF || (yyvsp[(3) - (3)].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[(1) - (3)].ival) / (yyvsp[(3) - (3)].ival); ;}
    break;

  case 29:

    { if ((yyvsp[(1) - (3)].ival) == SA_UNDEF || (yyvsp[(3) - (3)].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[(1) - (3)].ival) & (yyvsp[(3) - (3)].ival); ;}
    break;

  case 30:

    { if ((yyvsp[(1) - (3)].ival) == SA_UNDEF || (yyvsp[(3) - (3)].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = (yyvsp[(1) - (3)].ival) | (yyvsp[(3) - (3)].ival); ;}
    break;

  case 31:

    { if ((yyvsp[(2) - (2)].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs"); (yyval.ival) = ~(yyvsp[(2) - (2)].ival);;}
    break;

  case 32:

    { if ((yyvsp[(2) - (3)].ival) == SA_UNDEF) yyerror("cannot eval expr on forward refs");(yyval.ival) = (yyvsp[(2) - (3)].ival); ;}
    break;

  case 34:

    { if (symbols[(yyvsp[(1) - (1)].symbol)].type != ST_EQU && symbols[(yyvsp[(1) - (1)].symbol)].type != ST_SET) yyerror("non const in const expr"); (yyval.ival) = symbols[(yyvsp[(1) - (1)].symbol)].value; symbols[(yyvsp[(1) - (1)].symbol)].refd++;;}
    break;

  case 35:

    { (yyval.ival) = (yyvsp[(1) - (3)].ival) + (yyvsp[(3) - (3)].ival); ;}
    break;

  case 36:

    { (yyval.ival) = (yyvsp[(1) - (3)].ival) - (yyvsp[(3) - (3)].ival); ;}
    break;

  case 37:

    { (yyval.ival) = (yyvsp[(1) - (3)].ival) * (yyvsp[(3) - (3)].ival); ;}
    break;

  case 38:

    { (yyval.ival) = (yyvsp[(1) - (3)].ival) / (yyvsp[(3) - (3)].ival); ;}
    break;

  case 39:

    { (yyval.ival) = (yyvsp[(1) - (3)].ival) & (yyvsp[(3) - (3)].ival); ;}
    break;

  case 40:

    { (yyval.ival) = (yyvsp[(1) - (3)].ival) | (yyvsp[(3) - (3)].ival); ;}
    break;

  case 41:

    { (yyval.ival) = (yyvsp[(2) - (3)].ival); ;}
    break;

  case 42:

    { if (HIBYTE((yyvsp[(1) - (1)].ival)) && ((yyvsp[(1) - (1)].ival) < -128 || (yyvsp[(1) - (1)].ival) > 127)) yyerror("byte value expected"); (yyval.ival) = LOBYTE((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 44:

    { if (symbols[(yyvsp[(1) - (1)].symbol)].type == ST_UNDEF) { fixup_pending_index = add_fixup((yyvsp[(1) - (1)].symbol), addr + 1, FIXUP_IMM8); (yyval.ival) = SA_UNDEF; } else (yyval.ival) = symbols[(yyvsp[(1) - (1)].symbol)].value; symbols[(yyvsp[(1) - (1)].symbol)].refd++;;}
    break;

  case 46:

    { if (symbols[(yyvsp[(1) - (1)].symbol)].type == ST_UNDEF) { fixup_pending_index = add_fixup((yyvsp[(1) - (1)].symbol), addr + 1, FIXUP_IMM16); (yyval.ival) = SA_UNDEF; } else (yyval.ival) = symbols[(yyvsp[(1) - (1)].symbol)].value; symbols[(yyvsp[(1) - (1)].symbol)].refd++;;}
    break;

  case 47:

    { emit_buf((yyvsp[(2) - (2)].ival)); (yyval.ival) = AM_IMM; ;}
    break;

  case 49:

    { emit_buf_word((yyvsp[(2) - (2)].ival)); (yyval.ival) = AM_IMM; ;}
    break;

  case 51:

    { if (SA_UNDEF != (yyvsp[(1) - (1)].ival) && direct_page_addr == HIBYTE((yyvsp[(1) - (1)].ival))) { emit_buf(LOBYTE((yyvsp[(1) - (1)].ival))); (yyval.ival) = AM_DIRECT; } else { emit_buf_word((yyvsp[(1) - (1)].ival)); (yyval.ival) = AM_EXTENDED; } ;}
    break;

  case 52:

    { emit_buf_word((yyvsp[(2) - (2)].ival)); (yyval.ival) = AM_EXTENDED; ;}
    break;

  case 53:

    { if (HIBYTE((yyvsp[(2) - (2)].ival)) == direct_page_addr) { emit_buf(LOBYTE((yyvsp[(2) - (2)].ival))); (yyval.ival) = AM_DIRECT; } else yyerror("Direct page mismatch"); ;}
    break;

  case 54:

    { emit_buf(0x9F); emit_buf_word((yyvsp[(2) - (3)].ival)); adjust_fixup(FIXUP_IMM16, 2); (yyval.ival) = AM_INDEXED; ;}
    break;

  case 56:

    { emit_buf(0x84 | ((yyvsp[(2) - (2)].ival) << 5)); (yyval.ival) = AM_INDEXED; ;}
    break;

  case 57:

    { emit_buf(0x94 | ((yyvsp[(3) - (4)].ival) << 5)); (yyval.ival) = AM_INDEXED; ;}
    break;

  case 58:

    { constant_offset_direct((yyvsp[(1) - (3)].ival), (yyvsp[(3) - (3)].ival)); (yyval.ival) = AM_INDEXED; ;}
    break;

  case 59:

    { constant_offset_indirect((yyvsp[(2) - (5)].ival), (yyvsp[(4) - (5)].ival)); (yyval.ival) = AM_INDEXED; ;}
    break;

  case 60:

    { accumulator_offset_direct((yyvsp[(1) - (3)].ival), (yyvsp[(3) - (3)].ival)); (yyval.ival) = AM_INDEXED; ;}
    break;

  case 61:

    { accumulator_offset_indirect((yyvsp[(2) - (5)].ival), (yyvsp[(4) - (5)].ival)); (yyval.ival) = AM_INDEXED; ;}
    break;

  case 62:

    { emit_buf(0x80 | ((yyvsp[(2) - (3)].ival) << 5)); (yyval.ival) = AM_INDEXED; ;}
    break;

  case 63:

    { emit_buf(0x81 | ((yyvsp[(2) - (4)].ival) << 5)); (yyval.ival) = AM_INDEXED; ;}
    break;

  case 64:

    { emit_buf(0x82 | ((yyvsp[(3) - (3)].ival) << 5)); (yyval.ival) = AM_INDEXED; ;}
    break;

  case 65:

    { emit_buf(0x83 | ((yyvsp[(4) - (4)].ival) << 5)); (yyval.ival) = AM_INDEXED; ;}
    break;

  case 66:

    { emit_buf(0x93 | ((yyvsp[(5) - (6)].ival) << 5)); (yyval.ival) = AM_INDEXED; ;}
    break;

  case 67:

    { emit_buf(0x91 | ((yyvsp[(3) - (6)].ival) << 5)); (yyval.ival) = AM_INDEXED; ;}
    break;

  case 68:

    { pcr_direct((yyvsp[(1) - (3)].ival)); (yyval.ival) = AM_INDEXED; ;}
    break;

  case 69:

    { pcr_indirect((yyvsp[(2) - (5)].ival)); (yyval.ival) = AM_INDEXED; ;}
    break;

  case 70:

    { emit(0x3A); ;}
    break;

  case 71:

    { emit(0x48); ;}
    break;

  case 72:

    { emit(0x58); ;}
    break;

  case 73:

    { emit(0x47); ;}
    break;

  case 74:

    { emit(0x57); ;}
    break;

  case 75:

    { emit(0x4F); ;}
    break;

  case 76:

    { emit(0x5F); ;}
    break;

  case 77:

    { emit(0x43); ;}
    break;

  case 78:

    { emit(0x53); ;}
    break;

  case 79:

    { emit(0x19); ;}
    break;

  case 80:

    { emit(0x4A); ;}
    break;

  case 81:

    { emit(0x5A); ;}
    break;

  case 82:

    { emit(0x4C); ;}
    break;

  case 83:

    { emit(0x5C); ;}
    break;

  case 84:

    { emit(0x48); ;}
    break;

  case 85:

    { emit(0x58); ;}
    break;

  case 86:

    { emit(0x44); ;}
    break;

  case 87:

    { emit(0x54); ;}
    break;

  case 88:

    { emit(0x3D); ;}
    break;

  case 89:

    { emit(0x40); ;}
    break;

  case 90:

    { emit(0x50); ;}
    break;

  case 91:

    { emit(0x12); ;}
    break;

  case 92:

    { emit(0x49); ;}
    break;

  case 93:

    { emit(0x59); ;}
    break;

  case 94:

    { emit(0x46); ;}
    break;

  case 95:

    { emit(0x56); ;}
    break;

  case 96:

    { emit(0x3B); ;}
    break;

  case 97:

    { emit(0x39); ;}
    break;

  case 98:

    { emit(0x1D); ;}
    break;

  case 99:

    { emit(0x3F); ;}
    break;

  case 100:

    { emit(0x10); emit(0x3F); ;}
    break;

  case 101:

    { emit(0x11); emit(0x3F); ;}
    break;

  case 102:

    { emit(0x13); ;}
    break;

  case 103:

    { emit(0x4D); ;}
    break;

  case 104:

    { emit(0x5D); ;}
    break;

  case 105:

    { emit(opcodes[OP_ADCA].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 106:

    { emit(opcodes[OP_ADCB].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 107:

    { emit(opcodes[OP_ADDA].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 108:

    { emit(opcodes[OP_ADDB].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 109:

    { emit(opcodes[OP_ADDD].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 110:

    { emit(opcodes[OP_ANDA].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 111:

    { emit(opcodes[OP_ANDB].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 112:

    { emit(0x1C); emit(LOBYTE((yyvsp[(3) - (3)].ival))); ;}
    break;

  case 113:

    { emit(0x1C); emit(0xFE); ;}
    break;

  case 114:

    { emit(0x1C); emit(0xFB); ;}
    break;

  case 115:

    { emit(opcodes[OP_ASL].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 116:

    { emit(opcodes[OP_ASR].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 117:

    { emit(opcodes[OP_BITA].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 118:

    { emit(opcodes[OP_BITB].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 119:

    { rel_branch(BR_SHORT, 0x24, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 120:

    { rel_branch(BR_SHORT, 0x25, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 121:

    { rel_branch(BR_SHORT, 0x27, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 122:

    { rel_branch(BR_SHORT, 0x2C, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 123:

    { rel_branch(BR_SHORT, 0x2E, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 124:

    { rel_branch(BR_SHORT, 0x22, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 125:

    { rel_branch(BR_SHORT, 0x24, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 126:

    { rel_branch(BR_SHORT, 0x2F, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 127:

    { rel_branch(BR_SHORT, 0x25, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 128:

    { rel_branch(BR_SHORT, 0x23, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 129:

    { rel_branch(BR_SHORT, 0x2D, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 130:

    { rel_branch(BR_SHORT, 0x2B, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 131:

    { rel_branch(BR_SHORT, 0x26, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 132:

    { rel_branch(BR_SHORT, 0x2A, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 133:

    { rel_branch(BR_SHORT, 0x20, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 134:

    { rel_branch(BR_SHORT, 0x21, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 135:

    { rel_branch(BR_SHORT, 0x8D, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 136:

    { rel_branch(BR_SHORT, 0x28, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 137:

    { rel_branch(BR_SHORT, 0x29, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 138:

    { emit(opcodes[OP_CLR].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 139:

    { emit(opcodes[OP_CMPA].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 140:

    { emit(opcodes[OP_CMPB].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 141:

    { emit(0x10); emit(opcodes[OP_CMPD].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); adjust_fixup(FIXUP_NOCHANGE, 1); ;}
    break;

  case 142:

    { emit(0x11); emit(opcodes[OP_CMPS].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); adjust_fixup(FIXUP_NOCHANGE, 1); ;}
    break;

  case 143:

    { emit(0x11); emit(opcodes[OP_CMPD].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); adjust_fixup(FIXUP_NOCHANGE, 1); ;}
    break;

  case 144:

    { emit(opcodes[OP_CMPS].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 145:

    { emit(0x10); emit(opcodes[OP_CMPS].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); adjust_fixup(FIXUP_NOCHANGE, 1); ;}
    break;

  case 146:

    { emit(opcodes[OP_COM].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 147:

    { emit(0x3C); write_inb(); ;}
    break;

  case 148:

    { emit(opcodes[OP_DEC].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 149:

    { emit(opcodes[OP_EORA].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 150:

    { emit(opcodes[OP_EORB].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 151:

    { emit(0x1E); emit(((yyvsp[(2) - (4)].ival) << 4) | (yyvsp[(4) - (4)].ival)); ;}
    break;

  case 152:

    { emit(opcodes[OP_INC].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 153:

    { emit(opcodes[OP_JMP].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 154:

    { emit(opcodes[OP_JSR].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 155:

    { rel_branch(BR_LONG, 0x24, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 156:

    { rel_branch(BR_LONG, 0x25, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 157:

    { rel_branch(BR_LONG, 0x27, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 158:

    { rel_branch(BR_LONG, 0x2C, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 159:

    { rel_branch(BR_LONG, 0x2E, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 160:

    { rel_branch(BR_LONG, 0x22, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 161:

    { rel_branch(BR_LONG, 0x24, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 162:

    { rel_branch(BR_LONG, 0x2F, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 163:

    { rel_branch(BR_LONG, 0x25, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 164:

    { rel_branch(BR_LONG, 0x23, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 165:

    { rel_branch(BR_LONG, 0x2D, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 166:

    { rel_branch(BR_LONG, 0x2B, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 167:

    { rel_branch(BR_LONG, 0x26, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 168:

    { rel_branch(BR_LONG, 0x2A, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 169:

    { rel_branch(BR_LONG_NOPREFIX, 0x16, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 170:

    { rel_branch(BR_LONG, 0x21, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 171:

    { rel_branch(BR_LONG_NOPREFIX, 0x17, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 172:

    { rel_branch(BR_LONG, 0x28, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 173:

    { rel_branch(BR_LONG, 0x29, (yyvsp[(2) - (2)].ival)); ;}
    break;

  case 174:

    { emit(opcodes[OP_LDA].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 175:

    { emit(opcodes[OP_LDB].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 176:

    { emit(opcodes[OP_LDD].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 177:

    { emit(opcodes[OP_LDU].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 178:

    { emit(0x10); emit(opcodes[OP_LDU].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); adjust_fixup(FIXUP_NOCHANGE, 1);;}
    break;

  case 179:

    { emit(opcodes[OP_LDX].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 180:

    { emit(0x10); emit(opcodes[OP_LDX].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); adjust_fixup(FIXUP_NOCHANGE, 1); ;}
    break;

  case 181:

    { emit(opcodes[OP_LEAX].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 182:

    { emit(opcodes[OP_LEAY].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 183:

    { emit(opcodes[OP_LEAS].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 184:

    { emit(opcodes[OP_LEAU].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 185:

    { emit(opcodes[OP_LSL].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 186:

    { emit(opcodes[OP_LSR].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 187:

    { emit(opcodes[OP_NEG].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 188:

    { emit(opcodes[OP_ORA].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 189:

    { emit(opcodes[OP_ORB].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 190:

    { emit(0x1A); emit(LOBYTE((yyvsp[(3) - (3)].ival))); ;}
    break;

  case 191:

    { emit(0x1A); emit(4); ;}
    break;

  case 192:

    { emit(0x1A); emit(1); ;}
    break;

  case 193:

    { emit(0x34); emit((yyvsp[(2) - (2)].ival)); ;}
    break;

  case 194:

    { emit(0x36); emit((yyvsp[(2) - (2)].ival)); ;}
    break;

  case 195:

    { emit(0x35); emit((yyvsp[(2) - (2)].ival)); ;}
    break;

  case 196:

    { emit(0x37); emit((yyvsp[(2) - (2)].ival)); ;}
    break;

  case 197:

    { emit(opcodes[OP_ROL].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 198:

    { emit(opcodes[OP_ROR].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 199:

    { emit(opcodes[OP_SBCA].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 200:

    { emit(opcodes[OP_SBCB].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 201:

    { emit(opcodes[OP_STA].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 202:

    { emit(opcodes[OP_STB].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 203:

    { emit(opcodes[OP_STD].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 204:

    { emit(0x10); emit(opcodes[OP_STS].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); adjust_fixup(FIXUP_NOCHANGE, 1); ;}
    break;

  case 205:

    { emit(opcodes[OP_STU].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 206:

    { emit(opcodes[OP_STX].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 207:

    { emit(0x10); emit(opcodes[OP_STY].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); adjust_fixup(FIXUP_NOCHANGE, 1); ;}
    break;

  case 208:

    { emit(opcodes[OP_SUBA].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 209:

    { emit(opcodes[OP_SUBB].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 210:

    { emit(opcodes[OP_SUBD].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 211:

    { emit(0x1F); emit(((yyvsp[(2) - (4)].ival) << 4) | (yyvsp[(4) - (4)].ival)); ;}
    break;

  case 212:

    { emit(opcodes[OP_TST].ops[(yyvsp[(2) - (2)].ival)]); write_inb(); ;}
    break;

  case 213:

    { direct_page_addr = (yyvsp[(2) - (2)].ival); LOG("DP set to $%02X\n", direct_page_addr); ;}
    break;

  case 214:

    { if (origin_addr != 0) yyerror("origin already set"); start_addr = origin_addr = (yyvsp[(2) - (2)].ival); LOG("ORG set to $%04X\n", origin_addr); ;}
    break;

  case 216:

    {  ;}
    break;

  case 218:

    { emit(0); ;}
    break;

  case 219:

    { addr += (yyvsp[(2) - (2)].ival); ;}
    break;

  case 220:

    { symbols[(yyval.symbol)].type = ST_STRING; emit_str(symbols[(yyval.symbol)].name); ;}
    break;

  case 221:

    { symbols[(yyvsp[(3) - (3)].symbol)].type = ST_STRING; emit_str(symbols[(yyvsp[(3) - (3)].symbol)].name); ;}
    break;

  case 222:

    { if ((yyval.ival) > 255) yyerror("byte value expected"); emit(LOBYTE((yyval.ival))); ;}
    break;

  case 223:

    { if ((yyvsp[(3) - (3)].ival) > 255) yyerror("byte value expected"); emit(LOBYTE((yyvsp[(3) - (3)].ival))); ;}
    break;

  case 224:

    { adjust_fixup(FIXUP_NOCHANGE, -1); emit_word((yyval.ival)); ;}
    break;

  case 225:

    { adjust_fixup(FIXUP_NOCHANGE, -1); emit_word((yyvsp[(3) - (3)].ival)); ;}
    break;

  case 227:

    { (yyval.ival) = (yyvsp[(1) - (3)].ival) | (yyvsp[(3) - (3)].ival); ;}
    break;

  case 228:

    { (yyval.ival) = 1; ;}
    break;

  case 229:

    { (yyval.ival) = 2; ;}
    break;

  case 230:

    { (yyval.ival) = 4; ;}
    break;

  case 231:

    { (yyval.ival) = 6; ;}
    break;

  case 232:

    { (yyval.ival) = 8; ;}
    break;

  case 233:

    { (yyval.ival) = 16; ;}
    break;

  case 234:

    { (yyval.ival) = 32; ;}
    break;

  case 235:

    { (yyval.ival) = 64; ;}
    break;

  case 236:

    { (yyval.ival) = 64; ;}
    break;

  case 237:

    { (yyval.ival) = 128; ;}
    break;

  case 238:

    { (yyval.ival) = 0;;}
    break;

  case 239:

    { (yyval.ival) = 1;;}
    break;

  case 240:

    { (yyval.ival) = 2;;}
    break;

  case 241:

    { (yyval.ival) = 3;;}
    break;

  case 242:

    { (yyval.ival) = 4;;}
    break;

  case 243:

    { (yyval.ival) = 5;;}
    break;

  case 244:

    { (yyval.ival) = 8;;}
    break;

  case 245:

    { (yyval.ival) = 9;;}
    break;

  case 246:

    { (yyval.ival) = 10;;}
    break;

  case 247:

    { (yyval.ival) = 11;;}
    break;

  case 248:

    { (yyval.ival) = 0; ;}
    break;

  case 249:

    { (yyval.ival) = 1; ;}
    break;

  case 250:

    { (yyval.ival) = 2; ;}
    break;

  case 251:

    { (yyval.ival) = 3; ;}
    break;

  case 252:

    { (yyval.ival) = 0; ;}
    break;

  case 253:

    { (yyval.ival) = 1; ;}
    break;

  case 254:

    { (yyval.ival) = 2; ;}
    break;


/* Line 1267 of yacc.c.  */

      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
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
    {"ASRA", ASRA},
    {"ASRB", ASRB},
    {"CLRA", CLRA},
    {"CLRB", CLRB},
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
	}

	return i;
}

//------------------------
// add a fixup
//------------------------
int add_fixup(int symbol, int addr, FIXUP_TYPE type)
{
    assert(fixup_count < MAX_FIXUPS);

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
            fprintf(stderr, "ERROR: undefined symbol '%s' in file %s, line %d\n", symbols[f.symbol].name, CURRENT_FILE, symbols[f.symbol].lineno);
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
            assert(FALSE);
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
    assert(symbol_count < MAX_SYMBOLS);

    // error if symbol already exists
    if (lookup_symbol(name) > 0)
        return -1;

    symbols[symbol_count].name      = strdup(name);
    symbols[symbol_count].lineno    = lineno;
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
    fwrite(&pre, sizeof(pre), 1, fout);

    // write out the code bytes
    fwrite(&code, addr, 1, fout);

    // write out the tail
    fwrite(&post, sizeof(post), 1, fout);
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
        strcpy(infile, argv[iFirstArg]);
    }

    fout = fopen(g_szOutputFilename, "wb");

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

    // return err count for make/test purposes
    return err_count;
}

