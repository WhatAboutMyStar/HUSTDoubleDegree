/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//ListInsert_Dul.cpp
//This program is to insert a node into the DuLinkList
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

/* 往双链表某个位置插入结点 */
int ListInsert_DuL(DuLinkList &L,int i,int e)	//ListInsert_Dul()
{   
	DuLNode *p=L,*s;
    int j=0;
    if (i<1||i>INIT_LENGTH+1)	//out of location
    {   
	   cout<<"Errer! Out of location !";
	   return (ERROR);
    }
    while(j<i)                 	//delete the i_th element
    {  
	   p=p->next;
       ++j;
    } // p指向第i个结点
    if(!(s=(DuLinkList)malloc(sizeof(DuLNode)))) // 创建新结点
    {  
	   cout<<endl<<"Allocate space failure ! " ;
       return (ERROR);
    }
    s->data=e; // 新结点数据域
    s->prior=p->prior; // 插入p所指结点之前
    s->next=p;
    if(i==1) // 如果插入为第1个结点
	   L->next=s;
    p->prior->next=s;
    p->prior=s;
    return (OK);
} //ListInsert_Dul() end

void main()        		//main() function
{    
	int i,j,e;
    //DuLNode node[10];
    DuLNode *L,*p,/* 新增变量 */*pre;
    int array[INIT_LENGTH+1]={5,8,12,18,25,30,37,46,51,89};
    L=(DuLinkList)malloc(sizeof(DuLNode)); // 创建头结点
    L->next=NULL;
    L->prior=NULL;
	pre=L;
    for (i=INIT_LENGTH;i>0;i--)
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
    cout<<endl<<endl<<"ListInsert_Dul.cpp";
    cout<<endl<<"==================";
    cout <<endl<<endl<<"The old DuLNode is : ";  //output the old DuLinkList
    for(j=0;j<INIT_LENGTH;j++)
    {   
	   p=p->next;
	   cout<<p->data<<" ";
    }
    cout<<endl<<endl<<"Please input the location to insert (1--11) : ";
    cin>>i;
    cout<<"Please input the integer to insert (eg,58)  : ";
    cin>>e;
    if(ListInsert_DuL(L,i,e))
    {	
	   cout <<endl<<"The new DuLNode is : ";
	   p=L;
	   for(i=0;i<INIT_LENGTH+1;i++)
	   {  
	      p=p->next;
	      cout<<p->data<<" ";
	   }
    }
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end