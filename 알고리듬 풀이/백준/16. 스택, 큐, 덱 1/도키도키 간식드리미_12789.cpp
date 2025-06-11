/**
 * 백준 도키도키 간식드리미_12789
 * 현재의 줄은 Queue의 형태로 구현되어 있다. 
 * 그런데 한명 씩만 설 수 있는 임시 공간으로 한번 들어간다면 다시 현재 줄 서 있는 곳으로 돌아갈 수 없고 간식받는 곳으로만 갈 수 있다. 
 * 현재 줄 서있는 곳 : Queue -> 2 Or 3
 * 한 명씩만 설 수 있는 공간 : Stack -> 3
 * 간식받는곳 : Queue -> Escape
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 1,000                        *
 * 만약 모든 학생이 탈출할 수 있다면 Nice   *
 * 한명이라도 탈출할 수 없다면 Sad         *
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

#define MAX_SIZE 1001

static int queue[MAX_SIZE];
static int stack[MAX_SIZE];

static int top = -1;
static int head = -1;
static int tail = -1;

void Push(int value);
int Pop();
int Peek();
bool IsEmpty();
void Enqueue(int value);
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
        int input;
        cin >> input;
        Enqueue(input);
    }

    //  시작 번호
    int currentNumber = 1;

    for (int i = 0; i < N; ++i)
    {
        // 한놈 뽑아와서
        int temp = Dequeue();
        
        if (temp == currentNumber)
        {
            // 순서 맞으면 바로 간식 받음
            currentNumber++;
        }
        else
        {
            // 먼저 스택에 쌓여 있는 학생들 처리
            while (Peek() == currentNumber)
            {
                Pop();
                currentNumber++;
            }

            // 그래도 순서 안 맞으면 대기
            if (temp != currentNumber)
            {
                Push(temp);
            }
            else
            {
                currentNumber++;
            }
        }
    }

    // 스택에 남은 학생들도 순서대로 처리
    while (Peek() == currentNumber)
    {
        Pop();
        currentNumber++;
    }

    // 다 돌아봤는데 스택에 남아있는게 있다면 
    if (top == -1)
    {
        cout << "Nice" << '\n';
    }
    else
    {
        cout << "Sad" << '\n';
    }
    
    return 0;
}
void Push(int value)
{
    stack[++top] = value;
}

int Pop()
{
    if (top == -1)
    {
        return -1;
    }
    return stack[top--];
}

int Peek()
{
    return stack[top];
}

void Enqueue(int value)
{
    if (head == -1)
    {
        head++;
    }
    queue[++tail] = value;
}

int Dequeue()
{
    if (head > tail)
    {
        return -1;
    }

    return queue[head++];
}