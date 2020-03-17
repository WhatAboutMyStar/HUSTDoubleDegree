/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//SelectSort.cpp
//This function is to SelectSort SqList
# include <iostream.h>
# include <conio.h>

# define MAXSIZE 20

typedef int RedType;

typedef struct			//define structure SqList
{   
	RedType	r[MAXSIZE+1]; // 缓存数组
    int length; // 长度
}SqList;

/* 插入排序 */
void SelectSort(SqList &L)	//SelectSort() sub-function
{   
	int i,j,k,temp;
    for(i=0;i<L.length;++i) // 选择第i小的记录，并交换到位
    {   
		k=i;

		for(j=i+1;j<L.length;++j) // 在剩下的记录中选择key最小的记录
			if(L.r[j]<L.r[k])
				k=j;
		if(i!=k) // 把最小的记录放到位置i
		{   
			temp=L.r[i];
			L.r[i]=L.r[k];
			L.r[k]=temp; // 与第i记录交换
		}
    }
}//SelectSort() end

void main()			//main() function
{  
	int i;
    SqList L={{49,38,65,97,76,13,27,49,},8};
    cout<<endl<<endl<<"SelectSort.cpp";
    cout<<endl<<"=============="<<endl;
    cout<<endl<<"The disordered : ";
    for(i=0;i<L.length;i++)
        cout<<L.r[i]<<"  ";
    SelectSort(L);		//call SelectSort()
    cout<<endl<<"The sorted     : ";
    for(i=0;i<L.length;i++)
		cout<<L.r[i]<<"  ";
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end