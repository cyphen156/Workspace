//#include <iostream>
//
//using namespace std;
//
//class Calc {
//public:
//	virtual int add(int a, int b) = 0;
//	virtual int subtract(int a, int b) = 0;
//	virtual double average(int a[], int size) = 0;
//};
//
//class GoodCalc : public Calc {
//	int add(int a, int b) {
//		return a + b;
//	}
//
//	int subtract(int a, int b) {
//		return a - b;
//	}
//	double average(int a[], int size) {
//		double result = 0.f;
//		for (int i = 0; i < size; ++i) {
//			result += a[i];
//		}
//		return result / size;
//	}
//};
//int main() {
//	int arr[] = { 1, 2, 3, 4, 5 };
//
//	Calc* p = new GoodCalc();
//
//	cout << p->average(arr, 5) << endl;
//	return 0;
//}