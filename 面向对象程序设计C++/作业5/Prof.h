#pragma once
#include<string>
#include"PERSON.h"
using namespace std;
class Prof :public PERSON {
private:
	int age;
	int insurance; //保险
	double salary;
	string interest; //研究方向

public:
	Prof() = default;
	Prof(string name_, int id_, int age_, int insurance_, double salary_, string interest_);
	virtual void print();
};