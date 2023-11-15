//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Point {
//	int x, y;
//public: 
//	Point(int x, int y) {
//		this->x = x;
//		this->y = y;
//	}
//	int getX() {
//		return this->x;
//	}
//
//	int getY() {
//		return this->y;
//	}
//protected:
//	void move(int x, int y) {
//		this->x = x;
//		this->y = y;
//	}
//};
//
//class ChildPoint : private Point {
//	string color;
//public:
//	ChildPoint(int x, int y, string str) : Point(x, y) {
//		color = str;
//	}
//
//	void setPoint(int x, int y) {
//		move(x, y);
//	}
//	
//	string getPoint() {
//		string str;
//		str = to_string(getX()) + "," + to_string(getY());
//		return str;
//	}
//
//	void setColor(string str) {
//		this->color = str;
//	}
//
//	void show() {
//		cout << color << "색으로 ("
//			<< getPoint()
//			<< ")에 위치한 점입니다." << endl;
//	}
//};
//
//int main() {
//	ChildPoint cp(5, 5, "red");
//	cp.setPoint(10, 20);
//	cp.setColor("blue");
//	cp.show();
//	return 0;
//}