/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//PostOrderTraverse.cpp
//This function is to PostOrder BiTree
# include <malloc.h>
# include <iostream.h>
# include <conio.h>

# define STACK_INIT_SIZE 100
# define STACKINCREMENT 10
# define OK 1
# define ERROR 0

typedef char TElemType;

typedef struct BiTNode		//define structure BiTree
{  
	TElemType data; // 数据域
    struct BiTNode *lchild,*rchild; // 左右孩子
}BiTNode, *BiTree;

typedef struct Data       	//define structure Data
{  
	BiTNode *p; // 结点
    int tag; // 标志位
}Data,SElemType;

typedef struct SqStack  	//define structure SqStack
{    
	SElemType *base; // 栈底
    SElemType *top; // 栈顶
    int stacksize; // 栈大小
}SqStack;

/* 递归创建二叉树 */
int CreateBiTree(BiTree &T)	//createBiTree() sub-function
{  
	TElemType ch;
    cout<<"Please input data (/ for NULL node!) : ";
    cin>>ch;
    if(ch=='/')  T=NULL;
    else
    {  
		if(!(T=(BiTNode *)malloc(sizeof(BiTNode))))
		{  
			cout<<"Overflow!";	//no alloction
	        return (ERROR);
		}
        T->data=ch;
        CreateBiTree(T->lchild);	//create lchild
        CreateBiTree(T->rchild);  //create rchild
    }
    return (OK);
} //CreateBiTree() end

/* 初始化堆栈 */
int InitStack(SqStack &S)	//InitStack() sub-function
{   
	S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!S.base)
    {    
		cout<<endl<<"Allocate space failure !";
	    return (ERROR);
    }
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
    return (OK);
} //InitStack() end

/* 入栈 */
int Push(SqStack &S,SElemType e)	//Push() sub-function
{   
	if(S.top-S.base>S.stacksize)
    {    
		S.base=(SElemType *)realloc(S.base,(S.stacksize+
		       STACKINCREMENT*sizeof(SElemType)));
		if(!S.base)
		{  
			cout<<endl<<"Overflow!";
			return (ERROR);
		}
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
    }
    *S.top++=e;
    return (OK);
} //Push() end

/* 出栈 */
int Pop(SqStack &S,SElemType &e)	//Pop() sub-function
{    
	if(S.top==S.base)
	{   
		cout<<endl<<"It's a empty SqStack!";
		return (ERROR);
    }
    e=*--S.top;
    return (OK);
} //Pop() end

/* 判断空栈 */
int StackEmpty(SqStack S)		//StackEmpty() sub-function
{  
	if(S.top==S.base)
		return (OK);
    else
        return (ERROR);
} //StackEmpty() end

/* 后序遍历二叉树 */
int PostOrderTraverse(BiTree T)		//PostOrderTraverse sub-function
{   
	SqStack S;
    InitStack(S);			//call Initstack()
    Data Data1;
    Data1.p=T; // 根结点
    do
    {  
		if(Data1.p) // 如果结点不为空
		{  
			Data1.tag=0; // 设标志位
	        Push(S,Data1);             //call Push()
	        Data1.p=Data1.p->lchild; // 取左孩子
		}
        else 
		{  
			Pop(S,Data1);		//call Pop()
	        if(Data1.tag==0) // 如果该结点已经入栈一次
			{  
				Data1.tag=1; // 置标志位
		        Push(S,Data1); // 第二次入栈
		        Data1.p=Data1.p->rchild; // 取右孩子
			}
	        else // 否则直接打印
			{  
				cout<<Data1.p->data<<"->";    	//visit p Node
		        Data1.p=NULL; // 打印完成，取消该结点，继续遍历下一个结点
			}
		}
    }while(Data1.p||!StackEmpty(S));
    return (OK);
} //PostOrderTraverse() end

void main()				//main() function
{  
	BiTree T;
    cout<<endl<<endl<<"PostOrderTraverse.cpp";
    cout<<endl<<"=====================";
    cout<<endl<<endl<<"Please input data to create BiTree:"<<endl;
    CreateBiTree(T);			//call CreateBiTree()
    cout<<endl<<"PostOrder :"<<endl<<endl<<"Begin->";
    PostOrderTraverse(T);		//Call PostOrderTraverse()
    cout<<"End !"<<endl<<endl<<"...OK!...";
    getch();
} //main() end