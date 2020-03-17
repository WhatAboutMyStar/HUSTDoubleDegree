/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//Shellinert.cpp
//This function is Shell sort
# include <iostream.h>
# include <conio.h>

# define MAXSIZE 20

# define OK 1
# define ERROR 0

typedef int RedType;

typedef struct				//structure SqList
{   
	RedType	r[MAXSIZE+1]; // 缓存数组
    int length; // 长度
}SqList;

/* 希尔排序 */
void Shellinsert(SqList &L,int dk/* 增量 */) 	//Shellinsert() sub-function
{   /****************************
	 对顺序表L作一趟希尔插入排序
	****************************/
	int i,j;

    for(i=dk+1;i<=L.length;++i)
	{
		/******************************************
		 i与i-dk同组相邻，逆序则在本组查找插入位置 

		 假设，(58,12,6)同组

		 12<58 交换以后变成(12,58,6)
		 6<58，6<12 交换以后变成(6,12,58)
		******************************************/
		if(L.r[i]<L.r[i-dk]) // 需将L.r[i]插入有序增量子表
        {   
			L.r[0]=L.r[i]; // 暂存在L.r[0]
			for(j=i-dk;j>0&&(L.r[0]<L.r[j]);j-=dk) 
				L.r[j+dk]=L.r[j]; // 本组记录后移，查找插入位置
	        L.r[j+dk]=L.r[0]; // 插入
        }
	}
}

void main()				//main() function
{  
	int i,dk=5;
    SqList L={{0,49,38,65,97,76,13,27,49,55,4},10};
    cout<<endl<<endl<<"Shellinsert.cpp";
    cout<<endl<<"==============="<<endl;
    cout<<endl<<endl<<"The disordered             : ";
    for(i=1;i<=L.length;i++)
		cout<<L.r[i]<<"  ";
    Shellinsert(L,dk);            	//call Shellinsert()
    cout<<endl<<"The once ShellSorted sorted: ";
    for(i=1;i<=L.length;i++)
		cout<<L.r[i]<<"  ";
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end