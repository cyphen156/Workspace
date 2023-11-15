///**
//* 클래스 상속
//*
//* 중복되는 부분을 뽑아내서 부모 클래스로 구조화
//*
//* 부 - 자
//* 함수 뿐 아니라 멤버변수 또한 호출 가능
//* // 접근지정자 private ==> 부모클래스 멤버변수 호출 불가
//* 
//* get, set메서드 사용
//* 
//* 부모클래스 -> 자식클래스 대입시 일반적으로 불가능 
//* => 자식 클래스 포인터 형식으로 형변환 필요
//* 
//* 자식클래스 -> 부모 클래스 포인터 대입시 가능
//* but 자식클래스의 변수에는 접근 불가능해짐
//* 
//* 자식-부모-자식 캐스팅 가능
//* up down up
//* 부모-자식-부모의 캐스팅은 불가능
//* down up down 불가능
//* 
//* 
//* //* 부모 자식 사이의 접근지정자 정리
//* 
//* 부모 클래스에서 private를 통해 선언된 변수들은
//* 자식클래스에서 상속받고 있다 하더라도 접근 불가능, set, get메서드를 통해서 접근해야 함
//* -> 그러나 메모리 공간에 변수가 존재하지 않는다는 의미는 아니다.
//* 가령 자바의 경우 자식 클래스로 선언할 때 부모 클래스에 set, get메서드가 존재하지 않을 때 변수를 자동으로 기본값으로 
//* 초기화함, C++의 경우 부모 클래스의 변수공간이 선언되고 그 곳에 garbage value가 들어감
//* 
//* 자식 클래스의 인스턴스 생성시 매개변수 유무에 상관없이 부모 클래스의 기본 생성자 호출
//* -> 명시적으로 부모클래스의 매개변수 생성자 호출가능
//* B(int x) : A(x)
//*/
//
//#include <iostream>
//
//using namespace std;
//
//class Point {
//	int x, y;
//public:
//	void set(int x, int y) {
//		this->x = x;
//		this->y = y;
//	}
//
//	void show() {
//		cout << "(" << "X " << x << ", " << y << ")" << endl;
//	}
//};
//
//class ColorPoint : public Point {
//	string str;
//
//public :
//	void setColor(string str) {
//		this->str = str;
//	}
//	void setColorPoint(string str, int x, int y) {
//
//	}
//};
//int main() {
//	ColorPoint cp;
//
//
//	ColorPoint* pDer;
//
//	pDer = &cp;
//
//	Point g;
//	Point* pg = &g;
//
//	pDer = (ColorPoint*)pg;
//
//	return 0;
//}