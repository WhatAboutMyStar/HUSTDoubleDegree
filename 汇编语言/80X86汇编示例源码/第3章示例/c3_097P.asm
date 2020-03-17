       ; 第三章，习题 3.11
       ;     阅读程序，指出程序的功能

; 以下程序的显示结果为 (NUM)=39H
; 将一个字节的二进制数转换成十六进制的形式显示出来
; 程序中，存在的问题：如果数码大于9，即为A--F,显示的结果不对。
; 例如，NUM DB 00111011B

A     SEGMENT
NUM   DB  00111001B
BUF   DB  0AH,0DH,'(NUM)='
BUF0  DB  4 DUP(?)
A     ENDS

B  SEGMENT  STACK
   DB 200  DUP(0)
B  ENDS

C    SEGMENT
        ASSUME  DS:A,SS:B,CS:C
BEGIN: MOV  AX,A
       MOV  DS,AX
       LEA  DI,BUF0
       MOV  AL,NUM
       MOV  CL,4
       SHR  AL,CL
                       ; AL的高四位为0，原来的高四位移到了低四位
       OR   AL,30H     ; 相当于执行了 ADD AL,30H
       MOV  [DI],AL
       INC  DI
       MOV  AL,NUM
       AND  AL,0FH     ; 高四位置为0
       OR   AL,30H
       MOV  [DI],AL
       INC  DI
       MOV  BYTE PTR [DI],'H'
       INC  DI
       MOV  BYTE PTR [DI],'$'
       LEA  DX,BUF
       MOV  AH,9
       INT  21H
       MOV  AH,4CH
       INT   21H
C      ENDS
       END  BEGIN

