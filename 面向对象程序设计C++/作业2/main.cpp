/*
作业：以 3.2题为基础，构造一棵二叉树，树的深度不小于 3. 
（1）以先序遍历的方式，显示各个节点data 指向的内容。
(2) 查找某一个串是否在树中出现，返回找到的节点指针。
（3）以中序遍历的方式，显示以（2）中找到的节点为树根的子树。
要求：不改变数据成员的定义（私有的变量）；增加适当的成员函数，
完成上述功能；增加适当的普通函数（main函数），对上述功能进行测试。
*/
#include<iostream>
#include"Node.h"

int main()
{
	NODE t;
	char ch[11] = "0123456789";
	for (int i = 0; i < 10; i++)
	{
		t.insert(&ch[i]);
	}

	std::cout << "先序遍历：\n";
	t.preOrder();
	std::cout << std::endl;

	std::cout << "中序遍历：\n";
	t.inOrder();
	std::cout << std::endl;

	if (t.search(&ch[2]) == NULL)
	{
		std::cout << "Not Found\n";
	}
	else
	{
		std::cout << "Find :" << t.search(&ch[0]);
	}
	return 0;
}
