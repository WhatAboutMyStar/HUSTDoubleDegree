; P71 TEST 指令对标志位的影响
;     OF=0,  CF=0,   对于 AND, OR, XOR 一是如此
;     SF, ZF,  PF 依结果而定 

.386
CODE  SEGMENT  USE16
      ASSUME  CS:CODE
BEGIN:
      MOV  AX,0AFFFH
      MOV  BX,0A000H
      ADD  AX, BX
      MOV  AX, 1234H
      TEST  AX, 01H
      MOV  AX, 4C00H
      INT  21H
CODE  ENDS
      END BEGIN
