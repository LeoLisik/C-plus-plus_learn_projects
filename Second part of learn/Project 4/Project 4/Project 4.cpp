#include <iostream>
#include <Windows.h>
using namespace std;

class Point
{
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
	void Display() {
		gotoxy(x, y);
		cout << '*';
	}
	~Point()
	{
		cout << "Point" << endl;
	}
private:
	int x, y;
};

class Line : Point
{
private:
	int x, y;
public:
	Line(int x1, int y1, int x2, int y2):Point(x1, y1) {
		this->x = x2;
		this->y = y2;
	}
	void Display() {
		Point::Display();
		gotoxy(x, y);
		cout << '*';
	}
	~Line() {
		cout << "Line" << endl;
	}
};

class Triangel : Point, Line
{
public:
	Triangel(int x1, int y1, int x2, int y2, int x3, int y3):Line(x1, y1, x2, y2), Point(x3, y3) {
	}
	void Display() {
		Line::Display();
		Point::Display();
	}
	~Triangel() {
		cout << "Triangel" << endl;
	}
};

int main()
{
	Triangel C(20, 9, 50, 2, 1, 6);
	C.Display();
	Sleep(2000);
	system("cls");
}