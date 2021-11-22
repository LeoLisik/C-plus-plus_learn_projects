#include <iostream>
#include <Windows.h>
#include <fstream> 
#include <string>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string a;
    cout << "Напишите строки: ";
    getline(cin, a);

    ofstream fout("f.txt", ios::trunc);
    fout << a << endl;
    fout.close();

    ifstream fin("f.txt");
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        cout << "Запись в файле f: " << a << endl;
    }
    fin.close();

    ofstream outf("g.txt", ios::trunc);
    outf << a << endl;
    outf.close();

    for (int s, i = 0; i < a.size(); i++) {
        if (a[i] <= -33 and a[i] >= -64)
        {
            a[i] += 32;
        }
    }
    ifstream inf("g.txt");
    if (!inf.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        cout << "Запись в файле g: " << a << endl;
    }
    inf.close();

    system("pause");


}
