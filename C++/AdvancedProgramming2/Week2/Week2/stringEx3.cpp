//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main() {
//	string s1, s2 = "Game";
//	cout << "s1.size = " << s1.size() << endl;
//	cout << "s2.size = " << s2.size() << endl;
//	s1 = s2 + ' ' + "Over";
//	if (s1 == "Game Over")
//		cout << s1 << "가 맞습니다.\n" << endl;
//	// 0123456789
//	// Game over0
//	cout << s1.find("Over") << endl;	// 문자열 Over 시작 위치 반환 /// 5
//	cout << s1.find("e", 4) << endl;	// 4이후부터 e가 잇냐?
//	cout << s1[0] << endl;	// return G
//	cout << s1.substr(5, 4) << endl;	// str[5~]출력
//	printf("s1 = %s\n", s1.c_str());	// 문자열로 변환 출력
//	getline(cin, s1);
//	cout << s1 << endl;
//	return 0;
//}