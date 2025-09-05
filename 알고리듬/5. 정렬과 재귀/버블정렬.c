#include <stdio.h>
#include <stdbool.h>

void BubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        bool isSwapped = false;
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSwapped = true;
            }
        }

        if (!isSwapped)
        {
            break;
        }
    }   
}