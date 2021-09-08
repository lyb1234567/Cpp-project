#ifndef LINK_H_
#define LINK_H_
#include<iostream>
#include<string>
using namespace std;
class Link_list;
class Node {
public:
    double data = NULL;
    string str = " ";
    Node* next = NULL;
    Link_list* link;
};
class Link_list {
    
private:
    Node* head = NULL;

public:
    Link_list();
    Link_list(const Link_list& lst);
    int fun(int n);
    int len();
    bool isempty();
    void str_list(string str);
    void push_head(double new_data);
    void push_head(string new_str);
    void push_head(const Link_list& lst);
    void push_tail( double new_data);
    void push_tail(string new_str);
    void push_tail(const Link_list& lst);
    void change_head(Node* n) { head = n; };   
    Node* get_head() { return head; };
    void reverse();
    void insert(int index, double num);
    void insert(int index, string str);
    void insert(int index, const Link_list& l);
    void extend(const Link_list& l);
    bool remove(double a);
    bool remove( string str);
    void add_number(double n);
    void minus_number(double n);
    void print_list() const;
    void merge( const Link_list& lst);
    int find_nth(int n);
    int search(double n);
    int search(string str);
    void remove_duplix();
    int count(double n);
    int count(string str);


};
#endif // !LINK_H_H

#pragma once
