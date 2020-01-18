/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//DeleteBST.cpp
# include <malloc.h>
# include <iostream.h>
# include <conio.h>

# define OK 1
# define ERROR 0

typedef int KeyType;
typedef int TElemType;

typedef struct BiTNode		//define structure BiTree
{  
	TElemType data; // 数据域
    struct BiTNode *lchild,*rchild; // 左、右孩子
}BiTNode, *BiTree;

/* 创建二叉树 */
int CreateBiTree(BiTree &T,int array[],int &i)	//createBiTree() sub-function
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
}

/* 遍历二叉树 */
int PreOrderTraverse(BiTree T)		//PreOrderTraverse() sub-function
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
} //PreOrderTraverse() end

/* 递归查找二叉树结点匹配关键字 */
int SearchBST(BiTree T,KeyType key,BiTree f,BiTree &p)	//SearchBSF()
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
    else		
		SearchBST(T->rchild,key,T,p);
	return (OK);
}

/* 删除结点 */
int Delete(BiTree &p)		//Delete() sub-function
{  
	BiTree q,s;
    if(!p->data) // 数据域为0，不会执行
    {  
		q=p;
        p=p->lchild; // 移动左孩子到该结点
        free(q); // 释放结点
	}
    else if(!p->lchild) // 数据域不为0，左孩子为空
    {  
		q=p;
        p=p->rchild; // 移动右孩子到该结点
        free(q); // 释放结点
    }
	/***************************
	 如果删除根结点，左子树断链
	***************************/
    else // 数据域不为0，左孩子不为空
    {  
		q=p;
        s=p->lchild; // 该结点的左孩子
        while(s->rchild) // 查找该结点左子树的没有右孩子的右结点
		{  
			q=s; // q为没有右孩子的右结点的双亲
	        s=s->rchild;
		}
        p->data=s->data; // 交换数据
        if(q!=p) // 如果不是同一个结点 	
			q->rchild=s->lchild; // 没有右孩子的右结点的左孩子
        else		
			q->lchild=s->rchild; // NULL
	}
    return (OK);
}

/* 删除树中某个结点 */
int DeleteBST(BiTree &T,TElemType key)	//DeleteBST() sub-function
{  
	if(key!=49&&key!=38&&key!=13&&key!=27&&
	   key!=65&&key!=50&&key!=52&&key!=76)
	    return (ERROR);
    else // 递归检索结点，然后删除
    {  
		
		if(key==T->data)  	
			Delete(T);
		else if(key<T->data)	
			DeleteBST(T->lchild,key);
		else 	
			DeleteBST(T->rchild,key);
		return (OK); 
    }
}

void main()				//main() function
{  
	BiTree T;
    int array[]={49,38,13,0,27,0,0,0,65,50,0,52,0,0,76,0,0};
    int i=0;
    TElemType key;
    cout<<endl<<endl<<"DeleteBST.cpp";
    cout<<endl<<"============="<<endl;
    CreateBiTree(T,array,i);		//call CreateBiTree()
    cout<<endl<<endl<<"The gived BiTree by PreOrder traverse is as follows:";
    PreOrderTraverse(T);
    cout<<endl<<endl<<"Please input the data to delete (eg,13): ";
    cin>>key;
    if(DeleteBST(T,key))
		cout<<key<<" has been deleted !";
    else
        cout<<key<<" doesn't existed !";
    cout<<endl<<endl<<"The new BiTree by PreOrder traverse is as follows: ";
    PreOrderTraverse(T);
    cout<<endl<<endl<<"...OK!...";
    getch();
}