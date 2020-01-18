/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//Radixsort.cpp

# include <iostream.h>
# include <stdio.h>
# include <conio.h>

# define MAX_NUM_OF_KEY 8
# define RD 10
# define MAX_SPACE 10000
# define ERROR -1

typedef int KeyType;
typedef int InfoType;
typedef int ArrType[RD];

typedef struct SLCell
{  
	KeyType keys[MAX_NUM_OF_KEY]; // 关键字
    InfoType otheritems; // 其他数据项
    int next; 
}SLCell;

typedef struct SLList 
{   
	SLCell r[MAX_SPACE]; // 静态链表的可利用空间
    int keynum; // 记录的当前关键字个数
    int recnum; // 静态链表的当前长度
}SLList;

int Succ(int j)                             //Succ() function
{//To get the next function
    j++;
    return (j);   
}//end of Succ() function

/* Ord将记录中第i个关键字映射到[0..RD-1] */
int Ord(int KeyBit)                         //Ord() function
{
	int j;
	/* 查找映射位置 */
	for(j=0;j<=RD-1&&j!=KeyBit;j++);
	if(j!=KeyBit) 
		return(ERROR);            //KeyBit OVERFLOW THEN ERROR 
	else 
		return(j); // 返回映射位置
}//end of Ord() function

void OutExample(SLList L,int i)             //OutExample() function
{
////////////////////   Output ////////////////
     int temp,k;
	 printf("\nThe %d Collect result is:  ",i);
//	 temp=L.r[0].otheritems;
//	 printf("%d -> ",temp);
     temp=L.r[0].next;
	 printf("%d -> ",L.r[temp].otheritems);
	 for(k=0;k<L.recnum-2;k++)
	 { 
		 temp=L.r[temp].next;
	     printf("%d -> ",L.r[temp].otheritems);
	 }
	 printf("%d",L.r[L.r[temp].next].otheritems);
	 printf("\n");
//////////////////////////////////////////////
}//end of OutExample() function

/* 一趟分配的算法 */
void Distribute(SLList &L,int i,ArrType &f,ArrType &e)    //Distribute() function
{   /* 本算法按第i个关键字keys[i]建立RD个子表，使同一个子表中记录的keys[i]相同 */
	/* f[0..RD-1]和e[0..RD-1]分别指向各子表中第一个和最后一个记录 */
	int j,p;
    for(j=0;j<RD;j++) // 各子表初始化为空表
		f[j]=0;
	for(p=L.r[0].next;p;p=L.r[p].next)
    {  
		/* Ord将记录中第i个关键字映射到[0..RD-1] */
		j=Ord(L.r[p].keys[i]);                              //call Ord()
        if(!f[j]) // 没有记录
			f[j]=p;
        else
	        L.r[e[j]].next=p; // 第一次e[j]=0，后面借助e[j]把记录链起来
							  // 跟f[j]配合形成队列
        e[j]=p; // 将p所指的结点插入第j个子表中
    }//end of for 
}//end of Distrubute() function

/* 一趟收集的算法 */
void Collect(SLList &L,int i,ArrType f,ArrType e)         //Collect() function
{  
	/* 本算法按keys[i]自小到大地将f[0..RD-1]所指各子表依次链接成一个链表 */
	/* e[0..RD-1]为各子表的尾指针 */
	int j,t; 
	/* 找到第一个非空子表，succ为求后继函数 */
    for(j=0;!f[j];j=Succ(j)/* j++ */);                              //Succ()
	/* r[0].next指向第一个非空子表中第一个结点 */
    L.r[0].next=f[j];
    t=e[j];
    while(j<RD-1)                                          
    {  
		/* 顺序链接所有队列，f[i]->...->e[i]->f[i+n]->...->e[i+n] */
		for(j=Succ(j);j<RD-1&&!f[j];j=Succ(j)); // 找到下一个非空子表            
        if(f[j]) // 链接两个非空子表
		{ 
		 	L.r[t].next=f[j];
	        t=e[j];
		}//end of if
    }//end of while
    L.r[t].next=0; // t指向最后一个非空子表中的最后一个结点
    OutExample(L,i);                                       //Add Output Example function here
}//end of Collect() function

/* 链式基数排序 */
void RadixSort(SLList &L)
{  
	/* 对L作基数排序，使得L成为按关键字自小到大的有序静态链表，L.r[0]为头结点 */
	int i;
    ArrType f,e;
	
	/* 将L改造为静态链表 */
    for(i=0;i<L.recnum;i++)
		L.r[i].next=i+1;       
    L.r[L.recnum].next=0;  

    for(i=0;i<L.keynum;i++) // 按最低位优先依次对各关键字进行分配和收集
    {  
		Distribute(L,i,f,e); // 第i趟分配
        Collect(L,i,f,e); // 第i趟收集
    }//end of for
}//end of RadixSort() function

void InitExample(SLList &L)
{   //Take SLList L for example  
	L.keynum=3;                  //total key number is 3
	L.recnum=7;                  //total current node is 10     
	L.r[1].otheritems=278;
	L.r[2].otheritems=109;
	L.r[3].otheritems=163;
	L.r[4].otheritems=930;
	L.r[5].otheritems=580;
	L.r[6].otheritems=184;
	L.r[7].otheritems=505;
	//L.r[7].otheritems=0;

	cout<<"The InitExample SLList L is: "<<"278->109->163->930->580->184->505"<<endl;
	
	L.r[1].keys[0]=8;
	L.r[1].keys[1]=7;
	L.r[1].keys[2]=2;

	L.r[2].keys[0]=9;
	L.r[2].keys[1]=0;
	L.r[2].keys[2]=1;

    L.r[3].keys[0]=3;
	L.r[3].keys[1]=6;
	L.r[3].keys[2]=1;

	L.r[4].keys[0]=0;
	L.r[4].keys[1]=3;
	L.r[4].keys[2]=9;

	L.r[5].keys[0]=0;
	L.r[5].keys[1]=8;
	L.r[5].keys[2]=5;

	L.r[6].keys[0]=4;
	L.r[6].keys[1]=8;
	L.r[6].keys[2]=1;

	L.r[7].keys[0]=5;
	L.r[7].keys[1]=0;
	L.r[7].keys[2]=5;
}

void main()		                 //main function
{
	SLList L;
    cout<<"RadixSort.cpp"<<endl<<"============="<<endl<<endl;
	InitExample(L);              //For example
	RadixSort(L);                //RadixSort
	cout<<endl;
    getch();
}