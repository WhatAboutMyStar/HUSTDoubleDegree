/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//InitQueue.cpp
//This program is to create SqQueue
# include <malloc.h>
# include <iostream.h>
# include <conio.h>
# define MAXQSIZE 100
# define OK 1
# define ERROR 0

typedef int QElemType;
typedef struct SqQueue		//define structure SqQueue
{    
	QElemType *base; // 缓冲头
    int front; // 头指针
    int rear; // 尾指针
}SqQueue;

/* 初始化队列 */
int InitQueue(SqQueue &Q)	//InitQueue() sub-function
{   
	Q.base=(QElemType *)malloc(MAXQSIZE*sizeof(QElemType)); // 创建缓冲
    if(!Q.base)
    {   
		cout<<endl<<"Overflow ! ";
	    return (ERROR);
    }
    Q.front=Q.rear=0; // 空队列
    return (OK);
} //InitQueue() end

void main()			//main function
{  
	SqQueue Q;
    cout<<endl<<endl<<"InitQueue.cpp";
    cout<<endl<<"=============";
    if(InitQueue(Q))
		cout<<endl<<endl<<"Success ! The SqQueue has been initilized !";
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end