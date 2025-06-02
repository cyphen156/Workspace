/**
 * 백준 서로 다른 부분 문자열의 개수_11478
 * 문자열이 주어졌을 때 부분문자열을 구하고, 중복을 제거하여 갯수를 출력하라.
 * 예를 들어, ababc의 부분 문자열은 a, b, a, b, c, ab, ba, ab, bc, aba, bab, abc, abab, babc, ababc가 있고, 서로 다른것의 개수는 12개이다.
 * 
 * 제한사항
 *****************************************
 * 0 < strlen <= 1,000                   *
 * aplha is LowerCase                    *
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
    Node* next[26] = { nullptr }; // 다음 노드로 갈 수 있는 링크 수
    bool isEnd = false; // if length is 20 ==> true;
}node;

void InsertData(Node* root, const string& str);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}

void InsertData(Node* root, const string& str)
{
    Node* current = root;

    for (char ch : str)
    {
        int index = ch - 'a';
        if (current->next[index] == nullptr)
        {
            current->next[index] = new Node();
        }
        current = current->next[index];
    }

    current->isEnd = true;
}

bool SearchData(Node* root, const string& str)
{
    Node* current = root;

    for (char ch : str)
    {
        int index = ch - 'a';
        if (current->next[index] == nullptr)
        {
            return false;
        }
        current = current->next[index];
    }

    return current->isEnd;
}
