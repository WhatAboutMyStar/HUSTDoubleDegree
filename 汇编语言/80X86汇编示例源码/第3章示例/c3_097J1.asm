       ; 第三章，习题 3.11  程序的修改
       ; 

; c3_p87.asm 程序中，存在的问题：如果数码大于9，即为A--F,显示的结果不对。
; 例如，NUM DB 00111011B
; 分析： 
;    若四位二进制数为 0 ,  则要显示 0 的ASCII。'0'的ASCII为 30H,要在原二进制数上加30H
;    若四位二进制数为 9 ,  则要显示 9 的ASCII。'9'的ASCII为 39H,也是在原二进制数上加30H
;    若四位二进制数为 1010 ,  则要显示 A 的ASCII。'A'的ASCII为 41H,
;              要在原二进制数上加37H  (41H - 0AH  =37 H)
; 得出结论：若四位二进制数<10, 则加 30H; 否则加  37H

A     SEGMENT
NUM   DB  00111011B
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
       CMP  AL,10
       JB   L1
       ADD  AL,7
L1:    ADD  AL,30H
                        ; 不能用OR AL,30H, 为什么？
;       OR   AL,30H     ; 相当于执行了 ADD AL,30H

       MOV  [DI],AL
       INC  DI
       MOV  AL,NUM
       AND  AL,0FH     ; 高四位置为0

       CMP  AL,10
       JB   L2
       ADD  AL,7
L2:    ADD  AL,30H

;       OR   AL,30H

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

