/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//Search_Seq.cpp
//This function is to find location of the inputed element in SSTbale
# include <stdio.h>
# include <malloc.h>
# include <iostream.h>
# include <conio.h>

# define MAX_LENGTH 100

typedef int KeyType;

typedef struct				//define structure SSTable
{   
	KeyType *elem; // 缓冲头
    int length; // 长度
}SSTable;

/* 本人刚开始范了一个错误，折半查找用于有序表(由小到大) */
int Search_Seq(SSTable ST,KeyType key)	//Search_Seq function
{   
	int mid,low=1,high=ST.length; // 置区间初值
	printf("ST.length= %d\n",ST.length); // 本人添加，调试用
	
    while(low<=high) // 又叫二分查找
    {  
		mid=(low+high)/2; 
        if(key==ST.elem[mid]) // 找到待查元素
			return (mid);
		else if(key<ST.elem[mid]) // 继续在前半区间进行查找
			high=mid-1;
	    else
			low=mid+1;
    }

    return (0); // 顺序表中不存在待查元素
}

void main()  			   	//main() function
{  
	int i,key;
    SSTable ST;
	/***********
	 原代码勘误 
	***********/
    //ST.elem=(KeyType *)malloc(sizeof(KeyType));
	ST.elem=(KeyType *)malloc(MAX_LENGTH*sizeof(KeyType));
    cout<<endl<<endl<<"Search_Seq.cpp";
    cout<<endl<<"==============";
    cout<<endl<<endl<<"Please input the length of array (eg,5): ";
    cin>>ST.length;
    for(i=1;i<=ST.length;++i)
    {  
		cout<<"Please input the "<<i<<"th element (eg,58)   : ";
        cin>>ST.elem[i];
    }
    cout<<endl<<"The SSTable ST is : ";
    for(i=1;i<=ST.length;i++)
		cout<<ST.elem[i]<<"  ";		//output ST.elem[]
    cout<<endl<<endl<<"Please input the data to find : ";
    cin >>key;				//input the element to find
    cout<<"The location of "<<key<<" is (0 for none): ";
    cout<<Search_Seq(ST,key);		//call Search_Seq()
    cout<<endl<<endl<<"...OK!...";
    getch();
} //main() end