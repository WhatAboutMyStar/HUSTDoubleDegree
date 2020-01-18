/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//MergeSort.cpp

#include <iostream.h>
#include <conio.h>
#define MAXSIZE 20

#define LENGTH 7

typedef int RedType;

typedef struct		         //SqList structure
{   /* 缓存数组 */
	RedType	r[MAXSIZE+1];    //Records Type
    int length; // 长度
}SqList;

typedef SqList RcdType;

/* 将有序的SR[i...m]和SR[m+1...n]归并为有序的TR[i...n] */
void Merge(RcdType SR,RcdType &TR,int i,int m,int n)       //Merge() function
{   
	int j,k;
    for(j=m+1,k=i;i<=m&&j<=n;++k) // 将SR中记录由小到大并入TR
    {   
		if(SR.r[i]<=SR.r[j])
			TR.r[k]=SR.r[i++];
	    else
			TR.r[k]=SR.r[j++];
    }
    while(i<=m)
        TR.r[k++]=SR.r[i++]; // 将剩余的SR[i...m]复制到TR
    while(j<=n)
        TR.r[k++]=SR.r[j++]; // 将剩余的SR[j...n]复制到TR
}//end of Merge() function 

/* 将SR[s...t]归并排序为TR1[s...t] */
void MSort(RcdType SR,RcdType &TR1,int s, int t)           //MSort() function     
{  
	int m;
    RcdType TR2;//[LENGTH];
    if(s==t)
		TR1.r[s]=SR.r[t]; // 结束条件
    else
    {  
		/* 由特殊到一般的归纳思维 */
		m=(s+t)/2; // 将SR[s...t]平分为SR[s...m]和SR[m+1...t]
        MSort(SR,TR2,s,m); // 递归地将SR[s...m]归并为有序的TR2[s...m]
        MSort(SR,TR2,m+1,t); // 递归地将SR[m+1...t]归并为有序的TR2[m+1...t]
        Merge(TR2,TR1,s,m,t); // 将TR2[s...m]和TR2[m+1...t]归并到TR1[s...t]
    }//end of else
}//end of MSort() function

/* 对顺序表L作归并排序 */
void MergeSort(SqList &L)	//MergeSort() function
{
    MSort(L,L,1,L.length);
}//end of MergeSort() function

void main()		            //main function
{  
	int i;
    SqList L;//={{0,49,38,65,97,76,13,27,},LENGTH};
    cout<<"MergeSort.cpp"<<endl<<"============="<<endl<<endl;
    cout<<"Please input the length of SqList L: <eg. 7> ";
    cin>>L.length;

    cout<<"Please input the disordered array L.r: <eg. {49,38,65,97,76,13,27,...}>"<<endl;
    for(i=1;i<=L.length;i++)
		cin>>L.r[i];
    MergeSort(L);
    cout<<endl<<"The sorted array L.r:  ";
    for(i=1;i<=L.length;i++)
		cout<<L.r[i]<<"  ";
    cout<<endl;
    cout<<"...OK!..."<<endl;
    getch();
}//end of main() function