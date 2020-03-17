/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//EnQueue.cpp
//This program is to insert an element into the end of LinkQueue
# include <malloc.h>
# include <iostream.h>
# include <conio.h>

# define MAXQSIZE 100
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

/* 初始化循环队列 */
int InitQueue(LinkQueue &Q)	//InitQueue() subfunction
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

/* 往循环队列插入元素 */
int EnQueue(LinkQueue &Q,QElemType e)	//EnQueue() sub-function
{   
	QNode *p;
    p=(QueuePtr)malloc(sizeof(QNode)); // 创建结点
    if(!p)
    {  
		cout<<endl<<"Overflow !";
        return (ERROR);
    }
    p->data=e; // 数据域
    p->next=NULL; // 指针域
    if(Q.front==NULL) // 没有头结点
    {   
		Q.front=Q.rear=p;
	    return (OK);
    }
    Q.rear->next=p; // 新结点插入队列尾
    Q.rear=p; // 调整尾指针
    return (OK);
} //EnQueue() end

void main()			//main() function
{  
	int e=1;
    LinkQueue Q;
    QNode *q;
    InitQueue(Q);		//call InitQueue()
    cout<<endl<<endl<<"EnQueue.cpp";
    cout<<endl<<"==========="<<endl<<endl;
    while(e)
    {    
		cout<<"Please input integer (eg,58; 0 for exit) : ";
	    cin>>e;
	    if(e)
			EnQueue(Q,e);	//call EnQueue()
    }
    cout<<endl<<"The LinkQueue is : ";
    for(q=Q.front->next;q!=NULL;q=q->next)
		cout<<q->data<<"  ";
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end