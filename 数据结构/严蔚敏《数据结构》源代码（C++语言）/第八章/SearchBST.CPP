/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//SearchBST.cpp
//This function is to find element in the gived BiTree
# include <malloc.h>
# include <iostream.h>
# include <conio.h>
# include <stdio.h>

# define OK 1
# define ERROR 0

typedef int KeyType;
typedef int TElemType;
typedef char CElemType;

typedef struct BiTNode		//define structure BiTree
{  
	CElemType data1; // 数据域1
	TElemType data2; // 数据域2
    struct BiTNode *lchild,*rchild; // 左、右孩子
}BiTNode, *BiTree;

/* 创建二叉树 */
int CreateBiTree1(BiTree &T/*,int array[],int &i*/)	//CreateBiTree() sub-function
{  
	/* 本人改写另外一种实现方法，便于调试 */
	//TElemType ch;
	CElemType ch;
    cout<<"Please input data (/ for NULL node!) : ";
    cin>>ch;
    //ch=array[i];
    //i++;
	//printf("ch= %d\n",ch); // 本人添加，调试用
	if(ch=='/') 
		T=NULL;
    else
    {  
		if(!(T=(BiTNode *)malloc(sizeof(BiTNode))))
		{  
			cout<<"Overflow!";	//no alloction
	        return (ERROR);
		}
        T->data1=ch;
		CreateBiTree1(T->lchild);  //create lchild
        CreateBiTree1(T->rchild);  //create rchild
        //CreateBiTree(T->lchild,array,i);	//create lchild
        //CreateBiTree(T->rchild,array,i);  //create rchild
    }
    return (OK);
} //CreateBiTree() end

/* 创建二叉树 */
int CreateBiTree2(BiTree &T,int array[],int &i)	//CreateBiTree() sub-function
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
			cout<<"Overflow!";	//no alloction
	        return (ERROR);
        }
        T->data2=ch;
        CreateBiTree2(T->lchild,array,i);	//create lchild
        CreateBiTree2(T->rchild,array,i);  //create rchild
    }
    return (OK);
} //CreateBiTree() end

/* 遍历二叉树 */
int PreOrderTraverse1(BiTree &T)	//PreOrderTraverse sub-function
{  
	/*******************************************************
	 先输出双亲，再输出左孩子，然后输出右孩子

	 例如，创建二叉树输入：1、2、4、/、/、5、/、/、3、/、/

	             输出顺序：1、2、4、5、3
	*******************************************************/
	if(T) 
	{  
		cout<<endl<<T->data1;
	
		if(PreOrderTraverse1(T->lchild))
			if (PreOrderTraverse1(T->rchild))
				return (OK);
			return (ERROR);
    }
    else
		return (OK);
} //PreOrderTraverse() end

/* 遍历二叉树 */
int PreOrderTraverse2(BiTree &T)	//PreOrderTraverse sub-function
{  
	if(T) 
	{  
		cout<<endl<<T->data2;
	
		if(PreOrderTraverse2(T->lchild))
			if (PreOrderTraverse2(T->rchild))
				return (OK);
			return (ERROR);
    }
    else
		return (OK);
} //PreOrderTraverse() end

/* 递归查找二叉树结点匹配关键字 */
int SearchBST(BiTree T,KeyType key,BiTree f,BiTree &p) //SearchBST() Sub-function
{  
	if(!T)
    {    
		p=f;
	    return (ERROR);
    }
    else if(key==T->data2) // 找到结点
	{  
		p=T;
	    return (OK);
	}
    else if(key<T->data2) // 小于关键字，往左子树搜索
		SearchBST(T->lchild,key,T,p);
    else  // 否则，往右子树搜索
		SearchBST(T->rchild,key,T,p);
}

void main()			//main() function
{  
	BiTree T;
    int array[]={49,38,13,0,27,0,0,0,65,50,0,52,0,0,76,0,0};
    int i=0;
    cout<<endl<<endl<<"SearchBST.cpp";
    cout<<endl<<"=============";
    cout<<endl<<endl<<"The gived BiTree is as follows by PreOrderTraverse :"<<endl<<endl;
    CreateBiTree1(T/*,array,i*/);		//call CreateBiTree()
    PreOrderTraverse1(T);
	cout<<endl<<endl;
	CreateBiTree2(T,array,i);
    PreOrderTraverse2(T);
    BiTree f,p;
    KeyType key;
    cout<<endl<<endl<<"Please input the data to find (eg,27): ";
	/*********************************
	 原代码混合使用I/O输入输出，异常！
	*********************************/
    //scanf("%d",&key);
	cin>>key;
    if(SearchBST(T,key,f,p))             //call SearchBST()
		cout<<p->data2<<" is found !";
    else
		cout<<key<<" isn't found !";
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end