/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//LinkQueue operation
//This program is to initialize, Insert, Delete LinkQueue
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

typedef struct			//define structure LinkQueue
{   
	QueuePtr rear; // 尾指针
}LinkQueue;

int InitQueue(LinkQueue &Q)	//InitQueue() suvb-function
{    
	Q.rear=(QueuePtr)malloc(sizeof(QNode)); // 创建头结点
    if(!Q.rear)
    {    
		cout<<endl<<"Overflow !";
	    return (ERROR);
    }
    Q.rear->next=Q.rear; // 空循环队列
    return (OK);
} //InitQueue() end

int Insert(LinkQueue &Q,QElemType x)	//EnQueue() sub-function
{   
	QNode *p;
    p=(QueuePtr)malloc(sizeof(QNode)); // 创建结点
    if(!p)
    {  
		cout<<endl<<"Overflow !";
        return (ERROR);
    }
    p->data=x; // 数据域
    p->next=Q.rear->next; // 新结点插入队列末尾
    Q.rear->next=p;
    Q.rear=p; // 调整尾指针
    return (OK);
} //Insert() end

int Delete(LinkQueue &Q,QElemType &x)	//Delete() sub-function
{   
	QNode *q,*p;
    if(Q.rear->next==Q.rear) // 空循环队列
    {   
		cout<<"Empty! Can't delete!";
	    return (ERROR);
    }
    else
    {   
		p=Q.rear->next; // p指向所要删除前一个结点
	    x=p->next->data; // 获取数据域
	    q=p->next; // q指向所要删除结点
	    p->next=p->next->next; // 调整链表
    }
    free(q); // 释放结点
    return (OK);
} //Delete() end

void main()				//main() function
{    
	//int j;
    QElemType x=1;
    LinkQueue Q;
    //QNode *p;
    InitQueue(Q);
    cout<<endl<<endl<<"LinkQueue Operation";
    cout<<endl<<"==================="<<endl<<endl;
    while(x)
	{  
		cout<<"Please input an integar (eg,58; 0 for exit): ";
	    cin>>x;
	    Insert(Q,x);			//call Insert()
    }
    Delete(Q,x);			//call Delete()
    cout<<endl<<"The first element of LinkQueue is: "<<x;
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main()