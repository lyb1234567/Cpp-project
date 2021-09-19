#ifndef NUMBER_H_
#define NUMBER_H_
#include"game board.h"
#include<iostream>
using namespace std;

class Number
{
public:
	enum
	{
		UP = 'H',
		DOWN = 'P',
		LEFT = 'K',
		RIGHT = 'M'
	};
	Number(Board& board);
	void setNumber();
	void moveNumber(char key);
	void addNumber();
	int move_count() { return move; };
	bool deleteNumber(int x,int y);
	bool move_Right(int x,int y);
	bool move_LEFT(int x,int y);
	bool move_UP(int x,int y);
	bool move_DOWN(int x,int y);
	bool game_over();
	int get_score() { return score; };
	int move = 0;
	int score = 0;
	Board& board;
};
#endif // !NUMBER_H_

#pragma once
