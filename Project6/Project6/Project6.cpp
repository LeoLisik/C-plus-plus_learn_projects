#include <iostream>
#include <Windows.h>
#include <string>
#include <time.h>
#include <stdlib.h>
#define ch m.find_last_not_of("-0123456789.")
#define ch2 m.find_last_of("-")
#define ch3  m.find_last_of(".")-m.find_first_of(".")
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int* c = new int[21];
	int* str1 = new int[6];
	int* str2 = new int[6];
	int* str3 = new int[6];
	int* str4 = new int[6];
	int* str5 = new int[6];
	int* str6 = new int[6];
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
			c[i] = rand() % 9;
			if (rand() % 2 > 0) {
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
			cout << matrica[l][i] << " ";
		}
		cout << endl;
	}
}