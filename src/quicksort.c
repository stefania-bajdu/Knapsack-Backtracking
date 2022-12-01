#include <backpack.h>

void swap(element *x, element *y)
{
    element temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int partition(element *arr, int low, int high)
{
    int i, j;
    element pivot;
    pivot = arr[high];
    i = low - 1;
    for (j = low; j < high; j++)
        if (efficiency(arr[j]) >= efficiency(pivot))
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(element *arr, int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}
