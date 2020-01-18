
;  有符号乘法 IMUL, 和无符号乘法MUL

code segment
     assume cs:code
begin:
     mov  al,10H
     mov  bl,-2      ;  (bl)=FE
     imul bl         ;  (ax)=FFE0  ,结果高字节无有效位，有NC, NV

     mov  al,10H
     mul  bl         ;  (ax)=0FE0,  结果高字节有有效位，有CY, OV

     mov  al,-10h
     mov  bl,2
     imul bl         ; (ax) = FFE0 

     mov  al,-10h
     mov  bl,2
     mul  bl         ; (ax) = 01E0

 
     mov  ah,4ch
     int  21h
code ends
     end begin