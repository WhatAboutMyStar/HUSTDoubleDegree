; 循环次数未知的程序设计
; 以BUF为首址的字节存储区中，存放以'$'作结束标志的字符串。
; 显示该串，并要求将其中的小写字母转换成大写字母显示。
; p118

.386
STACK SEGMENT USE16 STACK
      DB 200 DUP(0)
STACK ENDS

DATA SEGMENT USE16
BUF  DB 'add ax,bx sub cx,10  mov dx,1234h END$'
DATA ENDS
CODE SEGMENT USE16
     ASSUME CS:CODE,DS:DATA,SS:STACK
BEGIN:
     MOV AX, DATA
     MOV DS, AX
     LEA BX, BUF
LOPA:MOV DL,[BX]
     CMP DL,'$'
     JE  EXIT
     CMP DL, 'a'
     JB  N
     CMP DL, 'z'
     JA  N
     SUB DL, 20H
N:   MOV AH, 2
     INT 21H
     INC BX
     JMP LOPA
EXIT:MOV AH,4CH
     INT 21H
CODE ENDS
     END BEGIN
