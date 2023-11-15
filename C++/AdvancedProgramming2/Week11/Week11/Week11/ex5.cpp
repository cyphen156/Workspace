#include <iostream>
#include <string>

using namespace std;

class Point {
	int x, y;
public:
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int getX() {
		return this->x;
	}

	int getY() {
		return this->y;
	}
protected:
	void move(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class ChildPoint : private Point {
	string color;
public:

	ChildPoint() : Point(0, 0){ 
		color = "black";
	}

	ChildPoint(int x, int y) : Point(x, y) {
		color = "red";
	}

	void setPoint(int x, int y) {
		move(x, y);
	}

	string getPoint() {
		string str;
		str = to_string(getX()) + "," + to_string(getY());
		return str;
	}

	void setColor(string str) {
		this->color = str;
	}

	void show() {
		cout << color << " 색으로 ("
			<< getPoint()
			<< ")에 위치한 점입니다." << endl;
	}
};

int main() {
	ChildPoint zeroPoint;
	zeroPoint.show();
	
	ChildPoint cp2(5, 5);
	cp2.setPoint(20, 40);
	cp2.show();
	return 0;
}