#include"game board.h"
#include"list.h"
#include<iostream>
#include<string>
using namespace std;
void Board::initwall()
{
	int p = ROW / 4;
	int number[4] = { 3,9,15,21 };
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			//放墙壁的地方
			if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1||(i%p)==0||(j%p)==0)
			{
				gameborad[i][j] = '*';
			}
			else
			{
				gameborad[i][j]= " ";
				nodearray_horizontal[i][j].data = "*";
				nodearray_vertical[i][j].data = "*";
				if (((i / 3) % 2 == 1) &&( (j / 3) % 2) == 1)
				{
					//存放一个字符为空的结点
					nodearray_horizontal[i][j].data = " ";
					nodearray_vertical[i][j].data = " ";
				}
			}
		}
	}
	int x;
	int y;
	int a;
	int b;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			x = number[i];
			y = number[j+1];

			//横向
			nodearray_horizontal[number[i]][number[j]].next = &nodearray_horizontal[x][y];
			nodearray_horizontal[x][y].prev = &nodearray_horizontal[number[i]][number[j]];
			//纵向
			nodearray_vertical[number[j]][number[i]].next = &nodearray_vertical[y][x];
			nodearray_vertical[y][x].prev = &nodearray_vertical[number[j]][number[i]];
		}

	}
	
}
void Board::drawall()
{
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			//画的时候多加一个空格，看起来好看一些
			cout << gameborad[i][j]<< " ";
		}
		if (i == 3)
		{
			cout << "Game:2048";
		}
		if (i == 4)
		{
			cout << "Version: 1.0";
		}
		if (i == 5)
		{
			cout << "Maker: Mirage";
		}
		if (i == 6)
		{
			cout << "a:left";
		}
		if (i == 7)
		{
			cout << "d:right";
		}
		if (i == 8)
		{
			cout << "w:up";
		}
		if (i == 9)
		{
			cout << "s:down";
		}
		cout << endl;
	}
}
void Board::setnumber(int x, int y, string n)
{

	gameborad[x][y] = n;
	nodearray_horizontal[x][y].data = n;
	nodearray_vertical[x][y].data = n;
}

string Board::getnumber(int x, int y)
{
	return gameborad[x][y];
}
bool Board::check_full()
{
	int count = 0;
	int number[4] = { 3,9,15,21 };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (gameborad[number[i]][number[j]] != " ")
			{
				count = count + 1;
			}
		}
	}
	if (count == 16)
	{
		return true;
	}
	else
	{
		return false;
	}
}