/*
在上周完成的 3.2 作业基础上，增加如下用法和功能。
（1）在能够加上 const 约束的地方，加上const 约束。包括 函数参数、常函数等等。
（2）给出增加const约束后违犯该约束的一个语法错误的语句（或者语句段），之后，将这些错误语句放在注释中，注明错误原因。
（3）增加一个静态数据成员，用于记录某一时刻有多少个类对象存在。（当 构造函数被调用时，记录的次数加1；当 析构函数被调用时，记录的次数加1）。每当该数据成员发生变化时，要输出相应的信息(静态成员的值，被构造或析构的对象中data串的内容。例如 ：construct  ***  string is ***** ;
（4）采用 NEW 和 delete 来创建和释放 树节点。
（5）在树节点（NODE）中，增加一个常数据成员 value, 保存该节点的价值（或权重）。遍历一棵树或者子树后，返回树的总 value,并输出总 value.
（6）增加一个私有的静态数据成员，记录树的创建者的姓名（即编程者）。在树中查找某一个串是否存在。存在时，输出该节点的创建者。
（7）输出类的大小，各个非静态数据成员在类中的偏移地址。要求使用数据成员指针的方式获得偏移地址。（设有指针 p, *(int *)&p 即为偏移量）
（8）修改某一个节点的 value 值（注意，value是常数据成员，要使用强制的类型转换），修改时要求使用数据成员指针。
*/
#include<iostream>
#include<string>
#include"Node.h"
int NODE::count = 0;
std::string NODE::name = "lyh";
int NODE::valueSum = 0;
int main()
{
	NODE t;
	
	char ch[11] = "0123456789";
	for (int i = 0; i < 10; i++)
	{
		t.insert(&ch[i]);
		std::cout << "现有节点数：" << t.count << std::endl;
	}

	std::cout << "先序遍历：\n";
	t.preOrder();
	std::cout << std::endl;
	std::cout << "valueSum = " << NODE::valueSum << std::endl;
	std::cout << "中序遍历：\n";
	t.inOrder();
	std::cout << std::endl;

	if (t.search(&ch[2]) == NULL)
	{
		std::cout << "Not Found\n";
	}
	else
	{
		std::cout << "creator name :" << NODE::name << std::endl;
		std::cout << "Find :" << t.search(&ch[0]) << std::endl;
	}
	printf("data的地址：%d\n", t.getDatap());
	printf("left的地址：%d\n", t.getLeftp());
	printf("right的地址：%d\n", t.getRightp());
	printf("value的地址：%d\n", t.getValuep());

	//调用析构函数销毁所有节点
	std::cout << "现在执行析构函数\n";
	t.~NODE();
	std::cout << "现有节点数：" << t.count << std::endl;
	std::cout << "类的大小：" << sizeof(t) << std::endl;
	//设置value的值为2
	t.setValue(2);
	std::cout << "Value:" << t.getValue() << std::endl;
	return 0;
}