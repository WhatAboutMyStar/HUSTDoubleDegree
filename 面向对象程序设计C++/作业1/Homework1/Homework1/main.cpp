#include<iostream>
#include"Set.h"
int main()
{
	SET s(10);
	for (int i = 0; i < 10; i++)
	{
		s.insert(i);
	}
	std::cout<<"集合的大小是：" << s.size() << std::endl;
	int test[10];
	for (int i = 0; i < 10; i++)
	{
		std::cout<<"has:"<<s.has(i)<<std::endl;
		std::cout<<"remove:" << s.remove(i) << std::endl;
		std::cout << "size: " << s.size() << std::endl;
	}

	return 0;
}