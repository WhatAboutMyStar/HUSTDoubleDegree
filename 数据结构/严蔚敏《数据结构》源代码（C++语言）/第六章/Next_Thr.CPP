/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//Next_Thr.cpp
//This function is to find the prior element in the gived BiTree
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
    PointerTag ltag,rtag; // 左右标志
}BiThrNode, *BiThrTree;

/* 递归创建二叉树 */
int CreateBiThrTree(BiThrTree &T,char array[],int &i)	//sub-function
{  
	TElemType ch;
    //cout<<"Pleae input data (/ for NULL node!) : ";
    //cin>>ch;
    ch=array[i];
    cout<<ch<<"  ";
    i++;
    if(ch=='/')  T=NULL;
    else
    {  
		if(!(T=(BiThrNode *)malloc(sizeof(BiThrNode))))
		{  
			cout<<"Overflow!";			//no alloction
	        return (ERROR);
		}
        T->data=ch;
        CreateBiThrTree(T->lchild,array,i);	//create lchild
        CreateBiThrTree(T->rchild,array,i);  	//create rchild
    }
    return (OK);
} //CreateBiTree() end

/* 中序线索化 */
void InThreading(BiThrTree p,BiThrTree &pre)	//InThreading() sub-function
{   
	if(p)
    {  
		InThreading(p->lchild,pre);		//InThreading lchild
        if(!p->lchild)
        {  
			/* 原代码有误 */
			//p->ltag=Link;
			p->ltag=Thread;

			/* 本人添加，调试用 */
			cout<<endl<<"__p->data="<<p->data; 
			cout<<endl<<"__p->ltag="<<p->ltag;
			cout<<endl<<"__p->rtag="<<p->rtag;

	        p->lchild=pre;
        }
		else /* 本人添加 */
			p->ltag=Link;

        if(!pre->rchild)
        {  
			pre->rtag=Thread;

			/* 本人添加，调试用 */
			cout<<endl<<"pre__->data="<<pre->data;
			cout<<endl<<"pre__->rtag="<<pre->rtag;
			cout<<endl<<"pre__->ltag="<<pre->ltag;

	        pre->rchild=p;
        }
		else /* 本人添加 */
			pre->rtag=Link;
        pre=p;
        InThreading(p->rchild,pre);			//InThreading rchild
    }
} //InThreading() end

int InOrderThreading(BiThrTree &Thrt,BiThrTree T)	//sub-function
{   
	BiThrTree pre;
    Thrt=(BiThrTree)malloc(sizeof(BiThrTree));	//allocate memory
    if(!Thrt)
    {   
		cout<<endl<<"Overflow!";
	    return (ERROR);
    }
    Thrt->ltag=Link;
    Thrt->rtag=Thread;
    Thrt->rchild=Thrt;
    if(!T)
        Thrt->lchild=Thrt;
    else
    {  
		Thrt->lchild=T;
	    pre=Thrt;
	    InThreading(T,pre);		//call InThreading() 
		pre->rtag=Thread;
	    pre->rchild=Thrt;
	    Thrt->rchild=pre;
    }
    return (OK);
} //InOrderThreadng() end

/* 后继 */
int Next_Thr(BiThrTree t,BiThrTree Thrt,BiThrTree &p)	//sub-function
{  
	/* 对照中序线索链表理解 */
	p=t->rchild; // 根结点的右孩子 

	/* 本人添加，调试用 */
	/*if(t->ltag==Link) // 0
		cout<<endl<<"t->ltag=="<<t->ltag;
	else if(t->ltag==Thread) // 1
		cout<<endl<<"t->ltag=="<<t->ltag;
	else 
		cout<<endl<<"Error!";*/ // 原代码输出结果，有左、右孩子的结点，左、右指针域没有初始化

	// ------------------------------------

    if(p==Thrt) // 空树
    {  
		cout<<endl<<"Error!";
        return (ERROR);
    }
	/* 原代码，下面代码永远为假 */
    if(t->rtag==Link) // 该结点右标志为Link
    { 
		cout<<endl<<"_p_->data="<<p->data; //本人添加，调试用

		while(p->ltag==Link) // 查找左链
		{
			cout<<endl<<"_p_->data="<<p->data; //本人添加，调试用
			p=p->lchild; 
		}
    }
    return (OK);
} //Next_Thr() end

void main()			//main() function
{  
	BiThrTree Thrt,T;
    char array[]={'A','B','C','/','/','D','/','/','E','/','/'};
    int i=0;
    cout<<endl<<endl<<"Next_Thr.cpp";
    cout<<endl<<"============"<<endl;
    cout<<endl<<"Create BiTree as follows:"<<endl;
    CreateBiThrTree(T,array,i);	//call CreateBiTree()
    getch();
    if(InOrderThreading(Thrt,T))
		cout<<endl<<endl<<"InOrderThreading Success !";
    
	/*BiThrTree p;
    p=Thrt->lchild->lchild->rchild;	//initial p 'D'
    cout<<endl<<"p->data="<<p->data;
    Next_Thr(T,Thrt,p);			//call Next_Thr()*/

	BiThrTree p,q;
	/* Thrt->lchild=T */
    //q=Thrt->lchild->lchild->rchild;	//initial p 'D'
	q=Thrt->lchild->lchild;	//initial p 'B'
    cout<<endl<<"q->data="<<q->data;
    Next_Thr(q,Thrt,p);			//call Next_Thr()
    cout<<endl<<"q->next="<<p->data;
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end