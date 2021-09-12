#include "game board.h"
#include"Number.h"
#include<iostream>
#include<Windows.h>
#include<ctime>
#include<conio.h>
#include"list.h"
void gotoxy(HANDLE hOut, int x, int y)
{
	COORD pos;
	pos.X = x; //横坐标
	pos.Y = y; //纵坐标
	SetConsoleCursorPosition(hOut, pos);
}
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;
int main()
{
	/*srand((unsigned int)time(NULL));
	Board board;
	board.initwall();
	board.drawall();
	Number number(board);
	number.setNumber();
	while (1)
	{
		gotoxy(hOut, 0, 24);
		char key = _getch();
		number.moveNumber(key);
	}
	gotoxy(hOut, 0, 27);*/
	list a;
	a.push_head('3');
	a.push_tail('4');
	a.push_tail('5');
	a.display_end();
	return 0;
}