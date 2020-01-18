/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//InitStack.cpp
//This program is to initialize a stack
# include <malloc.h>
# include <iostream.h>
# include <conio.h>

# define STACK_INIT_SIZE 100
# define STACKINCREMENT 10
# define OK 1
# define ERROR 0

typedef int SElemType;

typedef struct			//define structure SqStack()
{    
	SElemType *base; // 栈底
    SElemType *top; // 栈顶
    int stacksize; // 栈大小
}SqStack;

/* 初始化栈 */
int InitStack(SqStack &S)	//InitStack() sub-function
{   
	S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType)); // 分配空间
    if(!S.base)
    {    
		cout<<endl<<"Allocate space failure !";
	    return (ERROR);
    }
    S.top=S.base; // 空栈
    S.stacksize=STACK_INIT_SIZE; // 栈大小
    return (OK);
} //InitStack() end

void main()        	//main() function
{   
	SqStack S;
    cout<<endl<<endl<<"InitStack.cpp";
    cout<<endl<<"=============";
    if(InitStack(S))
		cout<<endl<<endl<<"Success! The stack has been created !";
    cout<<endl<<endl<<"...OK!...";
    getch();
}