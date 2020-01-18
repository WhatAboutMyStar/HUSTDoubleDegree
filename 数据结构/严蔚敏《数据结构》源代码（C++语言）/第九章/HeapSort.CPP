/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//HeapSort.cpp
//This function is to HeapSort SqList
# include <iostream.h>
# include <conio.h>

# define MAXSIZE 20

typedef int RedType;

typedef struct		//define structure SqList
{   
	RedType	r[MAXSIZE+1]; // 缓存数组
    int length; // 长度
}SqList;

typedef SqList HeapType;

/* 堆排序筛选算法 */
void HeapAdjust(HeapType &H,int s,int m) //HeapAdjust() sub-function
{  
	int temp,j;
    temp=H.r[s];
    for(j=2*s;j<=m;j*=2)
    {  
		if(j<m&&(H.r[j]<H.r[j+1])) // 沿key较大的孩子结点向下筛选
								   // j为key较大的记录的下标
			++j;
        if(!(temp<H.r[j])) // rc应插入的位置，在s处
			break;
        H.r[s]=H.r[j]; // 将记录转存至上一次位置s处
        s=j; // 保存此次记录下标
    }
    H.r[s]=temp; // 插入记录
} //HeapAdjust() end

/* 堆排序 */
void HeapSort(HeapType &H)      	//HeapSort() sub-function
{  
	int i,temp;
    for(i=H.length/2;i>0;--i) // 把H建成大顶堆
		HeapAdjust(H,i,H.length);
	for(i=H.length;i>1;--i)
    {  
		temp=H.r[1];
        H.r[1]=H.r[i];
        H.r[i]=temp; // 堆项记录和当前末排子序中最后一个记录相交换
        HeapAdjust(H,1,i-1); // 将H.r[1...i-1]重新调整为大项堆
    }
} //HeapSort() end

void main()				//main() function
{  
	int i;
	HeapType H={{0,49,38,65,97,76,13,27,49},8};
    cout<<endl<<endl<<"HeapSort.cpp";
    cout<<endl<<"============"<<endl;
    cout<<endl<<"The disordered : ";
    for(i=1;i<=H.length;i++)
		cout<<H.r[i]<<"  ";
    HeapSort(H);				//call HeapSort()
    cout<<endl<<"The sorted     : ";
    for(i=1;i<=H.length;i++)
		cout<<H.r[i]<<"  ";
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end