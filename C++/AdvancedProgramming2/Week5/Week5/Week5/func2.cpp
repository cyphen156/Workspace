//#include <iostream>
//#include <cstdio>
//
//using namespace std;
//
//int bigger(int a, int b) {
//	if (a > b)
//		return a;
//	else
//		return b;
//}
//
//bool dividedBy3(int n) {
//	if (n % 3 == 0)
//		return 1;
//	else
//		return 0;
//}
//
//int main() {
//	int a, b, n;
//
//	// 참조 변수
//	// 일반적인 변수와 메모리를 공유하는 변수
//	// 다른 점은 함수 호출의 매개변수로 전달 시 포인터 형식으로 전달되는 변수
//	// 일반 변수는 copy and paste 되어 지역 변수로 재생성되기 때문에 같은 이름으로 리턴해도
//	// 값이 변하지 않음
//	int& ra = a;
//
//	cin >> a >> b;
//	n = bigger(a, b);
//	cout << a << "중" << b << "중 큰 값은 " << n << "입니다.\n";
//	if (dividedBy3(n) == 1)
//		cout << n << "은 " << "3의 배수입니다.\n";
//	else 
//		cout << n << "은 " << "3의 배수가 아닙니다.\n";
//	printf("%d", printf("\0"));
//	return 0;
//}