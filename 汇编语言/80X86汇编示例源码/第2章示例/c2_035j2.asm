       ; 寻址方式举例 
       ; 变址寻址
       ; 变址寻址方式中使用了变量时的语法规定
       ;     (1) 取变量的偏移地址参加运算，而不是变量单元中的内容
       ;     (2) 默认的段是变量所在的段。
       ;     (3) 操作数的类型为变量的类型
       
.386
data   segment USE16
X      db 10H,20H,30H
Y      DW 1122H, 3344H, 5566H, 7788H
data   ends
       

CODE    SEGMENT USE16
        ASSUME  CS:CODE,DS:data 
START:  MOV   AX , DATA
        MOV   DS , AX
        MOV   BX , 0
        
        MOV   X[BX], 0       ;  比较各对几个单元清0
        MOV   Y[BX], 0       ;
        
        MOV   Y+4[BX],1234H  ;  是改了哪个单元的数据？

EXIT:   MOV   AX , 4C00H
        INT   21H
CODE  ENDS
        END  START