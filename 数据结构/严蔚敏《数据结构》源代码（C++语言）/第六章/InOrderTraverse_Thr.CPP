/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//InOrderTraverse.cpp
//This function is to InOrderTraverse BiThrTree
# include <malloc.h>
# include <iostream.h>
# include <conio.h>

# define OK 1
# define ERROR 0

typedef enum{Link,Thread} PointerTag;
typedef char TElemType;

typedef struct BiThrNode		//define structure BiTree
{  
	TElemType data; // 数据域
    struct BiThrNode *lchild,*rchild; // 左孩子、右孩子
    PointerTag ltag,rtag; // 左右标志位
}BiThrNode, *BiThrTree;

/* 创建二叉树 */
int CreateBiThrTree(BiThrTree &T)	//sub-function
{  
	TElemType ch;
    cout<<"Please input data (/ for NULL node!) : ";
    cin>>ch;
    //ch=array[i];
    //cout<<ch<<"  ";
    //i++;
    if(ch=='/')  T=NULL;
    else
    {  
		if(!(T=(BiThrNode *)malloc(sizeof(BiThrNode))))
		{  
			cout<<"Overflow!";			//no alloction
	        return (ERROR);
		}
        T->data=ch;
        CreateBiThrTree(T->lchild);	//create lchild
        CreateBiThrTree(T->rchild);  	//create rchild
   }
   return (OK);
} //CreateBiTree() end

void InThreading(BiThrTree p,BiThrTree &pre)	//InThreading() sub-function
{   
	if(p)
    {  
		/* 左子树线索化 */ 
		InThreading(p->lchild,pre);		//InThreading lchild
        if(!p->lchild) // 前驱线索
        {   /* 原代码有误 */
			//p->ltag=Link;
			p->ltag=Thread;
	        p->lchild=pre;
        }
        if(!pre->rchild) // 后继线索
        {  
			pre->rtag=Thread;
	        pre->rchild=p;
        }
        pre=p; // 保持pre指向p的前驱
		/* 右子树线索化 */ 
        InThreading(p->rchild,pre);			//InThreading rchild
    }
} //InThreading() end

/* 中序遍历二叉树T，并将其中序线索化，Thrt指向头结点 */
int InOrderThreading(BiThrTree &Thrt,BiThrTree T)	//sub-function
{   
	BiThrTree pre;
	/* 建立结点 */
    Thrt=(BiThrTree)malloc(sizeof(BiThrTree));	//allocate memory
    if(!Thrt)
    {   
		cout<<endl<<"Overflow!";
	    return (ERROR);
    }
    Thrt->ltag=Link;
    Thrt->rtag=Thread;
    Thrt->rchild=Thrt;
    if(!T) // 二叉树为空，则左指针指向头结点
		Thrt->lchild=Thrt;
    else // 二叉树非空，为每个结点建立线索
    {  
		Thrt->lchild=T;
	    pre=Thrt;
	    InThreading(T,pre);		//call InThreading()
		/* 对最后一个结点线索化 */
		pre->rtag=Thread;
	    pre->rchild=Thrt;
	    Thrt->rchild=pre;
    }
    return (OK);
} //InOrderThreadng() end

int InOrderTraverse_Thr(BiThrTree Thrt)	//InOrderTraverse_Thr() sub-function
{   /*********************************************
	 Thrt指向头结点，头结点的左链lchild指向根结点
	*********************************************/
	BiThrTree p;
    p=Thrt->lchild;
    while(p!=Thrt) // 空树或遍历结束时，p==Thrt
    {  
		while(!(p->ltag==Link))		//have lchild
			p=p->lchild;
		/* 访问后继结点 */
        while(p->rtag==Thread&&p->rchild!=Thrt)  //no rchild
		{
			p=p->rchild;
		}
        p=p->rchild;
    }
    return (OK);
} //InOrderTraverse_Thr() end

void main()			//main() function
{  
	BiThrTree Thrt,T;
    cout<<endl<<endl<<"InOrderTraverse.cpp";
    cout<<endl<<"===================";
    cout<<endl<<endl<<"Please input data to create BiThrTree :"<<endl;
    CreateBiThrTree(T);		//call CreateBiTree()
    if(InOrderThreading(Thrt,T)) //call InOrderThreading()
		cout<<endl<<"InOrderThreading Success!";
    InOrderTraverse_Thr(Thrt);	//call InOrderTraver_Thr()
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end