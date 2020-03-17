#include<iostream>
#include <conio.h>
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

void BubbleSort(SqList&L)
{
	int temp;
	for(int i=0;i<L.length-1;i++)
	{
		for(int j = 0;j<L.length-1-i;j++)
		{
			if(L.r[j]>L.r[j+1])
			{
				temp=L.r[j];
				L.r[j]=L.r[j+1];
				L.r[j+1]=temp;
			}
		}
	}
}

int main()
{
	SqList L;
	L.length=10;
	int j = 0;
	for(int i = 9;i>=0;i--)
	{
		L.r[j]=i;
		j++;	
	}	
	cout<<"排序前：";
	for(int i = 0;i<L.length;i++)
	{
		cout<<L.r[i]<<" ";
	}
	cout<<endl;
	cout<<"排序后:";
	BubbleSort(L);
	for(int i = 0;i<L.length;i++)
	{
		cout<<L.r[i]<<" ";
	}

	return 0;
} 
