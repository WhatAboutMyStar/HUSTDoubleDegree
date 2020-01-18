/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//MergeList_L.cpp
//This program is to merge two sorted LNode into one
//# include <stdio.h>
# include <stdlib.h>
# include <iostream.h>
# include <conio.h>

# define INIT_LENGTH 10

typedef struct LNode		//define  LNode structure
{	
	int data; // 数据域
	struct LNode *next; // 指针域
}LNode,*LinkList;

/* 归并两个单链表 */
void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc) //MergeList_L()
{   
	LNode *pa,*pb,*pc;
    pa=La->next; // La第一个结点
    pb=Lb->next; // Lb第一个结点
    Lc=pc=La;
    cout<<endl;
	/* 原代码，死循环！*/
    while(pa&&pb)
	{
       if(pa->data<=pb->data) // 如果pa数据域<=pb数据域
       {   
		  pc->next=pa; // pa插入pc下一个位置
	      pc=pa; // 调整pc
	      pa=pa->next; // 调整pa
       }
       else
       {   
		  pc->next=pb;
	      pc=pb;
	      pb=pb->next;
       }

       if(!pa)			//the end of pa
       {  
		  pc->next=pb; // 把Lb剩余结点链入
	      pc=pc->next; // 调整pc
		  //printf("here!");
       }
	   /* 改进以后代码 */
	   else if(!pb)    //the end of pb
	   {
		  pc->next=pa; // 把La剩余结点链入
	      pc=pc->next; // 调整pc
		  //printf("here!");
	   }
	   /* 原代码 */
       /*else		 	//the end of pa
       {  
		  pc=pa;
	      pc=pc->next;
       }*/
	}
} //MergeList_L() end

void main()       		//main() function
{    
	int i;
    LNode node1[INIT_LENGTH],node2[INIT_LENGTH],node3[INIT_LENGTH*2];
    LNode *La,*Lb,*Lc,*p,*q;
    int array1[INIT_LENGTH]={5,8,12,18,25,30,37,46,51,89};
    int array2[INIT_LENGTH]={6,9,13,19,26,31,38,47,52,90};
	/* 多此一举？*/
    La=node1;			//La points at node1[]
    La=(LinkList)malloc(sizeof(LNode)); // 创建头结点
    La->next=NULL;
    Lb=node2;			//Lb points at node2[]
    Lb=(LinkList)malloc(sizeof(LNode));
    Lb->next=NULL;
    Lc=node3;		//Lc points at node2[]
    Lc=(LinkList)malloc(sizeof(LNode));
    Lc->next=NULL;
    for (i=INIT_LENGTH;i>0;i--) // 创建结点，给结点数据域赋值并链接结点
    {   
	   p=(LinkList)malloc(sizeof(LNode));	//initial Lb
	   p->data=array1[i-1];
	   p->next=La->next;
	   La->next=p;
	   q=(LinkList)malloc(sizeof(LNode));	//initial Lb
	   q->data=array2[i-1];
	   q->next=Lb->next;
	   Lb->next=q;
    }
    p=La;				//output La
    cout<<endl<<endl<<"MergeList.cpp";
    cout<<endl<<"=============";
    cout <<endl<<endl<<"LNode La is : ";
    for(i=0;i<INIT_LENGTH;i++)
    {   
	   p=p->next;
	   cout<<p->data<<"  ";
    }
    q=Lb;				//output Lb
    cout <<endl<<"LNode Lb is : ";
    for(i=0;i<INIT_LENGTH;i++)
    {   
	   q=q->next;
	   cout<<q->data<<"  ";
    }
    MergeList_L(La,Lb,Lc);		//call MergeList()
    cout <<"LNode Lc is : ";
    p=La;
    for(i=0;i<INIT_LENGTH*2;i++)
    {   
	   p=p->next;
	   cout<<p->data<<" ";
    }
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end