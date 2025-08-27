/**
 * 백준 최대 힙_11279
 * 힙을 만드는데 첫 요소에 최댓값을 저장하는 최대 힙을 만든다.
 * 처음 푸는거니까 특별히 자료구조 직접 구현한다.
 * 
 * 제한사항
 *****************************************
 * 1 <= N < 100,001                      *
 * if InputValue is 0 Then remove()      *
 * else Then Push()                      *
 * InputValue is Intiger                 *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 1 + 20분
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

        // 부모가 자식보다 크면 안내려도됨
        if (arr[parent] >= arr[index])
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

        if (left < length && arr[left] > arr[largest])
        {
            largest = left;
        }
        if (right < length && arr[right] > arr[largest])
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
