/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//CreateList_L.cpp
//To create a LinkList

#include <stdlib.h>
#include <iostream.h>
#include <conio.h>

typedef struct LNode
{	
	int data; // 数据域
	struct LNode *next; // 指针域
}LNode,*LinkList;

/* 创建链表 */
void CreateList_L(LinkList &L,int n)              //CreateList_L() function
{ //To Creatre a LinkList L with HeadNode 
  int i;
  LNode *p;
  L=(LinkList)malloc(sizeof(LNode)); // 创建头结点
  L->next=NULL;
  cout<<"Please input the data for LinkList Nodes: <eg. 34,67,3,-9,45,...>"<<endl;
  for(i=n;i>0;--i) // 创建n个结点，对结点数据域赋值并链接起来
  {
	  p=(LinkList)malloc(sizeof(LNode)); // 创建结点
	  cin>>p->data;                               //Reverse order inputing for Creating a LinkList
	  p->next=L->next; // 链接结点到链表
	  L->next=p;
  }//end of for
  if(n) cout<<"Success to Create a LinkList !"<<endl;
  else cout<<"A NULL LinkList have been created !"<<endl;
}//end of CreateList() function 

void main()                                       //main() function
{
   LinkList L; // 头指针
   int InitLNodeNum; // 结点数目                              //the Init LinkNode Numbers
   cout<<"CreateList_L.cpp"<<endl<<"================"<<endl;
   cout<<endl<<"Please input the Init LinkNode Number: <eg. 5> ";
   cin>>InitLNodeNum; 
   CreateList_L(L,InitLNodeNum); 
   cout<<"OK...!"<<endl;
   getch();
}//end of main() function
