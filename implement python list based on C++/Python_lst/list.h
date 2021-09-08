#ifndef LIST_H_
#define LIST_H_
#include<iostream>
#include<string>
#include"Link_list.h"
using namespace std;
class list 
{
private:
	Link_list lst;
	string str;
	int len_list;
public:
	list();
	list( string str);
	list(const list& l);
	int len() { return lst.len(); }
	void append(double n);
	void append( string s);
	void append(const list& a);
	void  remove(double n);
	void  remove(string s);
	int index(double n);
	int index(string str);
	double max();
	double min();
	void sort();
	void insert(int index, double num);
	void insert(int index, string str);
	void insert(int index, const list& a);
	void extend(const list& a);
	bool isempty() { return lst.isempty();}
	list operator +(double n);
	list operator +(const list& l);
	list operator -(double n);
	friend ostream& operator <<(ostream& os, const list& lst);
	friend list operator +(double n,  list& lst1);
    friend list operator -(double n,  list& lst1);
	int operator[](int index)
	{
	 return lst.find_nth(index + 1);
	}
	list operator[](const char *str);
	double pop();
	list copy();
	int count(int n);
	int count(string n);
	void clear();
	list& operator =(const list& l);
	string operator ==( list& l);
	string operator !=(list& l);
};

#endif // !LIST_H_
#pragma once
