// ConsoleApplication42.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;
void print_arr(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
        if (i % 5 == 0)
        {
            cout << endl;
        }
    }
}
/**************************************************************************************/
void bubbleSort(int* num, int size)// bubble sort
{
    // Для всех элементов
    long k = 0;
    for (int i = 0; i < size - 1; i++)
    {
        k++;
        //cout << k << endl;
        for (int j = (size - 1); j > i; j--) // для всех элементов после i-ого
        {
            if (num[j - 1] > num[j]) // если текущий элемент меньше предыдущего
            {
                int temp = num[j - 1]; // меняем их местами
                num[j - 1] = num[j];
                num[j] = temp;
            }
        }
    }
}
/**************************************************************************************/
void bubblesortM(int* a, int n)
{
    bool b = true;
    while (b)
    {
        b = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                b = true;
            }
        }
    }
}
/**************************************************************************************/
void ShakerSort(int* arr, int n)
{
    int Start = 0;
    int End = n - 1;
    while (Start <= End)
    {
        for (int i = End; i >= Start; i--)
            if (arr[i - 1] > arr[i]) swap(arr[i], arr[i - 1]);
        Start++;


        for (int i = Start; i <= End; i++)
            if (arr[i - 1] > arr[i]) swap(arr[i], arr[i - 1]);
        End--;
    }
}
/**************************************************************************************/
void combsort(int* data, int n) // data — название вектора  (передаём по ссылке, чтобы вызов comb(array) менял вектор array)
{
    double factor = 1.2473309; // фактор уменьшения
    int step = n - 1; // шаг сортировки
        //Последняя итерация цикла, когда step==1 эквивалентна одному проходу сортировки пузырьком
    while (step >= 1)
    {
        for (int i = 0; i + step < n; i++)
        {
            if (data[i] > data[i + step])
            {
                std::swap(data[i], data[i + step]);
            }
        }
        step /= factor;
    }
}
/**************************************************************************************/
void gnomesort(int* arr, int n)
{
    int i = 0;
    while (i < n)
    {
        if (i == 0 || arr[i - 1] <= arr[i])
        {
            i++;
        }
        else
        {
            int tmp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = tmp;
            i--;
        }
    }
}
/**************************************************************************************/
void insertionSort(int* arr, int n) // сортировка вставками
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        int buff = arr[i]; // запомним обрабатываемый элемент
        for (j = i - 1; j >= 0 && arr[j] > buff; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = buff;
    }
}
/**************************************************************************************/
void shellsort(int* l, int* r) {
    int sz = r - l;
    int step = sz / 2;
    while (step >= 1) {
        for (int* i = l + step; i < r; i++) {
            int* j = i;
            int* diff = j - step;
            while (diff >= l && *diff > *j) {
                swap(*diff, *j);
                j = diff;
                diff = j - step;
            }
        }
        step /= 2;
    }
}
/**************************************************************************************/
void shellsorthib(int* l, int* r) {
    int sz = r - l;
    if (sz <= 1) return;
    int step = 1;
    while (step < sz) step <<= 1;
    step >>= 1;
    step--;
    while (step >= 1) {
        for (int* i = l + step; i < r; i++) {
            int* j = i;
            int* diff = j - step;
            while (diff >= l && *diff > *j) {
                swap(*diff, *j);
                j = diff;
                diff = j - step;
            }
        }
        step /= 2;
    }
}
/**************************************************************************************/
int steps[100];
void shellsortsedgwick(int* l, int* r) {
    int sz = r - l;
    steps[0] = 1;
    int q = 1;
    while (steps[q - 1] * 3 < sz) {
        if (q % 2 == 0)
            steps[q] = 9 * (1 << q) - 9 * (1 << (q / 2)) + 1;
        else
            steps[q] = 8 * (1 << q) - 6 * (1 << ((q + 1) / 2)) + 1;
        q++;
    }
    q--;
    for (; q >= 0; q--) {
        int step = steps[q];
        for (int* i = l + step; i < r; i++) {
            int* j = i;
            int* diff = j - step;
            while (diff >= l && *diff > *j) {
                swap(*diff, *j);
                j = diff;
                diff = j - step;
            }
        }
    }
}
/**************************************************************************************/
void is(int* l, int* r) {
    for (int* i = l + 1; i < r; i++) {
        int* j = i;
        while (j > l && *(j - 1) > *j) {
            swap(*(j - 1), *j);
            j--;
        }
    }
}
void shellsortpratt(int* l, int* r) {
    int sz = r - l;
    steps[0] = 1;
    int cur = 1, q = 1;
    for (int i = 1; i < sz; i++) {
        int cur = 1 << i;
        if (cur > sz / 2) break;
        for (int j = 1; j < sz; j++) {
            cur *= 3;
            if (cur > sz / 2) break;
            steps[q++] = cur;
        }
    }
    is(steps, steps + q);
    q--;
    for (; q >= 0; q--) {
        int step = steps[q];
        for (int* i = l + step; i < r; i++) {
            int* j = i;
            int* diff = j - step;
            while (diff >= l && *diff > *j) {
                swap(*diff, *j);
                j = diff;
                diff = j - step;
            }
        }
    }
}
/**************************************************************************************/
void selectionsort(int* l, int* r) {
    for (int* i = l; i < r; i++) {
        int minz = *i, * ind = i;
        for (int* j = i + 1; j < r; j++) {
            if (*j < minz) minz = *j, ind = j;
        }
        swap(*i, *ind);
    }
}
/**************************************************************************************/
template <class T>
class heap {
public:
    int size() {
        return n;
    }
    int top() {
        return h[0];
    }
    bool empty() {
        return n == 0;
    }
    void push(T a) {
        h.push_back(a);
        SiftUp(n);
        n++;
    }
    void pop() {
        n--;
        swap(h[n], h[0]);
        h.pop_back();
        SiftDown(0);
    }
    void clear() {
        h.clear();
        n = 0;
    }
    T operator [] (int a) {
        return h[a];
    }
private:
    vector<T> h;
    int n = 0;
    void SiftUp(int a) {
        while (a) {
            int p = (a - 1) / 2;
            if (h[p] > h[a]) swap(h[p], h[a]);
            else break;
            a--; a /= 2;
        }
    }
    void SiftDown(int a) {
        while (2 * a + 1 < n) {
            int l = 2 * a + 1, r = 2 * a + 2;
            if (r == n) {
                if (h[l] < h[a]) swap(h[l], h[a]);
                break;
            }
            else if (h[l] <= h[r]) {
                if (h[l] < h[a]) {
                    swap(h[l], h[a]);
                    a = l;
                }
                else break;
            }
            else if (h[r] < h[a]) {
                swap(h[r], h[a]);
                a = r;
            }
            else break;
        }
    }
};
void heapsort(int* l, int* r) {
    heap<int> h;
    for (int* i = l; i < r; i++) h.push(*i);
    for (int* i = l; i < r; i++) {
        *i = h.top();
        h.pop();
    }
}


