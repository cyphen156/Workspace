/**
* 백준 1차원 배열 1546 평균
* 과목수 N개의 시험 성적 중 최댓값을 찾고 나머지 하위 점수들을 X*100/M한 값으로 고치는 것
* 
* 제한사항
*****************************************
* 0 < N <= 1,000                        *
* 0 <= INPUT <= 100                     *
* at least one score is greater than 0  *
*****************************************
*
*
*
* 주의
* 출력값 오차범위가 존재한다. 절대오차 또는 상대오차 10**-2라면 소숫점 이하 두자리 까지 출력하라는 소리다.
*
* 풀이시간 5분
*/
#include <iostream>

using namespace std;

int main() {
    int N, MAX = 0;
    float sum = 0;

    cin >> N;

    float* arr = new float[N];

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
        if (MAX < (int)arr[i])
        {
            MAX = (int)arr[i];
        }
    }

    for (int i = 0; i < N; ++i)
    {
        arr[i] /= (MAX);
        arr[i] *= 100;
        sum += arr[i];
    }
    cout << sum / N << "\n";
    
    delete[] arr;
    return 0;
}