/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
     CLRZ = 426,
     CLRD = 427,
     ASLD = 428,
     ASRD = 429
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
#define CLRD 427
#define ASLD 428
#define ASRD 429




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE

{
    int ival;
    int symbol;
    char *lexeme;
}
/* Line 1529 of yacc.c.  */

	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

