#include <iostream>
#include <Windows.h>
#include <string>
#include <windows.h>
//#define DEBUG
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    string s;
    int iteration;
    float chastota;
    cout << "Введите текст = ";
    getline(cin, s);
    cout << "Введите частоту мигания текста (в сек.) = ";
    cin >> chastota;
    cout << "Введите количество раз, которое должен мигнуть текст";
    cin >> iteration;
    if (chastota > 0) {
        chastota = chastota * 1000;
    } else {
        cout << "Вы ввели недопустимое значение частоты, оно будет принято за пол секунды." << endl;
        chastota = 500;
    }
    int width_field = 120; //ширина поля
    int height_field = 30; //высота поля
    #ifdef DEBUG
    cout << "\x1b[31mDEBUG MOD ACTIVATED\x1b[0m" << endl;
    width_field = 20;
    #endif
    int summ = s.size();
    if (summ < width_field) {
        int summ_tochek = (width_field - s.size()) / 2;
        int summ_endl = height_field / 2;
        for (int i = 0; i < summ_endl - 2; i++) { //Выравнивание по высоте
            cout << endl;
        }
        for (int i = 0; i < summ_tochek; i++) { //Выравнивание по ширине
            cout << " ";
        }
        for (int i = 0; i < iteration; i++) {
            switch (i % 8) {
            case 0: {cout << "\x1b[31m" << s << "\x1b[0m";
                Sleep(chastota);
                for (int i = 0; i < summ; i++) {
                    cout << "\b";
                }
                cout << "\x1b[30m" << s << "\x1b[0m";
                Sleep(chastota);
                for (int i = 0; i < summ; i++) {
                    cout << "\b";
                } break; }
            case 1: {cout << "\x1b[32m" << s << "\x1b[0m";
                Sleep(chastota);
                for (int i = 0; i < summ; i++) {
                    cout << "\b";
                }
                cout << "\x1b[30m" << s << "\x1b[0m";
                Sleep(chastota);
                for (int i = 0; i < summ; i++) {
                    cout << "\b";
                } break; }
            case 2: {cout << "\x1b[33m" << s << "\x1b[0m";
                Sleep(chastota);
                for (int i = 0; i < summ; i++) {
                    cout << "\b";
                }
                cout << "\x1b[30m" << s << "\x1b[0m";
                Sleep(chastota);
                for (int i = 0; i < summ; i++) {
                    cout << "\b";
                } break; }
            case 3: {cout << "\x1b[34m" << s << "\x1b[0m";
                Sleep(chastota);
                for (int i = 0; i < summ; i++) {
                    cout << "\b";
                }
                cout << "\x1b[30m" << s << "\x1b[0m";
                Sleep(chastota);
                for (int i = 0; i < summ; i++) {
                    cout << "\b";
                } break; }
            case 4: {cout << "\x1b[35m" << s << "\x1b[0m";
                Sleep(chastota);
                for (int i = 0; i < summ; i++) {
                    cout << "\b";
                }
                cout << "\x1b[30m" << s << "\x1b[0m";
                Sleep(chastota);
                for (int i = 0; i < summ; i++) {
                    cout << "\b";
                } break; }
            case 5: {cout << "\x1b[36m" << s << "\x1b[0m";
                Sleep(chastota);
                for (int i = 0; i < summ; i++) {
                    cout << "\b";
                }
                cout << "\x1b[30m" << s << "\x1b[0m";
                Sleep(chastota);
                for (int i = 0; i < summ; i++) {
                    cout << "\b";
                } break; }
            case 6: {cout << "\x1b[37m" << s << "\x1b[0m";
                Sleep(chastota);
                for (int i = 0; i < summ; i++) {
                    cout << "\b";
                }
                cout << "\x1b[30m" << s << "\x1b[0m";
                Sleep(chastota);
                for (int i = 0; i < summ; i++) {
                    cout << "\b";
                } break; }
            case 7: {cout << "\x1b[36m" << s << "\x1b[0m";
                Sleep(chastota);
                for (int i = 0; i < summ; i++) {
                    cout << "\b";
                }
                cout << "\x1b[30m" << s << "\x1b[0m";
                Sleep(chastota);
                for (int i = 0; i < summ; i++) {
                    cout << "\b";
                } break; }
            case 8: {cout << "\x1b[35m" << s << "\x1b[0m";
                Sleep(chastota);
                for (int i = 0; i < summ; i++) {
                    cout << "\b";
                }
                cout << "\x1b[30m" << s << "\x1b[0m";
                Sleep(chastota);
                for (int i = 0; i < summ; i++) {
                    cout << "\b";
                } break; }
            }
        }
        /*while (true) {
            cout << "\x1b[31m" << s << "\x1b[0m";
            Sleep(chastota);
            for (int i = 0; i < summ; i++) {
                cout << "\b";
            }
            cout << "\x1b[30m" << s << "\x1b[0m";
            Sleep(chastota);
            for (int i = 0; i < summ; i++) {
                cout << "\b";
            }
            cout << "\x1b[32m" << s << "\x1b[0m";
            Sleep(chastota);
            for (int i = 0; i < summ; i++) {
                cout << "\b";
            }
            cout << "\x1b[30m" << s << "\x1b[0m";
            Sleep(chastota);
            for (int i = 0; i < summ; i++) {
                cout << "\b";
            }
            cout << "\x1b[33m" << s << "\x1b[0m";
            Sleep(chastota);
            for (int i = 0; i < summ; i++) {
                cout << "\b";
            }
            cout << "\x1b[30m" << s << "\x1b[0m";
            Sleep(chastota);
            for (int i = 0; i < summ; i++) {
                cout << "\b";
            }
        }*/
    } else {
        cout << "Простите, данная функция была деактивированна :(";
        /*string x = s.substr((summ / width_field) * width_field);
        string h;
        int summ_tochek = (width_field - x.size()) / 2;
#ifdef DEBUG
        cout << "\x1b[31mDEBUG\x1b[0m -" << s.substr(0, 20) << endl;
        cout << "\x1b[31mDEBUG\x1b[0m -" << s.substr(20, 20) << endl;
        cout << "\x1b[31mDEBUG\x1b[0m -" << s.substr(40, 20) << endl;
        cout << s;
#endif
        for (int i = 0; i < (summ / width_field) * width_field; i += width_field) {
            h += s.substr(i, width_field);
        }
        for (int i = 0; i < summ_tochek; i++) { //Выравнивание по ширине
            h += " ";
        }
        h += x;
        while (true) {
            cout << "\x1b[31m" << h << "\x1b[0m";
            Sleep(chastota);
            for (int i = 0; i < 10000; i++) {
                cout << "\b";
            }
            cout << "\x1b[30m";
            for (int i = 0; i < (summ / width_field) * width_field; i += width_field) {
                cout << s.substr(i, width_field) << endl;
            }
            for (int i = 0; i < summ_tochek; i++) { //Выравнивание по ширине
                cout << " ";
            }
            cout << x << "\x1b[0m";
            Sleep(chastota);
            for (int i = 0; i < summ; i++) {
                cout << "\b";
            }
            cout << "\x1b[32m";
            for (int i = 0; i < (summ / width_field) * width_field; i += width_field) {
                cout << s.substr(i, width_field) << endl;
            }
            for (int i = 0; i < summ_tochek; i++) { //Выравнивание по ширине
                cout << " ";
            }
            cout << x << "\x1b[0m";
            Sleep(chastota); 
            for (int i = 0; i < summ; i++) {
                cout << "\b";
            }
            cout << "\x1b[30m";
            for (int i = 0; i < (summ / width_field) * width_field; i += width_field) {
                cout << s.substr(i, width_field) << endl;
            }
            for (int i = 0; i < summ_tochek; i++) { //Выравнивание по ширине
                cout << " ";
            }
            cout << x << "\x1b[0m";
            Sleep(chastota);
            for (int i = 0; i < summ; i++) {
                cout << "\b";
            }
            cout << "\x1b[33m";
            for (int i = 0; i < (summ / width_field) * width_field; i += width_field) {
                cout << s.substr(i, width_field) << endl;
            }
            for (int i = 0; i < summ_tochek; i++) { //Выравнивание по ширине
                cout << " ";
            }
            cout << x << "\x1b[0m";
            Sleep(chastota);
            for (int i = 0; i < summ; i++) {
                cout << "\b";
            }
            cout << "\x1b[30m";
            for (int i = 0; i < (summ / width_field) * width_field; i += width_field) {
                cout << s.substr(i, width_field) << endl;
            }
            for (int i = 0; i < summ_tochek; i++) { //Выравнивание по ширине
                cout << " ";
            }
            cout << x << "\x1b[0m";
            Sleep(chastota);
            for (int i = 0; i < summ; i++) {
                cout << "\b";
            }
        }*/
    }
}