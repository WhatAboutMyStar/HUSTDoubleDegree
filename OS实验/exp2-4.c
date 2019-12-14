#include<stdio.h>
#include<unistd.h>
int main()
{
	
	if(fork()==0)
	{
		printf("getpid2 = %d\n",getpid());
		printf("getppid2 = %d\n",getppid());
		if(fork()==0)
		{
			printf("getpid3 = %d\n",getpid());
			printf("getppid3 = %d\n",getppid());
			if(fork()==0)
			{
				printf("getpid5 = %d\n",getpid());
				printf("getppid5 = %d\n",getppid());
			}
			sleep(1);
		}
		else
		{
			if(fork()==0)
			{
				printf("getpid4 = %d\n",getpid());
				printf("getppid4 = %d\n",getppid());			
			}		
		}
	}
	else
	{
		printf("getpid1 = %d\n",getpid());
		printf("getppid1 = %d\n",getppid());
	}
	return 0;
}
