//================================================================================
// as09 - an MC6809E cross-assember
//
// See LICENSE file for usage rights and obligations
//================================================================================

%{
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

%}

%union 
{
    int ival;
    int symbol;
    char *lexeme;
}

%right '!' '~'
%left '&' '|'
%left '+' '-'
%left '*' '/'

%token EQU INCLUDE SET
%token <symbol> ID STRING
%token <ival> CHAR
%token <ival> ABX ASLA ASLB ASRA ASRB CLRA CLRB COMA COMB CWAI DAA DECA DECB INCA INCB LSLA LSLB LSRA LSRB
%token <ival> MUL NEGA NEGB NOP ROLA ROLB RORA RORB RTI RTS SEX SWI SWI2 SWI3 SYNC TSTA TSTB TST
%token <ival> ADCA ADCB ADDA ADDB ADDD ANDA ANDB ANDCC ASL ASR BCC BCS BEQ BGE BGT BHI BHS BITA BITB BLE
%token <ival> BLO BLS BLT BMI BNE BPL BRA BRN BSR BVC BVS CLR CMPA CMPB CMPD CMPS CMPU CMPX CMPY COM
%token <ival> DEC EORA EORB EXG INC JMP JSR TFR
%token <ival> LBCC LBCS LBEQ LBGE LBGT LBHI LBHS LBLE LBLO LBLS LBLT LBMI LBNE LBPL LBRA LBRN LBSR LBVC LBVS
%token <ival> LDA LDB LDD LDS LDU LDX LDY LEAX LEAY LEAS LEAU LSL LSR NEG ORA ORB ORCC PSHS PSHU PULS PULU
%token <ival> SBCA SBCB ROL ROR STA STB STD STX STY STS STU SUBA SUBB SUBD
%token <ival> NUMBER A B D X Y U S PC CC DP PCR
%token <ival> SETDP ORG FCB FDB FCC RMB END FCZ
%token <ival> SETC CLRC SETZ CLRZ

%type <ival> register index_register accumulator imm8 imm16 op8 op16 push_registers push_register
%type <ival> direct_indexed_extended indexed words bytes byte_expr word_expr const_expr
%type <symbol> strings

%%

file: lines end
    ;

end:
    | END
    | END ID    { if (symbols[$2].type != ST_LABEL) yyerror("undefined label"); symbols[$2].refd++; start_addr = /*origin_addr +*/ symbols[$2].value; LOG("start addr set to '%s' ($%04X)\n", symbols[$2].name, start_addr);}
    ;

lines:
    | lines line        { yyerrok; }
    ;

line: label
    | instruction       { fixup_pending_index = FP_NONE; }
    | ID EQU word_expr  { if (symbols[$1].type != ST_UNDEF) yyerror("equate already defined"); symbols[$1].value = $3; symbols[$1].type = ST_EQU; }
    | ID SET word_expr  { symbols[$1].value = $3; symbols[$1].type = ST_SET; }
    | INCLUDE STRING    { push_file_stack(symbols[$2].name); symbols[$2].refd++;}
    ;

label: ID    { if (symbols[$1].type != ST_UNDEF) yyerror("label already defined"); symbols[$1].value = origin_addr + addr; symbols[$1].type = ST_LABEL; }
    ;

byte_expr: imm8
    | byte_expr '+' byte_expr   { if ($1 == SA_UNDEF || $3 == SA_UNDEF) yyerror("cannot eval expr on forward refs"); $$ = $1 + $3; }
    | byte_expr '-' byte_expr   { if ($1 == SA_UNDEF || $3 == SA_UNDEF) yyerror("cannot eval expr on forward refs"); $$ = $1 - $3; }
    | byte_expr '*' byte_expr   { if ($1 == SA_UNDEF || $3 == SA_UNDEF) yyerror("cannot eval expr on forward refs"); $$ = $1 * $3; }
    | byte_expr '/' byte_expr   { if ($1 == SA_UNDEF || $3 == SA_UNDEF) yyerror("cannot eval expr on forward refs"); $$ = $1 / $3; }
    | byte_expr '&' byte_expr   { if ($1 == SA_UNDEF || $3 == SA_UNDEF) yyerror("cannot eval expr on forward refs"); $$ = $1 & $3; }
    | byte_expr '|' byte_expr   { if ($1 == SA_UNDEF || $3 == SA_UNDEF) yyerror("cannot eval expr on forward refs"); $$ = $1 | $3; }
    | '~' byte_expr             { if ($2 == SA_UNDEF) yyerror("cannot eval expr on forward refs"); $$ = ~$2;}
    | '(' byte_expr ')'         { if ($2 == SA_UNDEF) yyerror("cannot eval expr on forward refs"); $$ = $2; }
    ;

