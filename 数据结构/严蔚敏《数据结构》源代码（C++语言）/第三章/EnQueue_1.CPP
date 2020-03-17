/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//EnQueue.cpp
//This program is to calculate the length of the SqQueue
# include <malloc.h>
# include <iostream.h>
# include <conio.h>

# define MAXQSIZE 100
# define LENGTH 10
# define OK 1
# define ERROR 0

typedef int QElemType;
static int array[LENGTH]={5,8,12,18,25,30,37,46,51,89};

typedef struct SqQueue			//define structure SqQueue
{    
	QElemType *base; // 缓冲头
    int front; // 头指针
    int rear; // 尾指针
}SqQueue;

/* 往循环队列插入元素 */
int EnQueue(SqQueue &Q,QElemType e)	//EnQueue() sub-function
{   
	if((Q.rear+1)%MAXQSIZE==Q.front) // 满队列
    {   
		cout<<"Errer ! The SqQeueu is full ! ";
	    return (ERROR);
    }
    Q.base[Q.rear]=e; // 插入循环队列
    Q.rear=(Q.rear+1)%MAXQSIZE; // 调整尾指针
    return (OK);
} //EnQueue() end

void main()				//main function
{  
	int e=1;
    SqQueue Q;
    Q.base=(QElemType *)malloc(MAXQSIZE*sizeof(QElemType)); // 创建缓冲
    Q.front=Q.rear=0; // 空队列
    cout<<endl<<endl<<"EnQueue.cpp";
    cout<<endl<<"==========="<<endl<<endl;
    while(e)
    {   
		cout<<"Please input the data to insert (eg,58; 0 for exit) : ";
        cin>>e;
        if (e)
			EnQueue(Q,e);
    }
    cout<<endl<<"The SqQueue is : ";		//output the SqQueue
    for(e=0;e<Q.rear;e++)
		cout<<Q.base[e]<<"  ";
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end