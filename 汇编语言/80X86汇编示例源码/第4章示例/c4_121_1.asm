     ; 输入一个数字串，数字串的最大长度为5
     ; 将其转换成字数据（即二进制形式），以16进制形式显示出来
.386
DATA SEGMENT USE16
BUF      DB 6, 7 DUP(0)
RESULT   DB 0DH,0AH,4 DUP(0), 0DH,0AH,'$'
ERRMSG   DB 0DH,0AH, 'Input is error',0DH,0AH, '$'
TOOLARGE DB 'Input number is too large ',0DH,0AH,'$'
DATA ENDS

STACK SEGMENT USE16 STACK
      DB 200 DUP(0)
STACK ENDS

CODE SEGMENT USE16
     ASSUME CS:CODE,DS:DATA,SS:STACK
BEGIN:
     MOV AX,DATA
     MOV DS,AX
     LEA DX,BUF
     MOV AH,10
     INT 21H
     
     MOV SI,OFFSET BUF+2
     MOV BX,10
     MOV AX,0

MAIN:                ; 转换处理部分
     MOV CL,[SI]
     CMP CL,0DH
     JZ  OUTPROC
     CMP CL,'0'
     JB  ERROR
     CMP CL,'9'
     JA  ERROR
     SUB CL,30H
     MUL BX
     JC  OUT_RANGE
     MOV CH,0
     ADD AX,CX
     JC  OUT_RANGE
     INC SI
     JMP MAIN

OUTPROC:               ; 输出部分
     LEA DI,RESULT+2
     MOV DX,4
     MOV CL,4
OUTPROC1:
     ROL AX,CL
     MOV BX,AX
     AND BX,0FH
     CMP BX,9
     JBE OUTPROC2
     ADD BX,7
OUTPROC2:
     ADD BX,30h
     MOV [DI],BL
     INC DI
     DEC DX
     JNZ OUTPROC1
     LEA DX,RESULT
     MOV AH,9
     INT 21H
     JMP EXIT

ERROR :
        LEA DX,ERRMSG
        MOV AH,9
        INT 21H
        JMP EXIT

OUT_RANGE:
        LEA DX,TOOLARGE
        MOV AH,9
        INT 21H
EXIT:   MOV AH,4CH
        INT 21H
CODE ENDS
     END BEGIN