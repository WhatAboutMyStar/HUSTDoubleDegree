
;  比较  串传送指令 与  不用该指令的效率区别

;  在程序运行开始和结束的时候，取了时间，最后显示所用的秒数

;  假设程序运行不会跨系统时间的小时（程序未对小时做处理）

;  与 c5_152_3.asm 比较
;  传送 8000H * FFFFH 个字节，本程序用时 14秒， 而 c5_152_3.asm 用时 3秒
;  传送 5000H * FFFFH 个字节，本程序用时 9秒， 而 c5_152_3.asm 用时 2秒
;  注意运行环境, 不同环境测出的速度不一样

.386
stack segment USE16 stack
hour1    db ?
minute1  db ?
second1  db ?
hensec1  db ?         ; 百分之一秒，可能无效
hour2    db ?
minute2  db ?
second2  db ?
hensec2  db ?  
         db 100 dup(0)
stack    ends
    
code segment USE16
     assume cs:code,ss:stack
gettime proc 
     mov ah,2ch
     int 21h
     mov [bp], ch
     mov [bp+1],cl
     mov [bp+2],dh
     mov [bp+3],dl
     ret
gettime endp

begin:     
     mov bp,0
     call gettime

     mov dx,8000H
lop_1:
     mov cx,0ffffH
     mov si,0
     mov di,0
lop_2:
     mov al,[si]
     mov [di],al
     inc si
     inc di
     dec cx
     jnz lop_2
     dec dx
     jnz lop_1

     mov bp,4
     call gettime
     mov  al, minute2
     sub  al, minute1
     mov  bl, 60
     mul  bl
     mov  dx, ax
     mov  al, second2
     sub  al, second1
     cbw             ; 如果 时间2的秒数 》时间1的秒数，则会直接加上正秒数
                     ; 否则 会减掉相应的秒数
     add  ax,dx
     mov  cx,0
     mov  bl,10
l1:  mov  ah,0
     div  bl
     push ax
     inc  cx
     cmp  al,0
     jnz  l1      

l2:  pop  dx
     xchg dh,dl
     add  dl,30h
     mov  ah,2
     int  21h
     loop l2 
     mov ah,4ch
     int 21h
code ends
     end begin
