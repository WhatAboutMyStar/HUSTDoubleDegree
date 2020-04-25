#include"Prof.h"
#include<string>
#include<iostream>
#include"PERSON.h"
using namespace std;
Prof::Prof(string name_, int id_, int age_, int insurance_, double salary_, string interest_) :
	PERSON{ name_,id_ }, age{ age_ }, insurance{ insurance_ }, salary{ salary_ }, interest{ interest_ }
{

}

void Prof::print()
{
	//打印姓名、年龄、社会保险号、工资和研究方向
	cout << "姓名：" << name << endl;
	cout << "年龄：" << age << endl;
	cout << "社会保险号：" << insurance << endl;
	cout << "工资：" << salary << endl;
	cout << "研究方向：" << interest << endl;
}