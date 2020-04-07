#include<iostream>
char c, * pc;
const char cc = 'a';
const char* pcc;
char* const cpc = &c;
const char* const cpcc = &cc;
char* const* pcpc;

int main()
{
	//1
	c = cc;   //正确没有问题
	//2
	//cc = c;   错误一个常量不能再次赋值
	//3
	pcc = &c;  //正确没有问题
	//4
	pcc = &cc; //正确没有问题
	//5
	pc = &c;//正确没有问题
	//6
	//pc = &cc;  错误一个普通变量不能指向一个常量，如若可以则存在普通变量改变常量值的可能性
	//7
//	pc = pcc;  错误无法从“const char *”转换为“char *”
	//8
//	pc = cpcc; 无法从“const char *const ”转换为“char *”
	//9
//	cpc = pc;  常量不能被赋值
	//10
	*pc = "ABCD"[2]; //正确没有问题
	//11
//	cc = 'a'; 本来就是常量不能再被赋值了
	//12
	*cpc = *pc;   //正确没有问题
	//13
	pc = *pcpc;//正确没有问题
	//14
	**pcpc = *pc;//正确没有问题
	//15
	*pc = **pcpc;//正确没有问题
	//16
//	*pcc = 'b';  常量不能被赋值
	//17
//	*pcpc = 'c'; 普通变量无法转化为常量
	//18
//	*cpcc = 'd'; 不能给常量赋值
	return 0;
}