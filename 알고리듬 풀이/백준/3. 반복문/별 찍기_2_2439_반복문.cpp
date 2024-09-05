/**
* 백준 반복문 2439 별 찍기-2
*
* 너도알고 나도 알고 모두 아는 반복문 필수예제 별찍기 ver2
* 문자열 간격을 조정할 수 있어야한다.
* 반복문 2개를 통한 문자열제어
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
* 풀이시간 5분
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
		for (int j = n-1; j > i; --j)
		{
			str += " ";
		}
		for (int j = 0; j <= i; ++j)
		{
			str += "*";
		}
		str += "\n";
	}
	cout << str << endl;
	return 0;
}