/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//PreOrdertraverse.cpp
//This function is to Preorder a BiTree
# include <malloc.h>
# include <iostream.h>
# include <conio.h>

# define OK 1
# define ERROR 0

typedef char TElemType;

typedef struct BiTNode		//define structure BiTree
{  
	TElemType data; // 数据域
    struct BiTNode *lchild,*rchild; // 左右孩子
}BiTNode, *BiTree;

/* 递归创建二叉树 */
int CreateBiTree(BiTree &T)	//createBiTree sub-function
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
	        return (0);
		} //if end
        T->data=ch;
        CreateBiTree(T->lchild);	//create lchild
        CreateBiTree(T->rchild);  //create rchild
    } //else end
    return (OK);
} //CreateBiTree() end

/* 先序遍历二叉树 */
int PreOrderTraverse(BiTree T)	//PreOrderTravers sub-function
{  
	if(T)
    {  
		cout<<T->data<<"->";                    //visite T
	    if(PreOrderTraverse(T->lchild))	//traverse lchild
			if(PreOrderTraverse(T->rchild))	//traverse rchild
				return (OK);
		return (ERROR);
    } //if end
    else
		return (OK);
} //PreOrderTraverse() end

void main()			//main() function
{  
	BiTree T;
    cout<<endl<<endl<<"PreOrderTraverse.cpp";
    cout<<endl<<"====================";
    cout<<endl<<endl<<"Please input data to create BiTree:"<<endl;
    CreateBiTree(T);		//call CreateBiTree()
    cout<<endl<<"PreOrder :"<<endl<<endl<<"Begin->";
    PreOrderTraverse(T);		//call PreOrderTraverse
    cout<<"End !"<<endl<<endl<<"...OK!...";
    getch();
} //main() end