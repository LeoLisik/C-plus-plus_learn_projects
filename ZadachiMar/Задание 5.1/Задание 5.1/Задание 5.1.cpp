#include <iostream>
#include <Windows.h>
#include <string>
#include <cstring>
#include <locale>
#include <cctype>
using namespace std;


int main()
{
    const int n = 255;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string a;
    cout << "Введите текст: ";
    getline(cin, a);
    for (int s, i = 0; i < a.size(); i++) {
        if (a[i] <= -33 and a[i] >= -64)
        {
            a[i] += 32;
        }
        if (a[i] >= 97 and a[i] <= 122)
        {
            a[i] -= 32;
        }
        cout << a;
    }