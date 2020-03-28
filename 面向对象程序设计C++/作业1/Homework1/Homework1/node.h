#pragma once
class NODE {
	char* data;
	NODE* left, * right;
public:
	NODE(char*);
	NODE(char* data, NODE* left, NODE* right);
	~NODE();
};