word_expr: imm16
    | '*'                       { $$ = addr + origin_addr; }
    | word_expr '+' word_expr   { if ($1 == SA_UNDEF || $3 == SA_UNDEF) yyerror("cannot eval expr on forward refs"); $$ = $1 + $3; }
    | word_expr '-' word_expr   { if ($1 == SA_UNDEF || $3 == SA_UNDEF) yyerror("cannot eval expr on forward refs"); $$ = $1 - $3; }
    | word_expr '*' word_expr   { if ($1 == SA_UNDEF || $3 == SA_UNDEF) yyerror("cannot eval expr on forward refs"); $$ = $1 * $3; }
    | word_expr '/' word_expr   { if ($1 == SA_UNDEF || $3 == SA_UNDEF) yyerror("cannot eval expr on forward refs"); $$ = $1 / $3; }
    | word_expr '&' word_expr   { if ($1 == SA_UNDEF || $3 == SA_UNDEF) yyerror("cannot eval expr on forward refs"); $$ = $1 & $3; }
    | word_expr '|' word_expr   { if ($1 == SA_UNDEF || $3 == SA_UNDEF) yyerror("cannot eval expr on forward refs"); $$ = $1 | $3; }
    | '~' word_expr             { if ($2 == SA_UNDEF) yyerror("cannot eval expr on forward refs"); $$ = ~$2;}
    | '(' word_expr ')'         { if ($2 == SA_UNDEF) yyerror("cannot eval expr on forward refs");$$ = $2; }
    ;

const_expr: NUMBER
    | ID                            { if (symbols[$1].type != ST_EQU && symbols[$1].type != ST_SET) yyerror("non const in const expr"); $$ = symbols[$1].value; symbols[$1].refd++;}
    | const_expr '+' const_expr     { $$ = $1 + $3; }
    | const_expr '-' const_expr     { $$ = $1 - $3; }
    | const_expr '*' const_expr     { $$ = $1 * $3; }
    | const_expr '/' const_expr     { $$ = $1 / $3; }
    | const_expr '&' const_expr     { $$ = $1 & $3; }
    | const_expr '|' const_expr     { $$ = $1 | $3; }
    | '(' const_expr ')'            { $$ = $2; }
    ;

imm8: NUMBER    { if (HIBYTE($1) && ($1 < -128 || $1 > 127)) yyerror("byte value expected"); $$ = LOBYTE($1); }
    | CHAR
    | ID        { if (symbols[$1].type == ST_UNDEF) { fixup_pending_index = add_fixup($1, addr + 1, FIXUP_IMM8); $$ = SA_UNDEF; } else $$ = symbols[$1].value; symbols[$1].refd++;}
    ;

imm16: NUMBER
    | ID        { if (symbols[$1].type == ST_UNDEF) { fixup_pending_index = add_fixup($1, addr + 1, FIXUP_IMM16); $$ = SA_UNDEF; } else $$ = symbols[$1].value; symbols[$1].refd++;}
    ;

op8: '#' byte_expr                      { emit_buf($2); $$ = AM_IMM; }
    | direct_indexed_extended
    ;

op16: '#' word_expr                     { emit_buf_word($2); $$ = AM_IMM; }
    | direct_indexed_extended
    ;

direct_indexed_extended: word_expr      { if (SA_UNDEF != $1 && direct_page_addr == HIBYTE($1)) { emit_buf(LOBYTE($1)); $$ = AM_DIRECT; } else { emit_buf_word($1); $$ = AM_EXTENDED; } }
    | '>' word_expr                     { emit_buf_word($2); $$ = AM_EXTENDED; }
    | '<' word_expr                     { if (HIBYTE($2) == direct_page_addr) { emit_buf(LOBYTE($2)); $$ = AM_DIRECT; } else yyerror("Direct page mismatch"); }
    | '[' word_expr ']'                 { emit_buf(0x9F); emit_buf_word($2); adjust_fixup(FIXUP_IMM16, 2); $$ = AM_INDEXED; }
    | indexed
    ;

