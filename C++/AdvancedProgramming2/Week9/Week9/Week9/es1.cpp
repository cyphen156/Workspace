//#include <iostream>
//#include "sample.cpp"
//
//using namespace std;
//
//class Circle {
//	int radious;
//
//public:
//
//	Circle() {
//		radious = 1;
//		cout << radious << "default" << endl;
//	}
//
//	Circle(int r) {
//		radious =  r;
//		cout << radious << "manual" << endl;
//	}
//
//	double getArea() {
//		return 3.14 * radious * radious;
//	}
//
//	void setArea(int r) {
//		radious = r;
//	}
//	~Circle() {
//		cout << "소멸자" << radious << endl;
//	}
//};
//int main() {
//	
//	/*Circle cl[2][3] = { Circle(10), Circle(20), Circle(), Circle(10), Circle(20), Circle()};
//
//	for (int i = 0; i < 2; i++) {
//		for (int j = 0; j < 3; j++) {
//			cout << i << "행" << j << "열 = " << cl[i][j].getArea() << endl;
//		}
//	}*/
//	Circle* pcl1 = new Circle;
//	Circle* pcl2 = new Circle(30);
//
//	cout << pcl1->getArea() << endl;
//	cout << pcl2->getArea() << endl;
//
//	delete(pcl1);
//	delete(pcl2);
//	/*Sample sparr[3];
//	Sample sparr2[2][2] = { {Sample(2, 3), Sample(2, 4)}, {Sample(5), Sample()}};
//
//	for (int i = 0; i < 2; ++i) {
//		cout << sparr[i].get() << "\n";
//	}
//
//	for (int i = 0; i < 2; ++i) {
//		for (int j = 0; j < 2; ++j) {
//			cout << i << "행 " << j << "열 = " << sparr2[i][j].get() << "\n";
//		}
//	}
//
//	int* p = new int;
//
//	if (p == nullptr) {
//		cout << "Err : p is nullptr" << endl;
//		return -1;
//	}
//	*p = 5;
//
//	int n = *p;
//
//	cout << n << '\n' << *p << endl;
//
//	int k;
//	cin >> k;
//
//	int* pa = new int[k];
//	if (pa == nullptr)
//		return -1;
//	int sum = 0;
//	for (int i = 0; i < k; i++) {
//		cout << "배열 정수 입력" << '\n';
//
//		cin >> pa[i];
//		sum += pa[i];
//	}
//	for (int i = 0; i < k; i++) {
//		cout << pa[i] << '\n';
//	}
//	cout << sum/k << endl;*/
//
//
//	//while (1) {
//	//	cout << "정수 반지름 입력 if n < 0 == > return -1;" << endl;
//
//	//	int n;
//	//	cin >> n;
//	//	if (n < 0)
//	//		break;
//	//	Circle* cl1 = new Circle(n);
//	//	cout << "원의 면적" << cl1->getArea() << endl;
//	//	delete(cl1);
//
//	//}
//
//	cout << "object Array manual allocation" << endl;
//
//	Circle* paa = new Circle[3];
//
//	for (int i = 0; i < 3; ++i) {
//		paa[i].setArea(i * 10);
//		cout << paa->getArea() << endl;
//	}
//	return 0;
//}
