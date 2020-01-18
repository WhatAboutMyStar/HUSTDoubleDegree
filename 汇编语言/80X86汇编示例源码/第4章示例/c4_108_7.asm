;阅读程序,指出其存在的问题
;  判断 x 中的内容, 为正,显示 positive > 0 
;                   为负,显示 < 0
;                   为0,显示 zero
.386
data segment USE16
msg  db  'hello'
x    db  -5
bufp db 'positive > 0 $'
bufn db ' < 0 $'
zero db 'zero $'
data ends

stack segment USE16 stack
      db 200 dup(0)
stack ends

code segment USE16
     assume cs:code,ds:data,ss:stack 
begin:
     mov ax,data
     mov ds,ax

 .if x==0
     lea dx,zero
 .elseif x>0
     lea dx,bufp
 .else
     lea dx,bufn
 .endif

     mov ah,9
     int 21h
     mov ah,4ch
     int 21h
code ends
     end begin


     