; P86 输入字符串

; (1) 观察输入数据的存放结果 ,验证最多能输入的字符数，验证存放形式
; (2) 将定义的数据区改小，观察输入数据的存放结果
; (3) 介绍等价的数据定义语句

STACK SEGMENT STACK
      DB 200 DUP(0)
STACK ENDS

DATA  SEGMENT
BUF   DB  11
      DB  ?
      DB  11 DUP(0)
DATA  ENDS   

CODE SEGMENT
     ASSUME CS:CODE,DS:DATA,SS:STACK

START:MOV AX,DATA
      MOV DS,AX

      LEA DX,BUF
      MOV AH,10
      INT 21H
      MOV AH,4CH
      INT 21H
CODE  ENDS
      END START

; 将 BUF 的定义改为  DB 20,?,10 dup(0)
;                    DB 1,2,3,4,5,6,7,8