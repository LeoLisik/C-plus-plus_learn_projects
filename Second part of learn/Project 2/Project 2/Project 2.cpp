#include <iostream>
#include <Windows.h>
using namespace std;

class Point
{
	friend class Line;
	friend class Triangel;
public:
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	static void gotoxy(int xpos, int ypos)
	{
		COORD position;
		HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
		position.X = xpos;
		position.Y = ypos;
		SetConsoleCursorPosition(screen, position);
	}
	~Point()
	{
		cout << "game";
	}
private:
	int x, y;
};

class Line
{
public:
	Line(Point& a, Point& b) {
		Point::gotoxy(a.x, a.y);
		putchar('.');
		Point::gotoxy(b.x, b.y);
		putchar('.');
	}
};

class Triangel
{
public:
	Triangel(Point& a, Point& b, Point& c) {
		Point::gotoxy(a.x, a.y);
		putchar('.');
		Point::gotoxy(b.x, b.y);
		putchar('.');
		Point::gotoxy(c.x, c.y);
		putchar('.');
	};
};

int main()
{
	Point A(40, 8);
	Point B(50, 2);
	Point C(20, 6);
	Triangel(A, B, C);
	Sleep(2000);
	system("cls");
	Line(A, B);
	Sleep(2000);
	system("cls");
	Line(A, C);
	Sleep(2000);
	system("cls");
	Line(B, C);
	Sleep(2000);
	system("cls");
}