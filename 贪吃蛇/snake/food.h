#ifndef FOOD_H_
#define FOOD_H_
#include<iostream>
using namespace std;
#include"wall.h"
class Food
{
public:

	Food(Wall& tempwall);
	void setFood();
	int FoodX;
	int FoodY;

	Wall& wall;
};
#endif
#pragma once
