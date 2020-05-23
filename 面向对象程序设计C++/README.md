# C++ 考试复习注意
- 目前提供模拟卷两份以Markdown文档形式上传，方便在网页端阅读

## 2020/5/23日模拟考试

### （一）填空题
- 1
```
若有：
int i;
int &j=i;
i=10;
j=i+1;
则执行上段程序后， i=__11____，j=___11_____。
```
- 2
```
在程序中填空：
class point{
public:
void show() {cout<<”point”<<endl;}
};
void main()
{
point p1;
point *p;
p=&p1;
____p1.show()___________ //通过对象p1 访问show 函数
____p->show()__________ //通过指针p 访问show 函数
}
```
- 3
```
面向对象程序设计的三个基本特征是___继承____、_封装___、__多态______。

```
- 4
```
new 的功能是____，
delete 的功能是___。（这应该不用专门写答案了吧）
```
- 5
```
如果一个类中至少有一个纯虚函数，则该类称为_____抽象类_______。
```
### （二）选择题
- 1
```
在C++语言中，使用class 定义类时，隐含的访问权限为_________。
(A) private （B）protected （C）public （D）const
```
- 2
```
一个类的数据成员可被本类的成员函数访问，该数据成员的权限可以是_________。
（A）public （B）protected （C）private （D）以上都对
```
- 3
```
一个只能被本类的成员函数和其友元函数访问的数据成员，其权限是_________。
（A）public （B）protected （C）private （D）protected 和private
```
- 4
```
在私有继承方式下，派生类只能访问其基类的_________。
（A）私有成员（B）保护成员（C）公有成员（D）公有和保护成员
```
- 5
```
下列说法中不正确的是_________。
（A）公有继承时，基类中的public 成员在派生类中仍是public 的
（B）公有继承时，基类中的protected 成员在派生类中仍是protected 的
（C）公有继承时，基类中的private 成员在派生类中仍是private 的
（D）私有继承时，基类中的public 成员在派生类中是private 的
```
- 6
```
关于析构函数，下列说法中不正确的是_________。
（A）析构函数可以有形参（B）析构函数有且只有一个
（C）析构函数可以被自动或显式调用（D）析构函数无返回类型

```
- 7
```
说明一个函数为虚函数时，使用的前缀关键字是_________。
（A）const （B）static （C）virtual （D）friend

```
- 8
```
在C++中，用于实现动态多态性的是_________。
（A）虚函数（B）友元函数（C）模板函数（D）静态成员函数

```
- 9
```
下列关于运算符重载的描述中，错误的是_________。
（A）运算符重载不能改变操作数个数（B）运算符重载不能改变运算符的功能
（C）运算符重载不可以改变结合方向（D）运算符重载不可以改变运算优先级
```
- 10
```
下列特性中不是面向对象程序设计语言所特有的是_________。
（A）封装（B）继承（C）多态性（D）模板
```
### （三）判断题
- 1 
```
在C++语言中，在main()函数中，语句const int x; 没有语法错误。( )
```

- 2
```
在C++语言中，在main()函数中，语句const char *p; 没有语法错误。( )
```

- 3 
```
在一个类的定义中，可以用语句const int x; 定义一个常数据成员，但必须在该类的所有的
构造函数成员初始值设定项列表中初始化。( )
```

- 4 
```
在一个类的定义中，可以用语句static int x=0; 定义一个静态数据成员。( )
```

- 5 
```
在一个类A 中，有带参数的构造函数，但没有无参数的构造函数时，可以使用如下方式定义一
个对象指针： A *p = new A[10]; ( )
```

- 6 
```
设A 类中有公有函数A & operator=(A &t)。在主程序中已有A 类对象obj1，现定义另一个该
类对象obj2 时，使用语句A obj2 = obj1; 该语句会调用A 类的operator= 函数。( )
```

- 7 
```
设A 类中有公有函数A & operator=(A &t)。在主程序中已有A 类对象obj1,obj2，语句obj2
= obj1; 会调用A 类的operator= 函数。( )
```

- 8 
```
设A 类中没有以对象引用为参数的拷贝构造函数，在主程序中已有A 类对象obj1，现定义另一
个该类对象obj2 时，语句A obj2 = obj1; 语法是正确的。( )
```

