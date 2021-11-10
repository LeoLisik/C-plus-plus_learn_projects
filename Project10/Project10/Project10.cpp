#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string temp;
    ifstream inf;
    inf.open("f.txt");
    if (inf.is_open()) {
        getline(inf, temp);
    } else { cout << "Что-то пошло не так, файл не открылся"; }
    inf.close();
    for (int i = 0; i < temp.length(); i++) {
        if (temp[i] == '9') {
            temp[i] = '1';
        } else if (temp[i] == '1') {
            temp[i] = '9';
        }
    }
    remove("f.txt");
    ofstream inf1("f.txt");
    inf1 << temp;
    inf1.close();
    cout << "Изменение файла завершено успешно";
}
