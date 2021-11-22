#include <iostream>
#include <Windows.h>
#include <fstream> 
#include <string>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char* str = new char[1024];
    string* stroki = new string;
    string s;
    ifstream f;
    int l = 0;

    f.open("f.txt");
    while (!f.eof())
    {
        f.getline(str, 1024, '\n');
        l++;
    }
    
    delete []str;
    
    for (int i = 0; i < l -1; i++) 
    {
        cout << "Успешность = " << i;
        getline(f, s);
        cout << "Выигрышь = " << i;
        stroki[i] = s;
        s.clear();
        cout << "У вас появились = " << stroki[0];
    }

    cout << stroki;












    f.close();

   /* string a;
    string f = "f.txt";
    string g = "g.txt";
    cout << "Напишите строки: ";
    getline(cin, a);

    ofstream fout(f, fstream:: in | fstream :: out | fstream :: app);
    fout << a << endl;
    fout.close();

    ifstream fin(f);
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        cout << "Запись в файле f: " << a << endl;
    }
    fin.close();

    ofstream outf(g, fstream::in | fstream::out | fstream::app);
    outf << a << endl;
    outf.close();

    ifstream inf(g);
    if (!inf.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        cout << "Запись в файле g: " << a << endl;
    }
    inf.close();

    system("pause");
    */
}