#include<iostream>
#include"Set.h"

SET::SET(int card)
{
	SET::card = card;
	used = 0;
	set = new int[card];
	std::cout << "SET对象成功创建!\ncard="<<SET::card<<"\nused="<<used << std::endl;
}
SET::~SET()
{
	delete[] set;
	std::cout << "SET对象已经销毁！" << std::endl;
}
int SET::size()
{
	return used;
}
int SET::insert(int v)
{
	if (used <= card)
	{
		set[used++] = v;
		return 1;
	}
	return 0;
}
int SET::remove(int v)
{
	int index = -1;
	for (int i = 0; i < used; i++)
	{
		if (v == set[i])
		{
			index = i;
		}
	}
	if (index == -1)
	{
		return 0;
	}
	for (int i = index + 1; i < used; i++)
	{
		set[i - 1] = set[i];
	}
	used--;
	return 1;
}
int SET::has(int v)
{
	for (int i = 0; i < used; i++)
	{
		if (set[i] == v)
		{
			return 1;
		}
	}
	return 0;
}