#include <string.h> 
#include <stdlib.h>

#define MAX_VALUE 0x7fffffff

void CountingSort(int arr[], int size)
{
    int* count = (int*)malloc((MAX_VALUE + 1) * sizeof(int));
    int* output = (int*)malloc(size * sizeof(int));

    if (count == NULL || output == NULL)
    {
        if (count != NULL)
        {
            free(count);
        }
        if (output != NULL)
        {
            free(output);
        }
        return;
    }

    memset(count, 0, (MAX_VALUE + 1) * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= MAX_VALUE; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}