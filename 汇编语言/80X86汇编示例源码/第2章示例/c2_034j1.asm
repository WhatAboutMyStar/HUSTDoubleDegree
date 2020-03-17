  ;  寻址方式 
  ;  求以BUF为首址的5个字节数据的和
  ;  寄存器间接寻址方式的应用

.386
STACK  SEGMENT  USE16 STACK
       DB 200  DUP(0)
STACK  ENDS

SEG1   SEGMENT USE16
BUF    DB  10,20,30,40,50
RES    DB  ?
SEG1   ENDS

CODE    SEGMENT USE16
        ASSUME  CS:CODE,DS:SEG1,SS:STACK
START:  MOV   AX , SEG1
        MOV   DS , AX
        MOV   BX , OFFSET  BUF
        MOV   CX , 5
        MOV   AH , 0
LP:     ADD   AH, [BX]      ; 指令可否换成 MOV AH,BX
                            ;     注意，换了之后有语法错误
        INC   BX
        DEC   CX
        JNZ   LP
        MOV   RES,AH
EXIT:   MOV   AX , 4C00H
        INT   21H
CODE  ENDS
        END  START