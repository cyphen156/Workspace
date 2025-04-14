/**
 * 백준 대푯값2_2587
 * 주어지는 5개의 수들의 평균과 중앙값을 구해라
 * 
 * 제한사항
 *****************************************
 * 0 < Input < 100                       *
 * Input % 10 == 0                       *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 5분
 */


#include <iostream>

using namespace std;

int main(void)
{
    int arr[5];

    int sum = 0, mid = 0, avg = 1;

    for (int i = 0; i < size(arr); ++i)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    for (int i = 0; i < size(arr)-1; ++i)
    {
        for (int j = i+1; j < size(arr); ++j)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    avg = sum / size(arr);
    mid = arr[size(arr) / 2];
    cout << avg << '\n' << mid << '\n';
    return 0;
}