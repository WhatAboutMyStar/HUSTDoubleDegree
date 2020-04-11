#include "Node.h"
#include<iostream>
#include<string>
NODE::NODE()
{
	count++;
}
NODE::NODE(char* data)
{
	count++;
	if (this->data = new char[strlen(data) + 1])
	{
		strcpy_s(this->data, strlen(data) + 1, data);
		left = right = 0;
	}
}
NODE::NODE(char* data, NODE* left, NODE* right)
{
	count++;
	this->data = data;
	this->left = left;
	this->right = right;
}
NODE::~NODE()
{
	if (left)
	{
		left->~NODE();
	}
	if (right)
	{
		right->~NODE();
	}
	if (data)
	{
		count--;
		delete data;
		std::cout << "该节点被销毁，现有节点数：" << count << std::endl;
		data = 0;
	}
}
void NODE::insert(char* x)
{
	if (data == nullptr)
	{
		data = new char[strlen(x) + 1];
		strcpy_s(data, strlen(x) + 1, x);
		return;
	}
	if (*x >= *data)
	{
		if (!right)
		{
			right = new NODE(x);
			return;
		}
		right->insert(x);
	}
	else if (*x < *data)
	{
		if (!left)
		{
			left = new NODE(x);
			return;
		}
		left->insert(x);
	}
}

void NODE::preOrder()
{
	if (data)
	{
		std::cout << *data << " ";
		valueSum += value;
	}
	if (left)
	{
		left->preOrder();
	}
	if (right)
	{
		right->preOrder();
	}
}

void NODE::inOrder()
{
	if (left)
	{
		left->inOrder();
	}
	if (data)
	{
		valueSum += value;
		std::cout << *data << " ";
	}
	if (right)
	{
		right->inOrder();
	}
}
const NODE* NODE::search(char* x)
{
	if (*x > * data)
	{
		if (!right)
		{
			return NULL;
		}
		return right->search(x);
	}
	else if (*x < *data)
	{
		if (!left)
		{
			return NULL;
		}
		return left->search(x);
	}
	else
	{
		return this;
	}
}
char* NODE::getDatap()
{
	return data;
}
NODE* NODE::getLeftp()
{
	return left;
}
NODE* NODE::getRightp()
{
	return right;
}
const int* NODE::getValuep()
{
	return &value;
}
void NODE::setValue(int x)
{
	int* changeValue = const_cast<int*>(&value);
	*changeValue = x;
}
int NODE::getValue()
{
	return value;
}