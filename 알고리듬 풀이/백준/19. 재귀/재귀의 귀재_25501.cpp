/**
 * 백준 재귀의 귀재_25501
 * 팰린드롬을 기억하는가?
 * https://cyphen156.tistory.com/205
 * 이걸 재귀로 풀면 된다.
 * 팰린드롬이면 1 아니면 0을 출력하면 된다.
 * 공백 이후 함수 호출 횟수를 출력한다.
 * 
 * 제한사항
 *****************************************
 * 0 < T <= 1,000                        *
 * Alpha is UpperCase                    *
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
#include <string>

using namespace std;

int recursion(const string& str, int left, int right);
int isPalindrome(const string& str);

static int callCount = 0;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        string input;
        cin >> input;

        callCount = 0;

        cout << isPalindrome(input) << ' ' << callCount << '\n';
    }
    return 0;
}

int recursion(const string& str, int left, int right)
{
    callCount++;
    if (left >= right)
    {
        return 1;
    }
    else if ((str)[left] != (str)[right])
    {
        return 0;
    }
    else
    {
        return recursion(str, left + 1, right - 1);
    }
}

int isPalindrome(const string& str)
{
    return recursion(str, 0, str.length() - 1);
}