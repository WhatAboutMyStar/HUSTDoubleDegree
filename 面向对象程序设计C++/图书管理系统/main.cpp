#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<filesystem>
#include"Book.h"
#include<vector>
using namespace std;
int id;

void login(); //初始登录界面
void addBook(); //添加一本书
void deleteBook(); //删除一本书
void Exit(); //退出程序
void findBook(); //查找一本书
void setInfo(); //设置书籍的信息
void showData(); //显示全部书籍信息

//初始登录界面
void login()
{
	system("cls");
	cout << setw(70) << "欢迎来到图书管理系统\n";
	cout << "请选择你要做的操作：\n";
	cout << "0.退出系统\n";
	cout << "1.查看系统中所有书籍\n";
	cout << "2.向系统中添加一本书\n";
	cout << "3.向系统中删除一本书\n";
	cout << "4.更改书籍信息\n";
	cout << "5.查找书籍\n";
}

//显示书籍信息
void showData()
{
	system("cls");
	vector<Book> v;
	ifstream fin("./book.txt");
	if (fin.fail())
	{
		cout << "打开文件失败\n";
		cin.get();
		cin.get();
		return;
	}

	string name;
	string isbn;
	double price;
	string author;
	int id_;
	bool flag;
	
	while (fin.eof() == false)
	{
		fin >> name;
		fin >> isbn;
		fin >> price;
		fin >> author;
		fin >> id_;
		fin >> flag;

		Book book{ name,isbn,price,author,id_ };
		book.setIsBorrow(flag);

		v.push_back(book);
	}
	cout << "一共" << id << "本书\n";
	cout << "ID号"
		<< setw(20) << "图书名称"
		<< setw(20) << "ISBN号"
		<< setw(20) << "书籍价格"
		<< setw(20) << "书籍作者"
		<< setw(20) << "是否被借阅" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].id
			<< setw(20) << v[i].name
			<< setw(20) << v[i].isbn
			<< setw(20) << v[i].price
			<< setw(20) << v[i].author;

		if (v[i].isBorrow == true)
		{
			cout << setw(20) << "借出" << endl;
		}
		else
		{
			cout << setw(20) << "可借" << endl;
		}
	}
	cin.get();
	cin.get();
}

//添加图书
void addBook()
{
	system("cls");
	string name;
	string isbn;
	double price;
	string author;
	cout << "请输入书名：";
	cin >> name;
	cout << "请输入书籍的ISBN号：";
	cin >> isbn;
	cout << "请输入书籍的价格:";
	cin >> price;
	cout << "请输入书籍的作者:";
	cin >> author;
	id++;
	Book book{ name,isbn,price,author,id };
	//更新ID
	ofstream fout("./ID.txt", ios::out);
	fout << id;
	fout.close();

	book.writeData();
}

//删除图书
void deleteBook()
{
	system("cls");
	int id_;
	cout << "请输入你想要删除的图书id:";
	cin >> id_;
	ifstream fin("./book.txt");

	vector<Book> v;

	string name;
	string isbn;
	double price;
	string author;
	int id_read;
	bool isBorrow_;

	while (fin.eof() == false)
	{
		fin >> name;
		fin >> isbn;
		fin >> price;
		fin >> author;
		fin >> id_read;
		fin >> isBorrow_;
		Book book{ name,isbn,price,author,id_read };
		book.setIsBorrow(isBorrow_);

		if (id_ == id_read)
		{
			continue;
		}
		else
		{
			v.push_back(book);
		}		
	}
	fin.close();

	//更新ID
	id--;
	ofstream fout1("./ID.txt", ios::out);
	fout1 << id;
	fout1.close();

	ofstream fout("./book.txt", ios::out);
	for (int i = 0; i < v.size(); i++)
	{
		fout << " " << v[i].name << " "
			<< v[i].isbn << " "
			<< v[i].price << " "
			<< v[i].author << " "
			<< i+1 << " "
			<< v[i].isBorrow;
	}
	fout.close();
}

