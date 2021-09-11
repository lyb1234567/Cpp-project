#ifndef BOARD_H_
#define BOARD_H_
class Board
{
public:
	enum
	{
		ROW = 24, //行数
		COL = 25//列数
	};
	void initwall();
	void drawall();
	void setnumber(int x, int y, int n);
	int getnumber(int x,int y);
private:
	char gameborad[ROW][COL]; 


	  
};
#endif // !BOARD_H_

#pragma once
