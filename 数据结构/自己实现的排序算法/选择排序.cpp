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

void SelectSort(SqList& L)
{
	int i,j,min;
	RedType temp;
	for(i=0;i<L.length;i++)
	{
		min=i;
		for(j=i+1;j<L.length;j++)
		{
			if(L.r[j]<L.r[min])
			{
				min=j;
			}
		}
		if(i!=min)
		{
			temp=L.r[i];
			L.r[i]=L.r[min];
			L.r[min]=temp;
		}
	}
}

int main()
{
	SqList L={{9,8,7,6,5,4,3,2,1,0},10};
	
	cout<<"排序前:";
	for(int i = 0;i<L.length;i++)
	{
		cout<<L.r[i]<<" ";
	}
	cout<<endl;
	cout<<"排序后:";
	SelectSort(L);
	for(int i = 0;i<L.length;i++)
	{
		cout<<L.r[i]<<" ";
	}
	cout<<endl;

	return 0;
} 
