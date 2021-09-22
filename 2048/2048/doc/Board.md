# Board

### Introduction

This class was used to initialize the whole wall and set numbers every time a number was moved through the **Number** class.

### Method

[initwall()](#initwall)

[drawwall()](#drawwall)

[setnumber()](#setnumber)

[getnumber()](#getnumber)

[check_full()](#check_full())

 



#### initwall

This method was used to initialize the wall as shown from its name. Since this game was run on the 4x4 game board. So it will have use a nested loop to scan the whole board. And since the **ROW** is 24 and **COLUMN** is 25, so there is also a logic which can check if i or j is the multiples of 6. 

So, in the first place, the horizontal and vertical linked list will be set to empty,  so was the gameboard array.



Then there will be a second nested loop for node linking. So in each column, the vertical node will be linked to each other, and in each row, the horizontal node will be linked to each other.

```C++
for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int x = number[i];
			int y = number[j];
			if (i == 0)
			{
				nodearray_vertical[x][y].next = &nodearray_vertical[x + 6][y];
				nodearray_vertical[x][y].prev = NULL;
			}
			else if (i == 3)
			{
				nodearray_vertical[x][y].next = NULL;
				nodearray_vertical[x][y].prev= &nodearray_vertical[x-6][y];
			}
			else
			{
				nodearray_vertical[x][y].next = &nodearray_vertical[x + 6][y];
				nodearray_vertical[x][y].prev = &nodearray_vertical[x - 6][y];
			}
		}
	}
```





#### drawwall

This method was used to draw wall and number for certain cells. And to distinguish different numbers, they are all colored through a special function 

```C++
SetConsoleTextAttribute(hConsole, number)
```

where hConsole is the console handle argument. And in order not to  break the 

 the wall it set the width for each string

```
setw(3)
```



####  setnumber

This method was  used to store a  string number in a certain position



#### getnumber

This method is used to return a string number at a certain position



#### check_full

This method was used to check the game board is already full. There will be a nested loop for checking it, since there are 16 cells in total there will be a counter for each iteration.