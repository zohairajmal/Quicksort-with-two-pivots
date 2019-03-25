/*Modified version of the Quicksort algorithm, where the sequence
of elements is always split into three subsequences by simultaneously using two random
elements as pivots.*/

#include <iostream>
#include <chrono>
#include <random>
#define N 1000
using namespace std;
int *Partition(int *Arr, int low, int high);
int piv[2] = {0, 0};
void QuickSort(int *Arr, int low, int r);

int main()
{
    srand(time(NULL));
    int Arr[N];
    double sum = 0;
    for (int i = 0; i < N; i++)
    {
        Arr[i] = rand() % 10000;
    }
    auto start = std::chrono::high_resolution_clock::now();
    QuickSort(Arr, 0, N - 1);
    auto finish = std::chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    sum = sum + elapsed.count();
    for (int i; i < N; i++)
        cout << Arr[i] << " ";
    cout << endl;
    cout << sum << "s Modified Time Taken" << endl;
    return 0;
}

int *Partition(int *Arr, int low, int high)
{
    int tempvar = 0;
    int i = low + 1;
    int piv1, piv2;
    int j;
    if (Arr[low] > Arr[low + 1])
        swap(Arr[low], Arr[low + 1]);

    piv1 = Arr[low];
    piv2 = Arr[low + 1];
    for (j = low + 2; j <= high; ++j)
    {
        if (Arr[j] <= piv1)
        {
            i++;
            tempvar = Arr[j];
            Arr[j] = Arr[i];
            Arr[i] = tempvar;
        }
    }
    if (i != low + 1)
    {
        Arr[low] = Arr[i];
        Arr[i] = piv1;
    }
    piv[0] = i - 1;
    int k = low + 1;
    for (; k < i && k < high; ++k)
    {
        Arr[k] = Arr[k + 1];
    }
    Arr[i] = piv2;
    low = i;
    int l = i;
    for (j = i + 1; j <= high; ++j)
    {
        if (Arr[j] <= piv2)
        {
            i++;
            swap(Arr[j], Arr[i]);
        }
    }
    Arr[l] = Arr[i];
    Arr[i] = piv2;
    piv[1] = i;
    return piv;
}

void QuickSort(int *A, int low, int high)
{
    int *p;
    srand(time(NULL));
    std::default_random_engine rng;
    int rand1 = std::uniform_int_distribution<>(0, 999)(rng);
    int rand2 = std::uniform_int_distribution<>(0, rand1)(rng);
    if (low >= high)
        return;
    p = Partition(A, low, high);
    QuickSort(A, low, (p[rand1] - 1));
    QuickSort(A, p[rand1] + 1, p[rand2] - 1);
    QuickSort(A, p[rand2] + 1, high);
    return;
}