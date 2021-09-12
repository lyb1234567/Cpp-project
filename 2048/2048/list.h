#include<string>
#include<iostream>
using namespace std;
class Node
{
public:
	char data;
	Node* next = NULL;
	Node* prev= NULL;
};
class list
{
private:
	Node* head = NULL;
	Node* tail = NULL;
public:
	Node* get_end();
	void push_head(char new_data);
	void push_tail(char new_data);
	void display_head();
	void display_end();
	bool remove(char a);
	Node* get_head() { return head; };
	double find(int index);
	int len();
};
#pragma once
