#include "game board.h"
#include"Number.h"
#include<iostream>
#include<Windows.h>
#include<ctime>
#include<conio.h>
#include<fstream>
#include<vector>
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
int max_val(vector <int> array)
{
	int max = array[0];
	for (auto i = array.begin(); i != array.end(); ++i)
	{
		if (max <= *i)
		{
			max = *i;
		}
	}
	return max;
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
	ofstream outFile;
	ifstream inFile;
	string filename = "score.txt";
	outFile.open(filename, std::ios_base::app);
	inFile.open(filename);
	int Best = 0;
	vector<int> score_array;
	while (inFile.good())
	{
		inFile >> Best;
		score_array.push_back(Best);
	}

	Best = max_val(score_array);
	srand((unsigned int)time(NULL));
	Board board;
	board.initwall();
	board.drawall();
	Number number(board);
	int  i = 0;
	number.setNumber();
	bool game_over = number.game_over();
	while (!game_over)
	{
		set_cursor(true);
		gotoxy(hOut, 0, 24);
		int c = _getch();
		if (c == 113)
		{
			break;
		}
		if (c == 224)
		{
			char key = _getch();
			number.moveNumber(key);
			set_cursor(false);
			gotoxy(hOut, 50, 26);
			cout << "Best:" << Best;
			gotoxy(hOut, 0, 0);
			board.drawall();
		}
		game_over= number.game_over();
	}
	gotoxy(hOut, 0, 27);
	cout << "game over";
	int score = number.get_score();
	outFile << score << endl;
	outFile.close();
	return 0;
}