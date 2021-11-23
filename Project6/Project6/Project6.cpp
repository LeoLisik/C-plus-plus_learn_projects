#include <iostream>
#include <Windows.h>
#include <string>
#include <time.h>
#include <stdlib.h>
#define ch m.find_last_not_of("-0123456789.")
#define ch2 m.find_last_of("-")
#define ch3  m.find_last_of(".")-m.find_first_of(".")
using namespace std;

int random(int min, int max)
{
	static bool flag;
	if (!flag)
	{
		srand(time(NULL));
		flag = true;
	}
	return min + rand() % (max - min);
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int* c = new int[21];
	int** matrica = new int* [6];
	string m;
	int Vvod = 0;
	do {
		do {
			cout << "0 - Заполнение массива случайными числами от -10 до 10, 1 - Заполнить вручную" << endl;
			cout << "Ваш выбор = ";
			getline(cin, m);
		} while ((ch != -1) or (ch2 != -1 and ch2 != 0) or (ch3 != 0));
		Vvod = atof(m.c_str());
	} while (Vvod > 1 or Vvod < 0);
	m.clear();
	if (Vvod == 1) {
		for (int i = 0; i <= 20; i++) {
			do {
				cout << "Введите элемент " << i << " = ";
				getline(cin, m);
			} while ((ch != -1) or (ch2 != -1 and ch2 != 0) or (ch3 != 0));
			c[i] = atof(m.c_str());
		}
	} else { 
		for (int i = 0; i <= 20; i++) {
			c[i] = random(-10, 10);
			if (random(0, 1) > 0) {
				c[i] *= -1;
			}
		}
	}
	for (int i = 0; i < 6; i++) {
		matrica[i] = new int[6];
	}
	int now_int = 0;

	for (int l = 0; l < 6; l++) {
		for (int i = 0; i < 6; i++) {
			matrica[l][i] = 0;
		}
	}
	for (int l = 0; l < 6; l++) {
		for (int i = 0; i < l + 1; i++) {
			matrica[l][i] = c[now_int];
			now_int++;
		}
	}
	for (int l = 0; l < 6; l++) {
		for (int i = 0; i < 6; i++) {
			cout.width(7);
			cout << matrica[l][i] << " ";
		}
		cout << endl;
	}
	delete[]c;
	for (int i = 0; i < 6; i++) {
		delete matrica[i];
	}
	delete[]matrica;
}