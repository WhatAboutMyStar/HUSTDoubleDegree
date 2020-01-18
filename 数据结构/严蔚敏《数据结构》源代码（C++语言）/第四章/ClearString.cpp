/*
 ******************************************
 * 注释 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

//ClearString.cpp
//Clear the String

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <iostream.h>
#include <stdlib.h>

#define MAXSIZE_S 40
#define OK 1
#define ERROR 0

typedef struct
{	
	char * ch; // 串的头指针
	int length; // 串的长度
}HString;

/* 清空串 */
int ClearString(HString &S)         //ClearString() function
{   //To clear the string S to be empty
    if (S.ch) // 释放串
    {free(S.ch); S.ch=NULL;}       //if S.ch !=NULL then free it
    S.length =0; // 长度清零
    return(OK);                      //success to clear the string S
}//end of clearString

/* 初始化串 */
int StrAssign(HString &S,char * chars)               //StrAssign() function
{                                                    //create a string T=chars
	int i=0,j;
	char *c;
	/********************************
	 原代码清空操作失败，想想为什么？
	********************************/
	// 串不为空，清空串
	//if(S.ch) free(S.ch);                             //dispose(T)
	for(c=chars;c[i]!='\0';i=i+1);// 计算串的长度
                         							 //i get the length of chars
	if(!i) // 长度为零
	{S.ch=NULL;S.length=0;}                          //if i==0 then set String T NULL
    else // 长度不为零
	{
		if(!(S.ch=(char *)malloc(i*sizeof(char)))) // 为串分配空间
		{ 
			cout<<"OVERFLOW!"<<endl;
		    return (ERROR);
		}//end of if
		else // 分配空间成功，为串赋值
		{  
			for(j=0;j<=i-1;j++)
				S.ch[j]=chars[j];
			/* 原代码少一个操作 */
			//S.ch[j]='\0'; // 此程序中，串加结束符位置竟然不一般
			S.ch[j-1]='\0'; // 错误用法，无奈总是调不通，空间释放失败
		    S.length=i; 
		}//end of else                                        
	}//end of else        
	printf("S.ch = %s\n",S.ch);
	return(OK);
}//end of StrAssign() function

void main()                                              //main() function
{
    char charsS[MAXSIZE_S];                               //user define here
    HString S;
    cout<<"ClearString.cpp"<<endl<<"================"<<endl;
    cout<<"Please input the string S: ";
    cin>>charsS;
    StrAssign(S,charsS);
    cout<<"Clear String result: "<<ClearString(S)<<endl;
    cout<<"...OK!"<<endl;
    getch();
}


