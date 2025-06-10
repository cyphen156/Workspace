/**
 * 백준 스택 2_28278
 *  정수 스택을 구현한 후 5가지 명령을 수행하는 프로그램을 만들어라
 * 명령어 입력은 숫자 번호로 이루어지며 기능은 다음과 같다.
 * Push 연산
 * Pop 연산
 * Count 연산
 * IsEmpty 연산
 * Peek 연산
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 1,000,000                    *
 * "다음 명령어 중 하나 이상은             *
 * 최소 한 번 이상                        *
 * 사용되어야 합니다:                      *
 * Pop, Count, IsEmpty, Peek."           *
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

#define MAX_SIZE 1000000

static int stack[MAX_SIZE];
static int top = -1;

void Push(int value);
int Pop();
int Count();
int IsEmpty();
int Peek();

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int command;
        cin >> command;
        switch (command)
        {
        case 1:
        {
            int value;
            cin >> value;
            Push(value);
            break;
        }
        case 2:
            cout << Pop() << '\n';
            break;
        case 3:
            cout << Count() << '\n';
            break;
        case 4:
            cout << IsEmpty() << '\n';
            break;
        case 5:
            cout << Peek() << '\n';
            break;
            
        default:
            cout << "Critical Error this is Wrong Command" << '\n';
            break;
        }
    }
    return 0;
}

void Push(int value)
{
    stack[++top] = value;
}
int Pop()
{
    if (IsEmpty() == 1)
    {
        return -1;
    }
    return stack[top--];
}
int Count()
{
    return top + 1;
}
int IsEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}
int Peek()
{
    if (IsEmpty() == 1)
    {
        return -1;
    }
    return stack[top];
}