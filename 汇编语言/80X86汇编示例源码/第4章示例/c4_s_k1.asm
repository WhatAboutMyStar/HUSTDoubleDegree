;  结构定义 和使用   <基本用法>

;  定义格式
;      结构名  STRUC
;             <数据定义语句序列>
;      结构名  ENDS
;              其中<数据定义语句>定义的变量名 也称结构字段名

;  STRUC 伪操作只定义了一种结构模式，并不分配存储单元。
;  定义结构类型的数据存储区时，采用如下格式：

;      变量名  结构名   字段值表

;  字段值表的形式为 <值1,值2,...,值n>
;      其中 值1和结构中的第一个字段名对应，值n和第n个字段名对应。
;      如果 某一个值 想使用 定义结构时预置的该字段的值，则可省略。
;      但 "," 不能省略。
;  特别强调：如果定义结构时，一个字段中有多个值，则在定义结构变量时，
;            字段值表中的对应项必须省略，不能用其他值来代替

;  在访问时，一次也只能访问 结构数据中的某一字段。
;      某一个字段的有效地址为：  变量名.字段名

; 结构定义中的一些说明
;     (1) 为什么第一个字段没有叫 name,而取名为 xingming，因为 name是一个关键字
;     (2) 姓名是 四个字节的串，写成 '0000', 表示是一个值，
;             在 s1 的定义中 用 's001' 表示实际的值。
;         不能 用“ 4 dup ('0') ”来代替'0000', 也不能用 '0','0','0','0' 来代替。
;         它们都表示一个字段后有 4 个值，在定义变量时，就必须缺省该字段
;         否则给出 错误信息： Field cannot be overridden
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
data ends

stack segment  USE16 stack
      db 200 dup(0)
stack ends

code segment USE16 
     assume cs:code ,ds:data,ss:stack
start:
      mov ax, data
      mov ds, ax
                      ; 下面计算 s1 的总成绩
      xor ax, ax      ; (ax)用于保存总成绩
      add ax, s1.english       ;  add ax , [0004]
      add ax, s1.math          ;  add ax , [0006]
      add ax, s1.chinese       ;  add ax , [0008]
      mov s1.total, ax         ;  mov [000A], ax
                      ; 下面计算 s2 的总成绩
      xor ax, ax      
      add ax, s2.english       ;  add ax, [0010]     
                               ;  s2 的offset为 0ch, 后面在空四个字节的xingming
      add ax, s2.math
      add ax, s2.chinese
      mov s2.total, ax
    
      mov ah,4ch
      int 21h
code  ends
      end start






