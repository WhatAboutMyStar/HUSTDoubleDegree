#include"PERSON.h"
#include"Staff.h"
#include"Student.h"
#include"Prof.h"
#include<string>
#include<iostream>
using namespace std;
PERSON::PERSON(string name_, int id_)
{
	name = name_;
	id = id_;
	next = nullptr;
}

void PERSON::print()
{
	cout << "姓名：" << name << endl;
	cout << "身份证号：" << id << endl;
}

//插入结点:传入头结点
void PERSON::insert(PERSON* p)
{
	cout << "插入学生输入1，老师输入2，教职工输入3:" << endl;
	int num;
	cin >> num;

	string name_;
	int id_;
	int age_;
	int insurance_;
	int grade_;
	double avg_;
	double salary_;
	string interest_; //研究方向

	PERSON* t;

	switch (num)
	{
	case 1:
		//string name_, int id_, int age_, int insurance_, int grade_, double avg_
		cout << "请输入学生姓名：";
		cin >> name_;
		cout << "请输入学生身份证：";
		cin >> id_;
		cout << "请输入学生年龄：";
		cin >> age_;
		cout << "请输入社会保险号：";
		cin >> insurance_;
		cout << "请输入学生年级：";
		cin >> grade_;
		cout << "请输入学生平均成绩：";
		cin >> avg_;
		t = new Student{ name_,id_,age_,insurance_,grade_,avg_ };
		t->next = p->next;
		p->next = t;
		cout << "插入学生成功!\n";
		break;
	case 2:
		cout << "请输入老师姓名：";
		cin >> name_;
		cout << "请输入老师身份证：";
		cin >> id_;
		cout << "请输入老师年龄：";
		cin >> age_;
		cout << "请输入社会保险号：";
		cin >> insurance_;
		cout << "请输入老师工资：";
		cin >> salary_;
		cout << "请输入老师研究方向：";
		cin >> interest_;
		t = new Prof{ name_,id_,age_,insurance_,salary_,interest_ };
		t->next = p->next;
		p->next = t;
		cout << "插入老师成功\n";
		break;
	case 3:
		cout << "请输入职工姓名：";
		cin >> name_;
		cout << "请输入职工身份证：";
		cin >> id_;
		cout << "请输入职工年龄：";
		cin >> age_;
		cout << "请输入社会保险号：";
		cin >> insurance_;
		cout << "请输入职工工资：";
		cin >> salary_;
		t = new Staff{ name_,id_,age_,insurance_,salary_ };
		t->next = p->next;
		p->next = t;
		cout << "插入职工成功\n";
		break;
	}
}

//删除结点
void PERSON::del(PERSON* p)
{
	cout << "请输入你要删除的姓名：";
	string name_;
	cin >> name_;
	bool flag = false;
	PERSON* t = p;
	p = p->next;
	while (p)
	{
		if (p->name == name_)
		{
			flag = true;
			break;
		}
		t = t->next;
		p = p->next;
	}
	if (flag == true)
	{
		t->next = t->next->next;
		delete p;
		cout << "成功删除该结点\n";
	}
	else
	{
		cout << "不存在该节点\n";
	}
	
}

void PERSON::search()
{
	cout << "请输入你要查找人的姓名：";
	string name_;
	cin >> name_;
	bool flag = false;
//	PERSON* t = p;
	PERSON* p = this->next;
	while (p)
	{
		if (p->name == name_)
		{
			flag = true;
			break;
		}
	//	t = t->next;
		p = p->next;
	}
	if (flag == true)
	{
		p->print();
	}
	else
	{
		cout << "没找到这个人\n";
	}
}

void PERSON::showStudent0()
{
	PERSON* p = this->next;
	while (p)
	{
		p->showStudent();
		p = p->next;
	}
}

void PERSON::showStudent()
{

}

void PERSON::showStudentR0(double avg_)
{
	PERSON* p = this->next;
	while (p)
	{
		p->showStudentR(avg_);
		p = p->next;
	}
}

void PERSON::showStudentR(double avg_)
{
	
}