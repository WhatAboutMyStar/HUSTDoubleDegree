/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//Simulation System
//This program is a Simulation Systemo
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

int InitQueue(LinkQueue &Q)	//InitQueue() sub-function
{    
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode)); // 创建头结点
    if(!Q.front)
    {    
		cout<<endl<<"Overflow !";
	    return (ERROR);
    }
    Q.front->next=NULL; // 空循环队列
    return (OK);
} //InitQueue() end

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
		Q.front=p;
	    Q.rear=p;
	    return (OK);
    }
    Q.rear->next=p; // 新结点插入队列尾
    Q.rear=p; // 调整尾指针
    return (OK);
} //EnQueue() end

int DeQueue(LinkQueue &Q,QElemType &e)	//DeQueue() sub-function
{   
	if(Q.front==Q.rear) // 满队列
    { 
		cout<<endl<<"If it was deleted, it's empty !";
        return 0;
    }
    QNode *p;
    p=Q.front->next; // 头指针所指下一个结点
    e=p->data; // 获取数据域
    Q.front->next=p->next; // 调整链表
    free(p); // 释放结点
    return (OK);
} //DeQueue() end

/* 输出队列 */
void OutQueue(LinkQueue &Q)		//Output()  sub-function
{   
	QNode *p;
    p=Q.front;
    cout<<"Queue : ";
    while(p!=Q.rear)
    {  
		p=p->next;
        cout<<p->data<<"  ";
    }
    cout<<endl;
} //OutQueue() end

void main()				//main() function
{    
	int j;
    LinkQueue LQ;
    //QNode *p;
    InitQueue(LQ);			//call InitQueue()
    cout<<endl<<endl<<"Simulation System";
    cout<<endl<<"================="<<endl<<endl;
    cout<<"Please input a integer ( 0 for exit ) :";
    cin>>j;
    while(j)
    {   
		if(j%2==1)    
			EnQueue(LQ,j);	//call EnQueue()
	    else	      
			DeQueue(LQ,j);	//call DeQueue()
	    OutQueue(LQ);			//call OutQueue()
	    cout<<endl<<"Please input a integer ( 0 for exit ) :";
	    cin>>j;
    }
    getch();
} //main() end