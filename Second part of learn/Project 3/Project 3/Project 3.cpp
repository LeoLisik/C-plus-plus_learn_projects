#include <iostream>
using namespace std;

class Matrix
{
private:
    float** Array;
    int Size;
public:
    Matrix& operator+(Matrix &B) {
        Matrix* C;
        C = new Matrix(Size);
        for (int i = 0; i < Size; i++)
            for (int j = 0; j < Size; j++)
            {
                C->Array[i][j] = this->Array[i][j] + B.Array[i][j];
            }
        return *C;
    }
    Matrix& operator-(Matrix& B) {
        Matrix* C;
        C = new Matrix(Size);
        for (int i = 0; i < Size; i++)
            for (int j = 0; j < Size; j++)
            {
                C->Array[i][j] = this->Array[i][j] - B.Array[i][j];
            }
        return *C;
    }
    Matrix& operator*(Matrix& B) {
        Matrix* C = new Matrix(Size);
        for (int i = 0; i < Size; i++)
            for (int j = 0; j < Size; j++)
            {
                C->Array[i][j] = this->Array[i][j] * B.Array[i][j];
            }
        return *C;
    }
    int operator--() {
        return (Array[0][0] * Array[1][1]) - (Array[0][1] * Array[1][0]);
    }
    Matrix(int SizeOfMatrix)
    {
        Size = SizeOfMatrix;
        Array = new float* [SizeOfMatrix];
        for (int i = 0; i < SizeOfMatrix; i++)
        {
            Array[i] = new float[SizeOfMatrix];
        }
        for (int i = 0; i < SizeOfMatrix; i++) {
            for (int j = 0; j < SizeOfMatrix; j++) {
                Array[i][j] = rand();
            }
        }
    }
    int PrintArr0() {
        return Array[0][0];
    }
    void PrintMatrix() {
        cout << endl;
        for (int i = 0; i < Size; i++) {
            for (int j = 0; j < Size; j++) {
                cout << this->Array[i][j] << " ";
            }
        }
        cout << endl;
    }
    ~Matrix()
    {
        for (int i = 0; i < Size; i++)
        {
            delete Array[i];
        }
        delete[] Array;
    }
};

int main() {
    Matrix A(2);
    Matrix B(2);
    Matrix C = A + B;
    Matrix D = A - B;
    Matrix E = A * B;
    A.PrintMatrix();
    cout << --A;
}






/*#include <iostream>
#include <fstream>
#define e endl;

using namespace std;

class Matrice_one
{
public:
    int n;
    int m;
    int** arr;

public:
    Matrice_one() : n(0), m(0), arr(nullptr)
    { }

    Matrice_one(int x, int y)
    {
        n = x;
        m = y;
        int** arr = new int* [n];
        cout << "Adress" << &arr << arr << e;

        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[m];
            cout << "Adress arr[i]" << " " << arr[i] << " " << e;

        }
    }

    int** arr_init()
    {
        ifstream fin("Matrice_one.txt", ios_base::in);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                fin >> arr[i][j];
            }
        fin.close();
        return arr;
    }

    void arr_out()
    {
        ofstream fout("Matrice_res.txt", ios_base::out);
        for (int l = 0; l < n; l++)
        {
            for (int q = 0; q < m; q++)
            {
                fout << " " << arr[l][q] << " ";
            }
            fout << e;
        }
        fout.close();
    } //Печать матрицы в файл  

    friend void Matr_mult(Matrice_one& obj, Matrice_one& ob, int n, int m, int n1, int m1);// перемножение матриц

    void Matr_pow();//возведение матрицы в квадрат

    void Matr_mult_scal(int c)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                arr[i][j] = arr[i][j] * c;
            }
        arr_out();
    }// Умножение матрицы на скаляр

    friend Matrice_one operator * (Matrice_one& obj, Matrice_one& ob);

    ~Matrice_one()
    {
        cout << "Вызван деструктор" << e;
        for (int i = 0; i < n; i++)
        {
            delete[](arr[i]);
        }
        delete[] arr;
    }; //деструктор

};

void Matrice_one::Matr_pow()
{
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            arr[i][k] = 0;
            for (int f = 0; f < m; f++)
            {
                arr[i][k] += arr[i][f] * arr[f][k];
            }
        }
    }
    arr_out();
}

Matrice_one operator * (Matrice_one& obj, Matrice_one& ob)
{
    Matrice_one temp2(obj.n, ob.m);
    for (int i = 0; i < obj.n; i++)
    {
        for (int k = 0; k < ob.m; k++)
        {
            temp2.arr[i][k] = 0;
            for (int f = 0; f < obj.m; f++)
            {
                temp2.arr[i][k] += obj.arr[i][f] * ob.arr[f][k];
            }
        }
    }
    return temp2;
}

int main() {
    Matrice_one A(1, 4);
    Matrice_one B(1, 4);
    A * B;
}*/