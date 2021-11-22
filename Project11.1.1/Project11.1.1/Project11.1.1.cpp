#include <iostream>
#include <Windows.h>
#include <string>
#include <stdlib.h>
using namespace std;
#define ch s.find_last_not_of("-0123456789.")
#define ch2 s.find_last_of("-")
#define ch3  s.find_last_of(".")-s.find_first_of(".")

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    string s;
    int* result = new int;
    int n, m, naideno = 0, a = 1, elements = 0, temp;
    do {
        do {
            cout << "Введите натуральное число = ";
            getline(cin, s);
        } while ((ch != -1) or (ch2 != -1 and ch2 != 0) or (ch3 != 0));
        n = atof(s.c_str());
    } while (n < 1);
    do {
        do {
            cout << "Введите количество чисел = ";
            getline(cin, s);
        } while ((ch != -1) or (ch2 != -1 and ch2 != 0) or (ch3 != 0));
        m = atof(s.c_str());
    } while (m < 1);
    while (naideno < m) {
        n++;
        cout << "n = " << n << endl;
        temp = n;
        while (a != 0) {
            if (temp % 5 == 0) {
                temp /= 5;
            }
            else if (temp % 3 == 0) {
                temp /= 3;
            }
            else if (temp % 2 == 0) {
                temp /= 2;
            }
            else if (temp == 1) {
                naideno++;
                result[elements] = n;
                elements++;
                break;
            }
            else {
                break;
            }
            cout << "Всё работает. temp = " << temp << endl;
        }
    }
    cout << "Результат = ";
    for (int i = 0; i < elements; i++) {
        cout << result[i] << ' ';
    }
    delete[]result;
}