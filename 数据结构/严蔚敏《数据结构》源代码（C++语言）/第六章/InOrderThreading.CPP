/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//InOrderThreading.cpp
//This function is to InOrderTraverse BiThrTree
# include <malloc.h>
# include <iostream.h>
# include <conio.h>

# define OK 1
# define ERROR 0

typedef enum{Link,Thread} PointerTag; // Link=0，Thread=1
typedef char TElemType; // 注意是字符型

typedef struct BiThrNode		//define structure BiTree
{  
	TElemType data; // 数据域
    struct BiThrNode *lchild,*rchild; // 左孩子、右孩子
    PointerTag ltag,rtag; // 左右标志
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
    if(ch=='/') T=NULL;
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

/*****************************************************************
 二叉树的结点之间隐含着一个线性关系，这个关系通过遍历才能显示出来
*****************************************************************/
void InThreading(BiThrTree p,BiThrTree &pre)	//InThreading() sub-function
{   /* 线索二叉树中，一个结点是叶子结点的充要条件为：左、右标志均是Thread */
	/* flash动画 (http://student.zjzk.cn/course_ware/data_structure/web/flashhtml/erchashuxiansuohua.htm) */
	if(p) // 线索：指向结点直接前驱和直接后继的指针
    {  
	    /* 左子树线索化 */ 
		InThreading(p->lchild,pre);		//InThreading lchild
		/* 当前结点没有左孩子，它的左指针就线索化为上一个结点 */
        if(!p->lchild) // 前驱线索 ltag
        {  
			/* 原代码有误 */
			//p->ltag=Link;
			p->ltag=Thread;
	        p->lchild=pre;
        }
		else/* 本人添加，不然指针域得不到初始化 */
			p->ltag=Link;
		/* 上一个结点没有右孩子，它的右指针就线索化为当前结点 */
        if(!pre->rchild) // 后继线索 rtag
        {  
			pre->rtag=Thread;
	        pre->rchild=p;
        }
		else/* 本人添加，不然指针域得不到初始化 */
			pre->rtag=Link;
        pre=p; // 调整pre的值指向当前结点，继续遍历下一个结点
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

void main()			//main() function
{  
	BiThrTree Thrt,T;
    cout<<endl<<endl<<"InOrderThreading.cpp";
    cout<<endl<<"====================";
    cout<<endl<<endl<<"Please input data to create BiThrTree :"<<endl;
    CreateBiThrTree(T);		//call CreateBiTree()
    if(InOrderThreading(Thrt,T)) //call InOrderThreading()
		cout<<endl<<"InOrderThreading Success !!";
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end