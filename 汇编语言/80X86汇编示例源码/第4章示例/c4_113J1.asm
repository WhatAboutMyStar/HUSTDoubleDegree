   ; 找出BUF数据区中的最大数，并保存在AL中
   ; BX : BUF数据区的下标

.386

DATA SEGMENT USE16 
  BUF  DB -2,5,-3,6,100,0,-20,-9,8,-100,20     
  N    =  $ - BUF
DATA ENDS

STACK SEGMENT USE16 STACK
  DB 200 DUP(0)
STACK ENDS

CODE SEGMENT USE16
  ASSUME CS:CODE, DS:DATA, SS:STACK
BEGIN:
     MOV AX, DATA
     MOV DS, AX
     
     ; 取第1个数，作为起始比较的数
     MOV AL, BUF

     ; 设置计数器，以正计数的方式进行循环控制
     MOV BX, 1
     
L1:  CMP BX, N
     JGE EXIT

     CMP AL, BUF[BX]
     JGE L2
     
     ; 重新设置比较数
     MOV AL, BUF[BX]

L2:  INC BX
     JMP L1

EXIT:
     MOV AH,4CH
     INT 21H
     
CODE ENDS
     END BEGIN
     