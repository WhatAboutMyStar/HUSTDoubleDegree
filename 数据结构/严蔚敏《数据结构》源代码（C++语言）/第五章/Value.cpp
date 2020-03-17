/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//Value.cpp

#include <stdarg.h>
#include <iostream.h>
#include <malloc.h>
#include <stdio.h>
#include <conio.h>

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

int Locate(Array A,va_list ap,int &off)               //Locate() function
{   //To get the offset of  element in the array A
	int ind,i;
	off=0;
    for(i=0;i<A.dim;++i) // 若ap指示的各下标值合法，则求出该元素在A中相对地址off
	{	
		ind=va_arg(ap,int); // 取得int类型的可变参数值
		printf("ind%d= %d\n",i,ind); // 本人添加，调试用
		/* 检测下标 */
		if(ind<0||ind>=A.bounds[i]) return OVERFLOW;  //Illegal substript
		off+=A.constants[i]*ind; // 例如，数组A[5][6]，则&A[1][1]=7
								 // A.constants[0]=6，A.constants[1]=1
	}//end of for
	return OK;
}//end of Locate() function
 
int Assign(Array &A,ElemType e,...)                   //Assign() function
{
	va_list ap; // va 可变参数
	int result,off=0;
	va_start(ap,e); // 初始化ap，等于第一个可变参数在堆栈的地址
	if((result=Locate(A,ap,off))<=0)  return result; // 获取元素相对地址
	*(A.base+off)=e; // 存储元素相对地址
	printf("off= %d\n",off); // 本人添加，调试用
	printf("e= %d\n",e); // 本人添加，调试用
	va_end(ap); // 结束ap
	return OK;
}//end of Assign() function

int Value(Array A,ElemType e,...)                     //Value() function
{
	int result,off=0;
	va_list ap;
	va_start(ap,e);
	if((result=Locate(A,ap,off))<=0) return result;
	e=*(A.base+off); // 获取元素相对地址
	printf("off= %d\n",off); // 本人添加，调试用
	printf("e= %d\n",e); // 本人添加，调试用
	va_end(ap);
	return e;                                   //that is OK;
}//end of Value() function

/* 创建dim-1维数组 */ 
int InitArray(Array &A,int dim,...)             //InitArray() function 
{
	int i,elemtotal=1;                          //Initialize total element of A 
	/* va 可变参数 */
	va_list ap;
	/* 有效性检测 */
	if(dim<1||dim>MAX_ARRAY_DIM) return (ERROR);//if dimention is illegal then return ERROR;
	A.dim=dim;                                  //set dimention of array
	A.bounds=(int*)malloc(dim*sizeof(int));     //allocate space for array A.bounds
    if(!A.bounds) return (OVERFLOW);            //failure to allocate
	/* 初始化ap，等于第一个可变参数在堆栈的地址 */
	va_start(ap,dim);                           //ap are the type of va_list
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
	int dim=2,r,i=0;                                      //default dimention is 2;
	int off=0,e=50/*,GetValue*/;                              //default Assign values=50;

	int bound[MAX_ARRAY_DIM];
	int Assbound[MAX_ARRAY_DIM];
	int GetVal[MAX_ARRAY_DIM];
	printf("Value.cpp\n=========\n\n");
	printf("Please input the dimentions of array you want to create: <eg. DimentionNum=2> \n");
	scanf("%d",&dim);                   
	printf("please assign the length of each dimention: \n<eg. Dimention1.length=3, Dimention2.length=4,...>\n");
	
	for(i=0;i<dim;i++)
	{   
		printf("Dimention%d.length= ",i+1);
		scanf("%d",&bound[i]);	
	}//end of for

	if(r=InitArray(A,dim,bound[0],bound[1],bound[2],bound[3],bound[4],bound[5],bound[6],bound[7]))
	{
		cout<<endl<<"Success to Initialize a Array!"<<endl
		    <<"Dimention= "<<dim<<endl<<"Total element is: "<<r<<endl<<endl;
        printf("Now begin to Assign!\n");
		printf("Assign values = <eg. 340>");
		scanf("%d",&e) ;
	    cout<<"Please input the array subscripts of which you want to assign values: "<<endl
			<<"Array[J1,J2,J3,...] <eg. J1=2,J2=3,...>"<<endl;
		//default: Abound[0]=0;Abound[1]=4;Abound[2]=1;Abound[3]=0;Abound[4]=1;Abound[5]=1;Abound[6]=0;Abound[7]=1;
		for(i=0;i<dim;i++)               //input the subscript of each dimention      
		{   
			printf("J%d= ",i+1);
		    scanf("%d",&Assbound[i]);
		}//end of for  

		if(Assign(A,e,Assbound[0],Assbound[1], Assbound[2], Assbound[3], Assbound[4], Assbound[5], Assbound[6], Assbound[7])==OK)
			cout<<endl<<"Success to Assign the array A!"<<endl; 
		else 
			cout<<"Failure to Assign."<<endl;

        cout<<"Now begin to GetValue!"<<endl;
		cout<<"Please input the array subscripts of which you want to GetValue: "<<endl
			<<"Array[J1,J2,J3,...] <eg. J1=2,J2=3,...>"<<endl;
		//default: Abound[0]=0;Abound[1]=4;Abound[2]=1;Abound[3]=0;Abound[4]=1;Abound[5]=1;Abound[6]=0;Abound[7]=1;
		for(i=0;i<dim;i++)               //input the subscript of each dimention      
		{   
			printf("J%d= ",i+1);
		    scanf("%d",&GetVal[i]);
		}//end of for  

		r=Value(A,/* 参数有误 */e,/*GetValue,*/GetVal[0],GetVal[1], GetVal[2],GetVal[3],GetVal[4], GetVal[5], GetVal[6],GetVal[7]);
		if(r!=OVERFLOW&&r!=UNDERFLOW&&r!=ERROR)
			cout<<"Success to GetValue from the array A!"<<endl
			    <<"The value is: "
		        <<r
				<<endl;
        else 
			cout<<"Failrue to GetValues!"<<endl;
	}//end of if
    getch();
}//end of main() function



