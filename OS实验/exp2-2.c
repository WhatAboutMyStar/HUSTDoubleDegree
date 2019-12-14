#include<stdio.h>
#include<unistd.h>
#include<time.h>
int main()
{
	printf("\n");
	int p = fork(); 
	if(p==0)
	{
		while(1)
		{
			printf("child1: pid = %d b\n",getpid());
			sleep(5);
		}	
	}
	else
	{
		
		if(fork()==0)
		{
			while(1)
			{
				printf("child2: pid = %d c\n",getpid());		
				sleep(5);			
			}		
		}
		while(1)
		{
			printf("parent: pid = %d a\n",getpid());
			sleep(5);		
		}
	}
}

