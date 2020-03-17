; ºê¿âµÄÊ¹ÓÃ

      INCLUDE  C5_172.asm
DATA  SEGMENT
BUF   DB  80, 0, 80 DUP(0)
DATA  ENDS

STACK0 < 200 DUP(0) >

CODE SEGMENT
     ASSUME  CS:CODE,DS:DATA,SS:STACK
START:
     MOV   AX, DATA
     MOV   DS, AX
     READ  BUF
     CRLF
     LEA   SI, BUF+2
     MOV   CL, BUF+1
     MOV   CH, 0
     CLD
Y1:  LODSB
     CMP  AL, 'a'
     JB   Y2
     CMP  AL, 'z'
     JA   Y2
     SUB   AL,  20H
Y2:  OUT1  AL
     LOOP  Y1
     CRLF
     MOV  AH,4CH
     INT  21H
CODE ENDS
     END  START
