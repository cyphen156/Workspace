#include <stdio.h>

void InsertionSort(int arr[], int size)
{
   for (int i = 1; i < size; ++i)
    {
        int key = arr[i];
        int j;

        // 뒤에서 앞으로 탐색하면서 이동
        for (j = i - 1; j >= 0; --j)
        {
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];  // 한 칸 뒤로 밀기
            }
            else
            {
                break; // 자기 자리를 찾으면 종료
            }
        }

        arr[j + 1] = key;  // key 삽입
    }
}