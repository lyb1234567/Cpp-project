#                 Linked list Class

### Methods

- [len()](#len)
- [isempty()](#isempty)
- [str_list()](#str_list)
- [push_head()](#push_head)
- [push_tail()](#push_tail)
- [change_head()](#change_head)
- [remove](#remove)
- [reverse()](#reverse)
- [add_number()](#add_number)
- [minus_number()](#minus_number)
- [print_list()](#print_list)
- [merge()](#merge)
- [search()](#serach)
- [remove_duplix()](#remove_duplix)
- [count()](#count)
- [insert()](#insert)
- [extend()](#extend)



### len()

to check the length of the linked list

#### perducode implementation

```c++
int count;
Node *temp=head;
while(temp)
{
    coun=count+1;
    temp=next temp
}
return count;
```



### isempty()

check if the linked list is empty by using the length function

#### perducode implementation

```C++
return if len()==0
```



### str_list()

Take  a string data type and  push every element of it into the linked list

```C++
Node *temp=head;
while(temp)
{
    string s;
    push_tail(s);
}
```

The reason for using string s first: if the a string type is push into the linked list directly, it will be converted to the corresponding integer. Since there will another `push_tail()` function which will take a int type as an argument



### push_head()

Take a string, double and linked list as a data type and insert all of them at the head of a linked list

#### perducode implementation

```C++
create a new node;
let the created pointer's next element  to point to the origin head
the created new node become a new head
```



### push_tail()

Take a string, double and linked list as a data type and insert all of them at the tail of a linked list

#### perducode implementation

```C++
	First check if the linked list is empty them scan the whole linked list
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
```





### change_head()

Take a node data type as an argument,change the head node of the  linked list

#### perducode implementation

```C++
head= input node;
```



### reverse()

Reverse the whole list

#### perducode implementation

```C++
Using two pointers.
First let one of them point to next
link_next = link_next->next;

Then let  another one's next point to head node; 
then swap head;
```



### remove ()

it takes string or double as an argument, remove the input element and return a boolean type

#### perducode implementation

```C++
First check if the head is None,if so just return false
Then if it only has one head then compare it element to the input element if not the same still return false otherwise make the head equal to Null.

Otherwise create a previous node,scan the whole linked list,link the removed node's previous node and next node;
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
```



### add_number()

take a interger as an argument add them all to each element of the linked list



### minus_number()

take a interger as an argument substract them all to each element of the linked list



### print_list()

print the whole linked list in a [x,x,x,x] style

#### perducode implementation

```C++
 cout << "[";
    Node* temp = head;
    while (temp != NULL) 
    {
        if (temp->str == " " &&!(temp->link) && temp->next != NULL)
        {
            cout << temp->data << ",";
        }
        else if (temp->data == NULL && !(temp->link)&& temp->next!=NULL)
        {
            cout << temp->str << ",";
        }
        else if (temp->str == " " && !(temp->link)&& temp->next == NULL)
        {
             cout << temp->data;
        }
        else if (temp->data == NULL && !(temp->link) && temp->next == NULL)
        {
            cout << temp->str;
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
```



### merge()

take a linked list an argument. merge two linked list

#### perducode implementation

```C++
scan the first linked list then link the last node to the head node of the second linked list
```





### search()

search for the input element from the linked list,and return the index of the element

#### perducode implementation

```C++
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
```



### remove_duplix

remove the duplicate from the whole linked list

#### perducode implementation

```C++
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
```



### count()

count the number of each element in the whole linked list bascially implemented through hashmap

#### perducode implementation

```C++
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
```



### insert()

This function can take three different data types like double,string and linked list. Which require the an index entered then the second argument can be pushed into the linked list.

#### perducode implementation

```C++
check if index ==0:
  if so:
     call pushhead(argument)
  else:
      scan the whole linked list
       Node* temp = head;
       // create a new to push in
        Node* in = new Node();
        //insert the argument
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
```



### extend()

Basically it does the exactly the same thing as [merge()](#merge) function,just take a linked list an argument.

#### perducode implementation

```C++
void insert(const linked list &l)
merge(l)
```

