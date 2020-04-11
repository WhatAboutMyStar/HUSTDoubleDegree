#include "Node.h"
#include<iostream>
#include<string>
NODE::NODE()
{

}
NODE::NODE(char* data)
{
	if (this->data = new char[strlen(data) + 1])
	{
		strcpy_s(this->data,strlen(data) + 1, data);
		left = right = 0;
	}
}
NODE::NODE(char* data, NODE* left, NODE* right)
{
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
		delete data;
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
		std::cout << *data << " ";
	}
	if (right)
	{
		right->inOrder();
	}
}
NODE* NODE::search(char* x)
{
	if (*x > *data)
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
