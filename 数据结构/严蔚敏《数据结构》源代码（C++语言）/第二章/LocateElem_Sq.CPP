/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//LocateElem_Sq.cpp
//This program is to find a element in the Sqlist
# include <stdlib.h>
# include <malloc.h>
# include <iostream.h>
# include <conio.h>

# define LIST_INIT_SIZE 100
# define LIST_INIT_LENGTH 10
# define LISTINCREMENT 10
# define OK 1
# define ERROR 0

typedef struct SqList			//define the SqList structure
{	
	int *elem; // 缓冲头
	int length; // 数据长度
	int listsize; // 缓冲大小
}SqList;

/* 检索缓冲，代码不完善 */
int LocateElem_Sq(SqList L,int e)	//LocateElem_Sq() sub-function
{  
	int i=1;
    int *p=L.elem;
    while(i<=L.length&&*p++!=e) // 查找值为e的元素
       ++i;
    if(i<=L.length) 
       return (i); // 返回所在位置
    else
       return (ERROR);
} //LocateElem_Sq() end

void main()        			//main() function
{    
	int e,j;
    SqList list;
    int array[10]={5,8,12,18,25,30,37,46,51,89};
    list.length=LIST_INIT_LENGTH;
    list.listsize=LIST_INIT_SIZE;
    list.elem=array;
    cout<<endl<<endl<<"LocateElem_Sq.cpp";
    cout<<endl<<"=================";
    cout<<endl<<endl<<"The old Sqlist is : ";
    for(j=0;j<10;j++)
       cout<<array[j]<<" ";
    cout<<endl<<endl<<"Please input the element to find : ";
    cin>>e;
    j=LocateElem_Sq(list,e);		//call LocateElem_Sq()_
    if(j)
       cout<<endl<<e<<" is found !"<<endl<<"Its location is "<<j<<" !";
    else
       cout<<e<<" is not found! ";
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end