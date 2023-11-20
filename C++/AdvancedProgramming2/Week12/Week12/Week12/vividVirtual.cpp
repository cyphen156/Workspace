//#include <iostream>
//
//using namespace std;
//
//class Shape {
//public: 
//	virtual void draw() = 0;
//};
//
//class Circle : public Shape {
//public:
//	string isToString() {
//		return "Circle Object";
//	}
//};
//
//class Rect : public Shape {
//public:
//	virtual void draw() {
//		cout << "not meta class" << endl;
//	}
//};
//int main() {
//
//	// reasons why
//	// virtual void draw() = 0;
//	// solution ==> vivid virtual method override
//	Shape sp;
//	Circle cl;
//
//	Rect rt;
//	return 0;
//}