- 9 
```
下面三种情况下，都会调用以对象引用为参数的拷贝构造函数。( )
（A）当函数的形参是对象，调用该函数传入对象值参时；
（B）当函数的返回值是对象，函数执行结束，返回调用者时；
（C）定义一个对象，用另一个对象初始化时。
```

- 10 
```
下面三种情况下，都会自动调用类的析构函数。( )
（A）当函数的形参是对象，调用该函数执行结束时；
（B）当函数中定义了对象，调用该函数执行结束时；
（C）当函数的返回值是一个对象，且未使用该函数定义另一个对象时，返回值被存放在临时对象
中，临时对象生命周期结束时。
```

### （四）阅读程序
```
请按程序运行时显示的先后顺序写。顺序不正确不给分。
1． 执行如下程序段， 显示的结果是什么？ (4 分)
#include <iostream >
using namespace std;
void exchange( int x, int y)
{ int temp;
temp=x; x=y; y=temp;
}
int main()
{ int p=60, q=80;
exchange(p , q );
cout<< "p= " << p <<endl;
cout<<" q= " << q << endl;
return 0;
}
显示的是：
如果将void exchange( int x, int y) 改为void exchange( int &x, int &y)，显示的结
果又是什么？
2．执行下面的程序后，显示的结果是什么？ (4 分)
#include <iostream >
using namespace std;
class student {
private:
int weight;
static int count;
public:
student (int x ) {
weight =x; count++;
cout<< " weight = "<< weight << " count = " << count<< endl;
}
void print_ weight ( ) {
cout<< " weight = "<< weight << " count = " << count<< endl;
}
};
int student::count=0;
void main()
{ student s1(22), s2(24) , s3(26);
s2. print_ weight ( );
}

3. 执行下面的程序后，显示的结果是什么？ (12 分)
#include <iostream >
using namespace std;
class Base {
private:
int x;
public:
Base(int t )
{
x = t;
cout<<" x = "<< x << endl;
}
virtual void display( ) { cout<<" Base Class!"<<endl; }
void tellvalue ( ) { cout<<"variable x is "<< x << endl; }
~Base( ) { cout<<" Deconstruct Base Object"<<endl; }
};
class Derived : public Base{
private:
int y;
public:
Derived( int xx, int yy) : Base(xx)
{
y =yy;
cout<<" y = "<< y << endl;
}
void display( ) { cout<<" Derived Class!"<<endl; }
void tellvalue ( ) { cout<<"variable y is "<<y << endl; }
~Derived ( ) { cout<<" Deconstruct Derived Object "<<endl; }
};
int main()
{
Derived myDerived(10, 20); // 显示：
myDerived . display ( ); // 显示：
Base *p = new Derived(30, 40); // 显示：
p -> display ( ); // 显示：
p-> tellvalue( ); // 显示：
((Derived *)p)->tellvalue(); // 显示：
delete p; // 显示：
cout<<"over"<<endl; // 显示：
return 0;
} // 显示：
```
### （五）程序改错
```
下面的程序有一些语法错误，请修改之，使之实现预定的功能。
#include <iostream>
using namespace std;
class Person
{
private:
int age;
public:
void Person(int i) {age = i;} //错误
void SetAge(int m) {age=m;}
int IncreaseAge ( ) const{ // 错误
age = age+1;
return age;
}
void DisplayAge( ) {cout<<"age="<<age<<endl;}
~Person() {
cout<<"Deconstruct person"<<endl;
}
};
void main()
{
int t;
Person obj1;
obj1.DisplayAge(); // 该行语句执行后显示： age=10
Person obj2(3);
obj2.age=20; //错误
obj2.DisplayAge( ); // 该行语句执行后显示： age=20
Person *p = &obj2;
t = p.IncreaseAge(); // 错误
p->DisplayAge( ); // 该行语句执行后显示： age=21
}
```

