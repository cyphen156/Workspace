/**
 * 백준 카드 2_2164
 * 1부터 N까지 순서대로 정렬되어 있는 카드뭉치가 존재한다.
 * 가장 위에 있는 카드를 바닥에 버리고 
 * 다음 카드는 기존 카드의 맨 아래로 이동
 * 마지막 한장이 남을때까지 반복했을 때 마지막 한장에 남은 수를 출력하라
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 500,000                      *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 0분
 */


#include <iostream>

using namespace std;

#define MAX_SIZE 1000001
static int queue[MAX_SIZE];

static int head = 0;
static int tail = 0;

void Enqueue(int value);
int Dequeue();

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    // 숫자 초기화
    for (int i = 1; i <= N; ++i)
    {
        Enqueue(i);
    }
    
    while((tail - head) > 1)
    {
        Dequeue();
        Enqueue(Dequeue());
    }

    cout << Dequeue() << '\n';
    return 0;
}

void Enqueue(int value)
{
    queue[tail++] = value;
}

int Dequeue()
{
    return queue[head++];
}