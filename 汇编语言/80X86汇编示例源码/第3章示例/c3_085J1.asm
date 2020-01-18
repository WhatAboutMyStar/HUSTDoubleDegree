;c3_085J1 强调显示的数据在DS:DX中
;C3_085J2 强调以'$'结尾

; 强化显示字符串 :显示的是DS:DX中的数据
; 设置两个段，一个做为数据段，一个作为附加段，
; 看看显示的结果是什么？
; 点评：DX设置的是T2有效地址，实际的显示内容为T1中的数据。

STACK SEGMENT STACK
      DB 200 DUP(0)
STACK ENDS

DATA1 SEGMENT
T1    DB 'abcdef',0dh,0ah,'$'
DATA1 ENDS   

DATA2 SEGMENT
T2    DB '012345678',0dh,0ah,'$'
DATA2 ENDS   

CODE SEGMENT
     ASSUME CS:CODE,DS:DATA1,ES:DATA2,SS:STACK

BEGIN:MOV AX,DATA1
      MOV DS,AX
      MOV BX,DATA2
      MOV ES,BX

      LEA DX,T2
      MOV AH,9
      INT 21H
      MOV AH,4CH
      INT 21H
CODE  ENDS
      END BEGIN

