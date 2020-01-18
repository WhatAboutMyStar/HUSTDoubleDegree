;     第三章的作业题

T3_7  SEGMENT 
      ASSUME  CS:T3_7
START:
      MOV  AX, 0
      DEC  AX
      ADD  AX, 07FFFH
      ADD  AX, 2
      NOT  AX
      SUB  AX, 0FFFFH
      ADD  AX, 8000H
      OR   AX, 0BFDFH
      AND  AX, 0EBEDH
      XCHG  AH, AL
      SAL  AX, 1
      RCL  AX, 1
      MOV  AH,4CH
      INT  21H
T3_7  ENDS
      END START

