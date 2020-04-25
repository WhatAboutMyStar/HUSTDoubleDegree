#include<string>
#include<iostream>
#include"Staff.h"
#include"PERSON.h"
using namespace std;

Staff::Staff(string name_, int id_, int age_, int insurance_, double salary_) :
	PERSON{ name_,id_ }, age{ age_ }, insurance{ insurance_ }, salary{ salary_ }
{

}

void Staff::print()
{
	//打印姓名、年龄、社会保险号和工资
	cout << "姓名：" << name << endl;
	cout << "年龄：" << age << endl;
	cout << "社会保险号：" << insurance << endl;
	cout << "工资：" << salary << endl;
}