;  结构 的使用  《高级用法》
;              c4_s_k1.asm  《基本用法》

;  用一个寄存器(BX,SI,DI,BP) 指向一个结构变量的开始地址 

;  功能：计算几个学生的总成绩
;    
.386    
data segment USE16 
student  struc
         xingming db  '0000'      
         english dw  0
         math    dw  0
         chinese dw  0
         total   dw  0
student  ends
s1       student  <'s001',90,100,110,0>
s2       student  <'s002',95,105,115,0>
s3       student  <'s003',85,95,105,0>
data ends

stack segment  USE16 stack
      db 200 dup(0)
stack ends

code segment USE16 
     assume cs:code ,ds:data,ss:stack
start:
      mov ax, data
      mov ds, ax
    
      mov cx, 3
      mov bx, offset s1
L1:
                      ; 下面计算 [bx] 指向的学生的总成绩
      xor ax, ax      ; (ax)用于保存总成绩
      add ax, [bx].english       ;  add ax , [bx+0004]
      add ax, [bx].math          ;  add ax , [bx+0006]
      add ax, [bx].chinese       ;  add ax , [bx+0008]
      mov [bx].total, ax         ;  mov [bx+000A], ax

      add bp, 12                 ;  准备计算下一个人的成绩
      LOOP L1

      mov ah,4ch
      int 21h
code  ends
      end start

; 注意：如果将上述 bx 改为bp, 结果不正确，[bp] 默认的是堆栈段





