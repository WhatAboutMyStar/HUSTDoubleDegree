/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//ListDelete_Sq.cpp
//Delete the NO.i Element of Sq_List and get the value

#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
#include <stdio.h>

//#define LIST_INIT_LENGTH 10  //LIST_INIT_LENGTH is the Init_Define_Length of Sq_List
//int array[LIST_INIT_LENGTH]={5,8,12,18,25,30,37,46,51,89};
			    //array use to assign init value of SqList
#define ElemType int
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct 
{	
	int *elem; // 缓冲头
	int length; // 数据长度
	int listsize; // 缓冲大小
}SqList;

/* 初始化SqList */
int InitList_Sq(SqList &L)                                    //InitList_Sq() function
{   //Inititial a Sq_List
	L.elem=(int *)malloc(LIST_INIT_SIZE *sizeof(int)); // 创建缓冲
	if (!L.elem) return(0);
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	return (1);
}//end of InitList_Sq() function

/* 删除缓冲中某个元素 */
void ListDelete_Sq(SqList &L,int i, int &e)            //ListDelete_Sq() function
{
   int *p,*q;
   if((i<1)||(i>L.length)) // 参数有效性检测
   { 
	  cout<<i<<" is OverFlow !"<<endl;
	  exit(0);
   }
   p=&(L.elem[i-1]); // 提取第i-1个元素
   e=*p;
   q=L.elem+L.length-1;
   for (++p;p<=q;++p) // 调整缓冲
      *(p-1)=*p;
   --L.length; // 数据长度减1
   cout<<"Success to Delete Sq_list !"<<endl;
}//end of ListDelete_Sq() function

void main()                                             //main() function
{
   SqList L;
   int e;
   int i,j;
   //L.elem=array;
   //L.length=LIST_INIT_LENGTH;
   cout<<"ListDelete_Sq.cpp"<<endl<<"================="<<endl<<endl;
   
   InitList_Sq(L);
   cout<<"Please input the Length of Demo SqList L: <eg. 5> ";
   cin>>L.length;
   cout<<"Please input the data of Demo SqList L: <eg. {34,54,30,2,40,...}> "<<endl;
   for(j=0;j<L.length;j++)
      cin>>L.elem[j];
	 
   cout<<endl;
   cout<<"Success to create a SqList:"<<endl;
   cout<<"Please input the NO.i element of Sq_List to delete:  <eg. 3> ";
   cin>>i;
   ListDelete_Sq(L,i,e);
   cout<<"The SqList After Delete is:  ";
   for(j=0;j<L.length;j++)
      cout<<L.elem[j]<<"  ";
   cout<<endl<<"...OK...!"<<endl;
   getch();
}//end of main() function
