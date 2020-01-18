/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//Build.cpp
//This function is to create a BiTree according string
# include <malloc.h>
# include <iostream.h>
# include <conio.h>

# define MAX_LENGTH 100

typedef char TElemType;

typedef struct BiTNode		//define stucture BiTree
{  
	TElemType data; // 数据域
    struct BiTNode *lchild,*rchild; // 左孩子、右孩子
}BiTNode, *BiTree;

/* 创建二叉树 */
BiTNode *Build(char *str,int i,int n)	//Build() sub-function
{   
	if(i>n) // 参数检测
		return (NULL);
    BiTree p;
    p=(BiTNode *)malloc(sizeof(BiTNode)); // 创建结点
    p->data=str[i]; // 数据域
    cout<<endl<<"Node["<<i<<"].data="<<p->data;
	/* 创建二叉树是一个递归过程 */
    p->lchild=Build(str,2*i,n); // 左孩子
    p->rchild=Build(str,2*i+1,n); // 右孩子
    return (p); // 最后返回根结点
} //Build() end

void main()			//main() function
{  
	char str[MAX_LENGTH];
    int i=1;
    int n;
    cout<<endl<<endl<<"Build.cpp";
    cout<<endl<<"=========";
    cout<<endl<<endl<<"Please input the length of string (eg,5): ";
    cin>>n;
    for(i=1;i<=n;++i)
    { 
		cout<<"Please input the "<<i<<"th letter:";
        cin>>str[i];
    }
    cout<<endl<<"str[]=";
    for(i=1;i<=n;i++)
		cout<<str[i];
    i=1; // 根结点
    cout<<endl<<endl<<"The BiTree is created in following order :"<<endl;
    if(Build(str,i,n))		//call Build()
		cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end
