/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//PostOrderTraverse.cpp
//This function is to postorder BiTree
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

/* 后序遍历二叉树 */
int PostOrderTraverse(BiTree T)	//PostOrderTraverse() sub-function
{  
	if(T)
    { 	
		if (PostOrderTraverse(T->lchild)) 	//traverse lchild
			if(PostOrderTraverse(T->rchild))	//traverse rchild
			{    
				cout<<T->data<<"->";		//visite T
				return (OK);
			}
		return (ERROR);
    }
    else
		return (OK);
} //PostOrderTraverse() end

void main()			//main() function
{  
	BiTree T;
    cout<<endl<<endl<<"PostOrderTraverse.cpp";
    cout<<endl<<"=========================";
    cout<<endl<<endl<<"Please input data to create BiTree:"<<endl;
    CreateBiTree(T);		//call CreateBiTree
    cout<<endl<<"PostOrder :"<<endl<<endl<<"Begin->";
    PostOrderTraverse(T);
    cout<<"End !"<<endl<<endl<<"...OK!...";
    getch();
} //main()