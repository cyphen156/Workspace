/**
* 백준 반복문 2438 별 찍기-1
*
* 필수예제 별찍기
* 스트링을 통한 문자열합성
*
* 제한사항
*****************************************
* 0 < A <= 100							*
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
#include <string.h>

using namespace std;

int main(void)
{
	int n;
	string str = "";
	
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			str += "*";
		}
		str += "\n";
	}
	cout << str << endl;
	return 0;
}