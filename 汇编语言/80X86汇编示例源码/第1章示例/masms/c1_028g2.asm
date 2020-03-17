   ;  第一章  P28 的例子的修改
   ;  给出一个汇编源程序的例子
   ;  该程序的写法与do ...while 循环的结构相同
   ;  比c1_028g1.asm  少一条指令
.386
DATA   SEGMENT USE16
       SUM    DW  0
DATA   ENDS

STACK  SEGMENT  USE16 STACK
       DB 200  DUP(0)
STACK  ENDS

CODE    SEGMENT USE16
        ASSUME  CS:CODE,DS:DATA,SS:STACK
BEGIN:  MOV   AX , DATA
        MOV   DS , AX

        MOV   AX ,  0   ;   0-> AX
        MOV   BX ,  1
MAINP:  ADD   AX , BX   
        ADD   BX , 2
        CMP   BX , 100
        JL    MAINP         ;若 (BX)<100，则转到 MAINP

        MOV   SUM , AX
        MOV   AX , 4C00H
        INT   21H
CODE  ENDS
        END  BEGIN