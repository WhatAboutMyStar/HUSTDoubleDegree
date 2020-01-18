     ;  显示ASCII 表
     ;  HEAD1, 到下属的各标号：HEAD1_0,HEAD1_1,HEAD1_2 显示了第一行线
     ;         第一行线，是用一个个字符方式显示的。
     ;  TOP1 定义了第一行数字和线的显示串，采用显示串语句
     ;  MIDDLE_L : 中间的线条
     ;  END_L    : 最低下的线条
     ;  DATA_L   : 中间有数据的行
     ;             在程序中，修改该行中不同的数据值，达到显示不同结果的目的
CRLF MACRO 
     MOV AH,2
     MOV DL,0AH
     INT 21H
     MOV DL,0DH
     INT 21H
     ENDM

L_VERTICAL MACRO        ; 显示竖线
     MOV AH,2
     MOV DL,179
     INT 21H
     ENDM

DISPLAY MACRO  A     ; 显示中间的线条或数字
                     ; A 给出了一个串定义的开始位置
     LEA DX,A
     MOV AH,9
     INT 21H
     ENDM

data segment
LUC      EQU  218     ; "┌"
HHH      EQU  196     ; "─"
HTH      EQU  194     ; "┬"
RUC      EQU  191     ; "┐"
VVV      EQU  179     ;  "│"
CRS      EQU  197     ; "┼"
VEV      EQU  195     ; "├"
top1     db   VVV,3 dup(20H),VVV,3 dup(20H),VVV,32,32,30H,VVV
         db   ' 16',VVV,' 32',VVV,' 48',VVV,' 64',VVV
         DB   ' 80',VVV,' 96',VVV,'112',VVV,'128',VVV
         DB   '144',VVV,'160',VVV,'176',VVV,'192',VVV
         DB   '208',VVV,'224',VVV,'240',VVV,0DH,0AH,'$'

top2     db '0123456789ABCDEF'
MIDDLE_L db VEV, 17 dup (3 dup(HHH),CRS), HHH,HHH,HHH,180,0dh,0ah,'$'
DATA_L   DB   19 DUP( VVV,3 dup(20H)),0DH,0AH,'$'

END_L    DB 192, 17 DUP(3 DUP(HHH),193),HHH,HHH,HHH,217,0DH,0AH,'$'


data ends

stack segment stack
      db 200 dup(0)
stack ends

code segment
     assume cs:code,ds:data,ss:stack
begin:
     mov ax,data
     mov ds,ax

display_head:
     mov dl,LUC
     mov ah,2
     int 21h
head1:
     mov BX,17
head1_0:
     MOV CX,3
     mov dl,HHH
     MOV AH,2
HEAD1_1:     
     INT 21H
     LOOP HEAD1_1
     MOV  DL,HTH
     MOV  AH,2
     INT  21H
     DEC  BX
     JNE  HEAD1_0

     MOV  CX,3
     MOV  DL,HHH
     MOV  AH,2
HEAD1_2:
     INT  21H
     LOOP HEAD1_2         
     MOV  DL,RUC
     MOV  AH,2
     INT  21H
     CRLF               ; 以上程序显示了第一行线
     
     LEA DX,TOP1
     MOV AH,9
     INT 21H            ; 显示了第一行  数字 0，16，32......
    
     DISPLAY   MIDDLE_L      ; 显示中间的线条

     LEA  BX,DATA_L+10
     MOV  CX,16
     MOV  SI,OFFSET TOP2
WR_DATA1:
     MOV  DL,[SI]
     MOV  [BX],DL
     ADD  BX,4
     INC  SI
     LOOP WR_DATA1
     LEA  DX,DATA_L
     MOV  AH,9
     INT  21H           ; 显示了第二行  数据 0，1，2，...... F
          

     MOV  SI,0          ; 第一个数据
MAIN:          
     DISPLAY  MIDDLE_L  ; 显示线条
     MOV  BX,OFFSET DATA_L+2      ; 前两列
     MOV  DL,TOP2[SI]
     MOV  [BX],DL
     ADD  BX,4
     MOV  [BX],DL
     ADD  BX,4
     MOV  DX,SI             ; 实际只用到了低8位
     MOV  CX,16             ; 一行16个数据
WR_DATA3:
     CMP  DL,7
     JZ   LLL
     cmp  DL,8
     JZ   LLL
     CMP  DL,9
     JZ   LLL
     CMP  DL,0AH
     JZ   LLL
     CMP  DL,0DH
     JZ   LLL
     CMP  DL,'$'           ; 特殊情况，在串中含有$字符，串打印结束，后面的部分不会打印
     JZ   LLL
     MOV  [BX],DL
     JMP  LLLL
LLL: MOV  [BX],BYTE PTR ' '
LLLL:ADD  DL,16
     ADD  BX,4
     LOOP WR_DATA3

     LEA  DX,DATA_L         ; 显示数据行
     MOV  AH,9
     INT  21H
     
     INC  SI                ; 显示所有的行
     CMP  SI,8
     JBE  MAIN

     DISPLAY END_L     
     mov  ah,4ch
     int  21h
code ends
     end begin
 