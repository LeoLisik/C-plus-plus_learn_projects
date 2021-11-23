#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string a;
	cout << "Введите текст: ";
	getline(cin, a);
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] <= -1 and a[i] >= -32)
		{
			a[i] -= 32;
		}
		if (a[i] >= 97 and a[i] <= 122)
		{
			a[i] -= 32;
		}
	}
	cout << a;
}