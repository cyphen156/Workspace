#include <iostream>

using namespace std;

class Point {
	// default private
private:
	int x, y;

public:
	Point();

	// Circle() : Circle(1) {};
	// Point() : Point(1) {};
	Point(int x, int y);

	void show();
};

// default generator 위임 생성실행
Point::Point() : Point(0, 0) { }
Point::Point(int a, int b) {
	x = a;
	y = b;
}

void Point::show() {
	cout << x << y << endl;
}

class Rectangle {
	int x, y;

public:
	Rectangle();
	Rectangle(int a);
	Rectangle(int a, int b);

	// 생성자는 스택의 형태로 쌓여있음
	// -> 소멸할때 LIFO의 순서로 소멸
	~Rectangle();

	int isSquare();

	// new / delete 키워드를 통한 객체 동적 생성
};

Rectangle::Rectangle(int a, int b) {
	x = a;
	y = b;
};
Rectangle::Rectangle(int a) : Rectangle(a, a) {};
Rectangle::Rectangle() : Rectangle(1, 1) {};

Rectangle::~Rectangle() {};

int Rectangle::isSquare() {
	if (x == y)
		return 1;
}
int main() {
	Point origin;

	Point target(10, 20);

	origin.show();
	target.show();

	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(3);

	if (rect1.isSquare() == 1)
		cout << "rect1은 정사각형입니다." << endl;
	if (rect2.isSquare() == 1)
		cout << "rect2은 정사각형입니다." << endl;
	if (rect3.isSquare() == 1)
		cout << "rect3은 정사각형입니다." << endl;

	
	return 0;
}