; 观察变量写的位置
; 符号常量定义可以出现在段内，也可以出现在段外
; 可以先引用，后定义

AA=10

d1 segment
x    db  CC
buf1 db  AA
CC  = 30
buf2 dw  AA,CC
d1  ends

XYZ=40
code segment
     assume cs:code,ds:d1
begin:
     mov ax,d1
     mov ds,ax

     mov bx,aa      ; 源操作数是什么寻址方式

     mov cx,BB      ; 先引用，后定义
BB =20

     mov dx,XYZ
     mov ax,4c00H
     int 21H
code ends
     end begin
