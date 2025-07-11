/**
 * 백준 영단어 암기는 괴로워_20920
 * 1. 빈도수 체크 필요 -> count
 * 2. 길이 기반 정렬
 * 3. 알파벳 순 정렬
 * 입력값 M 미만인 길이를 갖는 단어의 경우 무시한다.
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 100,000                      *
 * 0 < M <= 10                           *
 * 0 < strlen <= 10                      *
 * string is lowerCase                   *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 60분
 */


#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    map<string, int> countMap;
    int maxCount = 0;

    for (int i = 0; i < N; ++i) 
    {
        string word;
        cin >> word;

        if (word.length() < M)
        {
            continue;
        }

        int& cnt = countMap[word];
        cnt++;

        if (cnt > maxCount) 
        {
            maxCount = cnt;
        }
    }

    vector<vector<vector<string>>> buckets(maxCount + 1, vector<vector<string>>(11));

    for (map<string, int>::iterator it = countMap.begin(); it != countMap.end(); ++it) 
    {
        const string& word = it->first;
        int count = it->second;
        int len = word.length();
        buckets[count][len].push_back(word);
    }

    for (int c = maxCount; c >= 1; --c) 
    {
        for (int len = 10; len >= M; --len) 
        {
            vector<string>& vec = buckets[c][len];
            if (vec.empty()) 
            {
                continue;
            }

            sort(vec.begin(), vec.end()); // 알파벳 오름차순
            
            for (size_t i = 0; i < vec.size(); ++i)
            {
                cout << vec[i] << '\n';
            }
        }
    }

    return 0;
}