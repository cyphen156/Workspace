#include <stdbool.h>

void QuickSort(int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int pivot = arr[left + (right - left) / 2];
    int i = left;   // l ptr
    int j = right;  // r ptr

    while (true)
    {
        // 피벗보다 작은건 무시
        while (i <= j && arr[i] < pivot)
        {
            ++i;
        }

        // 피벗보다 큰거는 무시
        while (i <= j && arr[j] > pivot)
        {
            --j;
        }

        // 만약 둘의 left index와 right index 크기 비교가 역전되면
        // 이미 분할되어 있다는 소리
        // 고로 반으로 쪼개서 그 안에서 재분할
        if (i > j)
        {
            break;
        }

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        ++i;
        --j;
    }

    QuickSort(arr, left, j);
    QuickSort(arr, i, right);
}