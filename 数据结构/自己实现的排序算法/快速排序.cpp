#include<iostream>
#include<stdio.h>
using namespace std;

# define MAXSIZE 20
# define MAX_LENGTH 100

typedef int RedType;

typedef struct			//define structure SqList
{   
	RedType	r[MAXSIZE+1]; // 缓存数组
    int length; // 长度
}SqList;

int Partition(SqList &L,int low,int high)
{
	L.r[0]=L.r[low];
	while(low<high)
	{
		while(low<high&&L.r[0]<=L.r[high]) --high;
		L.r[low]=L.r[high];
		while(low<high&&L.r[0]>=L.r[low]) ++low;
		L.r[high]=L.r[low];
	}
	L.r[low]=L.r[0];
	return low;
}
void Qsort(SqList& L,int low,int high)
{
	int pivotloc;
	if(low<high)
	{
		pivotloc=Partition(L,low,high);
		Qsort(L,low,pivotloc-1);
		Qsort(L,pivotloc+1,high);
	}
}

void QuickSort(SqList&L)
{
	Qsort(L,1,L.length);
}

int main()
{
	SqList L;
	L.length=10;
	int j = 1;
	for(int i = 9;i>=0;i--)
	{
		L.r[j]=i;
		j++;	
	}	
	cout<<"排序前:";
	for(int i = 1;i<=L.length;i++)
	{
		cout<<L.r[i]<<" ";
	}
	cout<<endl;
	cout<<"排序后:";
	QuickSort(L);
	for(int i = 1;i<=L.length;i++)
	{
		cout<<L.r[i]<<" ";
	}
	cout<<endl;

	return 0;
} 
