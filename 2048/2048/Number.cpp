#include"Number.h"
#include"game board.h"
#include<Windows.h>
#include"list.h"
void gotoxy2(HANDLE hOut2, int x, int y)
{
	COORD pos;
	pos.X = x; //横坐标
	pos.Y = y; //纵坐标
	SetConsoleCursorPosition(hOut2, pos);
}
HANDLE hOut2 = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量
Number::Number(Board& bd) :board(bd)
{

}
void Number::setNumber()
{
	int number[4] = { 3,9,15,21 };
	list a;
	list b;
	for (int i = 0; i < 4; i++)
	{
		a.push_tail(number[i]);
		b.push_tail(number[i]);
	}
	int x1 = rand() % 4;
	int y1 = rand() % 4;
	int x2 = rand() % 4;
	int y2 = rand() % 4;
	while (true)
	{
		
		if (board.getnumber(number[x1], number[y1]) == ' ')
		{
			board.setnumber(number[x1], number[y1], 2);
			gotoxy2(hOut2,  number[y1]* 2, number[x1]);
			cout << "2";
			if (board.getnumber(number[x2], number[y2]) == ' ')
			{
				board.setnumber(number[x2], number[y2], 4);
				gotoxy2(hOut2, number[y2] * 2, number[x2]);
				cout << "4";
			}
			else 
			{
				int a = number[x2];
				int b = number[y2];
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
				board.setnumber(number[x2], number[y2], 4);
				gotoxy2(hOut2, number[y2] * 2, number[x2]);
				cout << "4";
			}
			break;
		}
		

	}
}