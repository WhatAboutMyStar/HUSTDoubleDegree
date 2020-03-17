; 传送偏移地址指令 P60
; 比较 MOV 指令和LEA指令
.386
DATA  SEGMENT  USE16
BUF   DB  'ABCDEF'
NUM   DW   72,-5,100H
POIN  DW   0
DATA  ENDS

CODE SEGMENT USE16
     ASSUME CS:CODE,DS:DATA
BEGIN: MOV  AX,  DATA
       MOV  DS,  AX
       MOV  ESI, OFFSET  NUM   
       LEA  ESI, NUM
       MOV  AX,  [ESI]
       LEA  AX,  [ESI]
       LEA  DI,  [ESI+4]
;      LEA  POIN, BUF  
       MOV  POIN, OFFSET BUF
       MOV  EBX,  12345678H
       LEA  DX,   [EBX+4321H]
       LEA  EAX,  [EBX+4321H]
       LEA  ECX,  [BX+4321H]
       
       MOV  AX, 4C00H
       INT  21H
CODE  ENDS
      END  BEGIN
             