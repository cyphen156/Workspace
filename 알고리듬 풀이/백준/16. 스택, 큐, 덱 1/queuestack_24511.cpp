/**
 * 백준 풍선 터트리기_2346
 * 입력받은 데이터를 넣었다가 뺏다가를 반복하면서 자료구조의 맨 뒤로 보내서 리턴한다.
 * 덱을 사용하면 편하지만 연습용으로 구현하겠다.
 * 
 * 제한사항
 *************************************************************************************
 * 첫째 줄에는 자료구조의 개수 N이 주어진다. (0 < N <= 100,000)                         *
 * 둘째 줄에는 i번 자료의 자료구조가 무엇인지 주어진다. (0 == Queue, 1 == stack)         *
 * 셋째 줄에는 i번 자료구조에 들어가는 원소이다. (0 < B(i) <= 1,000,000,000)             *
 * 넷째 줄에는 삽입할 수열의 길이 M이 주어진다. (0 < M <= 100,000)                      *
 * 다섯째 줄에는  원소를 담고 있는 길이 수열 C가 주어진다. (0 < C(i) <= 1,000,000,000)   * 
 *************************************************************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 90분
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_SIZE 100001

static int _isStack[MAX_SIZE];

int front = 0; 

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    vector<int> queue;
    for (int i = 0; i < N; ++i)
    {
        int input;
        cin >> input;
        _isStack[i] = input;
    }
    
    // 처음 입력
    for (int i = 0; i < N; ++i)
    {
        int input;
        cin >> input;
        
        if (!_isStack[i])
        {
            queue.push_back(input);
        }
    }

    int T;
    cin >> T;

    reverse(queue.begin(), queue.begin() + queue.size());
    for (int i = 0; i < T; ++i)
    {
        int input;
        cin >> input;
        
        // 1차 알고리즘
        
        // for (int j = 0; j < size(queueIndex); ++j)
        // {
        //     int index = queueIndex[j];
        
        //     int temp = queuestack[index];
        //     queuestack[index] = input;
        //     input = temp;
        // }

        queue.push_back(input);

        printf("%d ", queue[front++]);
    }
    return 0;
}