indexed: ',' index_register                 { emit_buf(0x84 | ($2 << 5)); $$ = AM_INDEXED; }
    | '[' ',' index_register ']'            { emit_buf(0x94 | ($3 << 5)); $$ = AM_INDEXED; }
    | const_expr ',' index_register             { constant_offset_direct($1, $3); $$ = AM_INDEXED; }
    | '[' const_expr ',' index_register ']'     { constant_offset_indirect($2, $4); $$ = AM_INDEXED; }
    | accumulator ',' index_register        { accumulator_offset_direct($1, $3); $$ = AM_INDEXED; }
    | '[' accumulator ',' index_register ']'    { accumulator_offset_indirect($2, $4); $$ = AM_INDEXED; }
    | ',' index_register '+'                { emit_buf(0x80 | ($2 << 5)); $$ = AM_INDEXED; }
    | ',' index_register '+' '+'            { emit_buf(0x81 | ($2 << 5)); $$ = AM_INDEXED; }
    | ',' '-' index_register                { emit_buf(0x82 | ($3 << 5)); $$ = AM_INDEXED; }
    | ',' '-' '-' index_register            { emit_buf(0x83 | ($4 << 5)); $$ = AM_INDEXED; }
    | '[' ',' '-' '-' index_register ']'    { emit_buf(0x93 | ($5 << 5)); $$ = AM_INDEXED; }
    | '[' ',' index_register '+' '+' ']'    { emit_buf(0x91 | ($3 << 5)); $$ = AM_INDEXED; }
    | const_expr ',' PCR                        { pcr_direct($1); $$ = AM_INDEXED; }
    | '[' const_expr ',' PCR ']'                { pcr_indirect($2); $$ = AM_INDEXED; }
    ;

