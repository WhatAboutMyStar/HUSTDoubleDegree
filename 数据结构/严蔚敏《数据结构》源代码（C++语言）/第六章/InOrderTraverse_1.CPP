/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//InOrderTraverse.cpp
//This function is to Inorder BiTree
# include <malloc.h>
# include <iostream.h>
# include <conio.h>

# define OK 1
# define ERROR 0

typedef char TElemType;

typedef struct BiTNode		//define structureBiTree
{  
	TElemType data; // 数据域
    struct BiTNode *lchild,*rchild; // 左孩子、右孩子
}BiTNode, *BiTree;

/* 创建二叉树 */
int CreateBiTree(BiTree &T)	//createBiTree() sub-function
{  
	TElemType ch;
    cout<<"Please input data (/ for NULL node!) : ";
    cin>>ch;			//input data
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

/* 中序遍历二叉树 */
int InOrderTraverse(BiTree T)	//InOrderTraverse sub-function
{  
	/********************************************************
	 例如，创建二叉树时输入：1、2、4、/、/、5、/、/、3、/、/
	 则输出结果：Begin->4->2->5->1->3->End!
	********************************************************/
	if(T)
    { 	/* 递归算法，先遍历左子树，再遍历根结点，最后遍历右子树 */
		if(InOrderTraverse(T->lchild))		//traverse lchild
		{  
			cout<<T->data<<"->";		//visite T
	        if(InOrderTraverse(T->rchild))	//traverse rchild
				return (OK);
		}
	    return (ERROR);
    } //if end
    else
		return (OK);
} //InOrderTraverse() end

void main()				//main() function
{  
	BiTree T;
    cout<<endl<<endl<<"InOrderTraverse.cpp";
    cout<<endl<<"===================";
    cout<<endl<<endl<<"Please input data to create BiTree:"<<endl<<endl;
    CreateBiTree(T);			//call CreateBiTree()
    cout<<endl<<"InOrder :"<<endl<<endl<<"Begin->";
    InOrderTraverse(T);
    cout<<"End!";
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end