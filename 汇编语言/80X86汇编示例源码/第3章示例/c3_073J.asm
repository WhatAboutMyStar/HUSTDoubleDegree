; P73 的语法规则实验
;      在386指令中，才能够 n >1

.386
CODE  SEGMENT  USE16
      ASSUME  CS:CODE
BEGIN:
      MOV  AX,1234H
      SAL  AX, 2
      MOV  AX, 4C00H
      INT  21H
CODE  ENDS
      END BEGIN
