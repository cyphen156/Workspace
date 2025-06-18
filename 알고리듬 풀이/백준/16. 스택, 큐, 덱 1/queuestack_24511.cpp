/**
 * 백준 풍선 터트리기_2346
 * 풍선 : 이중연결 리스트
 * 풍선 내부 종이 : data
 * 1번 풍선을 터트리고 그 안의 data만큼 이동하여 다음 풍선을 터트린다.-> pop() 
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 1,000                        *
 * -N <= data<= N                        *
 * data != 0                             *       
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 30분
 */


#include <iostream>

using namespace std;

#define MAX_SIZE 100001

static int queuestack[MAX_SIZE];
static bool isStack[MAX_SIZE] = { 0 };

void Push(int data);
int Pop();

void Enqueue(int data);
int Dequeue();

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int _isStack;
        cin >> _isStack;
        if (_isStack == 1)
        {
            isStack[i] = true;
        }
        else 
        {
            isStack[i] = false;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        int input;
        cin >> input;
        if (isStack[i])
        {
            Push(input);
        }
        else 
        {
            Enqueue(input);
        }
    }

    return 0;
}