/**************************************************************************************/
void quicksort(int* l, int* r) {
    if (r - l <= 1) return;
    int z = *(l + (r - l) / 2);
    int* ll = l, * rr = r - 1;
    while (ll <= rr) {
        while (*ll < z) ll++;
        while (*rr > z) rr--;
        if (ll <= rr) {
            swap(*ll, *rr);
            ll++;
            rr--;
        }
    }
    if (l < rr) quicksort(l, rr + 1);
    if (ll < r) quicksort(ll, r);
}
/**************************************************************************************/
int digit(int n, int k, int N, int M) {
    return (n >> (N * k) & (M - 1));
}
void _radixsort(int* l, int* r, int N) {
    int k = (32 + N - 1) / N;
    int M = 1 << N;
    int sz = r - l;
    int* b = new int[sz];
    int* c = new int[M];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < M; j++)
            c[j] = 0;
        for (int* j = l; j < r; j++)
            c[digit(*j, i, N, M)]++;
        for (int j = 1; j < M; j++)
            c[j] += c[j - 1];
        for (int* j = r - 1; j >= l; j--)
            b[--c[digit(*j, i, N, M)]] = *j;
        int cur = 0;
        for (int* j = l; j < r; j++)
            *j = b[cur++];
    }
    delete b;
    delete c;
}
void LSD(int* l, int* r) {
    _radixsort(l, r, 8);
}
/**************************************************************************************/
void _radixsortmsd(int* l, int* r, int N, int d, int* temp) {
    if (d == -1) return;
    if (r - l <= 32) {
        is(l, r);
        return;
    }
    int M = 1 << N;
    int* cnt = new int[M + 1];
    for (int i = 0; i <= M; i++)
        cnt[i] = 0;
    int cur = 0;
    for (int* i = l; i < r; i++) {
        temp[cur++] = *i;
        cnt[digit(*i, d, N, M) + 1]++;
    }
    int sz = 0;
    for (int i = 1; i <= M; i++)
        if (cnt[i]) sz++;
    int* run = new int[sz];
    cur = 0;
    for (int i = 1; i <= M; i++)
        if (cnt[i]) run[cur++] = i - 1;
    for (int i = 1; i <= M; i++)
        cnt[i] += cnt[i - 1];
    cur = 0;
    for (int* i = l; i < r; i++) {
        int ind = digit(temp[cur], d, N, M);
        *(l + cnt[ind]) = temp[cur];
        cur++;
        cnt[ind]++;
    }
    for (int i = 0; i < sz; i++) {
        int r = run[i];
        if (r != 0) _radixsortmsd(l + cnt[r - 1], l + cnt[r], N, d - 1, temp);
        else _radixsortmsd(l, l + cnt[r], N, d - 1, temp);
    }
    delete run;
    delete cnt;
}
void MSD(int* l, int* r) {
    int* temp = new int[r - l];
    _radixsortmsd(l, r, 8, 3, temp);
    delete temp;
}
/**************************************************************************************/


int main()
{
    srand(time(NULL));

    int n = 1000000;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0 + rand() % 100000;
    }
    clock_t start_time = clock();
    //bubbleSort(arr, n);
    bubblesortM(arr,n);
    //ShakerSort(arr, n);
    //gnomesort(arr,n);
    //combsort(arr, n);
    //insertionSort(arr, n);
    //shellsort(arr, arr + n);
    //shellsorthib(arr,arr + n);
    //shellsortsedgwick(arr, arr + n);
    //shellsortpratt(arr, arr + n);
    //selectionsort(arr, arr + n);
    //heapsort(arr, arr + n);
    //quicksort(arr, arr + n);
    //LSD(arr, arr + n);
    //MSD(arr, arr + n);
    clock_t end_time = clock();
    double time_second = (end_time - start_time) / (double)CLOCKS_PER_SEC;
    //print_arr(arr, n);

    cout << "Time in second= " << time_second;

}

