//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Power {
//	int kick;
//	int punch;
//
//public:
//	Power() {
//		this->kick = 0;
//		this->punch = 0;
//	}
//	
//	Power(int kick, int punch) {
//		this->kick = kick;
//		this->punch = punch;
//	}
//
//	Power operator+ (Power op2) {
//		Power temp;
//		temp.kick = this->kick + op2.kick;
//		temp.punch = this->punch + op2.punch;
//		return temp;
//	};
//
//	Power& operator+= (Power op2) {
//		this->kick += op2.kick;
//		this->punch += op2.punch;
//		return *this;
//	};
//	Power operator+ (int op2) {
//		Power temp;
//		temp.kick = kick + op2;
//		temp.punch = punch + op2;
//
//		return temp;
//	}
//	//전위증감
//	Power operator++ () {
//		kick++;
//		punch++;
//
//		return *this;
//	}
//
//	//후위증감
//	Power operator++ (int x) {
//		Power temp = *this;
//		kick++;
//		punch++;
//		
//		return temp;
//	}
//	bool operator== (Power op2) {
//		
//		if (this->kick == op2.kick && this->punch == op2.punch)
//			return true;
//		else
//			return false;
//	};
// 
//  // 전역함수 작성 (// defalut 매개변수가 없음 -> 인자 전달 필요 ///// 외부 전달 객체이기 때문에 private 변수 사용 불가 --> friend 한정자 사용해야함)
//	Power operator + (Power op1, Power op2) {
//
//  }
//	void show() {
//		cout << this->kick << ", " << this->punch << endl;
//	}
//};
//
// 
// 
 // 기본 데이터 타입을 default 피연산자로 전달시 반드시 전역함수로 구현
// 
//int main() {
//	Power a(0, 3);
//
//	Power b(1, 4);
//
//	Power c;
//
//	c = a + b;
//
//	c.show();
//
//	b = a + 2;
//
//	b.show();
//	return 0;
//}