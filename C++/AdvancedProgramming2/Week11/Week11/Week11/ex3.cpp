/**
* 다중 상속
* class external : base1, base2 {}
* 
* 다중 상속 수행시 멤버변수 중복 가능성 존재
* ==> 가상 상속
* 
* virtual 키워드를 사용
* 이미 상속된 변수가 존재하면 멤버변수를 먼저 상속한 멤버 변수만 생성
*/


//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Adder {
//protected:
//	int add(int a, int b) {
//		return a + b;
//	}
//};
//
//class Substract {
//protected:
//	int sub(int a, int b) {
//		return a - b;
//	}
//};
//
//class Calculator : Adder, Substract{
//public:
//	int calc(char op, int a, int b) {
//		int result = 0;
//		if (op == '+') {
//			result = a + b;
//		}
//		else if (op == '-') {
//			result = a - b;
//		}
//		return result;
//	}
//};
//int main() {
//	Calculator calc1;
//	cout << calc1.calc('+', 1, 6) << endl;
//	return 0;
//}