       ; 寻址方式举例 
       ; 变址寻址
       ; 变址寻址方式中使用了变量时的语法规定
       ;     (1) 取变量的偏移地址参加运算，而不是变量单元中的内容
       ;     (2) 默认的段是变量所在的段。
       
.386
data   segment USE16
X      db 10H,20H,30H
X2     db 11H, 22H
data   ends
       
STACK  SEGMENT  USE16 STACK
Y      db  40H, 50H
       DB 200  DUP(0)
STACK  ENDS

CODE    SEGMENT USE16
        ASSUME  CS:CODE,DS:data,SS:STACK
Z       DB    60H,70H        
START:  MOV   AX , DATA
        MOV   DS , AX
        MOV   BX , 0

        MOV   AH , X[BX]     ; 观察各用的什么段？
        MOV   AL,  Y[BX]
        MOV   CL,  Z[BX]
        
        MOV   AH,  X2[BX]     ; 取 X2的偏移地址
        
        MOV   AH, CS:X[BX]    ; 观察强制段
        MOV   AL, SS:X[BX]

EXIT:   MOV   AX , 4C00H
        INT   21H
CODE  ENDS
        END  START