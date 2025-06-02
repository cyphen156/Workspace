/**
 * 백준 듣보잡_1674
 * 두가지 데이터가 주어진다. 
 * 1. 들어보지 못한 사람
 * 2. 본적 없는 사람
 * 이 둘을 조합하여 둘 모두에 해당하는 데이터를 추출하라.
 * 메모리는 충분하지만 시간 여유는 적다
 * 중복이 없다고 했으니 20개의 노드 링크 끝에는 언제나 한개의 데이터만이 존재하거나 존재하지 않는 부울 형으로 존재
 * Trie 노드 해싱
 * 
 * 첫번째 데이터 셋에 대해서만 저장을 진행
 * 두번째 데이터 셋은 검색용으로 사용

 * 
 * 제한사항
 *****************************************
 * alpha is LowerCase                    *
 * 0 < strLength <= 20                   *
 * 0 < N, M <= 500,000                   *
 * There is no Duplicate Case            *
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
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node 
{
    Node* next[26] = { nullptr }; // 다음 노드로 갈 수 있는 링크 수
    bool isEnd = false; // if length is 20 ==> true;
}node;

void InsertData(Node* root, const string& str);

bool SearchData(Node* root, const string& str);


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str;
    cin >> str;

    Node root = Node();

    for (int i = 0; i < str.length(); ++i)
    {
        // 부분 문자열의 길이를 측정 (1, 2, 3 ... strlen)
        for (int j = 0; j < str.length() ++j)
        {
            // 부분 문자열
            InsertData(&root, str[i]);
        }
    }

    cout << count << '\n';

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
