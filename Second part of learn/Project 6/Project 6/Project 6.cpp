#include <iostream>
#include <Windows.h>
using namespace std;

class point
{
protected:
    int x, y;
public:
    point(int xi = 0, int yi = 0);
    int& givex();
    int& givey();
    void show();
    void move(int xn = 0, int yn = 0);
    static void gotoxy(int xpos, int ypos);
private:
    void hide();
};

void point::gotoxy(int xpos, int ypos) {
    COORD position;
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    position.X = xpos;
    position.Y = ypos;
    SetConsoleCursorPosition(screen, position);
}

point::point(int xi, int yi)
{
    x = xi; y = yi;
}
int& point::givex(void) { return x; }
int& point::givey(void) { return y; }

void point::show()
{
    gotoxy(x, y);
    cout << "*";
}
void point::hide()
{
    gotoxy(x, y);
    cout << " ";
}
void point::move(int xn, int yn)
{
    hide();
    x = xn; y = yn;
    show();
}

class figure : public point
{
public:
    figure(point p) : point(p.givex(), p.givey())
    {}
    virtual void show(char s) = 0;
    void hide()
    {
        show(' ');
    }
    void move(point p)
    {
        hide();
        x = p.givex();
        y = p.givey();
        show('*');
    }
};

class square : public figure
{
    int lq;
public:
    square(point d, int li) :figure(d)
    {
        lq = li;
    }
    ~square()
    {
        hide();
    }
    void show(char s = '*');
};

void square::show(char s)
{
    int d = lq / 2;
    for (int i = -d; i <= d; i++)
    {
        gotoxy(x + i, y + d);
        cout << s;
        gotoxy(x + i, y - d);
        cout << s;
    }
    for (int j = -d; j <= d; j++)
    {
        gotoxy(x - d, y + j);
        cout << s;
        gotoxy(x + d, y + j);
        cout << s;
    }
}

class star : public figure
{
    int rad;
public:
    star(point e, int ri) :figure(e)
    {
        rad = ri;
    }
    ~star()
    {
        hide();
    }
    void show(char s = '*');
};

void star::show(char s)
{
    gotoxy(x, y); cout << s;
    for (int i = 1; i <= rad; i++)
    {
        gotoxy(x + i, y); cout << s;
        gotoxy(x - i, y); cout << s;
        gotoxy(x, y + i); cout << s;
        gotoxy(x, y - i); cout << s;
    }
    for (int i = -rad; i <= rad; i++)
    {
        gotoxy(x + i, y + i); cout << s;
        gotoxy(x - i, y + i); cout << s;
    }
}

int main()
{
    point A(10, 8), B(15, 20);
    square C(A, 6);
    star E(B, 3);
    A.show();
    B.show();
    C.show();
    E.show();
    C.move(B);
}