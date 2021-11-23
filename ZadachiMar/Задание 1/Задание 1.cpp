#include <iostream>
#include <cstdlib.h>
#include <Windows.h>

using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char F;
	cout << "Введите текст: ";
	cin >> F;
	F = toupper((unsigned char)F);
	cout << "Тот же текст в верхнем регистре: " << ch << endl;
	return 0;

}

