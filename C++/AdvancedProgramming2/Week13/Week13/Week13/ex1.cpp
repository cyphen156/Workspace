/**
* Template
* 중복 함수의 여러가지 겹치는 부분들을 찍어내기 위한 디자인 패턴
* 
* 동일한 부분은 Template, 달라지는 부분만 떼어내서 파편화
* 제네릭 타입 선언 =>  ptr을 통한 메서드 생성
* 
* 템플릿은 반드시 함수를 가시적으로 명시해야함
* 안하면 컴파일 에러 발생
* 
*/

//#include <iostream>
//
//using namespace std;
//
//template <class T>
//
//void myswap(T& a, T& b) {
//	T temp;
//	temp = a;
//	a = b;
//	b = temp;
//}
//
//class Circle {
//	int radius;
//public: 
//	Circle() {
//		radius = 1;
//	}	
//	Circle(int i) {
//		this->radius = radius;
//	}
//
//class Circle {
//	double radius;
//public:
//	Circle() {
//		radius = 1;
//	}
//	Circle(int i) {
//		this->radius = radius;
//	}
//	int getRadius {}
//};
//int main() {
//	int a = 4, b = 5;
//
//	myswap(a, b);
//
//	cout << "a : " << a << "b : " << b;
//	
//	return 0;
//}