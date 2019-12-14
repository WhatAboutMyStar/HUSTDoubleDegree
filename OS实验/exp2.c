#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("\n");
	int p = fork(); 
	if(p==0)
	{
		printf("pid = %d b\n",getpid());
	}
	else
	{
		printf("pid = %d a\n",getpid());
		if(fork()==0)
		{
			printf("pid = %d c\n",getpid());		
		}
	}
}
