data segment
str1 db '1234567890$'
str2 db 'abcd$'
data ends

stack segment stack
      db 200 dup(0)
stack ends

code segment
     assume cs:code,ds:data,ss:stack
begin:
     mov ax, data
     mov ds, ax
     lea dx, str1
     mov ah, 9
     int 21h

mov dl,0ah
mov ah,2
int 21h
mov dl,0dh
mov ah,2
int 21h
     lea dx, str2
     mov ah,9
     int  21h
     mov  cx,5
l1:
     mov ah,8
     int 21h
;
     mov dl,al
     mov ah,2
     int 21h
loop l1

     mov  ah,4ch
     int  21h


code ends
     end begin
