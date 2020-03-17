/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//InitList_Sq.cpp

#include <stdlib.h>
#include <malloc.h>
#include <iostream.h>
#include <conio.h>

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
	return(1);
}//end of InitList_Sq() function

void main()                                                  //main() function 
{
    SqList L;
	cout<<"InitList_Sq.cpp"<<endl<<"==============="<<endl<<endl;
    if(!InitList_Sq(L))
       cout<<"Failure to Initialize a Sq_List !"<<endl;
    else
       cout<<"Success to Initialize a Sq_List !"<<endl;
    getch();
}//end of main() function
