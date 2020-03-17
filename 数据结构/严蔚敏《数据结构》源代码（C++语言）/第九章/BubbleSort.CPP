/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//BubbleSort.cpp
//This function is to sort SqList
# include <stdio.h>
# include <iostream>
# include <conio.h>
using namespace std;
# define MAXSIZE 20
# define MAX_LENGTH 100

typedef int RedType;

typedef struct			//define structure SqList
{   
	RedType	r[MAXSIZE+1]; // 缓存数组
    int length; // 长度
}SqList;

/* 冒泡排序 */
void BubbleSort(SqList &L)
{   
	int i,j,temp;

	/* 本程序中，L.length=实际元素个数+1 */
	//printf("L.length= %d\n",L.length); // 本人添加，调试用

	/* 假设实际元素个数用Real表示，本人觉得至多进行Real-1趟，Real-1=L.length-2 */

	/* 原代码 */
    //for(i=1;i<=L.length;++i) // 总共进行L.length趟

	/* 修改以后代码 */
	for(i=1;i<L.length-1;++i) // 总共进行L.length-2趟
		for(j=L.length-2;j>=i;--j) // 一趟排序，排好元素无需再排
			if(L.r[j+1]<L.r[j]) // 每两个相邻的关键字进行比较，逆序交换
			{   
				temp=L.r[j+1];
	            L.r[j+1]=L.r[j];
	            L.r[j]=temp;
			}
}

/* 本人提供另外一种实现方法 */
/*int Bubble_Sort(SqList &L) // 冒泡排序算法
{
	int i,j;
	int flag;
	ElemType temp;

	for(i=1;i<=L.length-1;i++) // 至多进行length-1趟排序
	{
		flag=0; // 设置标志位
		for(j=L.length-1;j>=i;j--) // 一趟排序，排好元素无需再排
		{
			if(L.elem[j].key < L.elem[j-1].key) // 每相邻元素进行比较
			{
				temp=L.elem[j];
				L.elem[j]=L.elem[j-1];
				L.elem[j-1]=temp; // 逆序时，交换记录
				flag=1; // 标志位置位
			}
		}
		if(flag==0) return True; // 判断排序是否结束
	}

	return False;
}*/

int main()			//main() function
{  
	int i;
    SqList L;
    cout<<endl<<endl<<"BubbleSort.cpp";
    cout<<endl<<"=============="<<endl;
    cout<<endl<<"Please input the length of SqList (eg,5): ";
    cin>>L.length;
    L.length++;			//the last is aided space
    for(i=1;i<L.length;++i) // 1 -> L.length-1
    {   
		cout<<"Please input the "<<i<<"th element of SqList (eg,58): ";
        cin>>L.r[i];
    }
    cout<<endl<<"The disordered : ";
    for(i=1;i<L.length;i++)
		cout<<L.r[i]<<"  ";
    BubbleSort(L);		//call BubbleSort()
    cout<<endl<<"The ordered    : ";
    for(i=1;i<L.length;i++)
		cout<<L.r[i]<<"  ";
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end
