
;   带间隔符的实参

;   数字参数     , 观察生成的 LIST文件
;       对于该例而言，最后数据段中存放的数据是一样的
;                     但是在扩展阶段，生成的LIST文件不同

;   如果参数只作为字符串中的一部分，最后的结果是不样的 


stack0 macro  a
stack  segment stack
       db  a
stack  ends
       endm

stack0 <500 dup(0)>

data1 macro a,b,c,d
      dw    a,b,c
      db    d dup(1)
      endm

data segment
x = 10
y=20
     data1 %x+2,5,%x+y, %y-5
     data1 x+2,5,x+y,y-5
data ends

code segment
     assume cs:code,ss:stack,ds:data
begin:
     mov ax,data
     mov ds,ax
                 ; 观察数据段    

     mov ah,4ch
     int 21h
code ends
     end begin
        