; 循环程序设计
; 比较不同的指令次序，程序的运行结果

.386
data segment  USE16
xx   db 'abcdef'
buf1 db '1234567'
buf2 db 'good'
data ends

code segment USE16
     assume cs:code,ds:data
begin:
     mov ax,data
     mov ds,ax
     mov cx, buf2 - buf1
     lea bx, buf2 - 1
LP:  mov dl, [bx]
     mov ah, 2
     int 21h
     dec bx       ;  如果将 dec bx  和 dec cx 交换，结果如何？
     dec cx
     jnz LP

     mov ah,4ch
     int 21h
code  ends
      end begin

