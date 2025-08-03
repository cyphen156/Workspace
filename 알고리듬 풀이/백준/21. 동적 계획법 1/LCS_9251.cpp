/**
 * 백준 LCS_9251
 * Longest Common Subsequence는 가장 긴 공통 부분 수열을 찾는 것이다.
 * 두 수열이 주어졌을 때 모든 부분 수열 일치하는 가장 긴 수열을 찾으면 된다.
 * 
 * 
 * 제한사항
 *****************************************
 * Alpha is Always UpperCase             *
 * 0 < strLength <= 1,000                *
 *****************************************
 *
 *
 *
 * 주의
 * 문제 풀이 제한시간이 매우 짧다. 
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 1 + 30분
 */


#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_SIZE 1001

using namespace std;

static string str1, str2;
static vector<vector<int>> lcsTable(MAX_SIZE, vector<int>(MAX_SIZE, 0));

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    str1.reserve(MAX_SIZE);
    str2.reserve(MAX_SIZE);

    cin >> str1 >> str2;
    
    for (int i = 1; i <= str1.length(); ++i)
    {
        for (int j = 1; j <= str2.length(); ++j)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                lcsTable[i][j] = lcsTable[i-1][j-1] + 1;
                continue;
            }
            lcsTable[i][j] = max(lcsTable[i-1][j], lcsTable[i][j-1]);
        }
    }

    cout << lcsTable[str1.length()][str2.length()] << '\n';
    return 0;
}