
 ; 1. 检验 LOOP 指令对标志位无影响
 ; 2. 判断以BUF为首址的10个字节中是否有非0字节
 ; 3. 判断以STR为首址的10个字节的串中是否有'空格'

.386

DATA SEGMENT  USE16
  BUF  DB  0,0,0,0,1,0,0,0,2,0,5,6
  MSG  DB  'VERY GOOD  '
DATA ENDS

STACK SEGMENT USE16 STACK
  DB  200 DUP(0)
STACK  ENDS

CODE SEGMENT USE16
  ASSUME CS:CODE, DS:DATA, SS:STACK
BEGIN:
     MOV AX, DATA
     MOV  DS, AX
     
     ; 第1种循环控制方法      
     MOV  CX, 5
     MOV  AX, 0
L1:   ADD  AX, CX
     DEC  CX
     JNZ  L1

     ; 第2种循环控制方法
     MOV  CX, 5     ; 观察执行此语句前的 ZF
     MOV  AX, 0
L2:  ADD  AX, CX
     LOOP L2        ; 观察执行此语句后的 ZF

     ; 第3种循环控制方法
                    ; 功能项2
     MOV  BX, OFFSET  BUF -1
     MOV  CX, 10
L3:   INC  BX
     CMP  BYTE PTR[BX], 0
     LOOPE L3
     MOV  AH, [BX]    ;  观察[BX]指向的数，及ZF

     ; 第4种循环控制方法
                    ; 功能项3
     MOV  BX, OFFSET  MSG -1
     MOV  CX, 10
L4:   INC  BX
     CMP  BYTE PTR[BX], ' '
     LOOPNE L4
     MOV  AH, [BX]    ;  观察[BX]指向的数，及ZF

     MOV  AH, 4CH
     INT  21H
CODE ENDS
  END BEGIN