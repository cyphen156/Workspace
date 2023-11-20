/**
*
* 가상 함수와 상속
* 
* Base / Derived/ virtual
* 
* if Derived에서 부모와 같은 이름의 함수가 있으면 
* 메서드를 베이스 코드 함수가 아닌 객체의 유형에 따라 호출 , 
* 오버라이딩 == 자식클래스가 부모 클래스의 가상함수를 
* defalut :: Derived, 업캐스팅 이후 Base호출 
* 같은 이름, 같은 포맷으로 재정의, 동적 바인딩
* 
* ==> virtual 함수는 메서드 오버라이딩을 통해 다형성을 형성한다.
* ==>>>> 그러려면 빈 메서드를 만들어 실제 구현시킬 필요가 있다..
* 
* 
* 동적 바인딩
* 
*/

//#include <iostream>
//#include <string>
//
//using	namespace std;
//
//class Base {
//public:
//	void f() {
//		cout << "Base :: f() is called" << endl;
//	}
//};
//
//class Extends : public Base{
//public:
//	void f() {
//		cout << "Extends :: f() is called" << endl;
//	}
//};
//
//class : virtual Base{
//public:
//	void f() {
//		cout << "Base :: f() is called" << endl;
//	}
//};
//
//class Extends : public Base {
//public:
//	void f() {
//		cout << "Extends :: f() is called" << endl;
//	}
//};
//
//class shape {
//
//public:
//	virtual void draw(){ };
//};
//
//class Circle : public shape {
//public:
//	virtual void draw() {  
//		cout << "circle :: Draw() is called" << endl;
//
//	};
//
//};
//
//class Rect : public shape {
//public:
//	virtual void draw() {
//		cout << "circle :: Draw() is called" << endl;
//
//	};
//
//};
//
//class Line : public shape {
//
//
//public:
//	virtual void draw() {
//		cout << "Line :: Draw() is called" << endl;
//
//	}
//};
//
//
//int main() {
//	Circle c;
//	Rect r;
//	
//	shape* ps;
//	
//	ps = &c;
//	ps->draw();
//
//	ps = &r;
//	ps->draw();
//	
//	Shape* ps2[4];
//
//	return 0;
//}