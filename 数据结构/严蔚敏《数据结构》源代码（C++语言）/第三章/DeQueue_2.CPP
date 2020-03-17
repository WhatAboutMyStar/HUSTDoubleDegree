/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//DeQueue.cpp
//This program is to delete the first element of LinkQueue
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

/* 创建空队列 */
int InitQueue(LinkQueue &Q)	//InitQueue() sub-function
{    
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode)); // 分配空间
    if(!Q.front)
    {    
		cout<<endl<<"Overflow !";
	    return (ERROR);
    }
    Q.front->next=NULL; // 空队列
    return (OK);
} //InitQueue() end

/* 往队列插入结点 */
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
    Q.rear->next=p; // 插入到队列末尾
    Q.rear=p; // 调整尾指针
    return (OK);
} //EnQueue() end

/* 删除队列结点 */
int DeQueue(LinkQueue &Q,QElemType &e)	//DeQueue() sub-function
{   
	if(Q.front==Q.rear) // 空队列
    { 
		cout<<endl<<"If it was deleted, it's empty !";
        return (ERROR);
    }
    QNode *p;
    p=Q.front->next; // 第一个结点
    e=p->data; // 获取该数据域
    Q.front->next=p->next; // 调整链表
    free(p); // 释放结点
    return (OK);
} //DeQueue() end

void main()				//main() function
{  
	int e=1;
    LinkQueue Q;
    QNode *q;
    InitQueue(Q);
    cout<<endl<<endl<<"DeQueue.cpp";
    cout<<endl<<"==========="<<endl<<endl;
    while(e)
    {    
		cout<<"Please input integer (eg,58; 0 for exit ) : ";
	    cin>>e;
	    if(e)
			EnQueue(Q,e);		//call EnQueue()
    }
    cout<<"The inputed QNode is : ";
    for(q=Q.front->next;q!=NULL;q=q->next)
		cout<<q->data<<"  ";
    if(DeQueue(Q,e))			//call DeQueue()
    {  
		cout<<endl<<"The first element is "<<e<<endl;
        cout<<"The new QNode is : ";
        for(q=Q.front->next;q!=NULL;q=q->next)
	    cout<<q->data<<"  ";
    }
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end