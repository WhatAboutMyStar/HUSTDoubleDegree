;  (1) 两组数据分别进行排序
;  (2) 将子程序写在了一个段中
;  (3) 观察  执行CALL 指令时，堆栈的变化，CS, IP的变化
;  (4) 观察执行　RET指令堆栈的变化
;　(5) 观察排序前后的数据区变化

;  CX 数据个数  (对 0 ...... N-1 之间的 N个数排序)
;  BX 数据的首地址  
.386
SUB_PROGRAM  SGEMENT USE16 
      ASSUME CS:SUB_PROGRAM
SORT  PROC  FAR
      PUSH  AX
      PUSH  DX
      PUSH  SI
      PUSH  DI
                      
      MOV   DX, CX
      DEC   DX          

      MOV   SI, 0
LOPI: 
      MOV   AL, [BX+SI]
      MOV   DI, SI
      INC   DI
LOPJ: CMP   AL, [BX+DI]
      JBE   NEXT
      XCHG  [BX+DI], AL
      MOV   [BX+SI], AL
NEXT: INC   DI
      CMP   DI, CX
      JB    LOPJ   ;   内循环 ，当指向第二个数的指针 小于 (CX) 时

      INC   SI
      CMP   SI, DX
      JB    LOPI
      POP   DI
      POP   SI
      POP   DX
      POP   AX
      RET
SORT  ENDP
SUB_PROGRAM ENDS

STACK SEGMENT   USE16 STACK
      DB 50 DUP(0)
STACK ENDS

DATA  SEGMENT USE16 
BUF1  DB 30H,10H,40H,20H,50H,70H,60H,90H,80H,0,0FFH
N1 = $-BUF1
BUF2  DB 22H,11H,33H,55H,44H,77H,66H,99H,88H,0AAH,0EEH,0
N2=  $ - BUF2
DATA  ENDS

CODE SEGMENT USE16 
     ASSUME CS:CODE,DS:DATA,SS:STACK
BEGIN:
     MOV  AX, DATA
     MOV  DS, AX
     LEA  BX, BUF1
     MOV  CX, N1
     CALL FAR PTR SORT
     LEA  BX, BUF2
     MOV  CX, N2
     CALL FAR PTR SORT
     MOV  AH,4CH
     INT  21H
CODE ENDS
     END  BEGIN
