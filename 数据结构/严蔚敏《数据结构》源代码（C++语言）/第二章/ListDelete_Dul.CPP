/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//ListDelete_Dul.cpp
//This program is to delete an element in the DuLinkList
# include <stdlib.h>
# include <malloc.h>
# include <iostream.h>
# include <conio.h>

# define INIT_LENGTH 10
# define OK 1
# define ERROR 0

typedef struct DuLNode 		//define DuLinkList structure
{
	int data; // 数据域
	struct DuLNode *prior; // 直接前驱
	struct DuLNode *next; // 直接后继
}DuLNode,*DuLinkList;

/* 删除双链表某个结点 */
int ListDelete_DuL(DuLinkList &L,int i,int &e)	//ListDelete_Dul() sub-function
{  
	DuLNode *p=L;
    int j=0;
    if (i<1||i>INIT_LENGTH)	//out of location
    {  
	   cout<<"Errer! Out of location!";
	   return (ERROR);
    }
    if(i==1)			//delete the first element
    {  
	   //p->next->prior=NULL; // 多此一举？
       p=p->next; // 第一个结点
       e=p->data; // 取数据域
	   /************
	    失败，断链！
	   ************/
       //L=p;
	   /*************
	    改进以后代码
	   *************/
	   L->next=p->next; // 头结点的下一个是第二个结点
	   p->next->prior=L; // 第二个结点的前一个是头结点
       free(p); // 释放第一个结点
       return (e);
    }
    while(j<i)                 	//delete the i_th element
    {  
	   p=p->next;
       ++j;
    } // 找到第i个结点，这个程序竟然没有出错处理？
    e=p->data; // 取数据域
    p->prior->next=p->next; // 当前结点的前一个结点的下一个是当前结点的下一个
    p->next->prior=p->prior; // 当前结点的下一个结点的前一个是当前结点的前一个
    free(p); // 释放当前结点
    return (e);
} //ListDelete_Dul() end

void main()        		//main() function
{    
	 int i,j,e;
     //DuLNode node[10];
     DuLNode *L,*p,/* 新增变量 */*pre;
     int array[INIT_LENGTH]={5,8,12,18,25,30,37,46,51,89};
     L=(DuLinkList)malloc(sizeof(DuLNode)); // 创建头结点
     L->next=NULL;
     L->prior=NULL;
	 pre=L;
     for (i=INIT_LENGTH;i>0;i--) // 创建结点，给结点数据域赋值并链接结点
     {	 
		 p=(DuLinkList)malloc(sizeof(DuLNode));
	     p->data=array[i-1];
		 /*********************
		  原代码创建双链表失败
		 *********************/
	     //p->next=L->next;
	     //p->next->prior=p;
	     //L->next=p;

#define HEAD 0

#if HEAD!=1
	#define TAIL 1
#endif

		 /*************************
		  代码修改如下，从头部链接
		 *************************/
#if HEAD       
		 if(i==INIT_LENGTH)// 第一个结点的处理
		 {
			 p->prior=L; // 当前结点前一个是头结点
			 p->next=L->next; // 当前结点下一个是头结点的下一个结点
			 L->next=p; // 头结点下一个是当前结点
		 }
		 else
		 {
			 p->prior=L; // 当前结点前一个是头结点
			 p->next=L->next; // 当前结点下一个是头结点的下一个结点
			 L->next->prior=p; // 头结点下一结点的前一结点是当前结点
			 L->next=p; // 头结点下一个是当前结点
		 }		 

		 /*************************
		  代码修改如下，从尾部链接
		 *************************/
#elif TAIL
		 p->prior=pre; // 当前结点前一个是pre
		 p->next=NULL; // 当前结点为末尾结点
		 pre->next=p; // pre下一个是当前结点
		 pre=p; // 修改pre指向当前结点
#endif
     }
     p=L;
     cout<<endl<<endl<<"ListDelete_Dul.cpp";
     cout<<endl<<"==================";
     cout <<endl<<endl<<"The old DuLNode is : ";  //output the old DuLinkList
     for(i=0;i<INIT_LENGTH;i++)
     {   
		 p=p->next;
	     cout<<p->data<<" ";
     }
     cout<<endl<<endl<<"Please input the location to delete (1--10): ";
     cin>>j;
     i=ListDelete_DuL(L,j,e);		//call ListDelete_Dul()
     if (i)
     {  
		 cout <<"The deleted element is : "<<i<<endl;
	     cout <<"The new DuLNode is : ";
	     p=L;
	     for(i=0;i<INIT_LENGTH-1;i++)
		 {   
			 p=p->next;
	         cout<<p->data<<" ";
		 }
     }
     cout<<endl<<endl<<"...OK!...";
     getch();
}