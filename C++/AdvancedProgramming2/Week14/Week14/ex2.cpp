#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	vector<int> vc;


	while (1)
	{
		cout << "정수를 입력하세요(종료 : 0 입력) >> ";
		int input;
		cin >> input;
		if (input == 0)
		{
			cout << "프로그램 종료";
			break;
		} else 
		{
			vc.push_back(input);
			double eval = 0.f;
			vector<int>::iterator iter;
			for (iter = vc.begin(); iter != vc.end(); ++iter)
			{
				cout << *iter << '\t';
				eval += *iter;
			}
			eval /= size(vc);
			cout << "\n평균 = " << eval << '\n';
		}
	}

	return 0;
}

