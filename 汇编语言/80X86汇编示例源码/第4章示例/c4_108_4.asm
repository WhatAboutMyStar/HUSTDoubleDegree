     ; 无条件转移指令，展示JMP 的用法 和妙用
     ; 构造标号地址列表
     ; 对于不同的输入，给出不同的回应
     ; 执行不同的程序段
     ;       跳跃表法
     ;       功能类似于 CASE语句
.386
DATA SEGMENT USE16
MSG     DB ' 1  :   DIR',0DH,0AH
        DB ' 2  :   COPY',0DH,0AH
        DB ' 3  :   RENAME',0DH,0AH
        DB '        OTHER',0DH,0AH,'$' 

MSG1    DB ' here is the program, DIR',0DH,0AH,'$'
MSG2    DB ' program   COPY',0DH,0AH,'$'
MSG3    DB ' RENAME',0DH,0AH,'$'
MSG4    DB ' ERROR COMMAND ',0DH,0AH,'$'

STAMENT DW  LABLE1,LABLE2,LABLE3,LABLE4
DATA ENDS

STACK SEGMENT USE16 STACK
      DB 200 DUP(0)
STACK ENDS 

CODE SEGMENT USE16
     ASSUME CS:CODE,DS:DATA,SS:STACK
BEGIN:
     MOV  AX,DATA
     MOV  DS,AX
     
     LEA  DX,MSG
     MOV  AH,9
     INT  21H
     
     MOV  AH,1
     INT  21H

     MOV  BX, 3
     CMP  AL,'1'
     JB   L1        ;  输入比 '1' 小
     
     CMP  AL,'3'
     JA   L1        ;  输入比 '3' 大

     MOV  BL,AL
     SUB  BL,31H    ; '1' --> 0,  '2'-->1 ,  '3'-->2
     MOV  BH,0      ; 具体的数字的二进制形式在 BX中

L1:  SHL  BX,1           ; (bx) *2 , 一个地址项占两个字节

     JMP  STAMENT[BX]    ; 从表中取地址, 转到不同的地方执行程序

BACK:
     MOV  AH, 4CH
     INT  21H

LABLE1 :                 ; 一个程序段
     LEA DX,MSG1
     MOV AH,9
     INT 21H
     JMP BACK

LABLE2:                  ; 一个程序段
     LEA DX,MSG2
     MOV AH,9
     INT 21H
     JMP BACK

LABLE3:
     LEA DX,MSG3
     MOV AH,9
     INT 21H
     JMP BACK

LABLE4:
     LEA DX,MSG4
     MOV AH,9
     INT 21H
     JMP BACK

CODE ENDS
     END BEGIN

