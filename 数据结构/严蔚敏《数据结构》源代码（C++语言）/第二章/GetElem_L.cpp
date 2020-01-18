/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//GetElem_L.cpp
//Get the NO.i Element of LinkList 

#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
#define ElemType int 
#define LIST_MAX_LENGTH 100  //LIST_MAX_LENGTH is the MaxLength of LinkList

typedef struct LNode
{	
	ElemType data; // 数据域
	struct LNode *next; // 指针域
}LNode,*LinkList;

void CreateList_L(LinkList &L,int n)               //CreateList_L() function
{  //To Creatre a LinkList L with HeadNode 
   int i;
   LNode *p;
   L=(LinkList)malloc(sizeof(LNode)); // 创建头结点
   L->next=NULL;
   for(i=n;i>0;--i) // 创建n个结点，对结点数据域赋值并链接结点
   {
	   p=(LinkList)malloc(sizeof(LNode));
	   cin>>p->data;                          //for example to a CreateList
	   p->next=L->next;
	   L->next=p;
   } //end of for
}//end of CreateList_L() function

/* 获取链表某个结点的数据域，存储e中返回 */
int GetElem_L(LinkList L,int i,int &e)             //GetElem_L() function
{  //L is the HeadPointer of LinkList with HeadNode,when the No.i exist,assign the
   //value to variable e and return "OK!" otherwise return "Error!"  
   LNode *p;
   int j=1;
   p=L->next; // 第一个结点
   while(p&&j<i) 
   {p=p->next;++j;} // 寻找第i个结点，直到链表结束或者j>=i
   if(!p||j>i) // 如果结点为空，或者j>i
   { 
	   cout<<"The NO. "<<i<<" element is not exist !"<<endl;
       getch();
       exit(0);
   }//end of if
   e=p->data; // 取第i个结点数据域
   return (e); 
}//end of GetElem_L() function

void main()                                                 //main() function
{
   LinkList L;
   int e;                                                   //e can be Every DataType 
   int i,LListNodeNum;                                    //j is a counter for cycle 
   cout<<"GetElem_L.cpp"<<endl<<"==============="<<endl<<endl;
   cout<<"Please input the LinkList NodeNum: <eg. 6> ";
   cin>>LListNodeNum;
   cout<<"Please input the LinkList NodeData: <23,45,2,5,-2,34,...> "<<endl;
    
   CreateList_L(L,LListNodeNum); 
   cout<<endl<<"Success to CreateList L!"<<endl;
   cout<<"Which NO.? element of LinkList you want to get: <eg. 3>  ";
   cin>>i;                                                 //input the No.i
   if(i>LListNodeNum) cout<<endl<<"Input Error!"<<endl;
   GetElem_L(L,LListNodeNum-i+1,e);
   cout<<endl<<"The NO."<<i<<" element of LinkList is: "<<e;
   cout<<endl<<"...OK...!"<<endl;
   getch();
}
