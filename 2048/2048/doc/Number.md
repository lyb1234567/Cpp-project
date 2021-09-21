# Number

### Methods

[Number(Board&board)](#Number)

[setNumber()](#setNumber)

[moveNumber(char key)](#moveNumber)

[addNumber()](#addNumber)

[move_count()](#move_count)

[deleteNumber(int x,int y)](#deleteNumber)

[move_Right(int x,int y)](#move_Right)

[move_LEFT(int x,int y)](move_LEFT)

[move_UP(int x,int y)](#move_UP)

[move_DOWN(int x,int y)](#move_DOWN)

[game_over()](#game_over)

[check_2048()](#check_2048)

[get_score()](#get_score)



### Data member

- int move=0
- int score=0
- Board &board





#### Number()

Take the Board class data type,so the number class will get to use the all of the features of the board class

```C++
Number::Number(Board&bd):board(bd)
{
    
}
```



#### setNumber()

In order to set two numbers randomly at the beginning of the game, it has to check the board if it is full first then start to set the numbers. Also one thing to think about is that this method should make sure that  the two numbers are not setted at the same position. So it needs to check every position of the board. Since all of the numbers are all put into a  centre of a cell. So that will be **3,9,15,21** of each row and column. And also it can set a **2** and a **2** or **4** randomly. So first there will be an array of integers initialized which contains **3,9,15,21** for the game to pick. Then choose the first one to set on the board, and use the coordinate to check if the position of the cell has been chosen or not. Then use a while loop to choose another a position which has been chosen for another number.



Pick the number randomly

##### fraction code

```C++
    int number[4] = { 3,9,15,21 };
	int sample[2] = { 2,4 };
	int x1 = rand() % 4;
	int y1 = rand() % 4;
	int x2 = rand() % 4;
	int y2 = rand() % 4;
```

For the logic which can be used to check another position:

```C++
		while(1)
				{
					x2 = rand() % 4;
					y2 = rand() % 4;
					if (number[x2] == a && number[y2] == b)
					{
						continue;
					}
					else if (number[x2] != a || number[y2] != b)
					{
						break;
					}

				}
```



#### addNumber

This method is used to add a number randomly when the numbers is moved. So it needs to check the if the randomly chosen cell is empty, if so , it can put the number in the cell. If the chosen the cell is not empty then it should check the other cells of the board using a while loop which has the same logic as the **setNumber()**  has.

##### fraction code

```C++
while (1)
		{
			x1 = rand() % 4;
			y1 = rand() % 4;
			if (board.getnumber(number[x1], number[y1]) == " ")
			{
				board.setnumber(number[x1], number[y1], "2");
				gotoxy2(hOut2, number[y1] * 2, number[x1]);
				break;
				return;
			}
			else
			{
				continue;
			}
		}
```



#### deleteNumber

Take two integers as arguments which can be used to delete a number at a certain position. Just set the number at corrdinates **x,y** a empty string.



#### moveNumber

The basic logic of the 2048 game is that when a user press the UP key, it will check if there the is a number on the top of the column, if no, it will be moved to the top of the column. If there is  a number which is already on the top next to the current number, then check if the current number is  the same as the top number,if no , then the current number should not be moved otherwise it will be added to the top number.



So basically it will use a nested for loop which can be used to scan the whole board. Use the **getnumber()** method of the board class. So the **moveNumber** method will take a input key from the keyboard. Every time it finds a cell which is not empty, then it will check the input key  if the key is equal to **UP,DOWN,LEFT,RIGTH** which has already been initialized as enum public member.



##### fraction code

```C++
for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int x = number[i];
			int y = number[j];
			if (board.getnumber(x, y) != " ")
			{
				if (key == UP)
				{
					move_UP(x,y);
				}
				else if (key == DOWN)
				{
					move_DOWN(x, y);
				}
				else if (key == LEFT)
				{
					move_LEFT(x, y);
				}
				else if (key == RIGHT)
				{
					move_Right(x, y);
				}
			}
		}
	}
move++;
addNumber();
```

And every time it moves a number, it will call the addNumber() method.



### move_UP

So the core of this method is basically using the logic of  double linked list. So a temp node which can be used as  pointer which can point to the specific position node at a column. And if the cell next the node is empty, it will jus move that cell delete the current number. If no, then it will check if the top number if equal to the current Node. If they are not the same, then the while loop will just break otherwise it will just add them up.



#### fraction code

```C++
Node *temp = &board.nodearray_vertical[x][y];
	Node* cur;
	string str = temp->data;
	int n=0;
	while (temp->prev)
	{
	   temp = temp->prev;
	   cur = temp->next;
       if (temp->data == " ")
	   {
			deleteNumber(temp_x, y);
			temp_x = temp_x - 6;
			board.setnumber(temp_x, temp_y, str);
	   }
	   else if (temp->data != " ")
	   {
		   if (temp->data != cur->data)
		   {
			   break;
		   }
		   else
		   {
			   int a = stoi(temp->data);
			   int b = stoi(cur->data);
			   int c = a + b;
			   score = score + c;
			   string d = to_string(c);
			   temp_x = temp_x - 6;
			   board.setnumber(temp_x, temp_y, d);
			   deleteNumber(temp_x+6, y);
			   break;

		   }
	   }

	}
```



#### move_DOWN

This method takes two integers as arguments which will move a number down which has the same logic as the moving number method mentioned above.

#### fraction code

```C++
Node* temp = &board.nodearray_vertical[x][y];
	Node* cur;
	string str = temp->data;
	while (temp->next)
	{
		temp = temp->next;
		cur = temp->prev;
		if (temp->data == " ")
		{
			deleteNumber(temp_x, y);
			temp_x = temp_x+6;
			board.setnumber(temp_x, temp_y, str);
		}
		else if (temp->data != " ")
		{
			if (temp->data != cur->data)
			{
				break;
			}
			else if(temp->data == cur->data)
			{
				int a = stoi(temp->data);
				int b = stoi(cur->data);
				int c = a + b;
				score = score + c;
				string d = to_string(c);
				temp_x = temp_x+6;
				board.setnumber(temp_x, temp_y, d);
				deleteNumber(temp_x-6, y);
				break;
			}
		}
		 
	}
```



#### move_Right

Same logic but on the row wise.

```C++
Node* temp = &board.nodearray_horizontal[x][y];
	Node* cur;
	string str = temp->data;
	while (temp->next)
	{
		temp = temp->next;
		cur = temp->prev;
		if (temp->data == " ")
		{
			deleteNumber(x, temp_y);
			temp_y = temp_y + 6;
			board.setnumber(temp_x, temp_y, str);
		}
		else if (temp->data != " ")
		{
			if (temp->data != cur->data)
			{
				break;
			}
			else if (temp->data == cur->data)
			{
				int a = stoi(temp->data);
				int b = stoi(cur->data);
				int c = a + b;
				score = score + c;
				string d = to_string(c);
				temp_y = temp_y + 6;
				board.setnumber(temp_x, temp_y, d);
				deleteNumber(x, temp_y-6);
				break;
			}
		}
	}
```



#### move_LEFT

Same logic but on the row wise.

```C++
Node* temp = &board.nodearray_horizontal[x][y];
	Node* cur;
	string str = temp->data;
	while (temp->prev)
	{
		temp = temp->prev;
		cur = temp->next;
		if (temp->data == " ")
		{
			deleteNumber(x, temp_y);
			temp_y = temp_y - 6;
			board.setnumber(temp_x, temp_y, str);
		}
		else if (temp->data != " ")
		{
			if (temp->data != cur->data)
			{
				break;
			}
			else
			{
				int a = stoi(temp->data);
				int b = stoi(cur->data);
				int c = a + b;
				score = score + c;
				string d = to_string(c);
				temp_y = temp_y - 6;
				board.setnumber(temp_x, temp_y, d);
				deleteNumber(x, temp_y+6);
				break;
			}
		}

	}
```





#### check_2048

scan every cell of the whole board, if a cell at the certain position which has 2048, then return true otherwise return false after the nested for loop.

```C++
for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int x = number[i];
			int y = number[j];
			if (board.getnumber(x, y) == "2048")
			{
				return true;
			}
		}
	}
```



#### game_over

Three this to determine  if the game is over are 

1. check the gameboard if it has a 2048 cell

2. check the gameboard if it is already full

3. when the  gameboard has already been proved to be true, then it will scan the whole board if there is a cell where a number is the same as the current number around the current number. First check the first row and  the last row respectively using the double linked list

   horizontal list since for the corner of the board, the node only have either **prev **or **next** pointer. Then check the first and last column since the column list of it also either has a **prev** or **next** pointer. Then we can check the remaining double linked list no matter if it is a **horizontal** one or **vertical** one



#### fraction code

```C++
else if(board.check_full())
	{
	int number[4] = { 3,9,15,21 };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == 0)
			{
				if (j == 0)
				{
					int x = number[i];
					int y = number[j];
			        string str1_ver = board.nodearray_vertical[x][y].data;
				string str2_ver = board.nodearray_vertical[x][y].next->data;
				string str1_hor = board.nodearray_horizontal[x][y].data;
				string str2_hor = board.nodearray_horizontal[x][y].next->data;
				if ((str1_ver == str2_ver) || (str1_hor == str2_hor))
					{
						return false;
					}
					else
					{
						continue;
					}
					}
					else if (j == 3)
					{
						int x = number[i];
						int y = number[j];
				string str1_ver = board.nodearray_vertical[x][y].data;
				string str2_ver = board.nodearray_vertical[x][y].next->data;
				string str1_hor = board.nodearray_horizontal[x][y].data;
			string str2_hor = board.nodearray_horizontal[x][y].prev->data;
						if ((str1_ver == str2_ver) || (str1_hor == str2_hor))
						{
							return false;
						}
						else
						{
							continue;
						}
					}
					else
					{
						int x = number[i];
						int y = number[j];
						string str1_ver = board.nodearray_vertical[x][y].data;
						string str2_ver = board.nodearray_vertical[x][y].next->data;
						string str1_hor = board.nodearray_horizontal[x][y].data;
						string str2_hor = board.nodearray_horizontal[x][y].prev->data;
						string str3_hor = board.nodearray_horizontal[x][y].next->data;
						if ((str1_ver == str2_ver) || (str1_hor == str2_hor) || (str1_hor == str3_hor))
						{
							return false;
						}
						else
						{
							continue;
						}
					}
				}
				else if (i == 3)
				{
					if (j == 0)
					{
						int x = number[i];
						int y = number[j];

						string str1_ver = board.nodearray_vertical[x][y].data;
						string str2_ver = board.nodearray_vertical[x][y].prev->data;
						string str1_hor = board.nodearray_horizontal[x][y].data;
						string str2_hor = board.nodearray_horizontal[x][y].next->data;
						if ((str1_ver == str2_ver) || (str1_hor == str2_hor))
						{
							return false;
						}
						else
						{
							continue;
						}
					}
					else if (j == 3)
					{
						int x = number[i];
						int y = number[j];
						string str1_ver = board.nodearray_vertical[x][y].data;
						string str2_ver = board.nodearray_vertical[x][y].prev->data;
						string str1_hor = board.nodearray_horizontal[x][y].data;
						string str2_hor = board.nodearray_horizontal[x][y].prev->data;
						if ((str1_ver == str2_ver) || (str1_hor == str2_hor))
						{
							return false;
						}
						else
						{
							continue;
						}
					}
					else
					{
						int x = number[i];
						int y = number[j];
						string str1_ver = board.nodearray_vertical[x][y].data;
						string str2_ver = board.nodearray_vertical[x][y].prev->data;
						string str1_hor = board.nodearray_horizontal[x][y].data;
						string str2_hor = board.nodearray_horizontal[x][y].prev->data;
						string str3_hor = board.nodearray_horizontal[x][y].next->data;
						if ((str1_ver == str2_ver) || (str1_hor == str2_hor) || (str1_hor == str3_hor))
						{
							return false;
						}
						else
						{
							continue;
						}
					}
				}
				else
				{
					int x = number[i];
					int y = number[j];
					if (j == 1 || j == 2)
					{
						string str1_ver = board.nodearray_vertical[x][y].data;
						string str2_ver = board.nodearray_vertical[x][y].next->data;
						string str3_ver = board.nodearray_vertical[x][y].prev->data;
						string str1_hor = board.nodearray_horizontal[x][y].data;
						string str2_hor = board.nodearray_horizontal[x][y].prev->data;
						string str3_hor = board.nodearray_horizontal[x][y].next->data;
						if ((str1_ver == str2_ver) || (str1_ver == str3_ver) || (str1_hor == str2_hor) || (str1_hor == str3_hor))
						{
							return false;
						}
						else
						{
							continue;
						}
					}
					if (j == 0)
					{
						string str1_ver = board.nodearray_vertical[x][y].data;
						string str2_ver = board.nodearray_vertical[x][y].next->data;
						string str3_ver = board.nodearray_vertical[x][y].prev->data;
						string str1_hor = board.nodearray_horizontal[x][y].data;
						string str2_hor = board.nodearray_horizontal[x][y].next->data;;
						if ((str1_ver == str2_ver) || (str1_ver == str3_ver) || (str1_hor == str2_hor))
						{
							return false;
						}
						else
						{
							continue;
						}
					}
					if (j == 3)
					{
						string str1_ver = board.nodearray_vertical[x][y].data;
						string str2_ver = board.nodearray_vertical[x][y].next->data;
						string str3_ver = board.nodearray_vertical[x][y].prev->data;
						string str1_hor = board.nodearray_horizontal[x][y].data;
						string str2_hor = board.nodearray_horizontal[x][y].prev->data;;
						if ((str1_ver == str2_ver) || (str1_ver == str3_ver) || (str1_hor == str2_hor))
						{
							return false;
						}
						else
						{
							continue;
						}
					}
					
				}
			}
		}
```

