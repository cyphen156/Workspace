/**
 * 백준 수 찾기_1920
 * N개의 정수중 X라는 정수가 있는지 빠른 시간 안에 찾아내라.
 * 시간복잡도가 O(N)이어선 안된다.
 * 출력 : true == 1, false == 0
 * 
 * 제한사항
 *****************************************
 * 1 <= N, M < 100001                    *
 * Input is Intiger                      *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 1 + 10분
 */


#include <iostream>
#include <algorithm>

static const int MAX_SIZE = 100000;
using namespace std;

static int N, M;
static int inputs[MAX_SIZE] = { 0 };

bool BinarySearch(int value);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> inputs[i];
    }

    cin >> M;

    sort(inputs, inputs + N);

    for (int i = 0; i < M; ++i)
    {
        int input;
        cin >> input;
        cout << BinarySearch(input) << '\n';
    }
    return 0;
}

bool BinarySearch(int value)
{
    int left = 0;
    int right = N - 1;
    int pivot;

    while (left <= right)
    {
        pivot = (left + right) / 2;

        if (inputs[pivot] == value)
        {
            return 1;
        }

        if (inputs[pivot] < value)
        {
            left = pivot + 1;
        }
        else 
        {
            right = pivot - 1;
        }
    }
    return 0;
}