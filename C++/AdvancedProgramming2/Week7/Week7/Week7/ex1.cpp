//#include <iostream>
//
//using namespace std;
//
//class Circle {
//public: 
//	int radious;
//	double getArea();
//	
//	// 생성자
//	Circle() {
//		radious = 1;
//		cout << "Circle() 기본 생성자\n" 
//			<< "반지름  = " << radious << endl;
//	}
//	// => 
//	Circle() : Circle(1) {};
//
//	Circle(double f) {
//		radious = f;
//		cout << "Circle() 오버로딩 생성자" << endl;
//	}
//
//	// 위임 생성자
//	Circle() : Circle(1) {
//		radious = 1;
//	}
//};
//
//double Circle::getArea() {
//	double result = 0.f;
//	result = 3.14 * radious * radious;
//
//	return result;
//};
//
//int main() {
//	int a, b;
//
//	Circle newCircle;
//	cin >> a >> b;
//	newCircle.radious = a;
//
//	cout << newCircle.getArea();
//	
//	Circle pizza(30);
//	return 0;
//}