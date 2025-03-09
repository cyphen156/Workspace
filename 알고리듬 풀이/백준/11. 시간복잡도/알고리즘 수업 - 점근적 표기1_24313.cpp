/**
 * 백준 알고리즘 수업 - 점근적 표기1_24313
 * 빅 - O표기법에 대해
 * O(g(n)) = {f(n) | 모든 n ≥ n0에 대하여 f(n) ≤ c × g(n)인 양의 상수 c와 n0가 존재한다}
 * f(n) = an + b :: O(N)정의를 만족하는지 알아보자
 * f(n), c, n0가 O(n) 정의를 만족하면 1, 아니면 0을 출력한다.
 * 
 * 제한사항
 *****************************************
 * 0 <= | a |, | b | <= 100              *
 * 0 < C <= 100                          *
 * 0 < n <= 100                          *
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

 using namespace std;
 
 bool checkBigO(int a, int b, int c, int n0) {
     for (int n = n0; n <= 10000; n++) {  // n0 이상 모든 n에 대해 검사
         if (a * n + b > c * n) {
             return false;
         }
     }
     return true;
 }
 
 int main(void) {
     int a, b, c, n0;
     cin >> a >> b;
     cin >> c;
     cin >> n0;
     
     cout << (checkBigO(a, b, c, n0) ? 1 : 0) << endl;
     return 0;
 }