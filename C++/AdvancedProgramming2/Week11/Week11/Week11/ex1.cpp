///**
//* 클래스 상속
//* 
//* 중복되는 부분을 뽑아내서 부모 클래스로 구조화
//* 
//* 부 - 자
//* 
//*/
//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//// 자식클래스 : 접근지정자 부모클래스
//class Person {
//	
//public : 
//	int mValue;
//	void func() {
//		mValue = 1;
//	};
//};
//
//class Student : public Person{
//public :
//	int mValue2;
//	void function2() {
//		mValue2 = 2;
//	}
//};
//
//int main() {
//	Person p = new Student;
//	p.func();	// p.Person::mValue;
//	p.function2();
//	
//	return 0;
//}