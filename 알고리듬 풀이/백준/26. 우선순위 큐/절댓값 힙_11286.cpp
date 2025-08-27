/**
 * 백준 절댓값 힙_11286
 * 힙을 만드는데 첫 요소에 절댓값이 최소가 되는 자료를 
 * 맨 처음 요소로 저장하는 최소 힙을 만든다.
 * 이 문제도 이전 문제인 최소 힙에서 변형하여 사용한다.
 * 
 * 제한사항
 *****************************************
 * 1 <= N < 100,001                      *
 * if InputValue is 0 Then remove()      *
 * else Then Push()                      *
 * InputValue is Intiger                 *
 * Allow InputValue Minus                *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 1 + 10분
 */

#include <iostream>

static const int MAX_SIZE = 100001;

using namespace std;

static int N;
static int arr[MAX_SIZE] = { 0 };
static int length = 0;

void Push(int value);
void Pop();
int Top();
bool Compare(int a, int b);
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int input;
        cin >> input;

        if (input == 0)
        {
            cout << Top() << '\n';
            Pop();
        }
        else 
        {
            Push(input);
        }
    }
    return 0;
}

void Push(int value)
{
    int index = length;
    arr[length++] = value;
    
    while (index > 0)
    {
        int parent = (index - 1) / 2;

        // 부모가 자식보다 작으면 안내려도됨
        if (!Compare(arr[index], arr[parent]))
        {
            break;
        }

        // else 
        // swap
        int temp = arr[parent];
        arr[parent] = arr[index];
        arr[index] = temp;

        index = parent;
    }
}

void Pop()
{
    if (length == 0)
    {
        return;
    }

    arr[0] = arr[length-1];
    length--;

    int index = 0;
    while (1)
    {
        int left = index * 2 + 1;
        int right = left + 1;
        int largest = index;

        if (left < length && Compare(arr[left],  arr[largest]))
        {
            largest = left;
        }
        if (right < length && Compare(arr[right], arr[largest]))
        {
            largest = right;
        }

        if (largest == index)
        {
            break;
        }

        // swap
        int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;

        index = largest;
    }
}

int Top()
{
    if (length == 0)
    {
        return 0;
    }

    return arr[0];
}

// 앞 인자가 더 작은것이 참
bool Compare(int a, int b)
{
    int lValue = abs(a);
    int rValue = abs(b);

    // 만약 절댓값이 똑같다면
    if (lValue == rValue)
    {
        // 음수 리턴
        return a < b;
    }
    // 아니라면 절댓값이 작은놈
    return lValue < rValue;
}