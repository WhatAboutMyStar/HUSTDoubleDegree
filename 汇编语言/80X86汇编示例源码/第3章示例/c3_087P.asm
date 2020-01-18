; 书上 p87 面的例子
.386
DATA  SEGMENT   USE16
AA     DB  10011010B
BB     DB  '(A)=$'
CC     DB  'B',0DH,0AH,'$'
DATA  ENDS
STACK SEGMENT USE16 STACK
      DB 200 DUP(0)
STACK ENDS
CODE  SEGMENT USE16
      ASSUME DS:DATA,SS:STACK,CS:CODE
START:
      MOV  AX, DATA
      MOV  DS, AX
      LEA  DX, BB
      MOV  AH, 9 
      INT  21H
      MOV  BL, AA
      MOV  BH, 0
      MOV  CX, 7
L:    BT   BX,  CX
      JC   P
      MOV  DL, 30H
      JMP  Q
P:    MOV  DL, 31H
Q:    MOV  AH, 2
      INT  21H
      DEC  CX
      JGE  L

      LEA  DX, CC
      MOV  AH, 9 
      INT  21H
      MOV  AH, 4CH
      INT  21H
CODE  ENDS
      END  START

 