/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//InsertBST.cpp
//This function is to insert element into the gived BiTree
# include <malloc.h>
# include <iostream.h>
# include <conio.h>

# define OK 1
# define ERROR 0

typedef int KeyType;
typedef int TElemType;

typedef struct BiTNode				//define structure BiTree
{  
	TElemType data; // 数据域
	struct BiTNode *lchild,*rchild; // 左、右孩子
}BiTNode, *BiTree;

/* 创建二叉树 */
int CreateBiTree(BiTree &T,int array[],int &i)	//createBiTree() function
{  
	TElemType ch;
    //cout<<"Pleae input data (0 for NULL node!) : ";
    //cin>>ch;
    ch=array[i];
    i++;
    if(ch==0)  T=NULL;
    else
    {  
		if(!(T=(BiTNode *)malloc(sizeof(BiTNode))))
		{  
			cout<<"Overflow!";		//no alloction
	        return (ERROR);
		}
        T->data=ch;
        CreateBiTree(T->lchild,array,i);	//create lchild
        CreateBiTree(T->rchild,array,i);  //create rchild
    }
    return (OK);
} //CreateBiTree() end

/* 遍历二叉树 */
int PreOrderTraverse(BiTree T)	//PreOrderTraverse() sub-function
{  
	if(T)
	{  
		cout<<endl<<T->data;
	
		if(PreOrderTraverse(T->lchild))
			if(PreOrderTraverse(T->rchild))
				return (OK);
			return (ERROR);
    }
    else
		return (OK);
}

/* 递归查找二叉树结点匹配关键字 */
int SearchBST(BiTree T,KeyType key,BiTree f,BiTree &p) //SearchBST()
{  
	if(!T)
    {    
		p=f;
	    return (ERROR);
	} 
    else if(key==T->data)
	{  
		p=T;
	    return (OK);
	}
    else if(key<T->data)
		SearchBST(T->lchild,key,T,p);
		/* 下面语句更规范 */
		//return SearchBST(T->lchild,key,T,p);
    else
		SearchBST(T->rchild,key,T,p);
		/* 下面语句更规范 */
	    //return SearchBST(T->rchild,key,T,p);
} //SearchBST() end

/* 检索结点，不存在则插入相应位置 */
int InsertBST(BiTree &T,TElemType e)	//InsertBST() sub-function
{   
	BiTree p;
    if(!SearchBST(T,e,NULL,p)) // 没有该结点
    {  
		BiTree s;
        s=(BiTree)malloc(sizeof(BiTNode)); // 分配结点空间
		/* 初始化结点 */
        s->data=e; 
        s->lchild=NULL; 
        s->rchild=NULL;
        if(!p) // 空表，否则不执行
			T=s;
        else if(e<p->data)  // p指向双亲
			p->lchild=s;
        else 
			p->rchild=s;
        return (OK);
    }
    else return (ERROR);
} //InsertBST() end

void main()				//main() function
{  
	BiTree T;
    int array[]={49,38,13,0,27,0,0,0,65,50,0,52,0,0,76,0,0};
    int i=0;
    cout<<endl<<endl<<"InsertBST.cpp";
    cout<<endl<<"============="<<endl;
    CreateBiTree(T,array,i);		//call CreateBiTree()
    cout<<endl<<"BiTree PreOrder :";
    PreOrderTraverse(T);
    TElemType e;
    cout<<endl<<endl<<"Please input the data to insert (eg,58): ";
    cin>>e;
    if(InsertBST(T,e))
		cout<<e<<" has been inserted to the BiTree !";
    else
        cout<<e<<" has existed and not been inserted to the BiTree !";
    cout<<endl<<endl<<"The new BiTree is as follows by PreOrderTraverse: ";
    PreOrderTraverse(T);			//call PreOrderTraverse()
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end