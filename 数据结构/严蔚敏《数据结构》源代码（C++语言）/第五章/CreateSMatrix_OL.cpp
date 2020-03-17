/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//CreateSMatrix_OL.cpp

#include <stdarg.h>
#include <iostream.h>
#include <malloc.h>
#include <stdio.h>
#include <conio.h>

#define OVERFLOW -1
#define OK 1

typedef int ElemType;
typedef struct OLNode
{   
	int i,j; // 非零元素的行下标和列下标
	ElemType e; // 元素值
	struct OLNode *right,*down; // 非零元素所在行表和列表的后继链域
}OLNode,*Olink;

typedef struct
{   
	Olink *rhead,*chead; // 行和列链表头指针向量基址
	int mu,nu,tu; // 稀疏矩阵的行数、列数和非零元素个数
}CrossList;

/* 建立十字链表 */
int CreateSMatrix_OL(CrossList &M)
{   //To CreateSMatrix M with CrossList type 
	int m,n,t,i,j,k,e;
	Olink p,q;
	/* 原代码清空操作失败 */
	//if(&M) free(&M); 
	printf("Please input the M.mu,M.nu and M.tu: <eg. M.mu=5,M.nu=4,M.tu=7>\n");
	scanf("%d%d%d",&m,&n,&t); // 输入行数、列数和非零元素个数
	M.mu=m;
	M.nu=n;
	M.tu=t;
	/* 参数检测 */
	if(M.tu>M.mu*M.nu) return(OVERFLOW);
	/* 创建行、列链表头结点 */
	if((M.rhead=(Olink*) malloc((m+1)*sizeof(Olink)))==NULL) return(OVERFLOW);
	if((M.chead=(Olink*)malloc((n+1)*sizeof(Olink)))==NULL) return(OVERFLOW);
	/* 初始化行、列链表 */
	for(i=0;i<M.mu;i++)
		M.rhead[i]=NULL;
    for(i=0;i<M.nu;i++)
		M.chead[i]=NULL;
	printf("Please input the i,j and e: <eg. i=2,j=3,e=89... To exit if input e=0>\n");
	printf("(0<=i<=%d),(0<=j<=%d)\n",M.mu-1,M.nu-1);
	/* 按任意次序输入非零元素 */
	for(scanf("%d%d%d",&i,&j,&e),k=1;e!=0&&k<=M.tu;printf("Please input the next i,j and e:\n"),scanf("%d%d%d",&i,&j,&e),k++)
	{ 
		/* 参数检测 */
		if(i>=M.mu||j>=M.nu||i<0||j<0) return(OVERFLOW);         //Control user input,[] from zero on
		if((p=(OLNode*)malloc(sizeof(OLNode)))==NULL) return(OVERFLOW); // 创建结点
		/* 给结点赋值 */
		p->i=i;
		p->j=j;
		p->e=e;
		if(M.rhead[i]==NULL) // 行表为空
		{
			M.rhead[i]=p;
		    p->right=NULL;
		}//end of if
	    else if (M.rhead[i]->j>j) // 小于现有列
		{ 
			p->right=M.rhead[i]; // 插入现有结点之前
		    M.rhead[i]=p;
		}//end of if
        else 
		{  
			for(q=M.rhead[i];(q->right)&&q->right->j<j;q=q->right); // 寻找在行表中的插入位置
			p->right=q->right; // 插入结点
			q->right=p;
		}//over the line insert
		if(M.chead[j]==NULL) // 列表为空
		{ 
			M.chead[j]=p;
			p->down=NULL;
		}//end of if(M.chead[j]==NULL)
		else if(M.chead[j]->i>i) // 小于现有行
		{ 
			p->down=M.rhead[j]; // 插入现有结点之前
		    M.rhead[j]=p;
		}//end of if
		else 
		{
			for(q=M.chead[j];(q->down)&&q->down->i<i;q=q->down); // 寻找在列表中的插入位置
			p->down=q->down;  // 插入结点
		    q->down=p;
		}//end of column insert
	}// end of for
	return (OK);
}//CreateSMatrix_OL
				
void main()                                          //main() function
{   
    CrossList M;
	cout<<"CreateSMatrix_OL.cpp"<<endl<<"===================="<<endl<<endl;
	if(CreateSMatrix_OL(M)==OK)  
		cout<<"Success to CreateSMatrix M!"<<endl;
	else
		cout<<"Error!"<<endl;
   	getch();
}//end of main



