; P11 ~ P13 中的指令说明
; 示例1 ：  push  04f8h
; 例1.1 ,   
; PUSHA
; PUSHAD
;        说明：(1)  在8086的汇编中，对于立即数的 push会报错；
;              (2)  在.386情况下，汇编程序不会报错；
;              (3)  使用了.386后，应指明段是 16位段，即USE16.
;              (4)  若使用了.386,而无USE16时，缺省是 USE32。
;              (5)  TD.exe 只能调试 16位段的汇编程序
.386
my_stack  segment  use16 stack  
          db 200 dup(0)
my_stack  ends

my_code  segment  use16
         assume cs:my_code, ss:my_stack
begin:
         push 04f8h        ; 示例1
         
         mov  eax,7ffA0011h  ; 例1.1        
         push eax          
         pop  bx
         pop  ecx
         
         mov  ax,1122h       ; 示例3
         mov  bx,3344h
         mov  cx,5566h
         mov  dx,7788h
         mov  bp,1234h
         mov  si,0AABBH
         mov  di,0CCDDH
         PUSHA             ; ax, cx,dx, bx, sp,bp, si, di
                           ; 保存的sp值，是执行该指令前的sp的值。
         
         PUSHAD            ; eax,ecx,edx,ebx,esp,ebp,esi,edi
         
         mov  ah,4ch
         int  21h
my_code  ends
         end  begin
                  
                           
