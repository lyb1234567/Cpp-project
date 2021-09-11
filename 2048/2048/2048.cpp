#include "game board.h"
#include"Number.h"
#include<iostream>
#include<Windows.h>
#include<ctime>
#include<conio.h>
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
	srand((unsigned int)time(NULL));
	Board board;
	board.initwall();
	board.drawall();
	Number number(board);
	number.setNumber();
	gotoxy(hOut, 0, 27);
	return 0;
}