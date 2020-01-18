 
;子程序
;求一串数据的和

; 涉及到三个参数：数据的起始地址、数据的个数，存放结果的地址
;     寄存器法
.386
data segment USE16
array1 dw 1,2,3,4,5,6,7,8,9,10
nums   dw 10
sum    dw ?
data   ends

stack segment USE16 stack
      db 200 dup(0)
stack ends

code  segment USE16
      assume cs:code,ds:data,ss:stack
start:mov ax, data
      mov ds, ax
      
;     寄存法
;       数据的起始地址 在bx 中
;       数据的个数在   cx中
;       返回结果在     ax中  
      mov  bx, offset array1
      mov  cx, nums

      call  far ptr sum_proc

      mov sum, ax
      mov ah, 4ch
      int 21h
code  ends

sub_code segment USE16
         assume cs:sub_code
sum_proc proc far
         xor  ax,ax
L1:      add  ax, [bx]
         inc  bx
         inc  bx
         LOOP L1
         RET
sum_proc endp
sub_code ends         

      end start
