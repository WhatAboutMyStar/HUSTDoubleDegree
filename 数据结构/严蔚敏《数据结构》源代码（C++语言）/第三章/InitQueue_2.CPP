/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//InitQueue.cpp
//This program is to delete the first element of the LinkQueue
# include <malloc.h>
# include <iostream.h>
# include <conio.h>

# define OK 1
# define ERROR 0

typedef int QElemType;

typedef struct QNode		//define structure QNode
{    
	QElemType data; // 数据域
    struct QNode *next; // 指针域
}QNode,*QueuePtr;

typedef struct LinkQueue	//define structure LinkQueue
{    
	QueuePtr front; // 头指针
    QueuePtr rear; // 尾指针
}LinkQueue;

/* 初始化队列 */
int InitQueue(LinkQueue &Q)	//InitQueue() sub-function
{    
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode)); // 创建头结点
    if(!Q.front)
    {    
		cout<<endl<<"Overflow !";
	    return (ERROR);
    }
    Q.front->next=NULL; // 空队列
    return (OK);
} //InitQueue() end

void main()			//main() function
{  
	LinkQueue Q;
    cout<<endl<<endl<<"InitQueue.cpp";
    cout<<endl<<"===============";
    if(InitQueue(Q))		//call InitQueue()
		cout<<endl<<endl<<"Initial Success !";
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end