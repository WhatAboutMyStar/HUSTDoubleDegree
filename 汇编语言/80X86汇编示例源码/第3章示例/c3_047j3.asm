; 观察变量的作用方法
; 程序的执行流程可以有多种，顺序、分支、循环
; 但汇编程序进行加工时，是顺序扫描源程序，
; 将其中的符号常量替换成相应的值,直到遇到同名的符号常量。

code segment
     assume cs:code
begin:

XX = 30
     JMP L2

L1:
     mov bx,XX      
     JMP EXIT
XX = 40

L2:
     mov cx,XX
     JMP L1

EXIT:
     mov ax,4c00H
     int 21H
code ends
     end begin
