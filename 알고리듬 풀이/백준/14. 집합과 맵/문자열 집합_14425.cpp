/**
 * 백준 문자열 집합_14425
 * 
 * 
 * 제한사항
 *****************************************
 * 
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
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;

    vector<string> strArr[501][26];
    bool isSorted[501][26] = { 0 };

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;

        int strlen = str.length();
        char ch = str.front();
        int headIDX = ch - 'a';
        strArr[strlen][headIDX].push_back(str);
    }
  
    int count = 0;

    for (int i = 0; i < M; ++i)
    {
        string str;
        cin >> str;

        int strlen = str.length();
        char ch = str.front();
        int headIDX = ch - 'a';
        
        if (!isSorted[strlen][headIDX])
        {
            sort(strArr[strlen][headIDX].begin(), strArr[strlen][headIDX].end());
            isSorted[strlen][headIDX] = true;
        }

        if (binary_search(strArr[strlen][headIDX].begin(), strArr[strlen][headIDX].end(), str))
        {
            count++;
        }
    }

    cout << count << '\n';
    return 0;
}