#include"Link_list.h"
#include"list.h"
#include<iostream>
#include<string>
#include<map>

using namespace std;

Link_list::Link_list()
{
    head = NULL;
}
Link_list::Link_list(const Link_list& lst)
{
    *this = lst;
}
int  Link_list::fun(int n)
{
	return n;
}
int Link_list::len()
{
    int i = 0;
    Node* temp = head;
    while (temp!=NULL)
    {
        i = i + 1;
        temp = temp->next;
    }
    return i;
}
void Link_list::print_list()const  {
    cout << "[";
    Node* temp = head;
    while (temp != NULL) 
    {
        if (temp->str == " " &&!(temp->link) && temp->next != NULL)
        {
            cout << temp->data<<",";
        }
        else if (temp->data == NULL && !(temp->link)&& temp->next!=NULL)
        {
            cout << "'" << temp->str << "'" << ",";
        }
        else if (temp->str == " " && !(temp->link)&& temp->next == NULL)
        {
            cout << temp->data;
        }
        else if (temp->data == NULL && !(temp->link) && temp->next == NULL)
        {
            cout <<"'"<<temp->str<<"'";
        }
        if (temp->data==NULL && temp->str==" " && temp->link && temp->next != NULL)
        {
            temp->link->print_list();
            cout << ",";
        }
        else if (temp->data == NULL && temp->str == " " && temp->link && temp->next == NULL)
        {
            temp->link->print_list();
        }
        temp = temp->next;
    }
    cout << "]";
}
void Link_list::push_head(double new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = head;
    head= new_node;
}
void Link_list::push_head( string new_str)
{
    Node* new_node = new Node();
    new_node->str = new_str;
    new_node->next = head;
    head = new_node;
}
void Link_list::push_head(const Link_list& lst)
{
    if (head == NULL)
    {
        head = new Node();
        head->link = new Link_list(lst);        
    }
    else
    {
        Node* ptr = new Node();
        ptr->link = new Link_list(lst);
        ptr->next = head;
        head = ptr;
    }
}
void Link_list::push_tail( double new_data)
{
    Node* temp = new Node();
    temp->data = new_data;
    temp->next = NULL;
    if (head == NULL)
    {
        push_head(new_data);
    }
    else
    {
        Node* p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}
void Link_list::push_tail( string new_str)
{
    Node* temp = new Node();
    temp->str = new_str;
    temp->next = NULL;
    if (head == NULL)
    {
        push_head( new_str);
    }
    else
    {
        Node* p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}
void Link_list::push_tail(const Link_list& lst)
{
    Node* temp = new Node();
    temp->link = new Link_list(lst);
    temp->next = NULL;
    if (head == NULL)
    {
        push_head(lst);
    }
    else
    {
        Node* p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}
void Link_list::add_number(double n)
{
    Node* temp = head;
    while (temp != NULL)
    {
        temp->data = temp->data +n;
        temp = temp->next;
    }
}
void Link_list::minus_number(double n)
{
    Node* temp = head;
    while (temp != NULL)
    {
        temp->data = temp->data - n;
        temp = temp->next;
    }
}
void Link_list::merge(const Link_list& lst)
{
    Node* temp = head;
    if (lst.head != NULL)
    {
        while (temp->next!= NULL)
        {
            temp = temp->next;
        }
        temp->next = lst.head;
    }
}
void Link_list::str_list(string str)
{
    string s;
    for (int i = 0; i < str.length(); i++)
    {
        s = str[i];
        push_tail(s);
    }
}
void Link_list::reverse()
{
    Node* current = head;
    Node* link_next = head;
    head = NULL;
    while (current)
    {
        link_next = link_next->next;
        current->next = head;
        head = current;
        current = link_next;
    }

}
bool Link_list::remove(double a)
{
    if (len() == 0)
    {
        return false;
    }
    else
    {
        Node* temp = head;
        if (len() == 1 && temp->data==a)
        {
            head= NULL;
            return true;
        }
        else if (len() == 1 && head->data != a)
        { 
            return false;
        }
        else
        {
            Node* prev = temp;
            if (temp->data == a)
            {
                head= temp->next;
                temp->next = NULL;
            }
            else
            {
                while (temp != NULL)
                {
                    if (temp->data == a)
                    {
                        prev->next = temp->next;
                        temp->next = NULL;
                        return true;
                    }
                    prev = temp;
                    temp = temp->next;
                }
                return false;
            }
        }
        

    }
}
bool Link_list::remove(string str)
{
    if (len() == 0)
    {
        return false;
    }
    else
    {
        Node* temp = head;
        if (len() == 1 && head->str == str)
        {
            head->next = NULL;
            return true;
        }
        else if (len() == 1 && head->str != str)
        {
            return false;
        }
        else
        {
            Node* prev = temp;
            if (temp->str == str)
            {
                head = temp->next;
                temp->next = NULL;
            }
            else
            {
                while (temp != NULL)
                {
                    if (temp->str == str)
                    {
                        prev->next = temp->next;
                        temp->next = NULL;
                        return true;
                    }
                    prev = temp;
                    temp = temp->next;
                }
                return false;
            }
        }


    }
}
bool Link_list::isempty()
{
    return (len() == 0);
}
int Link_list::search(double n)
{
    int count = 0;
    if (isempty())
    {
        throw std::invalid_argument("It is empty!!!!");
    }
    else
    {
        Node* temp = head;
        while (temp)
        {
            if (temp->data == n)
            {
                return count;
            }
            count = count + 1;
            temp = temp->next;
        }
        return -1;
    }
}
int Link_list::search(string str)
{
    int count = 0;
    if (isempty())
    {
        throw std::invalid_argument("It is empty!!!!");
    }
    else
    {
        Node* temp = head;
        while (temp)
        {
            if (temp->str == str)
            {
                return count;
            }
            count = count + 1;
            temp = temp->next;
        }
        return -1;
    }
}
void Link_list::remove_duplix()
{
    if (isempty())
    {
        return;
    }
    if (head->next == NULL)
    {
        return;
    }
    else
    {
        Node* outer = head;
        while (outer)
        {
            Node* inner = outer;
            while (inner)
            {
                if (inner->next != NULL)
                {
                    if (inner->next->data == outer->data)
                    {
                        inner->next = inner->next->next;
                    }
                    else
                    {
                        inner = inner->next;
                    }
                }
                else
                {
                    inner = inner->next;
                }
            }
            outer = outer->next;
        }
    }
}
void Link_list::insert(int index, double num)
{
    if (index == 0)
    {
        push_head(num);
    }
    else 
    {
        Node* temp = head;
        Node* in = new Node();
        in->data = num;
        int count = 0;
        while (temp)
        {
            count = count + 1;
            if (count == index)
            {
                in->next = temp->next;
                temp->next = in;
            }
            temp = temp->next;
        }
    }
}
void Link_list::insert(int index, string str)
{
    if (index == 0)
    {
        push_head(str);
    }
    else
    {
        Node* temp = head;
        Node* in = new Node();
        in->str = str;
        int count = 0;
        while (temp)
        {
            count = count + 1;
            if (count == index)
            {
                in->next = temp->next;
                temp->next = in;
            }
            temp = temp->next;
        }
    }
}
void Link_list::insert(int index, const Link_list& l)
{
    if (index == 0)
    {
        push_head(l);
    }
    else
    {
        Node* temp = head;
        Node* in = new Node();
        in->link = new Link_list(l);
        int count = 0;
        while (temp)
        {
            count = count + 1;
            if (count == index)
            {
                in->next = temp->next;
                temp->next = in;
            }
            temp = temp->next;
        }
    }
}
void Link_list::extend(const Link_list& l)
{
    merge(l);
}
int Link_list::find_nth(int n)
{
    if (len() == 0)
    {
        return -1;
    }
    else
    {

        int l = len() - 1;
        Node* current = head;
        int position = n - 1;
        if (position < 0 || position > l)
        {
            return -1;
        }
        int count = 0;
        while (count != position)
        {
            current = current->next;
            count = count + 1;
        }
        if (current != NULL)
        {
            if (current->data == NULL)
            {
                return 0;
            }
            if (current->data != NULL)
            {
                return current->data;
            }
        }
        else
        {
            return -1;
        }
    }
}
int Link_list::count(double n)
{
    map<int, int> b;
    Link_list l2 = *this;
    Node* temp = head;
    while (temp)
    {
        b[temp->data] = 0;
        temp = temp->next;
    }
    Node* current = l2.head;
    while (current)
    {
        if (b.find(current->data) != b.end())
        {
            b[current->data] = b[current->data] + 1;
        }
        current = current->next;
    }
    return b[n];
    
}
int Link_list::count(string str)
{
    map<string, int> b;
    Link_list l2 = *this;
    Node* temp = head;
    while (temp)
    {
        b[temp->str] = 0;
        temp = temp->next;
    }
    Node* current = l2.head;
    while (current)
    {
        if (b.find(current->str) != b.end())
        {
            b[current->str] = b[current->str] + 1;
        }
        current = current->next;
    }
    return b[str];

}
