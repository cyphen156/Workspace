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
 * 풀이시간 0분
 */


#include <iostream>

using namespace std;

struct Node 
{
    int _index;
    int _data;
    Node* prev;
    Node* next;
}node;

Node front;
Node back;
Node current;

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
        Push(input);
    }

    return 0;
}

void Push(int index, int data)
{
    Node* newNode = new Node();
    newNode->_index = index;
    newNode->_data = data;
    // 리스트 연결
    // 첫 요소 삽입
    current = newNode;

    if (front)
    {
        front->Prev = back;
        back->Next = front;
    }
}

int Pop()
{

}
