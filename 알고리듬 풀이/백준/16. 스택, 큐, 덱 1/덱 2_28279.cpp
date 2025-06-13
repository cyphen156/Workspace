/**
 * 백준 덱 2_28279
 * 정수를 저장하는 덱을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
 * 
 * 명령은 총 여덟 가지이다.
 * 
 * 1 X: 정수 X를 덱의 앞에 넣는다. (1 ≤ X ≤ 100,000)
 * 2 X: 정수 X를 덱의 뒤에 넣는다. (1 ≤ X ≤ 100,000)
 * 3: 덱에 정수가 있다면 맨 앞의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
 * 4: 덱에 정수가 있다면 맨 뒤의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
 * 5: 덱에 들어있는 정수의 개수를 출력한다.
 * 6: 덱이 비어있으면 1, 아니면 0을 출력한다.
 * 7: 덱에 정수가 있다면 맨 앞의 정수를 출력한다. 없다면 -1을 대신 출력한다.
 * 8: 덱에 정수가 있다면 맨 뒤의 정수를 출력한다. 없다면 -1을 대신 출력한다.
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 1,000,000                    *
 * 0 < Input <= 100,000                  *
 * 출력을 요구하는 명령은 하나 이상 주어진다 *
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

using namespace std;

#define MAX_SIZE 2000001

static int deque[MAX_SIZE];
static int front = MAX_SIZE / 2;
static int back = front;

void EnqueueFront(int value);
void EnqueueBack(int value);
int DequeueFront();
int DequeueBack();
int Size();
int IsEmpty();
int PeekFront();
int PeekEnd();

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

        switch(command)
        {
            case 1:
            {
                int input;
                cin >> input;

                EnqueueFront(input);
                break;
            }
            case 2:
            {
                int input;
                cin >> input;

                EnqueueBack(input);
                break;
            }   
            case 3:
                cout << DequeueFront() << '\n';
                break;
            case 4:
                cout << DequeueBack() << '\n';
                break;
            case 5:
                cout << Size() << '\n';
                break;
            case 6:
                cout << IsEmpty() << '\n';
                break;
            case 7:
                cout << PeekFront() << '\n';
                break;
            case 8:
                cout << PeekEnd() << '\n';
                break;
            default:
                break;
        }
    }

    return 0;
}

void EnqueueFront(int value)
{
    if (front == 0)
    {
        return;
    }
    deque[--front] = value;
}

void EnqueueBack(int value)
{
    if (back == MAX_SIZE-1)
    {
        return;
    }
    deque[back++] = value;
}

int DequeueFront()
{
    if (IsEmpty() == 1)
    {
        return -1;
    }
    return deque[front++];
}

int DequeueBack()
{
    if (IsEmpty() == 1)
    {
        return -1;
    }
    return deque[--back];
}

int Size()
{
    return back - front;
}

int IsEmpty()
{
    if (front == back)
    {
        return 1;
    }
    return 0;
}

int PeekFront()
{
    if (IsEmpty() == 1)
    {
        return -1;
    }
    return deque[front];
}

int PeekEnd()
{
    if (IsEmpty() == 1)
    {
        return -1;
    }
    return deque[back-1];
}
