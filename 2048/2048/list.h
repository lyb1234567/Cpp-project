#include<iostream>
#include<iostream>
class Node
{
public:
	double data;
	Node* next = NULL;
};
class list
{
private:
	Node* head = NULL;
public:
	void push_head(double new_data);
	void push_tail(double new_data);
	bool remove(double a);
	Node* get_head() { return head; };
	double find(int index);
	int len();
};
#pragma once
