;先引用符号常量，再定义，MASM是如何工作的？
;两遍扫描。在第一遍中，边扫描，边构造符号表，边替换。
;在替换时，从符号表中取值，（符号表中只记最新的值）
;对于第一遍扫描中出现的但未被替换的符号常量，
;在第二遍中用最后的符号表的值来代替。

code segment
     assume cs:code
begin:
     MOV AX, XX      ; 此处XX的值应是多少？
XX = 30
     mov bx,XX      

XX = 40
     mov cx,XX
     mov ax,4c00H
     int 21H
code ends
     end begin
