;-------------------------
; AS09 assember test file
;-------------------------
START:

;----------------------------
; inherent mode instructions
;----------------------------
    ABX
    ASLA
    ASLB
    ASRA
    ASRB
    CLRA
    CLRB
    COMA
    COMB
    DAA
    DECA
    DECB
    INCA
    INCB
    LSLA
    LSLB
    LSRA
    LSRB
    MUL
    NEGA
    NEGB
    NOP
    ROLA
    ROLB
    RORA
    RORB
    RTI
    RTS
    SEX
    SWI
    SWI2
    SWI3
    SYNC
    TSTA
    TSTB

;-------------------------
; address mode variations
;-------------------------
    ADCA    #$12
    ADCA    $12
    ADCA    $1234
    ADCA    [$1234]

    ADCB    #$12
    ADCB    $12
    ADCB    $1234
    ADCB    [$1234]

    ADDA    #$12
    ADDA    $12
    ADDA    $1234
    ADDA    [$1234]

    ADDB    #$12
    ADDB    $12
    ADDB    $1234
    ADDB    [$1234]

    ADDD    #$1234
    ADDD    $12
    ADDD    $1234
    ADDD    [$1234]

    ANDA    #$12
    ANDA    $12
    ANDA    $1234
    ANDA    [$1234]

    ANDB    #$12
    ANDB    $12
    ANDB    $1234
    ANDB    [$1234]

    ANDCC   #$12

    ASL     $12
    ASL     $1234
    ASL     [$1234]

    ASR     $12
    ASR     $1234
    ASR     [$1234]

    BITA    #$12
    BITA    $12
    BITA    $1234
    BITA    [$1234]

    BITB    #$12
    BITB    $12
    BITB    $1234
    BITB    [$1234]

    CLR     $12
    CLR     $1234
    CLR     [$1234]

    CMPA    #$12
    CMPA    $12
    CMPA    $1234
    CMPA    [$1234]

    CMPB    #$12
    CMPB    $12
    CMPB    $1234
    CMPB    [$1234]

    CMPD    #$1234
    CMPD    $12
    CMPD    $1234
    CMPD    [$1234]

    CMPS    #$1234
    CMPS    $12
    CMPS    $1234
    CMPS    [$1234]

    CMPU    #$1234
    CMPU    $12
    CMPU    $1234
    CMPU    [$1234]

    CMPX    #$1234
    CMPX    $12
    CMPX    $1234
    CMPX    [$1234]

    CMPY    #$1234
    CMPY    $12
    CMPY    $1234
    CMPY    [$1234]

    COM     $12
    COM     $1234
    COM     [$1234]

    CWAI    #$FF

    DEC     $12
    DEC     $1234
    DEC     [$1234]

    EORA    #$12
    EORA    $12
    EORA    $1234
    EORA    [$1234]

    EORB    #$12
    EORB    $12
    EORB    $1234
    EORB    [$1234]

    INC     $12
    INC     $1234
    INC     [$1234]

    JMP     $12
    JMP     $1234
    JMP     [$1234]

    JSR     $12
    JSR     $1234
    JSR     [$1234]

    LDA     #$12
    LDA     $12
    LDA     $1234
    LDA     [$1234]

    LDB     #$12
    LDB     $12
    LDB     $1234
    LDB     [$1234]

    LDD     #$1234
    LDD     $12
    LDD     $1234
    LDD     [$1234]

    LDS     #$1234
    LDS     $12
    LDS     $1234
    LDS     [$1234]

    LDU     #$1234
    LDU     $12
    LDU     $1234
    LDU     [$1234]

    LDX     #$1234
    LDX     $12
    LDX     $1234
    LDX     [$1234]

    LDY     #$1234
    LDY     $12
    LDY     $1234
    LDY     [$1234]

    LEAS    ,S
    LEAU    1,U
    LEAX    -1,X
    LEAY    1,Y

    LSL     $12
    LSL     $1234
    LSL     [$1234]

    LSR     $12
    LSR     $1234
    LSR     [$1234]

    NEG     $12
    NEG     $1234
    NEG     [$1234]

    ORA     #$12
    ORA     $12
    ORA     $1234
    ORA     [$1234]

    ORB     #$12
    ORB     $12
    ORB     $1234
    ORB     [$1234]

    ORCC    #$12

    ROL     $12
    ROL     $1234
    ROL     [$1234]

    ROR     $12
    ROR     $1234
    ROR     [$1234]

    SBCA    #$12
    SBCA    $12
    SBCA    $1234
    SBCA    [$1234]

    SBCB    #$12
    SBCB    $12
    SBCB    $1234
    SBCB    [$1234]

    STA     $12
    STA     $1234
    STA     [$1234]

    STB     $12
    STB     $1234
    STB     [$1234]

    STD     $12
    STD     $1234
    STD     [$1234]

    STS     $12
    STS     $1234
    STS     [$1234]

    STU     $12
    STU     $1234
    STU     [$1234]

    STX     $12
    STX     $1234
    STX     [$1234]

    STY     $12
    STY     $1234
    STY     [$1234]

    SUBA    #$12
    SUBA    $12
    SUBA    $1234
    SUBA    [$1234]

    SUBB    #$12
    SUBB    $12
    SUBB    $1234
    SUBB    [$1234]

    SUBD    #$1234
    SUBD    $12
    SUBD    $1234
    SUBD    [$1234]

    TST     $12
    TST     $1234
    TST     [$1234]

