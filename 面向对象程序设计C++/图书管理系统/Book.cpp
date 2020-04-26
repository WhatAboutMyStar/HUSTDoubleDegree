#include"Book.h"
#include<iostream>
#include<string>
#include<filesystem>
#include<fstream>
#include<ostream>
using namespace std;
Book::Book(string name_, string isbn_, double price_, string author_, int id_) :
	name{ name_ }, isbn{ isbn_ }, price{ price_ }, author{ author_ }, id{ id_ }, isBorrow{ false }
{

}

string Book::getAuthor()
{
	return author;
}

void Book::setAuthor(string author_)
{
	author = author_;
}

string Book::getName()
{
	return name;
}

void Book::setName(string name_)
{
	name = name_;
}

void Book::setIsbn(string isbn_)
{
	isbn = isbn_;
}
string Book::getIsbn()
{
	return isbn;
}

void Book::setPrice(double price_)
{
	price = price_;
}

double Book::getPrice()
{
	return price;
}

void Book::setId(int id_)
{
	id = id_;
}

int Book::getId()
{
	return id;
}

void Book::setIsBorrow(bool flag)
{
	isBorrow = flag;
}

bool Book::getIsBorrow()
{
	return isBorrow;
}

void Book::writeData()
{
	ofstream fout("./book.txt", ios::app);
	fout << " " << name << " " << isbn << " " << price << " " << author << " " << id << " " << isBorrow;
	fout.close();
}


Book::~Book()
{

}