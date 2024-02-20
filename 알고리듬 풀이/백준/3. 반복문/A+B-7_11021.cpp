/**
* 백준 반복문 11021 A+B - 7
*
* 테스트 케이스 번호를 동시에 출력하는 덧셈프로그램
* 
* 제한사항
*****************************************
* 0 < A, B < 10							*
*****************************************
*
*
*
* 주의
*
*
* 풀이시간 1분
*/
#include <iostream>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int A, B;
		cin >> A >> B;
		cout << "Case #" << i+1 << ": " << A + B << '\n';
	}
	return 0;
}