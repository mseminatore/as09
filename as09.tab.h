/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_AS09_TAB_H_INCLUDED
# define YY_YY_AS09_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    EQU = 258,                     /* EQU  */
    INCLUDE = 259,                 /* INCLUDE  */
    SET = 260,                     /* SET  */
    ID = 261,                      /* ID  */
    STRING = 262,                  /* STRING  */
    CHAR = 263,                    /* CHAR  */
    ABX = 264,                     /* ABX  */
    ASLA = 265,                    /* ASLA  */
    ASLB = 266,                    /* ASLB  */
    ASRA = 267,                    /* ASRA  */
    ASRB = 268,                    /* ASRB  */
    CLRA = 269,                    /* CLRA  */
    CLRB = 270,                    /* CLRB  */
    COMA = 271,                    /* COMA  */
    COMB = 272,                    /* COMB  */
    CWAI = 273,                    /* CWAI  */
    DAA = 274,                     /* DAA  */
    DECA = 275,                    /* DECA  */
    DECB = 276,                    /* DECB  */
    INCA = 277,                    /* INCA  */
    INCB = 278,                    /* INCB  */
    LSLA = 279,                    /* LSLA  */
    LSLB = 280,                    /* LSLB  */
    LSRA = 281,                    /* LSRA  */
    LSRB = 282,                    /* LSRB  */
    MUL = 283,                     /* MUL  */
    NEGA = 284,                    /* NEGA  */
    NEGB = 285,                    /* NEGB  */
    NOP = 286,                     /* NOP  */
    ROLA = 287,                    /* ROLA  */
    ROLB = 288,                    /* ROLB  */
    RORA = 289,                    /* RORA  */
    RORB = 290,                    /* RORB  */
    RTI = 291,                     /* RTI  */
    RTS = 292,                     /* RTS  */
    SEX = 293,                     /* SEX  */
    SWI = 294,                     /* SWI  */
    SWI2 = 295,                    /* SWI2  */
    SWI3 = 296,                    /* SWI3  */
    SYNC = 297,                    /* SYNC  */
    TSTA = 298,                    /* TSTA  */
    TSTB = 299,                    /* TSTB  */
    TST = 300,                     /* TST  */
    ADCA = 301,                    /* ADCA  */
    ADCB = 302,                    /* ADCB  */
    ADDA = 303,                    /* ADDA  */
    ADDB = 304,                    /* ADDB  */
    ADDD = 305,                    /* ADDD  */
    ANDA = 306,                    /* ANDA  */
    ANDB = 307,                    /* ANDB  */
    ANDCC = 308,                   /* ANDCC  */
    ASL = 309,                     /* ASL  */
    ASR = 310,                     /* ASR  */
    BCC = 311,                     /* BCC  */
    BCS = 312,                     /* BCS  */
    BEQ = 313,                     /* BEQ  */
    BGE = 314,                     /* BGE  */
    BGT = 315,                     /* BGT  */
    BHI = 316,                     /* BHI  */
    BHS = 317,                     /* BHS  */
    BITA = 318,                    /* BITA  */
    BITB = 319,                    /* BITB  */
    BLE = 320,                     /* BLE  */
    BLO = 321,                     /* BLO  */
    BLS = 322,                     /* BLS  */
    BLT = 323,                     /* BLT  */
    BMI = 324,                     /* BMI  */
    BNE = 325,                     /* BNE  */
    BPL = 326,                     /* BPL  */
    BRA = 327,                     /* BRA  */
    BRN = 328,                     /* BRN  */
    BSR = 329,                     /* BSR  */
    BVC = 330,                     /* BVC  */
    BVS = 331,                     /* BVS  */
    CLR = 332,                     /* CLR  */
    CMPA = 333,                    /* CMPA  */
    CMPB = 334,                    /* CMPB  */
    CMPD = 335,                    /* CMPD  */
    CMPS = 336,                    /* CMPS  */
    CMPU = 337,                    /* CMPU  */
    CMPX = 338,                    /* CMPX  */
    CMPY = 339,                    /* CMPY  */
    COM = 340,                     /* COM  */
    DEC = 341,                     /* DEC  */
    EORA = 342,                    /* EORA  */
    EORB = 343,                    /* EORB  */
    EXG = 344,                     /* EXG  */
    INC = 345,                     /* INC  */
    JMP = 346,                     /* JMP  */
    JSR = 347,                     /* JSR  */
    TFR = 348,                     /* TFR  */
    LBCC = 349,                    /* LBCC  */
    LBCS = 350,                    /* LBCS  */
    LBEQ = 351,                    /* LBEQ  */
    LBGE = 352,                    /* LBGE  */
    LBGT = 353,                    /* LBGT  */
    LBHI = 354,                    /* LBHI  */
    LBHS = 355,                    /* LBHS  */
    LBLE = 356,                    /* LBLE  */
    LBLO = 357,                    /* LBLO  */
    LBLS = 358,                    /* LBLS  */
    LBLT = 359,                    /* LBLT  */
    LBMI = 360,                    /* LBMI  */
    LBNE = 361,                    /* LBNE  */
    LBPL = 362,                    /* LBPL  */
    LBRA = 363,                    /* LBRA  */
    LBRN = 364,                    /* LBRN  */
    LBSR = 365,                    /* LBSR  */
    LBVC = 366,                    /* LBVC  */
    LBVS = 367,                    /* LBVS  */
    LDA = 368,                     /* LDA  */
    LDB = 369,                     /* LDB  */
    LDD = 370,                     /* LDD  */
    LDS = 371,                     /* LDS  */
    LDU = 372,                     /* LDU  */
    LDX = 373,                     /* LDX  */
    LDY = 374,                     /* LDY  */
    LEAX = 375,                    /* LEAX  */
    LEAY = 376,                    /* LEAY  */
    LEAS = 377,                    /* LEAS  */
    LEAU = 378,                    /* LEAU  */
    LSL = 379,                     /* LSL  */
    LSR = 380,                     /* LSR  */
    NEG = 381,                     /* NEG  */
    ORA = 382,                     /* ORA  */
    ORB = 383,                     /* ORB  */
    ORCC = 384,                    /* ORCC  */
    PSHS = 385,                    /* PSHS  */
    PSHU = 386,                    /* PSHU  */
    PULS = 387,                    /* PULS  */
    PULU = 388,                    /* PULU  */
    SBCA = 389,                    /* SBCA  */
    SBCB = 390,                    /* SBCB  */
    ROL = 391,                     /* ROL  */
    ROR = 392,                     /* ROR  */
    STA = 393,                     /* STA  */
    STB = 394,                     /* STB  */
    STD = 395,                     /* STD  */
    STX = 396,                     /* STX  */
    STY = 397,                     /* STY  */
    STS = 398,                     /* STS  */
    STU = 399,                     /* STU  */
    SUBA = 400,                    /* SUBA  */
    SUBB = 401,                    /* SUBB  */
    SUBD = 402,                    /* SUBD  */
    NUMBER = 403,                  /* NUMBER  */
    A = 404,                       /* A  */
    B = 405,                       /* B  */
    D = 406,                       /* D  */
    X = 407,                       /* X  */
    Y = 408,                       /* Y  */
    U = 409,                       /* U  */
    S = 410,                       /* S  */
    PC = 411,                      /* PC  */
    CC = 412,                      /* CC  */
    DP = 413,                      /* DP  */
    PCR = 414,                     /* PCR  */
    SETDP = 415,                   /* SETDP  */
    ORG = 416,                     /* ORG  */
    FCB = 417,                     /* FCB  */
    FDB = 418,                     /* FDB  */
    FCC = 419,                     /* FCC  */
    RMB = 420,                     /* RMB  */
    END = 421,                     /* END  */
    FCZ = 422,                     /* FCZ  */
    SETC = 423,                    /* SETC  */
    CLRC = 424,                    /* CLRC  */
    SETZ = 425,                    /* SETZ  */
    CLRZ = 426,                    /* CLRZ  */
    CLRD = 427,                    /* CLRD  */
    ASLD = 428,                    /* ASLD  */
    ASRD = 429                     /* ASRD  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{

    int ival;
    int symbol;
    char *lexeme;


};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_AS09_TAB_H_INCLUDED  */
