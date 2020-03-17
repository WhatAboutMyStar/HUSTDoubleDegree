; (1) 观察无前缀的串传送指令, si, di的变化
; (2) 观察无前缀的串传送指令，在CX等于0时，si, di的变化
; (3) 观察有前缀的串传送指令
; 观察 在 CX=0 时，数据是否移动，SI, DI 是否变化
; 观察 在 CX<>0  时，数据的移动情况，SI,DI 各指向什么单元

.386
data segment USE16 
buf1  db '012345'
n    = $ -buf1
buf2  db 'abcdef'
data  ends

stack segment  USE16 stack
      db 200 dup(0)
stack ends

code segment USE16 
     assume cs:code,ss:stack,ds:data,es:data
begin:
     mov ax, data
     mov ds, ax
     mov es, ax
     lea si, buf1
     lea di, buf2
     cld
     
     mov cx, n
     ; mov cx, 0
     movsb       ;先观察无前缀的串传送指令
     rep movsb

     mov ah,4ch
     int 21h
code ends
     end begin
