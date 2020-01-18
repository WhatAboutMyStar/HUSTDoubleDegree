; 观察变量的作用范围

d1 segment 
XYZ = 10
buf1 DB  XYZ
XYZ =20
buf2 db XYZ
d1 ends

code segment
     assume cs:code,ds:d1
begin:
     mov ax,d1
     mov ds,ax
XX = 30
     mov bx,XX      
XX = 40
     mov cx,XX
     mov ax,4c00H
     int 21H
code ends
     end begin
