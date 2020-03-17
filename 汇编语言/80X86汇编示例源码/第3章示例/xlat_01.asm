.386
DATA SEGMENT USE16
  NUM DB 'Hello World! How Are You!'
  LEN DW $-NUM
  
  TAB DB '!@#?%^&*()!@#?%^&*()!@#?%^&*()!@#?%^&*()!@#?%^&*()!@#?%^&*()!@#?%^&*()!@#?%^&*()!@#?%^&*()!@#?%^&*()',
         '!@#?%^&*()!@#?%^&*()!@#?%^&*()!@#?%^&*()!@#?%^&*()!@#?%^&*()!@#?%^&*()!@#?%^&*()!@#?%^&*()!@#?%^&*()',
         '!@#?%^&*()!@#?%^&*()!@#?%^&*()!@#?%^&*()!@#?%^&*()!@#?%^'
  
  MSG DB 255 DUP('$')
  
DATA ENDS

STACK SEGMENT USE16 STACK
  DB 200 DUP(0)
STACK ENDS

CODE SEGMENT USE16
     ASSUME CS:CODE,DS:DATA
BEGIN:
     MOV AX, DATA
     MOV DS, AX
     
     LEA SI,NUM
     LEA DI,MSG
     
     LEA BX,TAB
     
     MOV CX,LEN
LOOP1:
     MOV AL,[SI]
     INC SI
     XLAT
     MOV [DI], AL
     INC DI
     DEC CX
     JNE LOOP1
     
     LEA DX, MSG
     MOV AH, 9
     INT 21H
     
     MOV AH, 4CH
     INT 21H
CODE ENDS
     END BEGIN