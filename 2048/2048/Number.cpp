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
//设置随机的两个数字在游戏开始时候
void Number::setNumber()
{
	//为了保持数字在方格中间，使得数字坐标为3的奇数倍。
	int number[4] = { 3,9,15,21 };
	//棋盘出现的第二个数字随机从2或4中挑选
	int sample[2] = { 2,4 };
	int x1 = rand() % 4;
	int y1 = rand() % 4;
	int x2 = rand() % 4;
	int y2 = rand() % 4;
	while (true)
	{
		int x = rand() % 2;
		char n;
		string out;
		if (sample[x] == 2)
		{
			n = '2';
			out = "2";
		}
		if (sample[x] == 4)
		{
			n = '4';
			out = "4";
		}
		if (board.getnumber(number[x1], number[y1]) == ' ')
		{
			board.setnumber(number[x1], number[y1], '2');
			gotoxy2(hOut2,  number[y1]* 2, number[x1]);
			cout << "2";
			if (board.getnumber(number[x2], number[y2]) == ' ')
			{
				board.setnumber(number[x2], number[y2], n);
				gotoxy2(hOut2, number[y2] * 2, number[x2]);
				cout << out;
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
				board.setnumber(number[x2], number[y2], n);
				gotoxy2(hOut2, number[y2] * 2, number[x2]);
				cout << out;
			}
			break;
		}
		

	}
}

//在棋盘上随机添加数字2
void Number::addNumber()
{
	int number[4] = { 3,9,15,21 };
	int x1 = rand() % 4;
	int y1 = rand() % 4;
	if (board.getnumber(number[x1], number[y1]) == ' ')
	{
		board.setnumber(number[x1], number[y1], '2');
		gotoxy2(hOut2, number[y1] * 2, number[x1]);
		cout << '2';
	}
	else
	{
		while (1)
		{
			x1 = rand() % 4;
			y1 = rand() % 4;
			if (board.getnumber(number[x1], number[y1]) == ' ')
			{
				board.setnumber(number[x1], number[y1], '2');
				gotoxy2(hOut2, number[y1] * 2, number[x1]);
				cout << '2';
				break;
			}
			else
			{
				continue;
			}
		}
	}
	
}

//在棋盘上减少数字
bool Number::deleteNumber(int x,int y)
{
	if (board.getnumber(x, y) == ' ')
	{
		return false;
	}
	else
	{
		board.setnumber(x, y, ' ');
		gotoxy2(hOut2, y * 2, x);
		cout << " ";
		return true;
	}
}
/*
2048的基本逻辑就是，假如按键向上，有数字的一列中，先判断是否最顶端有数字，假如没有数字则跑到最顶端，假如有数字则判断两个数字是否一致，数字一致就叠加，数字不一致，则
该列中每一个数字都会根据列排开。其他方向一次类推
*/
void Number::moveNumber(char key)
{
	int number[4] = { 3,9,15,21 };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int x = number[i];
			int y = number[j];
			if (board.getnumber(x, y) != ' ')
			{
				if (key == UP)
				{
					for (int k = 0; k < 4; k++)
					{
						if (board.getnumber(number[k], y) != ' ' && number[k] != x && board.getnumber(x, y) == board.getnumber(number[k], y))
						{

						}
					}
				}
			}
		}
	}
	addNumber();
	gotoxy2(hOut2, 0, 0);
	board.drawall();


}