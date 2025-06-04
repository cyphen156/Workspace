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
 * 풀이시간 15분
 */


#include <iostream>

using namespace std;

struct Node 
{
    Node* next[26] = { nullptr }; // 다음 노드로 갈 수 있는 링크 수
    bool isEnd = false; // if length is 20 ==> true;
}node;

bool InsertData(Node* root, const string& str);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node* root = new Node();

    string str;
    cin >> str;

    int count = 0;

    for (int i = 0; i < str.length(); ++i)
    {
        for (int j = i; j < str.length(); ++j)
        {
            string partition = string(str).substr(i, j - i + 1);;
   
            if (InsertData(root, partition))
            {
                count++;
            }
        }    
    }

    cout << count << '\n';
    return 0;
}

// 이미 존재하면 return false, 새로 삽입에 성공하면 true
bool InsertData(Node* root, const string& str)
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

    if(current->isEnd != true)
    {
        current->isEnd = true;
        return true;
    }

    return false;
}
