/**
 * 백준 요세푸스 문제 0_11866
 * 원형 리스트를 사용한 문제
 * K번째배 순서에 있는 사람을 리스트에서 제거하는데, 리스트의 끝에 도달하면 다시 헤드로 돌아가서 연속해서 순서를 센다. 
 * Ex) 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4 ... 이렇게 계속 논리적으로 이어져 있다고 보면 된다.
 * 
 * 
 * 제한사항
 *****************************************
 * 0 < K <= N <= 1,000                   *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 60분
 */


#include <iostream>

using namespace std;

#define MAX_SIZE 1001

static int circleList[MAX_SIZE];

static int top = 0;
static int current = 0;
static int cnt = 0;

void Push(int value);
int Delete();
int Size();

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        Push(i+1);
    }

    int K;
    cin >> K;

    int stack = 0;
    int removed = 0;

    cout << "<";

    while (Size() > 0)
    {
        // 제거된 값이 아니라면 스택 증가
        if (circleList[current] != -1)
        {
            stack++;

            // K번째면 제거
            if (stack == K)
            {
                if (removed > 0) 
                {
                    cout << ", ";
                }
                cout << circleList[current];
                Delete();
                stack = 0;
                removed++;
            }
        }

        // current를 원형으로 이동
        current++;
        if (current >= top)
        {
            current = 0;
        }
    }

    cout << ">\n";

    return 0;
}

void Push(int value)
{
    circleList[top++] = value;
    cnt++;
}

int Delete()
{
    int temp = circleList[current];
    cnt--;
    circleList[current] = -1;
    return temp;
}

int Size()
{
    return cnt;
}