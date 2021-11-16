#include <iostream>
#include <string>
#include <Windows.h>
#define ch s.find_last_not_of("-0123456789.")
#define ch2 s.find_last_of("-")
#define ch3  s.find_last_of(".")-s.find_first_of(".")
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string s;
    int n, d = 0;
    do {
        do {
            cout << "Введите натуральное число = ";
            getline(cin, s);
        } while ((ch != -1) or (ch2 != -1 and ch2 != 0) or (ch3 != 0));
        n = atof(s.c_str());
    } while (n < 1);
    for (int i = 2; i < n - 1; i++) {
        if (n % i == 0) {
            d += i;
        }
    }
    cout << "Характер числа " << n << " равен = " << d;
}