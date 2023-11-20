//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Base {
//public:
//	virtual void f() {
//		cout << "Called :: Base" << endl;
//	}
//};
//
//class Derived : public Base {
//public:
//	virtual void f() {
//		cout << "Called :: Derived" << endl;
//	}
//};
//
//class GrandDerived : public Derived {
//public:
//	virtual void f() {
//		cout << "Called :: GD" << endl;
//	}
//};
//
//
//class Shape {
//public:
//	virtual void draw() {
//		cout << "Called :: GD" << endl;
//	}
//};
//
//class Circle : public Shape {
//public:
//	virtual void draw() {
//		Shape::draw();
//		cout << "Called :: GD" << endl;
//	}
//};
//int main() {
//	GrandDerived gd;
//
//	GrandDerived* gp;
//	Derived* dp;
//	Base* bp;
//
//	bp = dp = gp = &gd;
//
//	Circle cl;
//	Shape* pShape = &cl;
//	Circle* pCl;
//
//	pShape->draw();
//	return 0;
//}