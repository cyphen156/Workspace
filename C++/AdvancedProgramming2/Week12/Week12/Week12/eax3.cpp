//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Shape {
//protected:
//	string name;
//	int width, height;
//
//public :
//	Shape() {
//		name = "";
//		width = 0;
//		height = 0;
//	}
//	Shape(string name, int w, int h) : Shape(){
//		this->name = name;
//		this->width = w;
//		this->height = h;
//	}
//	virtual ~Shape() {
//		cout << "~Base() is called" << endl;
//	}
//	virtual double getArea() {
//		return 0;
//	}
//
//	string getName() {
//		return name;
//	}
//
//};
//
//class Rect : public Shape {
//public:
//	Rect() : Shape() {}
//	Rect(string str, int w, int h) : Shape(str, w, h) {};
//	virtual double getArea() {
//		return width * height;
//	}
//	~Rect() {
//		cout << "~Rect() is called" << endl;
//	}
//};
//
//class Triangle : public Shape {
//public:
//	Triangle(string str, int w, int h) : Shape(str, w, h) {};
//	virtual double getArea() {
//		return width * height / 2;
//	}
//	~Triangle() {
//		cout << "~Triangle() is called" << endl;
//	}
//};
//
//int main () {
//	Shape* p[2];
//
//	p[0] = new Rect("네모 피자", 30, 40);
//	p[1] = new Triangle("세모 피자", 30, 40);
//
//	for (int i = 0; i < 2; ++i) {
//		cout << p[i]->getName() << "의 넓이는 " << p[i]->getArea() << "입니다." << endl;
//		delete(p[i]);
//	}
//
//	//소멸자 
//	Rect* pR = new Rect();
//	Shape* pB = new Shape();
//	delete(pB);
//	delete(pR);
//	return 0;
//}