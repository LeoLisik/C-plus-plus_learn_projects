#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string a;
    cout << "Введите = ";
    getline(cin, a);
    for (int i = 0; i < a.size(); i++) {
        if (a[i] <= -1 and a[i] >= -32 and a[i] >= 97 and a[i] <= 122) {
            a[i] -= 32;
        }
    } //В верхний регистр
    int b = 0;
    string result; //Итоговый список строк
    while (a.empty() != 1) {
        string word; //Обрабатываемое слово
        if (a.find_first_of(" ") != 4294967295) {
            for (int i = 0; i < a.find_first_of(" "); i++) {
                word += a[i];
            }
        }
        else {
            word += a;
        }
        a.erase(0, a.find_first_of(" "));
        while (a[0] == ' ') {
            a.erase(0, 1);
        }
        if (a.find(word) == 4294967295) {
            b++;
            result += word + ' ';
        }
    }
    cout << "Количество уникальных слов = " << b << endl;
    cout << "Список слов = " << result << endl;
}