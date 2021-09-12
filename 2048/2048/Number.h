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
	bool deleteNumber(int x,int y);
	int FoodX;
	int FoodY;

	Board& board;
};
#endif // !NUMBER_H_

#pragma once
