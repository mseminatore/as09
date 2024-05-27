//================================================================================
// as09 - an MC6809E cross-assember
//
// See LICENSE file for usage rights and obligations
//================================================================================

#ifndef __AS09_H
#define __AS09_H

//-----------------
// constant decls
//-----------------
#define APP_NAME "as09"
#define APP_VER "0.4.0"

#define DONE 0

#define ADDRESS_BITS        16
#define INSTRUCTION_BITS    8

#define MAX_CODE    0x7FFF
#define MAX_SYMBOLS 1024
#define MAX_FIXUPS  1024

#define BUF_SIZE    256
#define INB_SIZE    10

#define SA_UNDEF    -1
#define FP_NONE     -1

#ifdef _WIN32
#   define strcasecmp _stricmp
#   define strdup _strdup
#endif

#ifndef TRUE
#   define TRUE 1
#endif

#ifndef FALSE
#   define FALSE 0
#endif

// remove this later
#define YYDEBUG 1

#ifndef LOBYTE
#   define LOBYTE(word) ((word) & 0xFF)
#endif

#ifndef HIBYTE
#   define HIBYTE(word) (((word) & 0xFF00) >> 8)
#endif

// opcode indices
enum
{
    OP_ADCA, OP_ADCB, OP_ADDA, OP_ADDB, OP_ADDD, OP_ANDA, OP_ANDB, OP_ASL, 
    OP_ASR, OP_BITA, OP_BITB, OP_CLR, OP_CMPA, OP_CMPB, OP_CMPD, OP_CMPS,
    OP_COM, OP_DEC, OP_EORA, OP_EORB, OP_INC, OP_JMP, OP_JSR, OP_LDA, OP_LDB,
    OP_LDD, OP_LDU, OP_LDX, OP_LEAX, OP_LEAY, OP_LEAS, OP_LEAU, OP_LSL, OP_LSR,
    OP_NEG, OP_ORA, OP_ORB, OP_ROL, OP_ROR, OP_SBCB, OP_SBCA, OP_STA, OP_STB,
    OP_STD, OP_STS, OP_STU, OP_STX, OP_STY, OP_SUBA, OP_SUBB, OP_SUBD, OP_TST,
};

// branch types
typedef enum { BR_SHORT, BR_LONG, BR_LONG_NOPREFIX } BRANCH_TYPE;

typedef struct
{
    FILE *fptr;
    int yylineno;
    int column;
    char *filename;    
} FileNode;

// opcodes for addressing modes
typedef struct
{
    uint8_t ops[4];
} Opcodes;

// symbol types
typedef enum
{
    ST_UNDEF,   // symbol is undefined
    ST_EQU,     // symbol is an EQUate
    ST_SET,     // symbol is a set value
    ST_LABEL,   // symbol is an address label
    ST_STRING   // symbol is a string literal
} SYMBOL_TYPE;

// fixup types
typedef enum
{
    FIXUP_NOCHANGE,
    FIXUP_IMM8,
    FIXUP_IMM16,
    FIXUP_REL8,
    FIXUP_REL16,
    FIXUP_MAX
} FIXUP_TYPE;

// Address mode types
typedef enum
{
    AM_IMM,
    AM_DIRECT,
    AM_INDEXED,
    AM_EXTENDED,
} ADDRESS_MODE_TYPE;

// symbol structure def'n
typedef struct
{
    const char *name;
    int type;
    int value;
    int lineno;
} Symbol_t;

// fixup structure def'n
typedef struct
{
    const char *filename;   // file where fixup resides
    int symbol;             // reference to symbol not yet defined
    int addr;               // address where symbol address is to be patched
    FIXUP_TYPE type;        // type of fixup imm8/16 or rel8/16
    int lineno;             // line number where fixup resides
} Fixup_t;

// token structure def'n
typedef struct 
{
    const char *lexeme;
    int token;
} Tokens;

//-----------------
// function decls
//-----------------
int yylex();
void yyerror(char*);
int add_fixup(int symbol, int addr, FIXUP_TYPE type);

#endif  //__AS_H
