/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//DeQueue.cpp
//This program is to delete the first element of the SqQueue
# include <malloc.h>
# include <iostream.h>
# include <conio.h>

# define MAXQSIZE 100
# define OK 1
# define ERROR 0

typedef int QElemType;

typedef struct SqQueue			//define structure SqQueue
{    
	QElemType *base; // 缓冲头
    int front; // 头指针
    int rear; // 尾指针
}SqQueue;

/* 往循环队列插入元素 */
int EnQueue(SqQueue &Q,QElemType e)	//EnQueue() sub-function
{   
	if((Q.rear+1)%MAXQSIZE==Q.front) // 满队列，少用一个元素空间
    {   
		cout<<"Errer ! The SqQeueu is full ! ";
	    return (ERROR);
    }
    Q.base[Q.rear]=e; // 插入元素
    Q.rear=(Q.rear+1)%MAXQSIZE; // 移动尾指针，尾指针指向下一个空闲
    return (OK);
} //EnQueue() end

/* 删除循环队列元素 */
int DeQueue(SqQueue &Q,QElemType &e)	//DeQueue() sub-function
{  
	if(Q.front==Q.rear) // 空队列
    {    
		cout<<endl<<"Errer !  It's empty!";
	    return (ERROR);
    }
    e=Q.base[Q.front]; // 头指针指向当前要读元素
    Q.front=(Q.front+1)%MAXQSIZE; // 调整头指针
    return (e);
} //DeQueue() end

void main()				//main() function
{  
	int i,e=1;
    SqQueue Q;
    Q.base=(QElemType *)malloc(MAXQSIZE*sizeof(QElemType)); // 创建缓冲
    Q.front=Q.rear=0; // 空队列
    cout<<endl<<endl<<"DeQueue.cpp";
    cout<<endl<<"============="<<endl<<endl;
    while(e)
    {   
		cout<<"Please input the integer to insert (eg,58; 0 for exit) : ";
        cin>>e;
        if(e)
	        EnQueue(Q,e);
    }
    i=DeQueue(Q,e);
    if(i)
        cout<<endl<<"The first element is "<<i;
    cout<<endl<<"The new SqQueue is : ";		//output
    for(e=Q.front;e<Q.rear;e++)
        cout<<Q.base[e]<<"  ";
    cout <<endl<<endl<<"...OK!...";
    getch();
} //main() end