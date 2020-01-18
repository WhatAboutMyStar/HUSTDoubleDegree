/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//DestroyQueue.cpp
//This program is to destrpu SqQueue
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
	/* 无头结点 */
    if(Q.front==NULL)		//new QNode
    {   
		Q.front=Q.rear=p;
	    return (OK);
    }
    Q.rear->next=p; // 新结点插入队列末尾
    Q.rear=p; // 调整尾指针
    return (OK);
} //EnQueue() end

/* 销毁队列 */
int DestroyQueue(LinkQueue &Q)	//DestroyQueue() sub-function
{   
	while(Q.front) // 从头部开始释放
    {   
		Q.rear=Q.front->next;
	    free(Q.front);
	    Q.front=Q.rear;
    }
    return (OK);
} //DestroyQueue() end

void main()			//main() function
{  
	int e=1;
    LinkQueue Q;
    QNode *q;
    Q.front=Q.rear=NULL;
    cout<<endl<<endl<<"DestroyQueue.cpp";
    cout<<endl<<"================"<<endl<<endl;
    while(e)
    {    
		cout<<"Please input integer (eg,58; 0 for exit ) : ";
	    cin>>e;
	    if(e)
			EnQueue(Q,e);       //call EnQueue()
    }
    cout<<endl<<"The new QNode is : ";
    for(q=Q.front;q!=NULL;q=q->next)
	    cout<<q->data<<"  ";
    DestroyQueue(Q);		//call DestroyQueue()
    cout<<endl<<endl<<"It has been destroyed successfully !";
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end