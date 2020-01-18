/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//Parent_Judge.cpp
//This function is to find the gived node's parent node
# include <malloc.h>
# include <iostream.h>
# include <conio.h>

# define MAXQSIZE 100
# define LENGTH 10
# define n 999
# define OK 1
# define ERROR 0

typedef int QElemType;
typedef int TElemType;

typedef struct BiTNode		//define structure BiTree
{  
	TElemType data; // 数据域
    struct BiTNode *lchild,*rchild; // 左孩子、右孩子
}BiTNode, *BiTree;

typedef struct SqQueue		//define structure SqQueue
{    
	//BiTNode *base; // 缓冲头
	BiTree *base;
    int front; // 头指针
    int rear; // 尾指针
}SqQueue;

/* 遍历二叉树 */
int PreOrderTraverse(BiTree T)	//PreOrderTraverse() sub-function
{  
	if(T)
    {  
		cout<<endl<<T->data;

	    if(PreOrderTraverse(T->lchild))
		{
			if(PreOrderTraverse(T->rchild))
			{
				return (OK);
			}
			return (ERROR);
		}
    }
    else
		return (OK);
} //ProOrderTraverse() end

/* 创建二叉树*/
int CreateBiTree(BiTree &T,int array[],int &i)	//createBiTree() sub-function
{  
	TElemType ch;
    //cout<<"Pleae input data (0 for NULL node!) : ";
    //cin>>ch;

    ch=array[i];
    i++;
    if(ch==0) T=NULL;
    else
    {  
		if(!(T=(BiTNode *)malloc(sizeof(BiTNode))))
		{  
			cout<<"Overflow!";	//no alloction
			return (ERROR);
		}
        T->data=ch;
        CreateBiTree(T->lchild,array,i);	//create lchild
        CreateBiTree(T->rchild,array,i);  //create rchild
    }
    return (OK);
} //CreateBiTree() end

int Parent_Judge(BiTree T,BiTree q,SqQueue Q)	//Parent_Judge() sub-function
{  
	BiTree parent,p;
    //Q.base=(BiTNode *)malloc(MAXQSIZE*sizeof(QElemType));
	Q.base=(BiTree *)malloc(MAXQSIZE*sizeof(BiTree));
    if(!Q.base)
    {   
		cout<<endl<<"Overflow !";
        return (ERROR);
    }
    parent=NULL;
    if(!T) // 空树
    {   
		cout<<endl<<"Empty BiTree!";
        return (ERROR);
    }
    else
    {  
		if(q->data==n)
		{  
			cout<<endl<<"No parent !";
	        return (OK);
		}
        else
		{  
			Q.front=0;
	        Q.rear=1;
	        //Q.base[1].data=T->data;
			Q.base[1]=T;
	        //p=T;
	 
			do
			{  
				Q.front=Q.front%MAXQSIZE+1;
				//p=&Q.base[Q.front];
				p=Q.base[Q.front];

				cout<<endl<<endl<<"p->data="<<p->data;

				//if((p->lchild->data==n)||(p->rchild->data==n))
				if((p->lchild->data==q->data)||(p->rchild->data==q->data))
				{  
					parent=p;
					Q.front=Q.rear;
					cout<<endl<<p->data;
					return (OK);
				}
				else
				{  
					if(p->lchild!=NULL)
					{  
						Q.rear=Q.rear%MAXQSIZE+1;
						//Q.base[Q.rear]=*(p->lchild);
						Q.base[Q.rear]=p->lchild;
					}
					if(p->rchild!=NULL)
					{  
						Q.rear=Q.rear%MAXQSIZE+1;
						//Q.base[Q.rear]=*(p->rchild);
						Q.base[Q.rear]=p->lchild;
					}
				} //else end
	  		}while(Q.rear!=Q.front);
			//while(Q.rear=Q.front); //do-while end
			if(parent==NULL)
			{  
				cout<<endl<<"No node n!";
				return (OK);
			} //if end
       } //else end
	} //else end
} //Parent_Judge() end

void main()			//main() function
{  
	SqQueue Q;
    BiTree T,t,q;
    int array[]={n,38,13,0,27,0,0,0,65,50,0,52,0,0,76,0,0};
    int i=0;
    cout<<endl<<endl<<"Parent_Judge.cpp";
    cout<<endl<<"================"<<endl;
    CreateBiTree(T,array,i);		//call CreateBiTree
    cout<<endl<<"BiTree PreOrder :";
    PreOrderTraverse(T);
    q=T->rchild->lchild; // q为右孩子的左孩子
    cout<<endl<<endl<<"T->rchild->lchild.data="<<q->data;
    Parent_Judge(T,q,Q);
    cout<<endl<<endl<<"...OK!...";
    getch();
}