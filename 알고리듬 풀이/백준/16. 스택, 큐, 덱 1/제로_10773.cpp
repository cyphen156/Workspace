/**
 * 백준 제로_10773
 * 0이 입력되면 Pop연산이 수행된다. 
 * 최종적으로 스택에 저장된 모든 데이터의 합을 구하라.
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 100,000                      *
 * 0 <= Input <= 1,000,000               *
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

#define MAX_SIZE 100001

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

    long long sum = 0;

    for (int i = 0; i < N; ++i)
    {
        int input;
        cin >> input;
        if(input == 0)
        {
            sum -= Pop();
        }   
        else
        {
            Push(input);
            sum += input;
        }
    }

    cout << sum << '\n';
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