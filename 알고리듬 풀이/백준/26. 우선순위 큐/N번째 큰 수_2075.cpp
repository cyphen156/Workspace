/**
 * 백준 N번째 큰 수_2075
 * N X N 크기의 행렬이 있다. 
 * 각 행렬의 요소는 항상 이전 행의 같은 열에 위치한 것보다 크다. 
 * 행렬의 요소 중, N번째로 큰 수를 찾아라.
 * 최대 힙을 통해 풀이한다.
 * 
 * 
 * 제한사항
 *****************************************
 * 1 <= N < 1,501                        *
 * Ni is Intiger                         *
 *****************************************
 *
 *
 *
 * 주의
 * 표에 적힌 수는 중복이 존재하지 않는다는 제약조건이 없다.
 * 시각 정보에 현혹되지 마라.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 1 + 5분
 */


#include <iostream>
#include <algorithm>

static const int MAX_SIZE = 1500 + 1;

using namespace std;

static int N;
static int length = 0;

// using sol 1, sol 2
// static int arr[MAX_SIZE * MAX_SIZE];

// void Push(int value);
// void Pop();
// int Top();

// using sol 3
static int matrix[MAX_SIZE][MAX_SIZE];
static int columnTop[MAX_SIZE]; // 각 열의 마지막 요소

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    // for (int i = 0; i < N * N; ++i)
    // {
        // int input;
        // sol 1
        // MAX_HEAP
        // cin >> input;
        // Push(input);

        // sol 2
        // ARRAY SORT
        // cin >> arr[i];
    // }

    // sol 3
    // partition Heap
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> matrix[i][j];
        }
        //
    }
    // sol 1
    // MAX_HEAP
    // 0 ~ N-1
    // for (int i = 0; i < N-1; ++i)
    // {
    //     Pop();
    // }
    // cout << Top() << '\n';

    // sol 2
    // sort(arr, arr + (N * N), greater<int>());
    // cout << arr[N-1] << '\n';

    // sol 3
    // 열기준 Top Index 초기화
    for (int i = 0; i < N; ++i)
    {
        columnTop[i] = N-1; // 이거 인덱스 저장용 배열임
    }

    int answer = 0;

    // 상위 N개를 순서대로 선택 (N번째가 정답)
    for (int i = 0; i < N; ++i)
    {
        int maxValue = 0x80000000;
        int maxColumn = -1;

        // 현재 각 열의 top 중 최댓값 찾기
        for (int j = 0; j < N; ++j)
        {
            int r = columnTop[j];
            if (r >= 0)
            {
                int v = matrix[r][j];
                if (v > maxValue)
                {
                    maxValue = v;
                    maxColumn = j;
                }
            }
        }

        answer = maxValue;

        // 선택된 열만 한 칸 위로
        if (maxColumn >= 0)
        {
            --columnTop[maxColumn];
        }
    }

    cout << answer << '\n';
    return 0;
}

// void Push(int value)
// {
//     int index = length;
//     arr[length++] = value;
    
//     while (index > 0)
//     {
//         int parent = (index - 1) / 2;

//         if (arr[parent] >= arr[index])
//         {
//             break;
//         }

//         int temp = arr[parent];
//         arr[parent] = arr[index];
//         arr[index] = temp;

//         index = parent;
//     }
// }

// void Pop()
// {
//     if (length == 0)
//     {
//         return;
//     }

//     arr[0] = arr[length-1];
//     length--;

//     int index = 0;
//     while (1)
//     {
//         int left = index * 2 + 1;
//         int right = left + 1;
//         int largest = index;

//         if (left < length && arr[left] > arr[largest])
//         {
//             largest = left;
//         }
//         if (right < length && arr[right] > arr[largest])
//         {
//             largest = right;
//         }

//         if (largest == index)
//         {
//             break;
//         }

//         int temp = arr[index];
//         arr[index] = arr[largest];
//         arr[largest] = temp;

//         index = largest;
//     }
// }

// int Top()
// {
//     if (length == 0)
//     {
//         return 0;
//     }

//     return arr[0];
// }