;--------------------------------
; register movement instructions
;--------------------------------

    EXG     A,B
    EXG     X,Y
    TFR     A,B
    TFR     S,U

;--------------------
; stack instructions
;--------------------

    PSHS    A,B,CC,DP,U,X,Y,PC
    PSHU    CC,D,DP,S,X,Y,PC
    PULS    CC,D,DP,U,X,Y,PC
    PULU    A,B,CC,DP,S,X,Y,PC

;---------------------
; branch instructions
;---------------------

BACK:
    BCC     BACK
    BCS     FORWARD
    BEQ     BACK
    BGE     FORWARD
    BGT     BACK
    BHI     FORWARD
    BHS     BACK
    BLE     FORWARD
    BLO     BACK
    BLS     FORWARD
    BLT     BACK
    BMI     FORWARD
    BNE     BACK
    BPL     FORWARD
    BRA     BACK
    BRN     FORWARD
    BSR     BACK
    BVC     FORWARD
    BVS     BACK
FORWARD:

LBRANCH:
    LBCC    LBRANCH
    LBCS    LBRANCH
    LBEQ    LBRANCH
    LBGE    LBRANCH
    LBGT    LBRANCH
    LBHI    LBRANCH
    LBHS    LBRANCH
    LBLE    LBRANCH
    LBLO    LBRANCH
    LBLS    LBRANCH
    LBLT    LBRANCH
    LBMI    LBRANCH
    LBNE    LBRANCH
    LBPL    LBRANCH
    LBRA    LBRANCH
    LBRN    LBRANCH
    LBSR    LBRANCH
    LBVC    LBRANCH
    LBVS    LBRANCH

;--------------------
; indexed addressing
;--------------------
    ADDA    ,X
    ADDA    ,X+
    ADDA    ,X++
    ADDA    ,-X
    ADDA    ,--X
    ADDA    $9,X
    ADDA    -$9,X
    ADDA    $78,X
    ADDA    -$78,X
    ADDA    $1234,X
    ADDA    -$1234,X

    ADDA    ,Y
    ADDA    ,Y+
    ADDA    ,Y++
    ADDA    ,-Y
    ADDA    ,--Y
    ADDA    $9,Y
    ADDA    -$9,Y
    ADDA    $78,Y
    ADDA    -$78,Y
    ADDA    $1234,Y
    ADDA    -$1234,Y

    ADDA    ,U
    ADDA    ,U++
    ADDA    ,-U
    ADDA    ,--U
    ADDA    $9,U
    ADDA    -$9,U
    ADDA    $78,U
    ADDA    -$78,U
    ADDA    $1234,U
    ADDA    -$1234,U

    ADDA    ,S
    ADDA    ,S++
    ADDA    ,-S
    ADDA    ,--S
    ADDA    $9,S
    ADDA    -$9,S
    ADDA    $78,S
    ADDA    -$78,S
    ADDA    $1234,S
    ADDA    -$1234,S

    ADDA    [,X]
    ADDA    [,X++]
    ADDA    [,--X]
    ADDA    [$9,X]
    ADDA    [-$9,X]
    ADDA    [$78,X]
    ADDA    [-$78,X]
    ADDA    [$1234,X]
    ADDA    [-$1234,X]

    ADDA    [,Y]
    ADDA    [,Y++]
    ADDA    [,--Y]
    ADDA    [$9,Y]
    ADDA    [-$9,Y]
    ADDA    [$78,Y]
    ADDA    [-$78,Y]
    ADDA    [$1234,Y]
    ADDA    [-$1234,Y]

    ADDA    [,U]
    ADDA    [,--U]
    ADDA    [$9,U]
    ADDA    [-$9,U]
    ADDA    [$78,U]
    ADDA    [-$78,U]
    ADDA    [$1234,U]
    ADDA    [-$1234,U]

    ADDA    [,S]
    ADDA    [,--S]
    ADDA    [$9,S]
    ADDA    [-$9,S]
    ADDA    [$78,S]
    ADDA    [-$78,S]
    ADDA    [$1234,S]
    ADDA    [-$1234,S]

    ADDA    A,X
    ADDA    B,Y
    ADDA    D,U
    ADDA    A,S

    ADDA    [A,X]
    ADDA    [B,Y]
    ADDA    [D,U]
    ADDA    [A,S]

    LDA     $1234,PCR
    LDA     -$1234,PCR
 
    LDA     [$1234,PCR]
    LDA     [-$1234,PCR]
   
    END START
