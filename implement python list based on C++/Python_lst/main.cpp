#include<iostream>
#include"Link_list.h"
#include<string>
#include"list.h"
#include <map>
#include <iostream>
#include <cassert>
int main()
{
	using namespace std;
	list a;
	a.append(3);
	a.append(1);
	a.append(6);
	a.append(2);
	a.append(6);
	cout << "Befor sorting:" << a << endl;
	a.sort();
	cout << "After sorting:" << a << endl;
	return 0;

}