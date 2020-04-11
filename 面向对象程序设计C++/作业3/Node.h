#pragma once
#include<string>
class NODE {
	char* data;
	NODE* left, * right;
	const int value = 1;
public:
	static int count;
	static std::string name;
	static int valueSum;
	NODE();
	NODE(char*);
	NODE(char* data, NODE* left, NODE* right);
	~NODE();
	void insert(char* x) ;
	void preOrder();
	void inOrder();
	const NODE* search(char* x);
	char* getDatap();
	NODE* getLeftp();
	NODE* getRightp();
	const int* getValuep();
	void setValue(int x);
	int getValue();
};