#pragma once
#include<string>
#include"PERSON.h"
using namespace std;
class Staff : public PERSON {
private:
	int age;
	int insurance; //±£œ’
	double salary;

public:
	Staff() = default;
	Staff(string name_, int id_, int age_, int insurance_, double salary_);
	virtual void print();
};
