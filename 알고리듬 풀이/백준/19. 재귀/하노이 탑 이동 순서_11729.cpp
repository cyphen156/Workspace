/**
 * 백준 하노이 탑 이동 순서_11729
 * 하노이 탑의 원판을 다른 장대로 옮길 때 옮긴 횟수를 출력하고, 수행 과정을 출력하는 프로그램을 만들어라.
 * 출력은 다음과 같다.
 * 첫째 줄에 옮긴 횟수 K를 출력한다.
 * K개의 줄에 두 정수 A B를 출력한다.
 * A B는 A번 탑의 맨 위 원판을 B로 옮긴다는 뜻이다.
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 20                           *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 20분
 */


#include <iostream>
#include <queue>

using namespace std;

static int cnt = 0;
static queue<int> beforeMoveQueue;
static queue<int> afterMoveQueue;

void Hanoi(int n, int from, int mid, int to);
void MoveTo(int from, int to);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin >> K;

    Hanoi(K, 1, 2, 3);
    
    cout << cnt << '\n';

    while (!beforeMoveQueue.empty() && !afterMoveQueue.empty())
    {
        cout << beforeMoveQueue.front() << ' ' << afterMoveQueue.front() << '\n';
        beforeMoveQueue.pop();
        afterMoveQueue.pop();    
    }

    return 0;
}

void Hanoi(int n, int from, int mid, int to)
{
    if (n == 1)
    {
        MoveTo(from, to);
        return;
    }

    Hanoi(n-1, from, to, mid);
    MoveTo(from, to);
    Hanoi(n-1, mid, from, to);
}

void MoveTo(int from, int to)
{
    beforeMoveQueue.push(from);
    afterMoveQueue.push(to);
    cnt++;
}