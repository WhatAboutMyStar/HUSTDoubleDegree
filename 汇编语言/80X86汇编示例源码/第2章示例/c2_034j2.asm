  ;  寻址方式 
  ;  求以BUF为首址的5个字数据的和
  ;  寄存器间接寻址方式的应用
.386
STACK  SEGMENT  USE16 STACK
       DB 200  DUP(0)
STACK  ENDS

DATA   SEGMENT USE16
BUF    DW  10,20,30,40,50
RES    DW  ?
DATA   ENDS

CODE    SEGMENT USE16
        ASSUME  CS:CODE,DS:DATA,SS:STACK
START:  MOV   AX , DATA
        MOV   DS , AX
        MOV   BX , OFFSET  BUF
        MOV   CX , 5
        MOV   AX , 0
LP:     ADD   AX, [BX]      ; 指令可否换成 MOV AX,BX
                            ; 程序的运行结果是什么？
        INC   BX
        INC   BX
        DEC   CX
        JNZ   LP
        MOV   RES,AX
EXIT:   MOV   AX , 4C00H
        INT   21H
CODE  ENDS
        END  START