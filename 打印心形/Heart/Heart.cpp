#include<iostream>
#include<ctime>
#include<conio.h>
#include<Windows.h>
#include<cmath>
void gotoxy(HANDLE hOut, int x, int y)
{
    COORD pos;
    pos.X = x; //横坐标
    pos.Y = y; //纵坐标
    SetConsoleCursorPosition(hOut, pos);
}
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量
int main()
{
    using namespace std;
    float x = 0;
    float y = 0;
    srand((unsigned int)time(NULL));
    while (1)
    {
        while (y < 20)
        {
            y++;
            gotoxy(hOut, y, x);
            cout << "*";
            Sleep(100);
        }
        while (x <5)
        {
            x++;
            gotoxy(hOut, y, x);
            cout << "*";
            Sleep(100);
        }
        while (y<40)
        {
            y++;
            gotoxy(hOut, y, x);
            cout << "*";
            Sleep(100);
        }
        while (x>0)
        {
            x--;
            gotoxy(hOut, y, x);
            cout << "*";
            Sleep(100);
        }
        while (y<60)
        {
            y++;
            gotoxy(hOut, y, x);
            cout << "*";
            Sleep(100);
        }
        while (x < 10)
        {
            x++;
            gotoxy(hOut, y, x);
            cout << "*";
            Sleep(100);
        }
        while (y > 0)
        {
            y--;
            gotoxy(hOut, y, x);
            cout << "*";
            Sleep(100);
        }
        while (x > 0)
        {
            x--;
            gotoxy(hOut, y, x);
            cout << "*";
            Sleep(100);
        }
        int a;
        int b;
        a = rand() % 5 + 1;
        b = rand() % 60 + 1;
        gotoxy(hOut, b, a);
        cout << "#";
        Sleep(100000);
    }
    return 0;


}