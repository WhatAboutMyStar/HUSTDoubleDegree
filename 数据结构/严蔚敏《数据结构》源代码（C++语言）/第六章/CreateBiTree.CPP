/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//CreateBiTree.cpp
//This function is to create BiTree
# include <stdio.h>
# include <malloc.h>
# include <iostream.h>
# include <conio.h>

# define OK 1
# define ERROR 0

typedef char TElemType;

typedef struct BiTNode		//define stricture BiTree
{  
	TElemType data; // 数据域
    struct BiTNode *lchild,*rchild; // 左孩子、右孩子
}BiTNode, *BiTree;

/* 递归创建二叉树，先创建根结点，再创建左右孩子 */
int CreateBiTree(BiTree &T)	//createBiTree() sub-function
{  
	TElemType ch;
    cout<<"Please input data (/ for NULL node!) : ";
    cin>>ch;
	printf("ch= %d\n",ch); // 本人添加，调试用
    if(ch==47) // '/' = (ASCII)47
		T=NULL; // 2层满二叉树，需要输入4次'/'，方才结束创建
    else
    {  
		if(!(T=(BiTNode *)malloc(sizeof(BiTNode)))) // 创建结点
		{  
			cout<<"Overflow!";	//no alloction
	        return (ERROR);
		}
        T->data=ch; // 数据域
        CreateBiTree(T->lchild);	//create lchild
        CreateBiTree(T->rchild);  //create rchild
    }
    return (OK);
} //CreateBiTree() end

void main()			//main() function
{  
	BiTree T;
    cout<<endl<<endl<<"CreateTree.cpp";
    cout<<endl<<"==============";
    cout<<endl<<endl<<"Please input data to create BiTree:"<<endl;
    if(CreateBiTree(T))		//call CreateBiTree
		cout<<endl<<"Create BiTree Success ! ";
    else
		cout<<endl<<"Create BiTree Failure ! ";
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end