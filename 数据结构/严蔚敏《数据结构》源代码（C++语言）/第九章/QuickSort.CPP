/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//QuickSort.cpp
//This function is to quick-sort SqList
# include <iostream.h>
# include <conio.h>

# define MAXSIZE 20

typedef int RedType;

typedef struct		//define SqList structure
{   
	RedType	r[MAXSIZE+1]; // 缓存数组
    int length; // 长度
}SqList;

/* 一趟快速排序过程 */ 
int Partition(SqList &L,int low,int high)	//Partition() sub-function
{   /* 交换顺序表L中子表r[low..high]的记录，枢轴记录到位，并返回其所在位置，
	   此时在它之前(后)的记录均不大(小)于它 */
	int pivotkey;
    L.r[0]=L.r[low]; // 用子表的第一个记录作枢轴记录
    pivotkey=L.r[low]; // 枢轴记录关键字
    while(low<high) // 从表的两端交替地向中间扫描
    {  
		while(low<high&&L.r[high]>=pivotkey) --high;
	    L.r[low]=L.r[high]; // 将比枢轴记录小的记录移到低端
	    while(low<high&&L.r[low]<=pivotkey) ++low;
	    L.r[high]=L.r[low]; // 将比枢轴记录大的记录移到高端
    }
    L.r[low]=L.r[0]; // 枢轴记录到位
    return (low); // 返回枢轴位置
} //Partition() end

/* 递归形式的快速排序 */
void Qsort(SqList &L,int low,int high)	//Qsort() sub-function
{  
	int pivotloc;
	/* 结束：每一部分中只剩下一个记录为止 */
    if(low<high) // 长度大于1
    {  
		pivotloc=Partition(L,low,high); // 将L.r[low..high]一分为二
        Qsort(L,low,pivotloc-1); // 对低子表递归排序，pivotloc是枢轴位置
        Qsort(L,pivotloc+1,high); // 对高子表递归排序
    }
}

void QuickSort(SqList &L)		//QuickSort() sub-function
{  
	Qsort(L,1,L.length);			//call Qsort()
}

void main()				//main() function
{  
	int i;
    SqList L={{0,49,38,65,97,76,13,27,49},8};
    cout<<endl<<endl<<"QuickSort.cpp";
    cout<<endl<<"============="<<endl;
    cout<<endl<<"The disordered : ";
    for(i=1;i<=L.length;i++)
		cout<<L.r[i]<<"  ";
    QuickSort(L);			//call QuickSort()
    cout<<endl<<"The sorted     : ";
    for(i=1;i<=L.length;i++)
		cout<<L.r[i]<<"  ";
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end