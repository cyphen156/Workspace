#include <iostream>
#include "my_NameSpace.h";
#include <stdio.h>
#include <string>
// ���ӽ����̽���� �� ����?
using namespace std;


int resSum(int n) {
	// ����ó��
	if (n <= 0) {
		return 0;
	}

	// Ȧ��ó��
	if (n % 2 == 1) {
		return resSum(n - 1);
	}

	// ¦��ó��
	return n + resSum(n - 1);
}
int main() {
	// �ּ����� ���� ����

	//int n = 3;
	//char c = '#';

	//cout << n << c - 0 << endl;
	//// true or false �� ����ϰ� ������ 
	//cout << boolalpha;
	//cout << noboolalpha;
	//cout << sizeof(true) << '\n' << false << endl;
	// <<, >> �� c��� ���� ��Ʈ����ŷ ������������
	//  c++������ ������ �Ǿ� ���

	/*
	int width, height;
	cin >> width >> height;
	printf("%d %d", width, height);
	*/

	// ferenheit to celcious
	//float C = 0.f, f = 0.f;

	//cin >> f;
	//C = (5.f / 9) * (f - 32);
	//cout << C << endl;


	//// score to grade
	//cout << "점수를 입력해주세요. >> ";
	//int score = 0;
	//cin >> score;
	//if (score > 100 || score < 0) {
	//	cout << "잘못된 입력입니다. 프로그램을 종료합니다.'\n'";
	//	return -1;
	//}
	//else {
	//	if (score >= 90)
	//		cout << 'A';
	//	else if (score >= 80)
	//		cout << 'B';
	//	else if (score >= 70)
	//		cout << 'C';
	//	else if (score >= 60)
	//		cout << 'D';
	//	else
	//		cout << 'F';
	//}
	//cout << " 입니다." << endl;
	cout << "1부터 10사이의 정수를 입력하세요.\n";
	int len = 0;

	cin >> len;
	string s = "";
	// 피라미드 별찍기
	for (int i = 0; i < len; i++ ) {
		for (int j = len - i; j > 0; j--) {
			s += ' ';
		}
		for (int j = 0; j <= i; j++ ) {
			s += '*';			
		}
		for (int j = 0; j <= i-1; j++) {
			s += '*';
		}
		s += '\n';
	}
	cout << s << endl;

	int num = 0;
	while (true) {
		cin >> num;
		if (num == 0)
			break;

	}
	return 0;
}