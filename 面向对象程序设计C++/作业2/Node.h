#pragma once
class NODE {
	char* data;
	NODE* left, * right;
public:
	NODE();
	NODE(char*);
	NODE(char* data, NODE* left, NODE* right);
	~NODE();
	void insert(char* x);
	void preOrder();
	void inOrder();
	NODE* search(char* x);
};
