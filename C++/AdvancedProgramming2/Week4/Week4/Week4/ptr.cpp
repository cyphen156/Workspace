//#include <iostream>
//#include <cstdlib>
//using namespace std;
//
//int main() {
//	// int* ptr == 포인터 변수 선언
//	// cout *ptr == 값 가져오기
//	//int n[10];
//	//for (int i = 0; i < 10; i++) {
//	//	n[i] = i;
//	//}
//	//int* nptr = n;
//
//	//char ch = 'a';
//	//char* chptr = &ch;
//
//	////*nptr = 25;
//	//*chptr = '\0';
//
//	//cout << *nptr << '\t' << '1' << *chptr << '1' << endl;
//
//	//for (int i = 0; i < 10; i++) {	
//	//	*nptr *= 2;
//	//	cout << n[i] << endl;
//	//	nptr++;
//	//}
//
//	// new/delete == malloc/free();
//	// but new/delete == class based 
//
//	/*double* dblPI = new double;
//	*dblPI = 3.14;
//	cout << sizeof(dblPI) << '\n';
//	double* dblPI_c = (double*)malloc(1 * sizeof(double));
//	*dblPI_c = 3.14;
//	cout << sizeof(dblPI_c) << '\n';
//
//	cout << "_msize of dblPI: " << _msize(dblPI) << " bytes" << endl;
//	cout << "_msize of dblPI_c: " << _msize(dblPI_c) << " bytes" << endl;*/
//
//	char* p = new char[10];
//	char** q = &p;
//
//	p[0] = 'A';
//	// 왜 배열이 통째로 출력되는가?
//	cout << &p << '\t' << p << '\n'
//		<< &q << '\t' << q << endl;
//	return 0;
//}