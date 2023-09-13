#include <iostream>
#include <string>

using namespace std;

int main() {
	int maxLen = 0, len = 0;
	string name, maxName = "\0";
	cout << "과일 이름을 입력하세요(프로그램 종료 : 0입력)." << endl;
	while (1) {
		cout << ">> ";
		getline(cin, name);
		len = name.size();
		if (name == "0") {
			cout << "이름이 가장 긴 과일 = " + maxName + "\n프로그램 종료" << endl;
			return 0;
		}
		if (maxLen < len) {
			maxLen = len;
			maxName = name;
		}
		cout << name + "의 길이 = " + to_string(name.length()) << endl;
	}
	return 0;
}