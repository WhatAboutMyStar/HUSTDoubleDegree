;C3_085J1 强调显示的数据在DS:DX中
;C3_085J2 强调以'$'结尾

; 强化 显示字符串 :显示的是DS:DX中的数据
; 在变量T1后，没有'$'
; 在变量T2的中间有'$'
; 看看显示的结果是什么？


STACK SEGMENT STACK
      DB 200 DUP(0)
STACK ENDS

DATA  SEGMENT
T1    DB 'abcdef'
T2    DB  31H,32H,33H,'$',34H,35H
DATA  ENDS   

CODE SEGMENT
     ASSUME CS:CODE,DS:DATA,SS:STACK

BEGIN:MOV AX,DATA
      MOV DS,AX

      LEA DX,T1
      MOV AH,9
      INT 21H
      MOV AH,4CH
      INT 21H
CODE  ENDS
      END BEGIN

