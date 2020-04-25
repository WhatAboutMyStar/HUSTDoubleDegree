#pragma once
#include"PERSON.h"
#include<string>
using namespace std;
class Student : public PERSON {
private:
	int age;
	int insurance; //保险
	int grade; //年级
	double avg; //平均成绩

public:
	Student() = default;
	Student(string name_, int id_, int age_, int insurance_, int grade_, double avg_);
	virtual void print();
	virtual void showStudent();
	virtual void showStudentR(double avg_);
};