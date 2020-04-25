#include<string>
#include<iostream>
#include"Student.h"
#include"PERSON.h"
using namespace std;

Student::Student(string name_, int id_, int age_, int insurance_, int grade_, double avg_) :
	PERSON{ name_,id_ }, age{ age_ }, insurance{ insurance_ }, grade{ grade_ }, avg{ avg_ }
{

}

void Student::print()
{
	//姓名、年铃、社会保险号、年级和平均成绩
	cout << "姓名：" << name << endl;
	cout << "年龄：" << age << endl;
	cout << "社会保险号：" << insurance << endl;
	cout << "年级：" << grade << endl;
	cout << "平均成绩：" << avg << endl;
}

void Student::showStudent()
{
	//姓名、年铃、社会保险号、年级和平均成绩
	cout << "姓名：" << name << endl;
	cout << "年龄：" << age << endl;
	cout << "社会保险号：" << insurance << endl;
	cout << "年级：" << grade << endl;
	cout << "平均成绩：" << avg << endl;
}

//限制分数
void Student::showStudentR(double avg_)
{
	if (avg > avg_)
	{
		//姓名、年铃、社会保险号、年级和平均成绩
		cout << "姓名：" << name << endl;
		cout << "年龄：" << age << endl;
		cout << "社会保险号：" << insurance << endl;
		cout << "年级：" << grade << endl;
		cout << "平均成绩：" << avg << endl;
	}
}