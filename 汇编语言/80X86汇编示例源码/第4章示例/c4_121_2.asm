     ; 课堂讲解
     ; 将一个无符号字节数转换成10进制形式显示
     ;    例如： 48H, 显示为72
     ;    基本思想： 展转相除，直到商为0
     ; 题中的关键字：无符号        （确定了使用无符号除法指令）
     ;               字节数据      （确定了采用字节运算）
     ;     在定义数据区时，一个字节数的最大值只有3位。
.386
DATA  SEGMENT USE16
BUF     DB 5        ; (48H ==72)  (-1 ==> 255)
OUTPUT DB 3 DUP(?),0DH,0AH,'$'

DATA  ENDS

STACK SEGMENT USE16 STACK
      DB 200 DUP(0)
STACK ENDS

CODE SEGMENT USE16
     ASSUME DS:DATA,CS:CODE,SS:STACK
BEGIN:
     MOV AX,DATA
     MOV DS,AX
     MOV AL,BUF
     MOV SI,OFFSET OUTPUT+2
     MOV CX,0
     MOV BL,10
L1:
     MOV AH,0
     DIV BL
     ADD AH,30H
     MOV [SI],AH
     INC CX
     DEC SI
     CMP AL,0
     JNE L1
     
     LEA DX,OUTPUT
     ADD DX,3
     SUB DX,CX
     MOV AH,9
     INT 21H
     MOV AH,4CH
     INT 21H
CODE ENDS
     END BEGIN

