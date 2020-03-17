;  条件汇编的例子

;  若 INCLUDEPART = 1 , 则包含 PART1部分的程序；
;  否则，不包含 PART1部分的程序；

.386
INCLUDEPART   =  0

code segment use16
     assume  cs:code
begin:
     mov  ax,0
IF   INCLUDEPART EQ 1
     MOV  BX, 0
     MOV  CX, 0
ENDIF
     MOV  AX, 4C00H
     INT  21H
CODE ENDS
     END BEGIN