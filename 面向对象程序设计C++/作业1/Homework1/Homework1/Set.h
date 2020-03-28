#pragma once
class SET {
	int* set;
	int card;
	int used;
public:
	SET(int card);
	~SET();
	int size();
	int insert(int v);
	int remove(int v);
	int has(int v);
};