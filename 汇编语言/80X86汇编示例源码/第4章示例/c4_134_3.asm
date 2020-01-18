 
;子程序
;求一串数据的和

; 涉及到三个参数：数据的起始地址、数据的个数，存放结果的地址
;     堆栈法
; 将要处理的数据放到指定名称的变量处
.386
data segment USE16 
array dw 1,2,3,4,5,6,7,8,9,10
nums   dw 10
sum    dw ?
data   ends

stack segment  USE16 stack
      db 200 dup(0)
stack ends

code  segment USE16 
      assume cs:code,ds:data,ss:stack
start:mov ax, data
      mov ds, ax
      
      lea   bx, array
      push  bx
      push  nums
      mov   dx, offset sum
      push  dx
      
      call  far ptr sum_proc

      mov ax, sum
      mov ah, 4ch
      int 21h
code  ends

     ; 子程序从指定地址处取数据
     ;       也将结果放在指定位置
sub_code segment  USE16 
         assume cs:sub_code
sum_proc proc far
         push ax
         push bx
         push cx
         push di
 
         mov  bp, sp
         add  bp, 12    ; bp 指向最后入栈的参数
         mov  di, [bp]    ;  结果的地址
         mov  cx, [bp+2]  ;  个数
         mov  bx, [bp+4]  ;  数据起始地址在 bx中

         xor  ax,ax
L1:      add  ax, [bx]
         inc  bx
         inc  bx
         LOOP L1
         mov  [di], ax
         pop  di
         pop  cx
         pop  bx
         pop  ax
         RET  6      ; 在弹出 IP,CS后，再废掉 6个字节
sum_proc endp
sub_code ends         

      end start
