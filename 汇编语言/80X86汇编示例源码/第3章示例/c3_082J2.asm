;  c3_082J2  
;  强调段与段寄存器建立联系,若不建立联系，汇编时出错
;  强调给段寄存器赋值后，访问结果才正确

data1  segment 
T1     dw 50H
T2     dd F
data1 ends

data2 segment
buf   db 'ABCDEF'
F     DW 70H
data2 ends

stack segment stack
      db 200 dup(0)
stack ends

code segment
     assume cs:code,ds:data1,ss:stack
start:
     mov ax,data1
     mov ds,ax

  ;     mov  ax, F   ; 编译错误: 未建立联系，就使用F
     
     MOV  AX, ES:F   ; 无语法错误，逻辑正确否？
     
ASSUME es:data2

     MOV AX, F    ; 无语法错误，逻辑正确否？
     LES SI, T2
     mov AX, F    ;  等价于 es : mov AX,[0006]

     MOV  BX,  T1    ; 比较取消联系后是否正确
ASSUME DS:NOTHING
  ;   MOV  BX, T1     ; 编译错误
  
     mov ah,4ch
     int 21h
code ends
     end start
