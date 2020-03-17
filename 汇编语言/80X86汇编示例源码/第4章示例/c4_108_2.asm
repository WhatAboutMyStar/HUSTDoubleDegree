; 在 c4_108_1.asm 增加显示出立方值的功能
.386

DATA   SEGMENT  USE16
  INPUT  DB  'Please input x (0...9) : $'
  TAB    DW  0,1,8,27,64,125,216,343,512,729
  
  ; 构造显示信息表，每个立方数据占4个字节
  OUTPUT DB  '  0$' , '  1$' , '  8$' , ' 27$' , ' 64$'
         DB  '125$' , '216$' , '343$' , '512$' , '729$'
  XXX    DW  ?
  INERR  DB  0DH,0AH,'INPUT ERROR! $'
  CRLF   DB  0DH,0AH,'$'
DATA   ENDS

STACK SEGMENT USE16 STACK
  DB 200 DUP(0)
STACK ENDS

CODE SEGMENT USE16
  ASSUME CS:CODE, DS:DATA, SS:STACK
START:
  MOV  AX, DATA
  MOV  DS, AX      
  
  MOV  DX, OFFSET INPUT
  MOV  AH, 9
  INT  21H

  MOV  AH ,1 
  INT  21H

  CMP  AL, '0'      ; 判断输入是否合法
  JB   LERR

  CMP  AL, '9'
  JA   LERR
  
  CMP AL, '0'
  JZ LP1
  
  
  

  AND  AL, 0FH ; 求立方
  MOV  BL, AL
  MOV  BH, 0 
  SAL  BX, 1
  SAL  BX, 1

  LEA  DX, CRLF
  MOV  AH, 9 
  INT  21H

  LEA  DX, OUTPUT[BX]; 替代指令 LEA DX,OUTPUT ADD DX,  BX
  MOV  AH, 9 
  INT  21H
  JMP  EXIT

LERR:
  ; 显示输入错误信息
  LEA  DX, INERR
  MOV  AH, 9
  INT  21H
  
LP1:
  LEA DX, MSG1
  MOV AH, 9
  INT 21H

LP2:
  LEA DX, MSG2
  MOV AH, 9
  INT 21H
  
  ......

EXIT:
  MOV  AH, 4CH
  INT  21H
CODE ENDS
  END START
  
  