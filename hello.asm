;---------------------------------------------------
; Hello World for the TRS-80 CoCo in MC6809 assembly
;---------------------------------------------------
CHARIN  EQU $A000
CHAROUT EQU $A002
STRING  FCC 'HELLO WORLD!' FCB 0    ; alternatively could use FCZ "HELLO WORLD!"

START
  LDX #STRING    ; get ptr to string

LOOP
  LDA ,X+        ; get next character
  BEQ DONE       ; if null terminator then done

  JSR [CHAROUT]  ; call ROM routine to print out next char
  BRA LOOP       ; do it again

DONE
  JSR [CHARIN]   ; ROM routine to poll keyboard
  BEQ DONE       ; wait for keypress
  SWI            ; quit
END START
