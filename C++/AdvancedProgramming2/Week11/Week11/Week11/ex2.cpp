//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class A {
//public:
//	A() {
//		cout << "default A." << endl;
//	}
//	A(int x) {
//		cout << "property A." << endl;
//	}
//};
//
//class B : public A {
//public: 
//	B() {
//		cout << "default B." << endl;
//	}
//	B(int x) : A(x) {
//		cout << "property B." << endl;
//	}
//};
//
//class TV {
//	int size;
//
//public:
//	TV() {
//		size = 20;
//	}
//	TV(int x) {
//		this->size = x;
//	}
//	int getSize() {
//		return size;
//	}
//	void setSize(int x) {
//		size = x;
//	}
//};
//
//class WideTV : public TV {
//	bool videoIn;
//public:
//	WideTV() {
//		videoIn = false;
//	}
//	WideTV(int x, bool videoIn) : TV(x) {
//		this->videoIn = videoIn;
//		// setSize(x);
//	}
//	bool getVideoIn() {
//		return this->videoIn;
//	}
//};
//
//class smartTV : WideTV {
//	string ipAddr;
//
//public:
//	smartTV() {
//		ipAddr = "iternet network not connected";
//	}
//	smartTV(string ipAddr, int size, bool videoIn) : WideTV(size, videoIn) {
//		this->ipAddr = ipAddr;
//	}
//
//	string getIpAddr() {
//		return ipAddr;
//	}
//
//	void print() {
//
//		cout << this << " :: " 
//			 << "IPAddr : " << this->getIpAddr() << "\t"
//			 << "Size : " << this->getSize() << "\t"
//			 << "VideoIn : " << this->getVideoIn() << endl;
//	}
//};
//int main() {
//	B b;
//	B c(10);
//
//	smartTV smTV;
//	smartTV smTV2("127.156.12.8", 55, true);
//
//	smTV.print();
//	smTV2.print();
//	return 0;
//}