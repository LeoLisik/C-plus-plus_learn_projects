#include <iostream>
#include <fstream>
#include <stdio.h>
#include <Windows.h>
using namespace std;

char Atbash(char ch) {
	if (ch == '\n') {
		return '|';
	} 
	else if (ch == ' ')
	{
		return ch;
	}
	else {
		return char((52 - (int(ch) + 53)) - 52);
	}
}

char Cezar(char ch, int shift) {
	if (ch == '\n') {
		return '|';
	}
	else if (ch == ' ') {
		return ch;
	}
	while ((int(ch) + shift) < 65)
	{
		ch += 52;
	}
	while ((int(ch) + shift) > 122)
	{
		ch -= 52;
	}
	return char(int(ch) + shift); //65 122
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << int('A');
	FILE* f;
	char ch;
	string buff = "";
	int choice;
	cout << "Как будем шифровать?\n1 - Атбаш\n2 - Цезарь\n3 - вермана\n";
	cin >> choice;
	if ((f = fopen("Lab5File.txt", "r")) != NULL) {
			switch (choice)
			{
			case 1:
				int d;
				while ((ch = getc(f)) != EOF) {
					buff += Atbash(ch);
					ch = getc(f);
				}
				break;
			case 2:
				int shift;
				cout << "\nВведите смещение\n";
				cin >> shift;
				while ((ch = getc(f)) != EOF) {
					cout << ch << endl;
					buff += Cezar(ch, shift);
				}
				cout << endl << buff << endl;
				break;
			case 3:
				break;
			}
	}
	cout << "Зашифровано\n";
	if ((f = fopen("Lab5File.txt", "w")) != NULL) {
		for (int i = 0; i < buff.length(); i++) {
			if (buff[i] == '|') {
				putc('\n', f);
			}
			else {
				putc(buff[i], f);
			}
		}
	}
	cout << "Записано\n";
	string a;
	cin >> a;
	fclose(f);
	buff = "";
	if ((f = fopen("Lab5File.txt", "r")) != NULL) {
		switch (choice)
		{
		case 1:
			while ((ch = getc(f)) != EOF) {
				buff += Atbash(ch);
			}
			break;
		case 2:
			int shift;
			cout << "Введите инвертированное смещение зашифрованного сообщения\n";
			cin >> shift;
			while ((ch = getc(f)) != EOF) {
				buff += Cezar(ch, shift);
			}
			break;
		case 3:
			break;
		}
	}
	cout << "Расшифровано\n";
	if ((f = fopen("Lab5File.txt", "w")) != NULL) {
		for (int i = 0; i < buff.length(); i++) {
			if (buff[i] == '|') {
				putc('\n', f);
			}
			else {
				putc(buff[i], f);
			}
		}
	}
	cout << "Записано\n";
}
