
; 打印乘法口诀表
; 定义 head 用于存放第一行要显示的数据，用了重复汇编
; 定义 buf  用于存放表中的一个数字

crlf macro
     mov ah,2
     mov dl,0ah
     int 21h
     mov dl,0dh
     int 21h
     endm

data segment
head db '    '
     N = 31H
     REPT  9
     db 3 dup(' '),N
     N = N + 1
     ENDM
     db '$'
buf  db '    $'
data ends

stack segment stack
      db 200 dup(0)
stack ends

code segment
     assume cs:code,ds:data
begin:
     mov ax,data
     mov ds,ax

     lea dx,head
     mov ah,9
     int 21h

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
      lea di,buf+3
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
      mov buf+2,' '        ; 为下一输出做准备

      ret
f2t10 endp

code ends
     end begin
