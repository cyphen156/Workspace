//#include <iostream>
//#include <iomanip>
//
//using namespace std;
//
//double area(int r, double PI = 3.14f);
//int area(int w, int h);
//double area(double x, double y);
//
//// 중복 함수를 이용한 세 가지 도형의 넓이를 구하는 프로그램
//int main()
//{
//	int w, h, r;
//	double x, y;
//	cout << "사각형의 가로, 세로 길이를 입력하세요 >> ";
//	cin >> w >> h;
//	cout << "가로 " << w << ", 세로 " << h 
//		<< "인 사각형의 넓이는 " << area(w, h) << "입니다.\n" << endl;
//
//	cout << fixed << setprecision(2);;
//	cout << "삼각형의 밑변, 높이를 입력하세요 >> ";
//	cin >> x >> y;
//	cout << "밑변 " << x << ", 높이 " << y
//		<< "인 삼각형의 넓이는 " << area(x, y) << "입니다.\n" << endl;
//
//	cout << "사각형의 가로, 세로 길이를 입력하세요 >> ";
//	cin >> r;
//	cout << "반지름이 " << r << "인 원의 넓이는 " << area(r) << "입니다." << endl;
//	return 0;
//}
//
//double area(int r, double PI) {
//	return r * r * PI;
//}
//
//int area(int w, int h) {
//	return w * h;
//}
//
//double area(double x, double y) {
//	return (x * y) / 2.f;
//}