/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/


//R_Rotate.cpp and L_Rotate.cpp
//This program is to R_Rotate and L_Rotate BSTree
# include <malloc.h>
# include <iostream.h>
# include <conio.h>

# define OK 1
# define ERROR 0

typedef int KeyType;
typedef int TElemType;

typedef struct BSTNode		//define structure BiTree
{  
	KeyType data; // 数据域
    int bf; // 标志位
    struct BSTNode *lchild,*rchild; // 左、右孩子
}BSTNode, *BSTree;

/* 递归创建二叉树 */
int CreateBSTree(BSTree &T,int array[],int &i)	//createBiTree() sub-function
{  
	KeyType ch;
    //cout<<"Pleae input data (0 for NULL node!) : ";
    //cin>>ch;
    ch=array[i];
    i++;
    if(ch==0)  T=NULL;
    else
    {  
		if(!(T=(BSTNode *)malloc(sizeof(BSTNode))))
		{ 
			cout<<"Overflow!";		//no alloction
	        return (ERROR);
		}
        T->data=ch;
        T->bf=0;
        CreateBSTree(T->lchild,array,i);	//create lchild
        CreateBSTree(T->rchild,array,i);  //create rchild
    }
    return (OK);
}

/* 遍历二叉树 */
int PreOrderTraverse(BSTree T)		//PreOrderTraverse() sub-function
{  
	if(T)
    {  
		cout<<endl<<T->data;
	
		if(PreOrderTraverse(T->lchild))
			if (PreOrderTraverse(T->rchild))   
				return (OK);
			return (ERROR);
    }
    else
		return (OK);
} //PreOrderTraverse() end

void R_Rotate(BSTree &p)       		//R_Rotate() sub-function
{  
	BSTree lc;
    lc=p->lchild; // 根结点的左孩子
    p->lchild=lc->rchild; // 根结点的左孩子变成原来根结点的左孩子的右孩子
    p->bf=0; // 设置标志位
    lc->rchild=p; // 原来根结点的左孩子的右孩子变成原来的根结点 
    lc->bf=0; // 设置标志位
    p=lc; // lc变为根结点
} //R_Rotate() end

/* 实际调整两个指针，最后调整根结点 */
void L_Rotate(BSTree &p)	 	//L_Rotate() sub-function
{  
	BSTree rc;
    rc=p->rchild;
    p->rchild=rc->lchild;
    p->bf=0;
    rc->lchild=p;
    rc->bf=0;
    p=rc;
} //L_Rotate() end

void main()				//main() function
{  
	BSTree T,p;
    int array[]={24,13,95,0,0,27,0,0,53,37,0,0,90,0,0};
    int i=0;
    cout<<endl<<endl<<"R_Rotate.cpp and L_Rotate.cpp";
    cout<<endl<<"=============================";
    CreateBSTree(T,array,i);		//call CreateBiTree()
    cout<<endl<<endl<<"The gived BSTree by PreOrder traverse is as follows:";
    PreOrderTraverse(T);
    p=T;
    R_Rotate(p);                         //call R_Rotate()
    cout<<endl<<endl<<"The R_Rotate BSTree by PreOrder traverse is as follows: ";
    PreOrderTraverse(p);
    L_Rotate(p);				//call L_Rotate()
    cout<<endl<<endl<<"The L_Rotate BSTree by PreOrder traverse is as follows: ";
    PreOrderTraverse(p);
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end