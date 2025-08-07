#include "TestFunctions.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "#1.Linear_Data_Structures/Linear_Data_Structures.h"
#include "#2.Non-linear_Data_Structures/Non-linear_Data_Structures.h"

using namespace Linear_Data_Structures;
/// <summary>
/// 테스트 함수 모음집
/// </summary>

// Stack example usage
void testStack()
{
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
}

// queue example usage
void testQueue()
{
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
}

// Deque example usage
void testDeque()
{
	Deque<int> deque;
	deque.PushFront(50);
	deque.PushBack(60);
	std::cout << "Deque Front: " << deque.Front() << '\n'
		<< "Deque Back: " << deque.Back() << '\n'
		<< "Deque Size : " << deque.Size() << std::endl;
	deque.PopFront();
	std::cout << "After PopFront, Deque Front: " << deque.Front() << '\n'
		<< "Deque Size : " << deque.Size() << std::endl;
	deque.PopBack();
	std::cout << "After PopBack, Deque Back: " << deque.Back() << '\n'
		<< "Deque Size : " << deque.Size() << std::endl;
	deque.Clear();
	std::cout << "Deque is Cleared: " << std::endl;

	Deque<std::string> stringDeque;
	stringDeque.PushFront("Deque");
	stringDeque.PushBack("Example");
	std::cout << "String Deque Front: " << stringDeque.Front() << '\n'
		<< "String Deque Back: " << stringDeque.Back() << '\n'
		<< "String Deque Size : " << stringDeque.Size() << std::endl;

	stringDeque.PopFront();
	std::cout << "After PopFront, String Deque Front: " << stringDeque.Front() << '\n'
		<< "String Deque Size : " << stringDeque.Size() << std::endl;
}

// PriorityQueue example usage
void testPriorityQueue()
{
	PriorityQueue<int> priorityQueue;
	priorityQueue.Push(1, 100);
	priorityQueue.Push(2, 200);
	priorityQueue.Push(3, 300);
	std::cout << "Priority Queue Top: " << priorityQueue.Top() << '\n'
		<< "Priority Queue Size : " << priorityQueue.Size() << std::endl;
	priorityQueue.Pop();
	std::cout << "After Pop, Priority Queue Top: " << priorityQueue.Top() << '\n'
		<< "Priority Queue Size : " << priorityQueue.Size() << std::endl;
	priorityQueue.Clear();
	std::cout << "Priority Queue is Cleared: " << std::endl;
	PriorityQueue<std::string> stringPriorityQueue;
	stringPriorityQueue.Push(1, "High");
	stringPriorityQueue.Push(2, "Medium");
	stringPriorityQueue.Push(3, "Low");
	std::cout << "String Priority Queue Top: " << stringPriorityQueue.Top() << '\n'
		<< "String Priority Queue Size : " << stringPriorityQueue.Size() << std::endl;
	stringPriorityQueue.Clear();
	std::cout << "String Priority Queue is Cleared: " << std::endl;
}

void testChunkBasedDeque()
{
}

void testAdaptorStack()
{
}

void testAdaptorQueue()
{
}

void testAdaptorPriorityQueue()
{
}

// Non-linear Data Structures Test
void testTree()
{

}