#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
using namespace std;

class Point;
class Triangle;
class Line;

class Point
{
	friend Triangle;
	friend Line;
private:
	int x, y;
	char ch;
public:
	Point(int x, int y, char ch);
	static void gotoxy(int xpos, int ypos);
};

void Point::gotoxy(int xpos, int ypos)
{
	COORD position;
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	position.X = xpos;
	position.Y = ypos;
	SetConsoleCursorPosition(screen, position);
}

Point::Point(int x, int y, char ch)
{
	this->x = x;
	this->y = y;
	this->ch = ch;
}

class Triangle
{
public:
	Triangle(Point& a, Point& b, Point& c);
};

Triangle::Triangle(Point& a, Point& b, Point& c)
{
	Point::gotoxy(a.x, a.y);
	_putch(a.ch);

	Point::gotoxy(b.x, b.y);
	_putch(b.ch);

	Point::gotoxy(c.x, c.y);
	_putch(c.ch);
}

class Line
{
public:
	Line(Point& a, Point& b);
};

Line::Line(Point& a, Point& b)
{
	Point::gotoxy(a.x, a.y);
	_putch(a.ch);

	Point::gotoxy(b.x, b.y);
	_putch(b.ch);
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Point a(5, 5, '·');
	Point b(10, 5, '·');
	Point c(5, 10, '·');

	Triangle abc(a, b, c);
	cout << endl << endl << endl << endl;
	system("pause");
	system("cls");

	Line ab(a, b);
	cout << endl << endl << endl << endl;
	system("pause");
	system("cls");

	Line ac(a, c);
	cout << endl << endl << endl << endl;
	system("pause");
	system("cls");

	Line bc(b, c);
	cout << endl << endl << endl << endl;
}