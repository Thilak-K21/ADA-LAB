#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    srand(time(NULL));
    clock_t start, end;
    int arr[15000];
    int n = 100;

    while (n <= 14500)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % 10000;
        }

        start = clock();
        quickSort(arr, 0, n - 1);
        end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken to sort %d numbers: %0.8f seconds\n", n, time_taken);

        n += 1000;
    }

    return 0;
}