#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Введите текст = ";
    string s = "";
    int count_glasn = 0, count_sogl = 0;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) { //Из больших в маленькие
        if (s[i] >= 65 and s[i] <= 90) {
            s[i] += 32;
        }
    }
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u') { //Проверка на гласную
            count_glasn++;
        }
        if (s[i] >= 98 and s[i] <= 100 or s[i] >= 102 and s[i] <= 104 or s[i] >= 106 and s[i] <= 110 or s[i] >= 112 and s[i] <= 116 or s[i] >= 118 and s[i] <= 122) { //Проверка на согласную
            count_sogl++;
        }
    }
    if (count_glasn > count_sogl) {
        cout << "Гласных букв больше.";
    } else if (count_sogl > count_glasn) {
        cout << "Согласных букв больше.";
    }
    else {
        cout << "Согласных и гласных букв поровну.";
    }
}