/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//InitArray.cpp

#include <stdarg.h>
#include <iostream.h>
#include <malloc.h>
#include <stdio.h>

#define MAX_ARRAY_DIM 8
#define ERROR 0
#define OVERFLOW -1
#define UNDERFLOW -2
#define OK 1

typedef int ElemType;
typedef struct
{	
	ElemType *base; // 数组元素基址
	int dim; // 数组维数
	int *bounds; // 数组维界基址，即每维大小
	int *constants; // 数组映像函数常量基址
}Array;

/* 创建dim-1维数组 */
int InitArray(Array &A,int dim,...)               //InitArray() function    
{
	int i,elemtotal=1;                            //Initialize total element of A 
	/* va 可变参数 */
	va_list ap;
	/* 有效性检测 */
	if(dim<1||dim>MAX_ARRAY_DIM) return (ERROR);  //if dimention is illegal then return ERROR;
	A.dim=dim;                                    //set dimention of array
	A.bounds=(int*)malloc(dim*sizeof(int));       //allocate space for array A.bounds
    if(!A.bounds) return (OVERFLOW);              //failure to allocate
	/* 初始化ap，等于第一个可变参数在堆栈的地址 */
	va_start(ap,dim);                             //ap are the type of va_list
	/**********************************************
	 第1维大小 × 第2维大小 × … × 第dim-1维大小
	**********************************************/
	for(i=0;i<dim;i++) // 计算dim-1维数组总的元素个数
	{
		A.bounds[i]=va_arg(ap,int); // 取得int类型的可变参数值
	    if(A.bounds[i]<0) return (UNDERFLOW); // 溢出
		elemtotal *=A.bounds[i];
	}//end of if

	va_end(ap); // 结束ap
	/* 分配存储空间 */
	A.base=(ElemType*)malloc(elemtotal*sizeof(ElemType));//allocating space to A.base
	if(!A.base) return(OVERFLOW);
	
	A.constants=(int*)malloc(dim*sizeof(int));           //allocating space to A.constants
	if (!A.constants) return(OVERFLOW);
	A.constants[dim-1]=1;                                 
	for(i=dim-2;i>=0;--i)                                //get the const Ci and save into A.constants[i-i],i=1,..,dim
		A.constants[i]=A.bounds[i+1]*A.constants[i+1]; // 存取第i维以后总的元素个数
	return elemtotal; // 总的元素个数
}//end of InitArray() function

	
void main()                                               //main() function
{
	Array A;
	int dim=2,r,i=0;                                      //Demo dimention is 2;
	int bound[MAX_ARRAY_DIM];
	printf("InitArray.cpp\n=============\n\n");
	do
	{	
		i++;
		printf("Please input the dimentions of array you want to create: <eg. 3> ");
	    scanf("%d",&dim);
	}while((dim<1||dim>MAX_ARRAY_DIM)&&i<3);           //input ctrl
	
	printf("please assign the length of each dimention: <eg. 3,4,5,...>\n");
	
	for(i=0;i<dim;i++)
	{   
		printf("dim[%d]= ",i+1);
		scanf("%d",&bound[i]);
	}

	if(r=InitArray(A,dim,bound[0],bound[1],bound[2],bound[3],bound[4],bound[5],bound[6],bound[7]))
		cout<<"Success to Initialize a Array!"<<endl
		    <<"Dimention= "<<dim<<endl<<"Total element is: "<<r<<endl;
	else 
		cout<<"Failure to InitArray!: ("<<r<<")"<<endl;

}



