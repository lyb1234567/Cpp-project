#include "game board.h"
#include"Number.h"
#include<iostream>
#include<Windows.h>
#include<ctime>
#include<conio.h>
#include<fstream>
#include<vector>
#include"list.h"
#include<iostream>
#include<string>
#include"Menu.h"
void gotoxy3(HANDLE hOut2, int x, int y)
{
	COORD pos;
	pos.X = x; //横坐标
	pos.Y = y; //纵坐标
	SetConsoleCursorPosition(hOut2, pos);
}
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量
void show_score()
{
	ifstream inFile;
	string filename = "score.txt";
	inFile.open(filename);
	int Best;
	vector<int> score_array;
	while (inFile.good())
	{
		inFile >> Best;
		score_array.push_back(Best);
	}
	for (int i = 0; i < score_array.size(); i++)
	{
		cout << score_array[i] << endl;
	}
}
int max_val(vector <int>& array)
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
void game()
{
	ofstream outFile;
	ifstream inFile;
	string filename = "score.txt";
	outFile.open(filename, std::ios_base::app);
	inFile.open(filename);
	int timer = 0;
	int Best = 0;
	int new_Best = 0;
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
	Number number(board);
	int  i = 0;
	number.setNumber();
	board.drawall();
	bool game_over = number.game_over();
	while (!game_over)
	{
		set_cursor(true);
		gotoxy3(hOut, 0, 24);
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
			gotoxy3(hOut, 0, 27);
			if (number.get_score() < Best)
			{
				cout << "Best:" << Best;
			}
			else
			{
				cout << "Best:" << number.get_score();
			}
			gotoxy3(hOut, 0, 0);
			board.drawall();
		}
		game_over = number.game_over();
	}
	gotoxy3(hOut, 0, 27);
	cout << "game over";
	int score = number.get_score();
	outFile << score << endl;
	outFile.close();

}
string Menu::AsciiArt2048()
{
	constexpr auto title_card_2048 = R"(
   /\\\\\\\\\          /\\\\\\\                /\\\         /\\\\\\\\\
  /\\\///////\\\      /\\\/////\\\            /\\\\\       /\\\///////\\\
  \///      \//\\\    /\\\    \//\\\         /\\\/\\\      \/\\\     \/\\\
             /\\\/    \/\\\     \/\\\       /\\\/\/\\\      \///\\\\\\\\\/
           /\\\//      \/\\\     \/\\\     /\\\/  \/\\\       /\\\///////\\\
         /\\\//         \/\\\     \/\\\   /\\\\\\\\\\\\\\\\   /\\\      \//\\\
        /\\\/            \//\\\    /\\\   \///////////\\\//   \//\\\      /\\\
        /\\\\\\\\\\\\\\\   \///\\\\\\\/              \/\\\      \///\\\\\\\\\/
        \///////////////      \///////                \///         \/////////
  )";
	return title_card_2048;
}
Menu::Menu()
{ 

}
void Menu::start()
{
	string title = AsciiArt2048();
	cout << title;

		gotoxy3(hOut, 15, 15);
		cout << "1:Start the game";
		gotoxy3(hOut, 15, 16);
		cout << "2:Show the score ranking";
		gotoxy3(hOut, 15, 17);
		cout << "Enter your choice:";
		char choice;
			cin >> choice;
			switch (choice)
			{
			case '1':
				gotoxy3(hOut, 0, 0);
				game();
				break;
			case '2':
				show_score();
				break;
			}


}