instruction: ABX    { emit(0x3A); }
    | ASLA          { emit(0x48); }
    | ASLB          { emit(0x58); }
    | ASRA          { emit(0x47); }
    | ASRB          { emit(0x57); }
    | CLRA          { emit(0x4F); }
    | CLRB          { emit(0x5F); }
    | COMA          { emit(0x43); }
    | COMB          { emit(0x53); }
    | DAA           { emit(0x19); }
    | DECA          { emit(0x4A); }
    | DECB          { emit(0x5A); }
    | INCA          { emit(0x4C); }
    | INCB          { emit(0x5C); }
    | LSLA          { emit(0x48); }
    | LSLB          { emit(0x58); }
    | LSRA          { emit(0x44); }
    | LSRB          { emit(0x54); }
    | MUL           { emit(0x3D); }
    | NEGA          { emit(0x40); }
    | NEGB          { emit(0x50); }
    | NOP           { emit(0x12); }
    | ROLA          { emit(0x49); }
    | ROLB          { emit(0x59); }
    | RORA          { emit(0x46); }
    | RORB          { emit(0x56); }
    | RTI           { emit(0x3B); }
    | RTS           { emit(0x39); }
    | SEX           { emit(0x1D); }
    | SWI           { emit(0x3F); }
    | SWI2          { emit(0x10); emit(0x3F); }
    | SWI3          { emit(0x11); emit(0x3F); }
    | SYNC          { emit(0x13); }
    | TSTA          { emit(0x4D); }
    | TSTB          { emit(0x5D); }

    | ADCA op8  { emit(opcodes[OP_ADCA].ops[$2]); write_inb(); }
    | ADCB op8  { emit(opcodes[OP_ADCB].ops[$2]); write_inb(); }
    | ADDA op8  { emit(opcodes[OP_ADDA].ops[$2]); write_inb(); }
    | ADDB op8  { emit(opcodes[OP_ADDB].ops[$2]); write_inb(); }
    | ADDD op16 { emit(opcodes[OP_ADDD].ops[$2]); write_inb(); }
    | ANDA op8  { emit(opcodes[OP_ANDA].ops[$2]); write_inb(); }
    | ANDB op8  { emit(opcodes[OP_ANDB].ops[$2]); write_inb(); }
    | ANDCC '#' byte_expr { emit(0x1C); emit(LOBYTE($3)); }
    | CLRC      { emit(0x1C); emit(0xFE); }
    | CLRZ      { emit(0x1C); emit(0xFB); }
    | ASL direct_indexed_extended   { emit(opcodes[OP_ASL].ops[$2]); write_inb(); }
    | ASR direct_indexed_extended   { emit(opcodes[OP_ASR].ops[$2]); write_inb(); }
    | BITA op8  { emit(opcodes[OP_BITA].ops[$2]); write_inb(); }
    | BITB op8  { emit(opcodes[OP_BITB].ops[$2]); write_inb(); }
    | BCC imm16  { rel_branch(BR_SHORT, 0x24, $2); }
    | BCS imm16  { rel_branch(BR_SHORT, 0x25, $2); }
    | BEQ imm16  { rel_branch(BR_SHORT, 0x27, $2); }
    | BGE imm16  { rel_branch(BR_SHORT, 0x2C, $2); }
    | BGT imm16  { rel_branch(BR_SHORT, 0x2E, $2); }
    | BHI imm16  { rel_branch(BR_SHORT, 0x22, $2); }
    | BHS imm16  { rel_branch(BR_SHORT, 0x24, $2); }
    | BLE imm16  { rel_branch(BR_SHORT, 0x2F, $2); }
    | BLO imm16  { rel_branch(BR_SHORT, 0x25, $2); }
    | BLS imm16  { rel_branch(BR_SHORT, 0x23, $2); }
    | BLT imm16  { rel_branch(BR_SHORT, 0x2D, $2); }
    | BMI imm16  { rel_branch(BR_SHORT, 0x2B, $2); }
    | BNE imm16  { rel_branch(BR_SHORT, 0x26, $2); }
    | BPL imm16  { rel_branch(BR_SHORT, 0x2A, $2); }
    | BRA imm16  { rel_branch(BR_SHORT, 0x20, $2); }
    | BRN imm16  { rel_branch(BR_SHORT, 0x21, $2); }
    | BSR imm16  { rel_branch(BR_SHORT, 0x8D, $2); }
    | BVC imm16  { rel_branch(BR_SHORT, 0x28, $2); }
    | BVS imm16  { rel_branch(BR_SHORT, 0x29, $2); }
    | CLR direct_indexed_extended   { emit(opcodes[OP_CLR].ops[$2]); write_inb(); }
    | CMPA op8  { emit(opcodes[OP_CMPA].ops[$2]); write_inb(); }
    | CMPB op8  { emit(opcodes[OP_CMPB].ops[$2]); write_inb(); }
    | CMPD op16 { emit(0x10); emit(opcodes[OP_CMPD].ops[$2]); write_inb(); adjust_fixup(FIXUP_NOCHANGE, 1); }
    | CMPS op16 { emit(0x11); emit(opcodes[OP_CMPS].ops[$2]); write_inb(); adjust_fixup(FIXUP_NOCHANGE, 1); }
    | CMPU op16 { emit(0x11); emit(opcodes[OP_CMPD].ops[$2]); write_inb(); adjust_fixup(FIXUP_NOCHANGE, 1); }
    | CMPX op16 { emit(opcodes[OP_CMPS].ops[$2]); write_inb(); }
    | CMPY op16 { emit(0x10); emit(opcodes[OP_CMPS].ops[$2]); write_inb(); adjust_fixup(FIXUP_NOCHANGE, 1); }
    | COM direct_indexed_extended   { emit(opcodes[OP_COM].ops[$2]); write_inb(); }
    | CWAI op8  { emit(0x3C); write_inb(); }
    | DEC direct_indexed_extended   { emit(opcodes[OP_DEC].ops[$2]); write_inb(); }
    | EORA op8  { emit(opcodes[OP_EORA].ops[$2]); write_inb(); }
    | EORB op8  { emit(opcodes[OP_EORB].ops[$2]); write_inb(); }
    | EXG register ',' register { emit(0x1E); emit(($2 << 4) | $4); }
    | INC direct_indexed_extended   { emit(opcodes[OP_INC].ops[$2]); write_inb(); }
    | JMP direct_indexed_extended   { emit(opcodes[OP_JMP].ops[$2]); write_inb(); }
    | JSR direct_indexed_extended   { emit(opcodes[OP_JSR].ops[$2]); write_inb(); }
    | LBCC imm16    { rel_branch(BR_LONG, 0x24, $2); }
    | LBCS imm16    { rel_branch(BR_LONG, 0x25, $2); }
    | LBEQ imm16    { rel_branch(BR_LONG, 0x27, $2); }
    | LBGE imm16    { rel_branch(BR_LONG, 0x2C, $2); }
    | LBGT imm16    { rel_branch(BR_LONG, 0x2E, $2); }
    | LBHI imm16    { rel_branch(BR_LONG, 0x22, $2); }
    | LBHS imm16    { rel_branch(BR_LONG, 0x24, $2); }
    | LBLE imm16    { rel_branch(BR_LONG, 0x2F, $2); }
    | LBLO imm16    { rel_branch(BR_LONG, 0x25, $2); }
    | LBLS imm16    { rel_branch(BR_LONG, 0x23, $2); }
    | LBLT imm16    { rel_branch(BR_LONG, 0x2D, $2); }
    | LBMI imm16    { rel_branch(BR_LONG, 0x2B, $2); }
    | LBNE imm16    { rel_branch(BR_LONG, 0x26, $2); }
    | LBPL imm16    { rel_branch(BR_LONG, 0x2A, $2); }
    | LBRA imm16    { rel_branch(BR_LONG_NOPREFIX, 0x16, $2); }
    | LBRN imm16    { rel_branch(BR_LONG, 0x21, $2); }
    | LBSR imm16    { rel_branch(BR_LONG_NOPREFIX, 0x17, $2); }
    | LBVC imm16    { rel_branch(BR_LONG, 0x28, $2); }
    | LBVS imm16    { rel_branch(BR_LONG, 0x29, $2); }
    | LDA op8       { emit(opcodes[OP_LDA].ops[$2]); write_inb(); }
    | LDB op8       { emit(opcodes[OP_LDB].ops[$2]); write_inb(); }
    | LDD op16      { emit(opcodes[OP_LDD].ops[$2]); write_inb(); }
    | LDU op16      { emit(opcodes[OP_LDU].ops[$2]); write_inb(); }
    | LDS op16      { emit(0x10); emit(opcodes[OP_LDU].ops[$2]); write_inb(); adjust_fixup(FIXUP_NOCHANGE, 1);}
    | LDX op16      { emit(opcodes[OP_LDX].ops[$2]); write_inb(); }
    | LDY op16      { emit(0x10); emit(opcodes[OP_LDX].ops[$2]); write_inb(); adjust_fixup(FIXUP_NOCHANGE, 1); }
    | LEAX indexed  { emit(opcodes[OP_LEAX].ops[$2]); write_inb(); }
    | LEAY indexed  { emit(opcodes[OP_LEAY].ops[$2]); write_inb(); }
    | LEAS indexed  { emit(opcodes[OP_LEAS].ops[$2]); write_inb(); }
    | LEAU indexed  { emit(opcodes[OP_LEAU].ops[$2]); write_inb(); }
    | LSL direct_indexed_extended   { emit(opcodes[OP_LSL].ops[$2]); write_inb(); }
    | LSR direct_indexed_extended   { emit(opcodes[OP_LSR].ops[$2]); write_inb(); }
    | NEG direct_indexed_extended   { emit(opcodes[OP_NEG].ops[$2]); write_inb(); }
    | ORA op8                       { emit(opcodes[OP_ORA].ops[$2]); write_inb(); }
    | ORB op8                       { emit(opcodes[OP_ORB].ops[$2]); write_inb(); }
    | ORCC '#' byte_expr            { emit(0x1A); emit(LOBYTE($3)); }
    | SETZ                          { emit(0x1A); emit(4); }
    | SETC                          { emit(0x1A); emit(1); }
    | PSHS push_registers           { emit(0x34); emit($2); }
    | PSHU push_registers           { emit(0x36); emit($2); }
    | PULS push_registers           { emit(0x35); emit($2); }
    | PULU push_registers           { emit(0x37); emit($2); }
    | ROL direct_indexed_extended   { emit(opcodes[OP_ROL].ops[$2]); write_inb(); }
    | ROR direct_indexed_extended   { emit(opcodes[OP_ROR].ops[$2]); write_inb(); }
    | SBCA op8                      { emit(opcodes[OP_SBCA].ops[$2]); write_inb(); }
    | SBCB op8                      { emit(opcodes[OP_SBCB].ops[$2]); write_inb(); }
    | STA direct_indexed_extended   { emit(opcodes[OP_STA].ops[$2]); write_inb(); }
    | STB direct_indexed_extended   { emit(opcodes[OP_STB].ops[$2]); write_inb(); }
    | STD direct_indexed_extended   { emit(opcodes[OP_STD].ops[$2]); write_inb(); }
    | STS direct_indexed_extended   { emit(0x10); emit(opcodes[OP_STS].ops[$2]); write_inb(); adjust_fixup(FIXUP_NOCHANGE, 1); }
    | STU direct_indexed_extended   { emit(opcodes[OP_STU].ops[$2]); write_inb(); }
    | STX direct_indexed_extended   { emit(opcodes[OP_STX].ops[$2]); write_inb(); }
    | STY direct_indexed_extended   { emit(0x10); emit(opcodes[OP_STY].ops[$2]); write_inb(); adjust_fixup(FIXUP_NOCHANGE, 1); }
    | SUBA op8                      { emit(opcodes[OP_SUBA].ops[$2]); write_inb(); }
    | SUBB op8                      { emit(opcodes[OP_SUBB].ops[$2]); write_inb(); }
    | SUBD op16                     { emit(opcodes[OP_SUBD].ops[$2]); write_inb(); }
    | TFR register ',' register     { emit(0x1F); emit(($2 << 4) | $4); }
    | TST op8                       { emit(opcodes[OP_TST].ops[$2]); write_inb(); }

    | SETDP byte_expr   { direct_page_addr = $2; LOG("DP set to $%02X\n", direct_page_addr); }
    | ORG NUMBER        { if (origin_addr != 0) yyerror("origin already set"); start_addr = origin_addr = $2; LOG("ORG set to $%04X\n", origin_addr); }
    | FCB bytes
    | FDB words         {  }
    | FCC strings
    | FCZ strings       { emit(0); }
    | RMB const_expr    { addr += $2; }
    ;

