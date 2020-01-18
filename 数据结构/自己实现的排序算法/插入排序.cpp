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

void InsertSort(SqList&L)
{
	int i,j;
	for(i=2;i<=L.length;i++)
	{
		if(L.r[i]<L.r[i-1])
		{
			L.r[0]=L.r[i]; 
			for(j=i-1;L.r[0]<L.r[j];j--)
			{
				L.r[j+1]=L.r[j];
			}
			L.r[j+1]=L.r[0];
		}
	}
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
	InsertSort(L);
	for(int i = 1;i<=L.length;i++)
	{
		cout<<L.r[i]<<" ";
	}
	cout<<endl;

	return 0;
} 
