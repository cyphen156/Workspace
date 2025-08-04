#include <iostream>
#include <string>
#include "#1.Linear_Data_Structures/Linear_Data_Structures.h"
#include "#2.Non-linear_Data_Structures/Non-linear_Data_Structures.h"

using namespace Linear_Data_Structures;
/// <summary>
/// 메인 애플리케이션 진입점 클래스
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns></returns>
int main(int argc, char* argv[])
{
	Stack<int> stack;
	stack.Push(10);
	stack.Push(20);
	std::cout << "Stack top: " << stack.Peek() << '\n'
		<< "Stack Size : " << stack.Size() << std::endl;
	stack.Pop();
	std::cout << "After Pop, Stack top: " << stack.Peek() << '\n'
		<< "Stack Size : " << stack.Size() << std::endl;
	stack.Clear();
	std::cout << "Stack is Cleared: " << std::endl;

	Stack<std::string> stringStack;

	return 0;
}