/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//CreateList.cpp
//This program is to create two LNode and merge them into one
# include <stdlib.h>
# include <malloc.h>
# include <iostream.h>
# include <conio.h>

# define OK 1
# define ERROR 0

typedef struct LNode		//define the LNode structure
{	
	int data; // 数据域
	struct LNode *next; // 指针域
}LNode,*LinkList;

/* 创建链表 */
int CreateList(LinkList &head,LinkList s,int x,int y)  	//CreateList()
{   
	head=(LinkList)malloc(sizeof(LNode)); // 创建头结点
    if(!head) // 出错处理
    {   
		cout <<endl<<"Overflow ! The first LNode isn't allocated !";
	    return (ERROR); // 返回出错码
	}
    s=(LinkList)malloc(sizeof(LNode)); // 创建结点
    if(!s)
    {   
	    cout <<endl<<"Overflow ! The second LNode isn't allocated !";
	    return (ERROR); 
	}
    head->next=s; // 链接s
    s->next=NULL; // s后继为空
    head->data=x; // 数据域赋值
    s->data=y; // 数据域赋值
    return (OK); // 成功创建链表返回OK
} //CreateList() end

void main()        			//main()  function
{    
	 int x=10,y=15;
     LNode L1,L2;
     LNode *p1,*p2;
     p1=&L1;
     p2=&L2;
     cout<<endl<<endl<<"CreateList.cpp";
     cout<<endl<<"==============";
     if(CreateList(p1,p2,x,y))		//call CreateList()
     {	
		 cout<<endl<<endl<<"OK! The two LNode are : ";
		 cout<<p1->data<<"->"<<p1->next->data; // 打印链表
     }
     cout<<endl<<endl<<"...OK!...";
     getch();
} //main() end