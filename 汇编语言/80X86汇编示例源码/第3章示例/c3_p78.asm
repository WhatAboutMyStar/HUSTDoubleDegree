; 书上 p77 -78 面的例子

DATA  SEGMENT
A     DB  10011010b
B     DB  '(A)=$'
C     DB  'B',0DH,0AH,'$'
DATA  ENDS
STACK SEGMENT STACK
      DB 200 DUP(0)
STACK ENDS
CODE  SEGMENT
      ASSUME DS:DATA,SS:STACK,CS:CODE
START:
      MOV  AX, DATA
      MOV  DS, AX
      LEA  DX, B
      MOV  AH, 9 
      INT  21H
      MOV  BL, A
      MOV  CL, 8
NEXT: MOV  DL, 0
      SAL  BL, 1
      RCL  DL, 1
      ADD  DL, 30H
      MOV  AH, 2
      INT  21H
      DEC  CL
      JNE  NEXT
      LEA  DX, C
      MOV  AH, 9 
      INT  21H
      MOV  AH, 4CH
      INT  21H
CODE  ENDS
      END  START

 