//查找书籍
void findBook()
{
	system("cls");
	cout << "请输入要查找的书籍的名字:";
	string name_;
	cin >> name_;

	ifstream fin("./book.txt");
	if (fin.fail())
	{
		cout << "打开文件失败\n";
		cin.get();
		cin.get();
		return;
	}

	vector<Book> v;

	string name;
	string isbn;
	double price;
	string author;
	int id_read;
	bool isBorrow_;

	while (fin.eof() == false)
	{
		fin >> name;
		fin >> isbn;
		fin >> price;
		fin >> author;
		fin >> id_read;
		fin >> isBorrow_;
		Book book{ name,isbn,price,author,id_read };
		book.setIsBorrow(isBorrow_);
		if (name == name_)
		{
			v.push_back(book);
		}
	}
	if (v.size() == 0)
	{
		cout << "没有找到这本书\n";
	}
	else
	{
		cout << "一共" << v.size() << "本书\n";
		cout << "ID号"
			<< setw(20) << "图书名称"
			<< setw(20) << "ISBN号"
			<< setw(20) << "书籍价格"
			<< setw(20) << "书籍作者"
			<< setw(20) << "是否被借阅" << endl;

		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i].id
				<< setw(20) << v[i].name
				<< setw(20) << v[i].isbn
				<< setw(20) << v[i].price
				<< setw(20) << v[i].author;
			if (v[i].isBorrow == false)
			{
				cout << setw(20) << "可借\n";
			}
			else
			{
				cout << setw(20) << "借出\n";
			}
		}
	}
	cin.get();
	cin.get();
}


//设置图书信息
void setInfo()
{
	system("cls");
	int id_;
	cout << "请输入你要修改的书的id:";
	cin >> id_;
	cout << "请选择你要修改的信息：\n";
	cout << "1.修改书名\n";
	cout << "2.修改ISBN号\n";
	cout << "3.修改价格\n";
	cout << "4.修改作者\n";
	cout << "5.修改借阅状态\n";
	int choose;
	cin >> choose;

	ifstream fin("./book.txt");

	vector<Book> v;

	string name;
	string isbn;
	double price;
	string author;
	int id_read;
	bool isBorrow_;

	while (fin.eof() == false)
	{
		fin >> name;
		fin >> isbn;
		fin >> price;
		fin >> author;
		fin >> id_read;
		fin >> isBorrow_;
		Book book{ name,isbn,price,author,id_read };
		book.setIsBorrow(isBorrow_);
		if (id_read == id_)
		{
			cout << "请输入你要改变的内容:";
			switch (choose)
			{
				case 1:
					cin >> name;
					book.setName(name);
					break;
				case 2:
					cin >> isbn;
					book.setIsbn(isbn);
					break;
				case 3:
					cin >> price;
					book.setPrice(price);
					break;
				case 4:
					cin >> author;
					book.setAuthor(author);
					break;
				case 5:
					cout << "(输入0为可借，1为借出)";
					bool flag;
					cin >> flag;
					book.setIsBorrow(flag);
					break;
			}
		}
		v.push_back(book);
	}
	fin.close();

	ofstream fout("./book.txt", ios::out);
	for (int i = 0; i < v.size(); i++)
	{
		fout << " " << v[i].name << " "
			<< v[i].isbn << " "
			<< v[i].price << " "
			<< v[i].author << " "
			<< i + 1 << " "
			<< v[i].isBorrow;
	}
	fout.close();
}

void Exit()
{
	system("cls");
	cout << "欢迎再次使用本系统\n";
	exit(0);
}

int main()
{
	ifstream fin("./ID.txt", ios::in);
	fin >> id;
	fin.close();
	int choose;
	while (true)
	{
		login();
		cin >> choose;
		switch (choose)
		{
			case 0:
				Exit();
				break;
			case 1:
				showData();
				break;
			case 2:
				addBook();
				break;
			case 3:
				deleteBook();
				break;
			case 4:
				setInfo();
				break;
			case 5:
				findBook();
				break;
		}
	}
	return 0;
}
