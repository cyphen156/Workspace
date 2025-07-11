/**
 * 백준 인사성 밝은 곰곰이_25192
 * ENTER 이후 문자열이 처음 등장했을 때 카운트를 누적한다.
 * 만약 다음 ENTER 입력 이전에 같은 문자열이 등장했을 경우 카운트를 누적하지 않는다.
 * 해싱 또는 TRIE 자료 구조를 통한 빠른 문자열 검사가 필요하다.
 * 대소문자 구분 해야한다 -> 해시  만들어라
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 100,000                      *
 * 0 < strLen <= 20                      *
 * first Input is Always ENTER           *
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
#include <set>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    int N;
    cin >> N;

    int count = 0;
    set<string> users;

    for (int i = 0; i < N; ++i)
    {
        string input;
        cin >> input;

        if (input == "ENTER")
        {
            count += users.size();
            users = set<string>();
        }
        else 
        {
            users.insert(input);
        }
    }
    count += users.size();
    cout << count << '\n';
    return 0;
}