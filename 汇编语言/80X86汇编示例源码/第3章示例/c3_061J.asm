;要点：（1）数据的存放
;      （2）LDS指令
;      （3）物理地址的计算，数据单元的访问

.386
data1  segment USE16
T1     dw -50H
T2     dd F
T3     db '1234567'
data1 ends

data2 segment USE16
buf   db 'ABCDEF'
F     DW 70H
data2 ends

stack segment USE16 stack
      db 200 dup(0)
stack ends

code segment USE16
     assume cs:code,ds:data1,ss:stack
start:
     mov ax,data1
     mov ds,ax

     MOV SI, 6        ;增加了两个语句，以和MOV AX,[SI]比较
     MOV AX,[SI]    

     MOV AX,T1
     LDS SI,T2
     MOV AX,[SI]

     MOV AX, T1    ; 和 上面的MOV AX, T1的结果有何不同？

     mov ah,4ch
     int 21h
code ends
     end start

