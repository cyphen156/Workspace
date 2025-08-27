/**
 * 백준 중앙값 구하기_2696
 * 수열이 있다. 
 * 이 수열의 홀수 번째 수를 읽을 때 마다 입력받은 값의 중앙 값을 출력하라.
 * 중앙값은 정렬된 수열의 가운데 있는 요소이다.
 * 입력은 한줄에 최대 10개 요소까지 입력된다. 
 * 중앙값을 바로 출력하지 말고 저장했다가 10개씩 출력한다.
 * 1차 구현 뭐가 문제일지는 알지만 간단하게 구성하기 위해 우선 입력받고, 정렬한뒤 큐에 넣어 출력시켯다.
 * 예상대로 매 중앙값 계산시 마다 정렬 연산이 되기 때문에 시간이 오래 걸린다.
 * 2차 구현에서는 2개의 힙을 사용하여 구성하도록 하겠다.
 * 매 순간 최소, 최대 힙을 통해 중앙값을 저장하여 즉시 저장할 수 있도록 구성하였다.
 * 
 * 제한사항
 *****************************************
 * 1 <= T < 1,001                        *
 * 1 <= M < 10,000                       *
 * M is Odd                              *
 * Value is Intiger                      *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 30분
 */


#include <iostream>
#include <algorithm>
#include <queue>

static const int MAX_TEST_COUNT = 1000;
static const int MAX_ARRAY_SIZE = 10000;

using namespace std;

static int T, M;
// sol 1 
// 입력 배열
// static int arr[MAX_ARRAY_SIZE];

// sol 2
// 입력 힙
static priority_queue<int> maxHeap;
static priority_queue<int, vector<int>, greater<int>> minHeap;
// 출력 큐
static queue<int> resultQueue;

void print();

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        cin >> M;

        // 입력
        // for (int j = 0; j < M; ++j)
        // {
            // sol 1
            // cin >> arr[j];

            // if (j % 2 == 0)
            // {
            //     sort(arr, arr + j + 1);
            //     int mid = arr[j / 2];
            //     resultQueue.push(mid);
            // }
        // }

        // sol 2
        maxHeap = priority_queue<int>();
        minHeap = priority_queue<int, vector<int>, greater<int>>();
            
        for (int j = 0; j < M; ++j)
        {
            int x; 
            cin >> x;

            if (maxHeap.empty() || x <= maxHeap.top()) 
            { 
                maxHeap.push(x); 
            }
            else
            { 
                minHeap.push(x); 
            }

            if (maxHeap.size() > minHeap.size() + 1)
            {
                int mv = maxHeap.top(); maxHeap.pop();
                minHeap.push(mv);
            }
            else if (minHeap.size() > maxHeap.size())
            {
                int mv = minHeap.top(); minHeap.pop();
                maxHeap.push(mv);
            }

            if ((j % 2) == 0)
            {
                resultQueue.push(maxHeap.top());
            }
        }

        print();
    }
    return 0;
}

void print()
{
    // 갯수 출력
    cout << resultQueue.size() << '\n';

    int cnt = 0;
    // 중앙값 출력
    while (resultQueue.empty() != true)
    {
        cout << resultQueue.front() << ' ';
        resultQueue.pop();
        cnt++;

        if (cnt == 10)
        {
            cout << '\n';
            cnt = 0;
        }
    }

    if (cnt != 0)
    {
        cout << '\n';
    }
}