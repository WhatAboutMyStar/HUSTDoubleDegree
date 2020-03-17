/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//HuffmanCoding.cpp
//This function is to create HuffmanTree code
# include <stdio.h>
# include <malloc.h>
# include <iostream.h>
# include <conio.h>
# include <string.h>

# define MAX_LENGTH 100

typedef char **HuffmanCode; // 动态分配数组存储哈夫曼编码表

typedef struct			//define structure HuffmanTree
{  
	unsigned int weight; // 权值
    unsigned int parent,lchild,rchild; // 双亲、左孩子、右孩子
}HTNode,*HuffmanTree; // 动态分配数组存储哈夫曼树

void Select(HuffmanTree HT,int i,int &s1,int &s2)  //Select sub-function
{  
	int j,k=1;                	//s1 is the least of HT[].weight
    while(HT[k].parent!=0)	//s2 is the second least of HT[].weight
		k++;
    s1=k; // 找到第一个父结点为0的结点
    for(j=1;j<=i;++j) // 且权值最小
		if(HT[j].parent==0&&HT[j].weight<HT[s1].weight)
			s1=j;
    k=1;
    while((HT[k].parent!=0||k==s1))
		k++;
    s2=k; // 找到另一个父结点为0的结点
    for(j=1;j<=i;++j) // 且权值最小
		if(HT[j].parent==0&&HT[j].weight<HT[s2].weight&&j!=s1)
			s2=j;
} //Select() end

void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n) //sub-function
{   // w存放n个字符的权值(均>0)，构造哈夫曼树HT，并求出n个字符的哈夫曼编码HC
	int m,i,s1,s2,start,/* c ,*/f;
	unsigned int c;
    HuffmanTree p;
    if(n<=1) // 参数检测
		return;
    m=2*n-1; // 结点总的数目
    HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode)); // 0号单元未用
	/* 初始化 HT[1...n] */
    for(p=HT+1,i=1;i<=n;++i,++p,++w)	//initial HT[1...n]
    {  
		p->weight=*w; // 权值
	    cout<<endl<<"HT["<<i<<"].weight="<<p->weight<<"  ";
	    p->parent=0;
	    p->lchild=0;
	    p->rchild=0;
    }
	/* 初始化 HT[n+1...2*n-1] */
    for(;i<=m;++i,++p)			//initial HT[n+1...2*n-1]
    {  
		p->weight=0;
	    p->parent=0;
	    p->lchild=0;
	    p->rchild=0;
    }
    cout<<endl<<endl<<"HuffmanTree is created in following order :";
    for(i=n+1;i<=m;++i) // 建哈夫曼树
    {	
		// 在initial HT[1...i-1]选择parent为0且weight最小的两个结点，其序号分别为s1和s2
		Select(HT,i-1,s1,s2);	//s1 is the least, s2 is the second least
        HT[s1].parent=i; // 父结点
        HT[s2].parent=i;
        HT[i].lchild=s1; // 孩子结点
        HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight; // 父结点权值
        cout<<endl<<"HT["<<s1<<"] and HT["<<s2<<"] create";
        cout<<" HT["<<i<<"], weight="<<HT[i].weight;
    }
	// ---------------------------------------------
	/* 从叶子到根逆向求每个字符的哈夫曼编码 */
    HC=(HuffmanCode)malloc((n+1)*sizeof(char *)); // 分配n个字符编码的头指针向量
    char *cd;
    cd=(char *)malloc(n*sizeof(char)); // 分配求编码的工作空间
    cd[n-1]='\0'; // 编码结束符
    cout<<endl<<endl<<"HuffmanTree Code is as follows :"<<endl;
    for(i=1;i<=n;++i) // 逐个字符求哈夫曼编码
    {  
		start=n-1; // 编码结束位置
        for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent) // 从叶子到根逆向求编码
		{
			if(HT[f].lchild==c) // 双亲左孩子是该结点
				cd[--start]='0';
			else // 否则双亲左孩子不是该结点
				cd[--start]='1';
		}
        HC[i]=(char*)malloc((n-start)*sizeof(char)); // 为第i个字符编码分配空间
        strcpy(HC[i],&cd[start]); // 从cd复制编码(串)到HC
        printf("\nHT[%d] node's Huffman code is: %s",i,HC[i]);
    }
    free(cd); // 释放工作空间
} //HuffmanCoding() end

void main()            		//main() function
{  
	HuffmanTree HT;
    HuffmanCode HC;
    int n,i;
    int *w,W[MAX_LENGTH];;
    cout<<endl<<endl<<"HuffmanCoding.cpp";
    cout<<endl<<"================="<<endl;
    cout<<endl<<"Please input the number of the element of HuffmanTree (eg,5): ";
    cin>>n; // 带权结点数
    for(i=0;i<n;++i)
    {  
		cout<<"Please input the weight of the "<<i+1<<"th element (eg,8): ";
        cin>>W[i]; // 权值
    }
    w=W;
    HuffmanCoding(HT,HC,w,n);	//call HuffmanCoding()
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end