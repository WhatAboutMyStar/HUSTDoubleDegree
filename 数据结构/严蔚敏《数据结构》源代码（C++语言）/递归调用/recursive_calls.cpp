/*
 ******************************************
 * 《递归调用》实例分析 Copyleft @ 华兄
 *
 * 个人主页 http://591881218.qzone.qq.com/
 ******************************************
*/

#include <stdio.h>

#define OK 1
#define ERROR 0

int func(int Cnt,int fre, ...);

/* 递归：层层调用，层层返回，返回到断点 */
int func(int Cnt,int fre, ...)
{	/* 由特殊到一般的归纳思维 */
	printf("Cnt = %d\n",Cnt); // Cnt

	fre++;

	if(Cnt==1)
		return OK; // One return value if Everything is Ok.
	else if(Cnt>1)
		/************************************************************************************************************
		 下面两条语句执行的最终结果一样，但“func(--Cnt,fre);”同时还执行两次“printf("func(%d) is over!\n",fre);”
		 语句(下面)，编译器发出警告：“'func' : not all control paths return a value”，所有被调用函数的返回值都
		 是通过某一个(组)特殊寄存器传递，而不会跟随被调用函数结束而消失。
		************************************************************************************************************/
		/*①*/func(--Cnt,fre); // 堆栈依然会为返回值准备空间
		/*②*///return func(--Cnt,fre); // 规范用法
	else 
		return ERROR;

	/********************************************************** 
	 fre的值不一样，说明每个被调用函数都有自己独立的堆栈空间，
	 注意，如果没有下面的“return OK;”，函数返回值将出现异常！
	**********************************************************/
	//printf("func(%d) is over!\n",fre); // Cnt-1

	//return OK; // 匹配“func(--Cnt,fre);”语句，逻辑上有出入，可以去掉
}

int main()
{
	int num=0,fre=0,tmp=0;
	
	printf("Enter a valid positive number: ");
	scanf("%d",&num);
	tmp=func(num,fre);

	if(OK==tmp)
		printf("Everything is Ok!\n\n");
	else if(ERROR==tmp)
		printf("Please input a valid positive number!\n\n");
	else 
		printf("Something is Error!\n\n");

	return OK;
}
