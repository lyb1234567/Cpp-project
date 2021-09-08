#include"Link_list.h"
#include"list.h"
#include<iostream>
#include<string>
#include<cctype>
#include <map>
#include <cassert>
using namespace std;
list::list(const list& l)
{
	str = l.str;
	lst = l.lst;
}
void list:: append(double n)
{
	lst.push_tail(n);
}
void list::append(string s1)
{
	lst.push_tail(s1);
}
void list::append(const list& a)
{
	lst.push_tail(a.lst);
}
void list::remove(double n)
{
	lst.remove(n);
}
void list::remove(string s1)
{
	lst.remove(s1);
}
void list::sort()
{
	Node* current = lst.get_head();
	Node* index;
	double temp;
	if (len() == 0)
	{
		throw "The list is empty!!";
	}
	else
	{
		while (current)
		{
			index = current->next;
			while (index)
			{
				if (current->data > index->data)
				{
					temp = current->data;
					current->data = index->data;
					index->data = temp;
				}
				index = index->next;
			}
			current = current->next;
		}
	}
}
double list::max()
{
	double max;
	Node* current = lst.get_head();
	if (len() == 0)
	{
		return -1;
	}
	else
	{
		max = current->data;
	}
	while (current)
	{
		if (max<=current->data)
		{
			max = current->data;
		}
		if (current->data == NULL)
		{
			throw "'<' not supported between instances of 'str' and 'int'";
		}
		current = current->next;
	}
	return max;
}
double list::min()
{
	double min;
	Node* current = lst.get_head();
	if (len() == 0)
	{
		return -1;
	}
	else
	{
		min = current->data;
	}
	while (current)
	{
		if (min >= current->data)
		{
			min = current->data;
		}
		if (current->data == NULL)
		{
			throw "'<' not supported between instances of 'str' and 'int'";
		}
		current = current->next;
	}
	return min;
}
int list::index(double n)
{
	int a=lst.search(n);
	return a;
}
int list::index(string str)
{
	int a = lst.search(str);
	return a;
}
double list::pop()
{
	int n = len() - 1;
	double a = lst.find_nth(n + 1);
	lst.remove(a);
	return a;
}
int list::count(int n)
{
	return lst.count(n);
}
int list::count(string n)
{
	return lst.count(n);
}
void list::insert(int index, double num)
{
	lst.insert(index, num);
}
void list::insert(int index, string str)
{
	lst.insert(index, str);
}
void list::insert(int index, const list & l)
{
	lst.insert(index, l.lst);
}
void list::extend(const list& l)
{
	lst.extend(l.lst);
}
void list::clear()
{
	int a = len();
	Node* temp = lst.get_head();
	while (temp)
	{
		temp = temp->next;
		lst.change_head(temp);
	}

}
list::list()
{
	
}
list::list( string str)
{
	lst.str_list(str);
}
list list::operator+(double n) 
{
	lst.add_number(n);
	return *this;
}
list list::operator-(double n)
{
	lst.minus_number(n);
	return *this;
}
list operator +(double n, list& lst1)
{
	return lst1 + n;
}
list operator-(double n,  list& lst1)
{
	return lst1-n;
}
list list ::operator +(const list& l) 
{
	lst.merge(l.lst);
	return *this;
}
ostream& operator <<(ostream& os,  const list& lst1)
{
	lst1.lst.print_list();
	return os;
 }
ostream& operator <<(ostream& os, list [])
{
	cout << "sb";
	return os;
}
//list operator+( list& l1, list &l2) 
//{
//	l1.lst.merge(l2.lst);
//	return l1;
//}
string list::operator ==(list& l)
{
	Node* temp1 = this->lst.get_head();
	Node* temp2 = l.lst.get_head();
	if (this->lst.len() != l.lst.len())
	{
		return "False";
	}
	while (temp1 && temp2)
	{
		if (temp1->data != temp2->data)
		{
			return "False";
		}
	    if (temp1->str != temp2->str)
		{
			return "False";
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return "True";
}
string list::operator !=(list& l)
{
	Node* temp1 = this->lst.get_head();
	Node* temp2 = l.lst.get_head();
	if (this->lst.len() != l.lst.len())
	{
		return "True";
	}
	while (temp1 && temp2)
	{
		if (temp1->data != temp2->data)
		{
			return "True";
		}
		if (temp1->str != temp2->str)
		{
			return "True";
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return "False";
}
list& list::operator=(const list& l)
{
	this->lst = l.lst;
	return *this;
}
list list::copy()
{
	return *this;
}
list list::operator[](const char * str)
{
	Link_list link;
	int slice= stoi(str);
	int count = 0;
	Node* current = lst.get_head();
	while (current)
	{
		if (count == slice)
		{
			lst.change_head(current);
			return *this;
		}
		count = count + 1;
		current = current->next;
	}
	Node* n = NULL;
	lst.change_head(n);
	return *this;
}
