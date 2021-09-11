#ifndef NUMBER_H_
#define NUMBER_H_
#include"game board.h"
#include<iostream>
using namespace std;

class Number
{
public:
	Number(Board& board);
	void setNumber();
	int FoodX;
	int FoodY;

	Board& board;
};
#endif // !NUMBER_H_

#pragma once
