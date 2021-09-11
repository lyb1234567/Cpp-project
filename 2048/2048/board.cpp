#include"game board.h"
#include<iostream>
#include<string>
using namespace std;
void Board::initwall()
{
	int p = ROW / 4;
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
				gameborad[i][j]= ' ';
			}
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
			cout << gameborad[i][j] << " ";
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
void Board::setnumber(int x, int y, char n)
{
	gameborad[x][y] = n;
}

int Board::getnumber(int x, int y)
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
			if (gameborad[number[i]][number[j]] != ' ')
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