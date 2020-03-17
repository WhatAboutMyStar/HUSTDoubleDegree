READ  MACRO  A
      LEA  DX, A
      MOV  AH, 10
      INT  21H
      ENDM

WRITE  MACRO  A
      LEA  DX, A
      MOV  AH, 9
      INT  21H
      ENDM

CRLF  MACRO  
      MOV  AH, 2
      MOV  DL, 0AH
      INT  21H
      MOV  DL, 0DH
      INT  21H
      ENDM

OUT1  MACRO  A
      MOV  DL, A
      MOV  AH, 2
      INT  21H
      ENDM

STACK0 MACRO  A
STACK  SEGMENT  PARA STACK 'STACK'
       DB   A
STACK  ENDS
       ENDM

test_s segment
xx     db '10'
test_s ends
