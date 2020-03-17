 
;子程序
;求一串数据的和

; 涉及到三个参数：数据的起始地址、数据的个数，存放结果的地址
;     约定单元法
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
      
      call  far ptr sum_proc

      mov ax, sum
      mov ah, 4ch
      int 21h
code  ends

     ; 子程序从指定地址处取数据
     ;       也将结果放在指定位置
sub_code segment USE16 
         assume cs:sub_code
sum_proc proc far
         push ax
         push bx
         push cx
         lea  bx, array
         mov  cx, nums
         xor  ax,ax
L1:      add  ax, [bx]
         inc  bx
         inc  bx
         LOOP L1
         mov  sum, ax
         pop  cx
         pop  bx
         pop  ax
         RET
sum_proc endp
sub_code ends         

      end start
