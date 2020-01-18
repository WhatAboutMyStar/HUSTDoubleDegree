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

typedef SqList HeapType;

void HeapAdjust(HeapType& H,int s,int m)
{
	int temp,j;
	temp=H.r[s];
	for(j=2*s;j<=m;j*=2)
	{
		if(j<m&&H.r[j]<H.r[j+1]) ++j;
		if(temp>H.r[j]) break;
		H.r[s]=H.r[j];
		s=j;
	}
	H.r[s]=temp;
	
}

void HeapSort(HeapType& H)
{
	int temp,i;
	for(i=H.length/2;i>0;i--)
	{
		HeapAdjust(H,i,H.length);
	}
	for(i=H.length;i>1;i--)
	{
		temp=H.r[1];
		H.r[1]=H.r[i];
		H.r[i]=temp;
		HeapAdjust(H,1,i-1);
	}
}

int main()
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
 

	return 0;
} 
