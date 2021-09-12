#ifndef BOARD_H_
#define BOARD_H_
#include"list.h"
class Board
{
public:
	enum
	{
		ROW = 24, //行数
		COL = 25//列数
	};
	list a;
	void initwall();
	void drawall();
	void setnumber(int x, int y, char n);
	int getnumber(int x,int y);
	bool check_full();
private:
	Node nodearray_horizontal[ROW][COL];
	Node nodearray_vertical[ROW][COL];
	char gameborad[ROW][COL]; 


	  
};
#endif // !BOARD_H_

#pragma once
