#include <stdio.h>

int f(int x)
{
    if (x==1)  return 1;
	return x*f(x-1);
}

void main()
{
   printf("%d\n",f(5));
}
