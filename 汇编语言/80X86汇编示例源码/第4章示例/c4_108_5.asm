; 段间转移指令
; 从CODE1 的L1 处，转移到 CODE2的L2处。后又转回CODE1的L3处
.386
STACK  SEGMENT USE16 STACK
       DB  200 DUP(0)
STACK  ENDS

DATA   SEGMENT USE16
BUF1   DB 'good',0DH,0AH,24H
BUF2   DB 'Hello',0DH,0AH,24H
BUF3   DB 'AAAAAAAAAAAAAAAAAAA$'
DATA   ENDS

CODE1   SEGMENT USE16
       ASSUME  CS:CODE1,DS:DATA,SS:STACK
BEGIN:
       MOV  AX, DATA
       MOV  DS, AX      

L1:    JMP  FAR PTR L2

       LEA  DX, BUF3     ; 未执行的代码段
       MOV  AH,9
       INT  21H

L3:    LEA  DX, BUF2
       MOV  Ah, 9
       INT  21H

EXIT:  MOV  AH, 4CH
       INT  21H
CODE1   ENDS

CODE2  segment USE16
       assume  cs:code2
L2:    LEA  DX,BUF1
       MOV  AH,9
       INT  21H
       
       JMP  FAR PTR L3
CODE2  ENDS

       END  BEGIN
