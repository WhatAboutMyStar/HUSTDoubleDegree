; 输入 0～9之间的数码，求其立方
; 书上的例子  P109 , 对程序作了修改, 对于错误输入，直接显示出错信息后，返回

.386
STACK  SEGMENT USE16 STACK
       DB  200 DUP(0)
STACK  ENDS

DATA   SEGMENT  USE16
INPUT  DB  'Please input x (0...9) : $'
TAB    DW  0,1,8,27,64,125,216,343,512,729
XXX    DW  ?
INERR  DB  0DH,0AH,'INPUT ERROR! $'
DATA   ENDS

CODE   SEGMENT  USE16
       ASSUME  CS:CODE,DS:DATA,SS:STACK
BEGIN:
       MOV  AX, DATA
       MOV  DS, AX      
       MOV  DX, OFFSET INPUT
       MOV  AH, 9
       INT  21H
       MOV  AH ,1 
       INT  21H

       CMP  AL,  '0'      ; 判断输入是否合法
       JB   LERR
       CMP  AL, '9'
       JA   LERR

       AND  AL, 0FH       ; 求立方
       MOV  BL, AL
       MOV  BH, 0 
       SAL  BX, 1

       MOV  AX, TAB[BX]  
       MOV  XXX,AX
       JMP  EXIT

LERR:                     ; 显示输入错误信息
       LEA  DX, INERR
       MOV  AH, 9
       INT  21H

EXIT:  MOV  AH, 4CH
       INT  21H
CODE   ENDS

       END  BEGIN
