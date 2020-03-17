; C5_180m.asm  为主模块
; C5_180s.asm  为子模块

    ;  NAME    SUB_MODULE
       EXTRN   AVG:WORD,COUNT:WORD
                ;  用到的外部变量
       PUBLIC  SUB_P
                ; 子程序 SUB_P 为外部模块所调用

DATA2  SEGMENT PARA 'A1'
SUM    DW  0     ; 求 1+3+5+...+99 的和，结果为 2500,即 09C4H
DATA2  ENDS

STACK  SEGMENT PARA STACK 'STACK'
       DB  200 DUP(0)
STACK  ENDS

CODE2  SEGMENT PARA 'C1'
       ASSUME CS:CODE2,SS:STACK,ES:DATA2
SUB_P  PROC FAR
       MOV  AX,  DATA2
       MOV  ES,  AX
       MOV  AX,  0
NEXT:  ADD  AX,  BX
       ADD  BX,  2
       LOOP NEXT
       MOV  SUM, AX
       MOV  DX,  0
       DIV  COUNT
       MOV  AVG, AX
       RET
SUB_P  ENDP
CODE2  ENDS
       END
       