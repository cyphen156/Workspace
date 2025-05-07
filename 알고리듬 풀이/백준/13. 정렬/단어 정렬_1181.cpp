/**
 * 백준 단어 정렬_1181
 * 길이순 정렬, 사전순 정렬
 * --> 2계층 정렬
 * 중복은 제거한다.
 * 
 * 제한사항
 *****************************************
 * 1 ≤ N ≤ 20,000                        *
 * 0 < strlen <= 50                      *
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
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;


    vector<string> strVec[51];

    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        strVec[str.length()].push_back(str);
    }

    // 정렬할래?
    for (int i = 0; i < 51; ++i)
    {
        if (strVec[i].size() != 0)
        {
            sort(strVec[i].begin(), strVec[i].end());
            strVec[i].erase(unique(strVec[i].begin(), strVec[i].end()), strVec[i].end());
            for (int j = 0; j < strVec[i].size(); ++j)
            {
                cout << strVec[i][j] << '\n';
            }
        }
    }

    return 0;
}