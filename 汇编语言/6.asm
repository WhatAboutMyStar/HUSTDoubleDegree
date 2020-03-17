.386
		INCLUDE MACRO.LIB
DATA SEGMENT USE16
	N EQU 30
	BUF DB  'zhangsan',0,0   ;学生姓名，不足10个字节的部分用0填充
	  	DB    100, 85, 80,?   ; 平均成绩还未计算
        DB  'lisi',6 DUP(0)
		DB    50, 4, 50,?
		DB  N-3 DUP( 'TempValue',0,8,9,9,?) ;除了3个已经具体定义了学生信息的成绩表以外，其他学生的信息暂时假定为一样的。
     	DB  'LIUYIHENG',0     ;最后一个必须是自己名字的拼音
		DB    85, 85, 100, ?
	MSGTS DB 'Please input the student name: $';提示输入学生姓名
	MSGTS2 DB 'Not exist',0AH,0DH,'Please input the student name again:(input q,exit) $';提示再次输入
	IN_NAME DB 10
			DB ?
			DB 10 DUP(0)       ;存储输入姓名字符串的地方 
	POIN DW ?				   ;学生课程成绩表的起始偏移地址
DATA ENDS

STACK SEGMENT USE16 STACK 
	DB 200 DUP(0)
STACK ENDS

CODE SEGMENT USE16
	ASSUME CS:CODE,DS:DATA,SS:STACK
LOP1:
	CRLF		;换行回车

	WRITE MSGTS2  		;9号调用输出提示字符串
	
	JMP LOP2

COMPUTEEA:
	LEA SI,IN_NAME
	ADD SI,2
	ADD BX,4
	ADD DI,BX
	MOV BX,10
	MOV CL,IN_NAME+1
	DEC CH
	JZ LOP2				;没找到再输入
	JMP LOP3

START:
	MOV AX,DATA
	MOV DS,AX

AGAIN:
	WRITE MSGTS    ;9号调用输出提示字符串

LOP2:
	LEA DX,IN_NAME
	MOV AH,10
	INT 21H    ;10号调用，将输入字符串存入缓冲区。

	MOV DL,0AH
	MOV AH,2
	INT 21H

	LEA BX,IN_NAME
	ADD BX,2
	CMP BYTE PTR [BX],0DH
	JE LOP1
	CMP BYTE PTR [BX],'q' ;输入q退出
	JZ EXIT

	LEA SI,IN_NAME
	ADD SI,2
	MOV CH,N
	MOV CL,IN_NAME+1
	MOV BX,10
	LEA DI,BUF

LOP3:
	MOV AL,[SI]   ;IN_NAME里的数
	MOV DL,[DI]	  ;BUF 里的数
	CMP AL,DL
	JNZ COMPUTEEA   ;计算下一处的EA
	INC SI
	INC DI
	DEC BX
	DEC CL
	JNZ LOP3

	ADD BX,DI
	MOV POIN,BX			   ;将该学生课程成绩表的起始偏移地址保存到POIN字变量中。

CAL:
	MOV DX,[POIN+2]
	SHR DX,1							;计算平均成绩
	MOV BH,2
	MOV AX,[POIN]
	ADD AX,AX
	ADD AX,[POIN+1]
	ADD AX,DX
	MUL BH
	MOV BX,7
	DIV BX
	
	CMP AX,90
	JS A
	CMP AX,80
	JS B
	CMP AX,70
	JS C0
	CMP AX,60
	JS D
	JMP F
A:							;级别A
	CRLF
	OUT1 'A'
	CRLF
	JMP AGAIN
B:							;级别B
	CRLF
	OUT1 'B'
	CRLF
	JMP AGAIN
C0:							;级别C
	CRLF
	OUT1 'C'
	CRLF
	JMP AGAIN
D:							;级别D
	CRLF
	OUT1 'D'
	CRLF
	JMP AGAIN
F:							;级别F
	CRLF
	OUT1 'F'
	CRLF
	JMP AGAIN


EXIT:
	MOV AH,4CH
	INT 21H

CODE ENDS
	END START