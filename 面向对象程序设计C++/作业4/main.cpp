//书6.3题 ， 7.2题
/*
6.3定义描述个人信息的类PERSON ，记录个人姓名name 和身份证号IDnumber 等信
息，定义函数成员print ， 打印个人基本情况然后由类PERSON 派生出类
TEACHER ，记录教师个人职称、工薪等信息.定义函数成员print，打印教师的基
本情况.
*/
#include<iostream>
#include<string>
using namespace std;
class PERSON {
protected:
	string name;
	int id;
	PERSON* next; //7.2题用
	
public:
	PERSON() = default;
	PERSON(string name_, int id_);
	virtual void print();
	void insert(PERSON* p); //7.2
	void del(PERSON* p); //7.2
};

class TEACHER: public PERSON{
private:
	string title; //职称
	double salary;

public:
	TEACHER() = default;
	TEACHER(string name_, int id_, string title_, double salary_);
	virtual void print() override;
};

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

TEACHER::TEACHER(string name_ ,int id_, string title_, double salary_)
	:PERSON{ name_,id_ }, title{ title_ }, salary{ salary_ }
{

}

void TEACHER::print()
{
	PERSON::print();
	cout << "职称是：" << title << endl;
	cout << "工资：" << salary << endl;
}

void print(PERSON* p)
{
	p->print();
}
/*
7.2在异质链表中，每个节点的类型不要求相同，节点指针通常使用父类指针. 以大学学
生及教职人员为例，学生信息包括姓名、年铃、社会保险号、年级和平均成绩等， 职
员信息包括姓名、年龄、社会保险号和工资等，教授信息包括姓名、年龄、社会保险
号、工资和研究方向等.为大学学生及教职人员建立-个异质链表，插入、删除和打
印大学人员信息.*/
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
};

Student::Student(string name_, int id_, int age_, int insurance_, int grade_, double avg_):
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

Prof::Prof(string name_, int id_, int age_, int insurance_, double salary_, string interest_):
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


class Staff : public PERSON {
private:
	int age;
	int insurance; //保险
	double salary;

public:
	Staff() = default;
	Staff(string name_, int id_, int age_, int insurance_, double salary_);
	virtual void print();
};
Staff::Staff(string name_, int id_, int age_, int insurance_, double salary_):
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
	t->next = t->next->next;
	delete p;
	cout << "成功删除该结点\n";
}

int main()
{
	//6.3 test
	TEACHER t{ "许向阳",123456789,"教授",99999999.99 };
	t.print();
	print(&t);
	cout << endl;
	
	//7.2 test
	PERSON* p = new PERSON(); //链表头结点
	p->insert(p);
	p->insert(p);
	p->del(p);

	return 0;
}
