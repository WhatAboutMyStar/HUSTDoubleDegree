#pragma once
#include<string>
using namespace std;
class PERSON {
public:
	string name;
	int id;
	PERSON* next; //7.2Ã‚”√
	PERSON() = default;
	PERSON(string name_, int id_);
	virtual void print();
	void insert(PERSON* p); //7.2
	void del(PERSON* p); //7.2
	void search();
	virtual void showStudent();
	virtual void showStudent0();
	virtual void showStudentR(double avg_);
	virtual void showStudentR0(double avg_);
};