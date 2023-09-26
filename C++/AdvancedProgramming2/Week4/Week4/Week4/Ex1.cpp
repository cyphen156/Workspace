//#include <iostream>
//
//using namespace std;
//
//typedef struct {
//	// 원시 클래스
//
//};
//
//int main() {
//	const int DIM = 10;
//	int size = 20; 
//
//	int arr[10] = { 0 };
//	char s[50];
//	float R[DIM] = { 0.f };
//	// s 초기화
//	for (int i = 0; i < 50; i++) {
//		s[i] = '\0';
//	}
//	for (int i = 0; i < 10; i++) {
//		arr[i] = i;
//		cout << arr[i] << '\t' << R[i] << '\n';
//	}
//
//	int num = 10;
//	cout << "&num = " << &num << '\n';
//
//	cout << "&s = " << &s;
//	cout << endl;
//
//	// 주소 저장변수 == ptr
//	int* ptr = &num;
//
//	int* ptr2 = ptr;
//
//	cout << "&ptr = " << &ptr << '\n'
//		<< "ptr = " << ptr << endl;
//
//	cout << "ptr2 = " << ptr2;
//	return 0;
//}