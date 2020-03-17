.386
DATA   SEGMENT USE16
A        DW  M
BUF      DB 'AB',0DH,0AH
CON  EQU  500
B        DW   0FFAAH
D        DD   BUF
M        DB   2 DUP(1), 2 DUP(2,'B'), '123',1,2,3
DATA   ENDS

code segment USE16
     assume cs:code,ds:data
begin:
     mov ax,data
     mov ds,ax
     mov ah,4ch
     int 21h
code ends
     end begin

