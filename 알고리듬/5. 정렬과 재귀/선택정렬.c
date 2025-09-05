#include <stdio.h>

void SelectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] < arr[min_idx]) 
            { 
                min_idx = j; 
            }
        }
        if (min_idx != i)
        {
            int t = arr[i]; 
            arr[i] = arr[min_idx]; 
            arr[min_idx] = t;
        }
    }
}