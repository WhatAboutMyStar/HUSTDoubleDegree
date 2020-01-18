
; 从 BEG (begin) 开始， 求 (COUNT) 个奇数（BEG为奇数）
;                       或偶数（BEG为偶数）的和。
;和存入 SUM 单元中
;求它们的平均数，放到 AVG中。

   ;   NAME    MAIN_MODULE
       EXTRN   SUB_P : FAR       ; 特别注意，此处不是extern
                                 ; 本模块用到外部子程序 SUB_P
       PUBLIC  AVG, COUNT     
               ;本模块中的变量AVG, COUNT 为其它模块所用
DATA1  SEGMENT
BEG    EQU   1
COUNT  DW    50
AVG    DW    0
DATA1  ENDS

STACK SEGMENT PARA STACK 'STACK'
      DB  200 DUP(0)
STACK ENDS

CODE1 SEGMENT PARA 'C1'
      ASSUME  CS:CODE1,SS:STACK,DS:DATA1
START:
      MOV  AX,  DATA1
      MOV  DS,  AX
      MOV  BX,  BEG
      MOV  CX,  COUNT
      CALL SUB_P      ; 调用外部子程序
      MOV  AH,  4CH
      INT  21H
CODE1 ENDS
      END  START