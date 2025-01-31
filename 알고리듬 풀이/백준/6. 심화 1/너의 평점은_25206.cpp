/**
 * 백준 너의 평점은_25206
 * 학점 계산 프로그램 만들기
 * 
 * 제한사항
 *****************************************
 * if grade is p Exacpt Value
 * 0 < subject <= 20
 * 1 ≤ 과목명의 길이 ≤ 50
 * 과목명은 알파벳 대소문자 또는 숫자로만 이루어져 있으며, 띄어쓰기 없이 주어진다.
 * 입력으로 주어지는 모든 과목명은 서로 다르다.
 * 학점은 1.0,2.0,3.0,4.0중 하나이다.
 * 등급은 A+,A0,B+,B0,C+,C0,D+,D0,F,P중 하나이다.
 * 적어도 한 과목은 등급이 P가 아님이 보장된다.
 *****************************************
 *
 *
 *
 * 주의
 * 
 * 
 * 풀이시간 20분
 */
#include <iostream>
#include <unordered_map>

using namespace std;

const unordered_map<string, float> uMap_grades
{
    {"A+", 4.5f},
    {"A0", 4.f},
    {"B+", 3.5f}, 
    {"B0", 3.f},
    {"C+", 2.5f}, 
    {"C0", 2.f},
    {"D+", 1.5f}, 
    {"D0", 1.f},
    {"F", 0.f}, 
};

int main(void)
{
    float sum = 0.f;
    float cnt = 0.f;
    double avg = 0.;
    for (int i = 0; i < 20; ++i)
    {
        string subject;
        string grade;
        float credit = 0.f;
        cin >> subject >> credit >> grade;
        if (grade == "P")
        {
            continue;
        }
        sum += credit * uMap_grades.at(grade);
        cnt += credit; 
    }
    avg = (double)sum / cnt;
    cout.precision(7);
    cout << avg << endl;
    return 0;
}