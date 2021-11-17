#include <iostream>
#include <conio.h>
#include <math.h>

using std::cout;
using std::endl;
using std::cin;

// функция, проверяющая, простое число или нет
int primeNumber(int number)
{
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
            return 0;
        if ((i == number)  (i > sqrt((double)number)))
            return 1;
    }
    return 1;
}

int main()
{
    int n;
    cout << "Vvedite chislo  n: ";
    cin >> n;

    // подсчитываем кол-во элементов для массива простых чисел, не включающего 2, 3 и 5
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        if ((primeNumber(i) == 1) && (i != 2) && (i != 3) && (i != 5))
            count++;
    }

    // выделяем для него память
    int* arr = new int[count];

    // заполняем его
    for (int i = 2, j = 0; i <= n; i++)
    {
        if (primeNumber(i) == 1)
        {
            if ((i != 2) && (i != 3) && (i != 5))
            {
                arr[j] = i;
                j++;
            }
        }
    }

    // получаем в порядке возрастания n первых натуральных чисел,
    // которые не делятся ни на какие простые числа, кроме 2, 3 и 5
    cout << "Result: " << endl;
    for (int i = 1; i < n; i++)
    {
        if ((i % 2 == 0)  (i % 3 == 0) || (i % 5 == 0))
        {
            for (int j = 0; j < count; j++)
            {
                if (i % arr[j] != 0)
                {
                    cout << i << ' ';
                    break;
                }
            }
        }
    }

    delete[] arr;
    _getch();
    return 0;
}