/*今天的作业：在 第 7章第2题 （c07_02）的基础上，增加一些功能。
（1）信息查询   例如，身份证号，或者姓名等，查找相应的人员是否存在。若不存在，则显示未找到；
否则，显示该人员的其他信息。
（2）删除查找到某一个结点  ； 
（3）只显示链表中的学生的信息，其他人员的信息不显示 
（4）在链表中找出分出大于某个给定值的学生，并显示出来。  注意，为了实现相应的功能，可修改基类的数据成员。
*/

#include<iostream>
#include<string>
#include"PERSON.h"
#include"Prof.h"
#include"Staff.h"
#include"Student.h"
using namespace std;

int main()
{
	//7.2 test
	PERSON* p = new PERSON(); //链表头结点
	//插入4个人
	p->insert(p);
	p->insert(p);
	p->insert(p);
	p->insert(p);
	//查找,查一个存在的，再查一个不存在的
	p->search();
	p->search();
	//删除一个人
	p->del(p);
	//显示学生信息
	p->showStudent0();
	//显示特定学生信息,高于60分就输出
	p->showStudentR0(60);
	return 0;
}
