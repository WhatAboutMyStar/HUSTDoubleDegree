; 使用递归子程序 求 N!  以十进制形式显示结果
.386
stack segment  USE16 stack
      db 200 dup(0)
stack ends

data segment USE16 
msg    db  'input a number (1..9) : $'
output db  0dh,0ah,'jie cheng is : '
result db  6 dup (' '),'$'
error  db  0dh,0ah,'input error ! $'
data ends

code segment USE16 
     assume cs:code,ds:data,ss:stack
start:
     mov  ax, data
     mov  ds, ax
     lea  dx, msg      ; 显示提示信息
     mov  ah, 9
     int  21h
     
     mov  ah, 1        ; 输入一个字符
     int  21h

     cmp  al, '1'      ; 判断是否在 ‘1’- ‘9’之间
     jb   error_p      ; 不在，进行出错处理
     cmp  al,'9'
     ja   error_p

     sub  al, 30h
     mov  bl, al
     mov  bh, 0       ; BX 为待求阶乘 的数
                      ; 结果在 (DX,AX)中
     call f_jiechen

     call f_zhuanhuan   ; (DX,AX)  -> result 缓冲区中

     lea  dx, output
     mov  ah, 9
     int  21h
     jmp  exit

error_p:
     lea  dx, error
     mov  ah, 9
     int  21h
exit:mov  ah,4ch
     int  21h

; BX  中的数为 待求阶乘的 数
f_jiechen proc
     cmp  bx,1
     jg   LP
     mov  ax,1
     mov  dx,0
     ret
LP:  dec  bx
     call f_jiechen
     inc  bx
     mul  bx
     ret
f_jiechen endp

; 将 (DX,AX) 中的内容，转换成 十进制数串
f_zhuanhuan proc
     mov   bx, 10
     lea   si, result+5
l1:  div   bx
     add   dl,30H
     mov   [si],dl
     dec   si
     cmp   ax, 0
     jz    f_exit
     mov   dx,0
     jmp   l1
f_exit:
     ret
f_zhuanhuan  endp

code ends
     end start
