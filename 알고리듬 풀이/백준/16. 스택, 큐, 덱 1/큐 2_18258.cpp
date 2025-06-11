/**
 * 백준 큐 2_18258
 * 큐 2_18258
 * 명령은 총 여섯 가지이다.
 * push X: 정수 X를 큐에 넣는 연산이다.
 * pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 * size: 큐에 들어있는 정수의 개수를 출력한다.
 * empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
 * front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 * back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 * 
 *  
 * 제한사항
 *****************************************
 * 0 < Command <= 2,000,000              *
 * 0 < Input <= 100,000                  *
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

#define MAX_SIZE 2000000

static int queue[MAX_SIZE];

static int head = 0;
static int tail = 0;

void Push(int value);
int Pop();
int Size();
int Empty();
int Front();
int Back();

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        string command;
        cin >> command;

        if (command == "push")
        {
            int input;
            cin >> input;
            Push(input);
        }   
        else if (command == "pop")
        {
            cout << Pop() << '\n'; 
        } 
        else if (command == "size")
        {
            cout << Size() << '\n';
        }
        else if (command == "empty")
        {
            cout << Empty() << '\n';
        }
        else if (command == "front")
        {
            cout << Front() << '\n';
        }
        else if (command == "back")
        {
            cout << Back() << '\n';
        }

        // fatal Error
        else
        {
            cout << "*****There is No Command in Program*****" << '\n';
            break;
        }
    }

    return 0;
}

void Push(int value)
{
    queue[tail++] = value;
}

int Pop()
{
    if (Empty() == 1)
    {
        return -1;
    }
    return queue[head++];
}

int Size()
{
    return (tail - head);
}

int Empty()
{
    if (head >= tail)
    {
        return 1;
    }
    return 0;
}

int Front()
{
    if (Empty() == 1)
    {
        return -1;
    }
    return queue[head];
}

int Back()
{
    if (Empty() == 1)
    {
        return -1;
    }
    return queue[tail-1];
}