strings: STRING             { symbols[$$].type = ST_STRING; emit_str(symbols[$$].name); }
    | strings ',' STRING    { symbols[$3].type = ST_STRING; emit_str(symbols[$3].name); }
    ;

bytes: byte_expr               { if ($$ > 255) yyerror("byte value expected"); emit(LOBYTE($$)); }
    | bytes ',' byte_expr      { if ($3 > 255) yyerror("byte value expected"); emit(LOBYTE($3)); }
    ;

words: word_expr             { adjust_fixup(FIXUP_NOCHANGE, -1); emit_word($$); }
    | words ',' word_expr    { adjust_fixup(FIXUP_NOCHANGE, -1); emit_word($3); }
    ;

push_registers: push_register
    | push_registers ',' push_register  { $$ = $1 | $3; }
    ;

push_register: CC   { $$ = 1; }
    | A     { $$ = 2; }
    | B     { $$ = 4; }
    | D     { $$ = 6; }
    | DP    { $$ = 8; }
    | X     { $$ = 16; }
    | Y     { $$ = 32; }
    | S     { $$ = 64; }
    | U     { $$ = 64; }
    | PC    { $$ = 128; }

register: D     { $$ = 0;}
    | X         { $$ = 1;}
    | Y         { $$ = 2;}
    | U         { $$ = 3;}
    | S         { $$ = 4;}
    | PC        { $$ = 5;}
    | A         { $$ = 8;}
    | B         { $$ = 9;}
    | CC        { $$ = 10;}
    | DP        { $$ = 11;}
    ;

index_register: X   { $$ = 0; }
    | Y             { $$ = 1; }
    | U             { $$ = 2; }
    | S             { $$ = 3; }
    ;

accumulator: A  { $$ = 0; }
    | B         { $$ = 1; }
    | D         { $$ = 2; }
    ;

%%

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
