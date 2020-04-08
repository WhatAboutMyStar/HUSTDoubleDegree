/*
构造一棵二叉树，树的深度不小于 3. 
（1）以先序遍历的方式，显示各个节点data 指向的内容。
（2）查找某一个串是否在树中出现，返回找到的节点指针。
（3）以中序遍历的方式，显示以（2）中找到的节点为树根的子树。
要求：不改变数据成员的定义（私有的变量）；
增加适当的成员函数，完成上述功能；
增加适当的普通函数（main函数），对上述功能进行测试。
*/ 


#include<iostream>
using namespace std;

char target='b'; 

class NODE{
	char *data;
	NODE *left,*right;
public:
	NODE(char *c){data=c;left=0;right=0;};
	NODE(char *c,NODE *l,NODE *r){data=c;left=l;right=r;};
	~NODE(){};
	NODE *DLR(bool (NODE::*func)());
	NODE *LDR(bool (NODE::*func)());
	bool prt();
	bool compare();
};

NODE *NODE::DLR(bool (NODE::*func)()){
	NODE *temp;
	if((this->*func)())return this;
	if(left){
		temp=left->DLR(func);
		if(temp)return temp;
	}
	if(right){
		temp=right->DLR(func);
		if(temp)return temp;
	}
	return 0;
}

NODE *NODE::LDR(bool (NODE::*func)()){
	NODE *temp;
	if(left){
		temp=left->LDR(func);
		if(temp)return temp;
	}
	if((this->*func)())return this;
	if(right){
		temp=right->LDR(func);
		if(temp)return temp;
	}
	return 0;
}


bool NODE::prt(){
	cout<<*data;
	return 0;
}

bool NODE::compare(){
	if(*data==target)return 1;
	else return 0;
}


int main(){
	char a='a',b='b',c='c',d='d',e='e';
	NODE x(&c),y(&d),z(&e);
	NODE q(&b,&y,&z);
	NODE p(&a,&q,&x);
	p.DLR(&NODE::prt);
	cout<<endl<<"请输入查找字符：";
	cin>>target;
	NODE *target_ptr=p.DLR(&NODE::compare);
	if(target_ptr)*target_ptr->LDR(&NODE::prt);
	else cout<<"字符未找到";
	return 0;
}
