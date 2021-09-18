#include "game board.h"
#include"Number.h"
#include<iostream>
#include<Windows.h>
#include<ctime>
#include<conio.h>
#include"list.h"
static int i = 0;
void test()
{
	cout << i;
	i++;
}
void gotoxy(HANDLE hOut, int x, int y)
{
	COORD pos;
	CONSOLE_CURSOR_INFO CursorInfo;
	pos.X = x; //横坐标
	pos.Y = y; //纵坐标
	SetConsoleCursorPosition(hOut, pos);
}
void set_cursor(bool visible) {
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);


using namespace std;
int main()
{

	srand((unsigned int)time(NULL));
	Board board;
	board.initwall();
	//board.setnumber(3, 15, "3");
	//board.setnumber(3, 21, "2");
	//board.setnumber(3, 9, "4");
	//board.setnumber(3, 3, "4");
	board.drawall();
	Number number(board);
	int  i = 0;
	number.setNumber();
	Node* temp = &board.nodearray_horizontal[3][21];
	while (1) 
	{
		set_cursor(true);
		gotoxy(hOut, 0, 24);
		int c = _getch();
		if (c == 224)
		{
			char key = _getch();
			number.moveNumber(key);
			set_cursor(false);
			gotoxy(hOut, 0, 0);
			board.drawall();
		}
	}
	gotoxy(hOut, 0, 28);
	return 0;
}