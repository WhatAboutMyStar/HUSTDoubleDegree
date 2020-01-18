
; 打印乘法口诀表
; 定义 head 用于存放第一行的一个数字
; 定义 buf  用于存放表中的一个数字

crlf macro
     mov ah,2
     mov dl,0ah
     int 21h
     mov dl,0dh
     int 21h
     endm

data segment
head db '   $'
buf  db '   $'
data ends

code segment
     assume cs:code,ds:data
begin:
     mov ax,data
     mov ds,ax

     mov cx,9
     mov si,offset head+2

     lea dx,head
     mov ah,9
     int 21h
     mov bl,31H
l1:
     mov [si],bl
     int 21h
     inc bl
     loop l1

     crlf

     mov ch,1           ; 打印 9行  (还要用ch 做为一个乘数 ）
l2:
     mov al,ch
     mov ah,0
     call f2t10         ; 最左边的乘数  (ch)

     mov cl,1           ; 作为 一行 中列的乘数（在内循环中变化）
l3:
     mov al, cl
     mul ch
     call f2t10         ; 待转换的数在 AX中
     inc cl
     cmp cl,10
     jb  l3
     crlf
     inc ch
     cmp ch,10
     jb  l2
     crlf          
     mov ah,4ch
     int 21h


f2t10 proc
      lea di,buf+2
      mov bl,10
start:
      div bl
      add ah,30h
      mov [di],ah
      dec di
      cbw 
      cmp al,0
      jne start

      lea dx,buf
      mov ah,9
      int 21h
      mov buf+1,' '        ; 为下一输出做准备

      ret
f2t10 endp

code ends
     end begin
