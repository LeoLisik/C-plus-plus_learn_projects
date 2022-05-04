#include <iostream>
#include <Windows.h>
using namespace std;

int* BubbleSort(int* array, int ArrayLenght) {
	for (int i = 0; i < ArrayLenght; i++) {
		for (int j = 0; j < ArrayLenght - 1; j++) {
			if (array[j] > array[j + 1]) {
				int b = array[j];
				array[j] = array[j + 1];
				array[j + 1] = b;
			}
		}
	}
	return array;
}

int* DBubbleSort(int* array, int ArrayLenght) {

}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int ArrayLenght, choice;
	cout << "Введите размер массива = ";
	cin >> ArrayLenght;
	int* digitals = new int[ArrayLenght];
	for (int i = 0; i < ArrayLenght; i++) {
		cout << "Введите " << i << " число = ";
		cin >> digitals[i];
	}
	cout << "Изначальный массив:" << endl;
	for (int i = 0; i < ArrayLenght; i++) {
		cout << digitals[i] << " ";
	}
	cout << endl;
	cout << "Чем сортируем? 1 - Пузырьковая, 2 - Пузырьковая двунаправленная = ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		digitals = BubbleSort(digitals, ArrayLenght);
	default:
		break;
	}
	cout << "Отсортированный массив: " << endl;
	for (int i = 0; i < ArrayLenght; i++) {
		cout << digitals[i] << " ";
	}
	delete[] digitals;
}