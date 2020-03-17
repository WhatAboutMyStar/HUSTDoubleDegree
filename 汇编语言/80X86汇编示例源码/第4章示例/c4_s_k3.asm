;  结构 的使用  《高级用法》
;              c4_s_k1.asm  《基本用法》
;              c4_s_k2.asm  《高级用法》


;  功能：计算100个学生的总成绩
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
students student 100 dup(<>)
data ends

stack segment  USE16 stack
      db 200 dup(0)
stack ends

code segment USE16 
     assume cs:code ,ds:data,ss:stack
start:
      mov ax, data
      mov ds, ax    

      mov bx, offset students

      mov [bx].english, 100
      mov [bx].math, 100
      mov [bx].chinese ,100

                     ; 给第一个学生赋姓名 'abcd'
                     ; 采用基址加变址的方式
      mov SI, 0          
      mov al, 'a'
      mov cx,4
L1:
      mov [bx].xingming[SI] , AL
      INC SI
      INC AL
      LOOP L1

      mov ah,4ch
      int 21h
code  ends
      end start

; 注意：寻址方式





