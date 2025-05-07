/**
 * 백준 숫자 카드_10815
 * N개의 카드 중 M개의 입력에 대해 존재 유무를 찾는 프로그램 작성하기
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 500,000                      *
 * -100,000 <= NInput ≤ 100,000          *
 * 0 < M <= 500,000                      *
 * -100,000 <= MInput ≤ 100,000          *
 * return Value (Yes :: 1, No :: 0)      *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 5분
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;

    vector<int> NInputs;
    for (int i = 0; i < N; ++i)
    {
        int input;
        cin >> input;
        NInputs.push_back(input);
    }

    sort(NInputs.begin(), NInputs.end());

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int input;
        cin >> input;
        if (binary_search(NInputs.begin(), NInputs.end(), input))
        {
            cout << 1; 
        }
        else
        {
            cout << 0;
        }
        cout << ' ';
    }
    cout << endl;
    return 0;
}