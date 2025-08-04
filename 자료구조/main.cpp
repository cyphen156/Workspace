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
/// 

int main(int argc, char* argv[])
{
	// Stack example usage
	/*
	Stack<int> stack;
	stack.Push(10);
	stack.Push(20);
	std::cout << "Stack top: " << stack.Top() << '\n'
		<< "Stack Size : " << stack.Size() << std::endl;
	stack.Pop();
	std::cout << "After Pop, Stack top: " << stack.Top() << '\n'
		<< "Stack Size : " << stack.Size() << std::endl;
	stack.Clear();
	std::cout << "Stack is Cleared: " << std::endl;

	Stack<std::string> stringStack;
	*/

	// queue example usage
	/*
	Queue<int> queue;
	queue.Push(30);
	queue.Push(40);
	std::cout << "Queue front: " << queue.Front() << '\n'
		<< "Queue Size : " << queue.Size() << std::endl;
	queue.Pop();
	std::cout << "After Pop, Queue front: " << queue.Front() << '\n'
		<< "Queue Size : " << queue.Size() << std::endl;
	queue.Clear();
	std::cout << "Queue is Cleared: " << std::endl;

	Queue<std::string> stringQueue;
	stringQueue.Push("Hello");
	stringQueue.Push("World");
	std::cout << "Queue Back: " << stringQueue.Back() << '\n'
		<< "Queue Size : " << stringQueue.Size() << std::endl;
	stringQueue.Clear();
	std::cout << "String Queue is Cleared: " << std::endl;
	*/

	return 0;
}