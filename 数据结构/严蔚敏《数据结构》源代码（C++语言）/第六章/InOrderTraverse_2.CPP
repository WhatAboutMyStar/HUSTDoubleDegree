/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//InOrderTraverse.cpp
//This function is to InOrder BiTree
# include <stdio.h>
# include <malloc.h>
# include <iostream.h>
# include <conio.h>

# define STACK_INIT_SIZE 100
# define STACKINCREMENT 10
# define OK 1
# define ERROR 0

typedef int SElemType ;
typedef char TElemType;

typedef struct SqStack  	//define structure SqStack
{    
	SElemType *base; // 栈底
    SElemType *top; // 栈顶
    int stacksize; // 栈大小
}SqStack;

typedef struct BiTNode		//define structure BiTree
{  
	TElemType data; // 数据域
    struct BiTNode *lchild,*rchild; // 左孩子、右孩子
}BiTNode, *BiTree;

/* 创建二叉树 */
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

/* 初始化栈 */
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
		STACKINCREMENT*sizeof(SElemType))); // 调整栈空间
	 
		if(!S.base)
		{   
			cout<<endl<<"Overflow!";
	        return (ERROR);
		}
	    S.top=S.base+S.stacksize;
	    S.stacksize+=STACKINCREMENT;
    }
    *S.top++=e;
	//printf("__p= %ld\n",*(S.top-1)); // 本人添加，调试用
    return (OK);
} //Push() end

/* 出栈 */
int Pop(SqStack &S,/*SElemType &e*/BiTree &e)	//Pop() sub-function
{    
	if(S.top==S.base)
    {    
		cout<<endl<<"It's a empty SqStack!";
	    return (ERROR);
    }
	/*************
	 原代码不可用 
	*************/
    //e=*--S.top;
	/*************
	 修改以后代码 
	*************/
	e=(BiTree)*--S.top;
	//printf("p__= %ld\n",e); // 本人添加，调试用
    return (OK);
} //Pop() end

/* 判断空栈 */
int StackEmpty(SqStack S)	//StackEmpty() sub-function
{  
	if(S.top==S.base)
		return (OK);
    else
		return (ERROR);
} //StackEmpty() end

/* 二叉树的遍历 */
int InOrderTraverse(BiTree T)	//InOrderTraverse sub-function
{   
	SqStack S;
    InitStack(S);		//call InitStack()
    BiTree p;
    p=T;
    while(p||!StackEmpty(S))
    {   
		/********************************************
		 例如，创建二叉树时输入：1、2、/、/、3、/、/ 
		 则结果为Begin->2->1->3->End! 
		********************************************/
		if(p) // 根指针、左子树入栈，遍历左子树
		{  
			Push(S,int(p)); 	//call Push()
	        p=p->lchild;
		}
        else // 左子树、根指针退栈，访问根结点，遍历右子树
		{  
			/* 原代码出栈，参数类型转换结果出错 */
			//Pop(S,int(p));	//call Pop()
			/*************
			 改进以后代码
			*************/
			Pop(S,p);
			/*if(!(p->data))
				return ERROR;
	        else 
				cout<<p->data<<"->";*/
			cout<<p->data<<"->";    	//visit p Node
	        p=p->rchild;
		}
    }
    return (OK);
} //InOrderTraverse() end

void main()			//main() function
{  
	BiTree T;
    cout<<endl<<endl<<"InOrderTraverse.cpp";
    cout<<endl<<"==================="<<endl;
    cout<<endl<<"Please input data to create BiTree:"<<endl;
    CreateBiTree(T);		//call CreateBiTree()
    cout<<endl<<"InOrder :"<<endl<<endl<<"Begin->";
    InOrderTraverse(T);		//Call InOrderTraverse()
    cout<<"End !"<<endl<<endl<<"...OK!...";
    getch();
} //main() end