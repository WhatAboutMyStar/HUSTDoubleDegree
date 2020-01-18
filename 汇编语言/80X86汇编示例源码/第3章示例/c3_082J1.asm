;要点：（1）数据的存放
;      （2）LDS指令
;      （3）物理地址的计算，数据单元的访问
;             三条 MOV  AX,T1的结果比较

data1  segment 
T1     dw 50H
T2     dd F
data1 ends

data2 segment
buf   db 'ABCDEF'
F     DW 70H
data2 ends

stack segment stack
      db 200 dup(0)
stack ends

code segment
     assume cs:code,ds:data1,ss:stack
start:
     MOV AX,0      ;
     MOV AX,T1     ; 还没有将DATA1段的首址送DS,(AX)=?

     mov ax,data1
     mov ds,ax
     MOV AX,T1     ; DS已为DATA1段的首址，(AX) = ?

     LDS SI,T2     ; LDS的功能是？
     MOV AX,[SI]   ; (AX)= ?

     mov AX,T1    ; (AX)=?
     
     mov AX,4C00H
     int 21h
code ends
     end start

