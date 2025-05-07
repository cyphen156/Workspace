/**
 * 백준 수 정렬하기 2_2751_MergeSort
 * 중복 없는 오름차순 정렬, 버블정렬 말고 다른거 써라
 * // 퀵소트
 * 또는 중복이 없다는 전제조건이 있기 때문에 Bool 해시 배열로 사용가능
 * 
 * 제한사항
 *****************************************
 * 1 ≤ N ≤ 1,000,000                     *
 * -1,000,000 ≤ Input ≤ 1,000,000        *
 *****************************************
 *
 *
 *
 * 주의
 * 입력 자료 수가 커진다. 버블 정렬하면 TimeLimit 발생
 * 
 * 풀이시간 0분
 */


#include <iostream>

using namespace std;

void MergeSort(int* array, int start, int End);
void Merge(int* array, int left, int mid, int right);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int* arr = new int[N];

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    MergeSort(arr, 0, N-1);

    for (int i = 0; i < N; ++i)
    {
        cout << arr[i] << '\n';
    }
    
    delete[] arr;

    return 0;
}

void MergeSort(int* array, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = left + (right - left) / 2;

    MergeSort(array, left, mid);
    MergeSort(array, mid + 1, right);

    Merge(array, left, mid, right);
}

void Merge(int* array, int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];

    for (int i = 0; i < leftSize; ++i)
        leftArr[i] = array[left + i];

    for (int i = 0; i < rightSize; ++i)
        rightArr[i] = array[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < leftSize && j < rightSize)
    {
        if (leftArr[i] <= rightArr[j])
            array[k++] = leftArr[i++];
        else
            array[k++] = rightArr[j++];
    }

    while (i < leftSize)
        array[k++] = leftArr[i++];

    while (j < rightSize)
        array[k++] = rightArr[j++];

    delete[] leftArr;
    delete[] rightArr;
}
