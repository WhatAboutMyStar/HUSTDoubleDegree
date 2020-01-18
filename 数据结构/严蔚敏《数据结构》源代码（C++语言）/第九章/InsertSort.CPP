/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//InsertSort.cpp
//This function is to sort SqList
# include <iostream.h>
# include <conio.h>

# define MAXSIZE 20
# define MAX_LENGTH 100

typedef int RedType;

typedef struct			//define structure SqList
{   
	RedType	r[MAXSIZE+1]; // 缓存数组
    int length; //长度
}SqList;

/* 插入排序 */
void InsertSort(SqList &L)	//InsertSort() sub-function
{  
	int i,j;
	/********************************************************************************************
	 整个排序过程为先将第1个记录作为一个有序序列，然后从第2个记录起，逐个将记录插入到该有序序列。
	 对于n个记录的插入排序过程为进行n-1趟插入排序的过程。
	********************************************************************************************/
    for(i=2;i<=L.length;++i) // 共进行L.length-1趟
		if(L.r[i]<L.r[i-1])
		{                  // 需将L.r[i]插入有序子表
			L.r[0]=L.r[i]; // 复制为监视哨

			for(j=i-1;L.r[0]<L.r[j];--j)
				L.r[j+1]=L.r[j]; // 记录后移
			
			L.r[j+1]=L.r[0]; // 插入记录
        }
}

void main()			//main() function
{  
	int i;
    SqList L;
    cout<<endl<<endl<<"InsertSort.cpp";
    cout<<endl<<"==============";
    cout<<endl<<"Please input the length of SqList (eg,5): "<<endl<<endl;
    cin>>L.length;
    for(i=1;i<=L.length;++i)
    {   
		cout<<"Please input the "<<i<<"th integer (eg,58): ";
        cin>>L.r[i];
    }
    cout<<endl<<"The disordered : ";
    for(i=1;i<=L.length;i++)
        cout<<L.r[i]<<"  ";
    InsertSort(L);		//call InsertSort()
    cout<<endl<<"The ordered    : ";
    for(i=1;i<=L.length;i++)
        cout<<L.r[i]<<"  ";
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end