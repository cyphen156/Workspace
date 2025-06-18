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

struct Node 
{
    int _index;
    int _data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;
Node* current = nullptr;

void Push(int index, int data);
int Pop();

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
        Push(i, input);
    }

    current = head;

    for (int i = 0; i < N; ++i)
    {
        cout << Pop() << " ";
    }

    return 0;
}

void Push(int index, int data)
{
    Node* newNode = new Node();
    newNode->_index = index;
    newNode->_data = data;

    if (!head) 
    {
        head = newNode;
        head->next = head;
        head->prev = head;
    } 
    else 
    {
        Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
}

int Pop()
{
    int move = current->_data;
    int result = current->_index + 1;

    if (current->next == current)
    {
        delete current;
        current = nullptr;
    }
    else
    {
        // 현재 선택된놈 빼버리기
        Node* temp = current;
        current->prev->next = current->next;
        current->next->prev = current->prev;

        if (move < 0)
        {
            move = -move;
            for (int i = 0; i < move; ++i)
            {
                current = current->prev;
            }
        }
        else
        {
            for (int i = 0; i < move; ++i)
            {
                current = current->next;
            }
        }
        delete temp;
    }

    return result;
}