### （六）程序阅读和理解
```
阅读如下程序：写出main 函数中各条语句执行后显示的结果。（10 分）
#include <iostream>
using namespace std;
class Array {
private:
int length; int *data;
public:
Array( ) {
length=0;
data = NULL;
cout<<"construct Array without parameter"<<endl;
};
Array(int len) {
length = len;
data=new int[length];
memset(data,0,sizeof(int)*length);
cout<<"construct Array length ="<<length<<endl;
};
void Init( )
{ data[2]=2;
data[1]=1;
data[0]=100;
}
Array(Array &p)
{ length = p.length;
data= new int[length];
memcpy(data,p.data,sizeof(int)*length);
cout<<"construct Array by object"<<endl;
}
~Array() {
cout<<"deconstruct Array length = "<<length<<endl;
if (data) delete [] data;
};
void friend display_first(Array p);
void friend display_second(Array &p);
};
void display_first(Array p) {cout<<"first element is "<<p.data[0]<<endl; }
void display_second(Array &p) {cout<<"second element is "<<p.data[1]<<endl; }
void main( ) {
Array a1(10); // 显示
a1.Init( );
display_first(a1); // 显示
display_second(a1); // 显示
Array *p1=new Array(1); // 显示
Array *p2=new Array[1]; // 显示
delete p1; // 显示
delete [ ]p2; // 显示
} // 显示

2、在上述程序中，删掉函数Array(Array &p) 之后，程序仍然可编译连接，生成执
行程序。运行该新的程序会有什么不同（重点写不同之处）， 并解释产生差异的原
因？（10 分）
```


### （七）编写程序
按照要求，编写完整的程序。
- (1) 定义一个一维整型数数组OneArray 类，包括如下成员
- 私有数据成员： int length; // 数组长度<br>
  int *data; // 数据区指针
- 构造函数（数组长度）： 设置数组长度，并为数据区动态分配空间；
- 以对象引用为参数的复制构造函数， 用一个数组对象构造另一个对象；
- 初始化函数：给数组中的各元素赋值（运行程序时，输入具体的数据）；
- 析构函数：释放分配的空间
- 重载= 运算符，将一个数组对象拷贝赋值给另一个数组对象；
- 重载+运算符，实现两个一维数组对象的加法（即数组中各对应元素相加），
- 要求两个运算对象都不能不改变，运算结果可赋值给另一个对象。
- (2) 在主程序中，按顺序逐项完成如下功能
- 定义一个OneArray 类对象a1，其数组长度为10 ；
- 初始化a1 的数据元素；
- 用对象a1 构造对象a2;
- 定义对象a3, 其数组长度为20 ；将a1 对象赋值给对象a3
- 将a1 与a2 的之和赋给a3。

```
//参考程序
#include<iostream>
#include<algorithm>
using namespace std;
class OneArray{
private:
	int length;
	int *data;
public:
	//构造函数（数组长度）： 设置数组长度，并为数据区动态分配空间；
	OneArray(int len)
	{
		length = len;
		data = new int[len];
	}
	//以对象引用为参数的复制构造函数， 用一个数组对象构造另一个对象；
	OneArray(OneArray& a)
	{
		data = new int[a.length];
		length = a.length;
		for(int i=0;i<length;i++)
		{
			data[i] = a.data[i];
		}
	}
	//初始化函数：给数组中的各元素赋值（运行程序时，输入具体的数据）；
	void Init()
	{
		for(int i=0;i<length;i++)
		{
			cin>>data[i];
		}
	}
	~OneArray()
	{
		delete [] data;
	}
	//重载= 运算符，将一个数组对象拷贝赋值给另一个数组对象；
	void operator=(const OneArray& a)
	{
		if(length == a.length)
		{
			for(int i=0;i<length;i++)
			{
				data[i] = a.data[i];
			}
		}
		else if(length > a.length)
		{
			length = a.length;
			for(int i=0;i<a.length;i++)
			{
				data[i] = a.data[i];
			}
		}
		else
		{
			cout<<"数组长度左侧数组过小\n";
		}
	}
	
	//重载+运算符，实现两个一维数组对象的加法（即数组中各对应元素相加），
	//要求两个运算对象都不能不改变，运算结果可赋值给另一个对象。
	OneArray operator+(const OneArray& a)
	{
		int l = min(length,a.length);
		OneArray temp(l);
		for(int i=0;i<l;i++)
		{
			temp.data[i] = data[i] + a.data[i];
		}
		temp.print();
		return temp;
	}
	
	void print()//测试用
	{
		for(int i=0;i<length;i++)
		{
			cout<<data[i]<<" ";	
		}	
		cout<<endl;
	} 
};
int main()
{
	OneArray a1(10);
	a1.Init();//0 1 2 3 4 5 6 7 8 9
	a1.print();
	
	OneArray a2(a1);
	a2.print();
	
	OneArray a3(20);
	a3 = a1;
	a3.print();
	
	a3 = a1 + a2 ;
 	a3.print();
	return 0;
}

```
