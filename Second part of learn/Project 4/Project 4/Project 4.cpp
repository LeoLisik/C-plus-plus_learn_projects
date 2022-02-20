#include <iostream>
#include <Windows.h>
using namespace std;

class Point
{
public:
	Point() 
	{
		this->x = 0;
		this->y = 0;
	}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int GetX() {
		return this->x;
	}
	int GetY() {
		return this->y;
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
		cout << "\ndestroyed";
	}
private:
	int x, y;
};

class Line : Point
{
public:
	Line() {
		Point::gotoxy(0, 0);
		putchar('.');
		Point::gotoxy(100, 100);
		putchar('.');
	}
	Line(Point& a, Point& b) {
		Point::gotoxy(a.GetX(), a.GetY());
		putchar('.');
		Point::gotoxy(b.GetX(), b.GetY());
		putchar('.');
	}
};

class Triangel : Point, Line
{
public:
	Triangel(Point& a, Point& b, Point& c) {
		Point::gotoxy(a.GetX(), a.GetY());
		putchar('.');
		Point::gotoxy(b.GetX(), b.GetY());
		putchar('.');
		Point::gotoxy(c.GetX(), c.GetY());
		putchar('.');
	};

	Triangel(Line& a, Line& b, Line& c) {
		putchar('.');
	}
};

int main()
{
	cout << "\nI'm alive\n";
	Point A(15, 3);
	Point B(29, 6);
	Point C(3, 2);
	Point D(2, 15);
	Point E(220, 3);
	Point F(50, 12);
	Line L1(A, B);
	Line L2(C, D);
	Line L3(E, F);
	Triangel T1(L1, L2, L3);
}