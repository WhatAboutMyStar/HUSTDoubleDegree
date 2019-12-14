#include<stdio.h>
#include<unistd.h>

int main()
{
	if(fork()==0)
	{
		printf("\n");
		execl("./a.out","./a.out",NULL);			
	}
	else
	{
		printf("\n");
		printf("我是父进程\n");
	}	
	return 0;
}
