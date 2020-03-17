       ; 寻址方式举例 
       ; 用  变址寻址方式求 一组数据的和
.386
STACK  SEGMENT  USE16 STACK
       DB 200  DUP(0)
STACK  ENDS

SEG1   SEGMENT USE16
BUF1   DB  1,2,3,4
BUF2   DB  10,20,30,40
RES    DB  ?
SEG1   ENDS

CODE    SEGMENT USE16
        ASSUME  CS:CODE,DS:SEG1,SS:STACK
START:  MOV   AX , SEG1
        MOV   DS , AX
        MOV   BX , 0
        MOV   CX , 4
        MOV   AH , 0
LP:     ADD   AH, BUF2[BX]
        INC   BX
        DEC   CX
        JNE   LP
        MOV   RES,AH
EXIT:   MOV   AX , 4C00H
        INT   21H
CODE  ENDS
        END  START