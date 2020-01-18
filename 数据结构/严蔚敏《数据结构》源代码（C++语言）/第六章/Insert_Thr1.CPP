/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//Insert_Thr.cpp
//This function is to insert element into the gived BiTree
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

/* 创建二叉树 */
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

/* 代码有误，具体查看 Next_Thr.CPP */
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
	        p->lchild=pre;
        }
        if(!pre->rchild)
        {  
			pre->rtag=Thread;
	        pre->rchild=p;
        }
        pre=p;
        InThreading(p->rchild,pre);			//InThreading rchild
    }
} //InThreading() end

/* 中序遍历二叉树T，并将其中序线索化，Thrt指向头结点 */
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
	    pre->rchild=Thrt;
	    pre->rtag=Thread;
	    Thrt->rchild=pre;
    }
    return (OK);
} //InOrderThreadng() end

int Next_Thr(BiThrTree t,BiThrTree Thrt,BiThrTree &p)	//sub-function
{  
	p=t->rchild;
    if(p==Thrt)
    {  
		cout<<endl<<"Error!";
        return (ERROR);
    }
    if(t->rtag==Link)
    {  
		while(p->ltag==Link)
			p=p->lchild;
    }
    return (OK);
} //Next_Thr() end

/* 插入结点之后，依然保证是线索二叉树 */
int Insert_Thr(BiThrTree Thrt,BiThrTree t,TElemType x)	//Insert_Thr()
{   
	BiThrTree q;
    q=(BiThrTree)malloc(sizeof(BiThrNode)); // 创建结点
    if(!q)
    {  
		cout<<endl<<"Overflow!";
        return (ERROR);
    }
    q->data=x; // 数据域
	/* q的右指针域继承t的右指针域 */
    q->rchild=t->rchild; 
    q->rtag=t->rtag;
	/* t变为q的前驱 */
    q->lchild=t;
    q->ltag=Thread;
	/* q变t的右孩子 */
    t->rchild=q;
    t->rtag=Link;
    if(q->rtag==Link) // 如果继承的是右孩子
    {  
		BiThrTree p;
        Next_Thr(q,Thrt,p); // 查找q的下一结点
        p->lchild=q; // 该结点左指针域指向q
    }
    return (OK);
} //Insert_Thr() end

void main()				//main() function
{  
	BiThrTree Thrt,T,p;
    char array[]={'A','B','C','/','/','D','/','/','E','/','/'};
    int i=0;
    char x;
    cout<<endl<<endl<<"Insert_Thr.cpp";
    cout<<endl<<"=============="<<endl;
    cout<<endl<<"Create BiTree as follows:"<<endl;
    CreateBiThrTree(T,array,i);		//call CreateBiTree()
    //getch();
    if(InOrderThreading(Thrt,T))
		cout<<endl<<endl<<"InOrderThreading Success !";
    p=Thrt->lchild->lchild->rchild;	//initial p
    cout<<endl<<"p->data="<<p->data;
    cout<<endl<<"Please input the data to insert: ";
    cin>>x;
    if(Insert_Thr(Thrt,p,x))		//call Insert_Thr()
		cout<<endl<<"Insert success!";
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end