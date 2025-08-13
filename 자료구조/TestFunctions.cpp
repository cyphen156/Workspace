#include "TestFunctions.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "#1.Linear_Data_Structures/Linear_Data_Structures.h"
#include "#2.Non_Linear_Data_Structures/Non_Linear_Data_Structures.h"

using namespace Linear_Data_Structures;
using namespace Non_Linear_Data_Structures;
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
void testNode()
{
	Node<int>* root = CreateNode<int>(1);
	AttachChild(root, CreateNode<int>(2));
	AttachChild(root, CreateNode<int>(3));
	AttachChild(root, CreateNode<int>(4));
	AttachChild(root, CreateNode<int>(5));
	std::cout << "Root Node Data: " << root->data << std::endl;
	std::cout << "Root Node Child Count: " << root->childCount << std::endl;
	for (unsigned int i = 0; i < root->childCount; ++i)
	{
		std::cout << "Child " << i + 1 << " Data: " << root->children[i]->data << std::endl;
	}

	AttachChild(root->children[0], CreateNode<int>(3));
	AttachChild(root->children[0], CreateNode<int>(6));
	std::cout << "After attaching children to first child:" << std::endl;
	for (unsigned int i = 0; i < root->children[0]->childCount; ++i)
	{
		std::cout << "Child of first child " << i + 1 << " Data: " << root->children[0]->children[i]->data << std::endl;
	}

	
	DetachAllChildren(root);
	delete root;
	std::cout << "Node Test Completed." << std::endl;
}

/// <summary>
/// Tree.h에 있는 모든 기능을 테스팅
/// 곙계테스트 포함
/// </summary>
void testTree()
{
	Tree<int> tree;
	tree.Insert(1);
	tree.Insert(2);
	tree.Insert(3, 4, true); // Insert with initial capacity and order
	tree.Insert(4, 5, false); // Insert without order
	tree.Insert(5, 6, true); // Insert with order
	std::cout << "Tree Node Count: " << tree.Size() << std::endl;
	// Pre-order traversal
	tree.PreOrderTraversal([](const Node<int>* node) {
		std::cout << "Node Data: " << node->data << std::endl;
	});
	// Level-order traversal
	tree.LevelOrderTraversal([](const Node<int>* node) {
		std::cout << "Node Data: " << node->data << std::endl;
	});
	std::cout << "Subtree Node Count: " << tree.CountSubtreeNodes(tree.GetRoot()) << std::endl;
	tree.Clear();
	std::cout << "Tree Cleared." << std::endl;
}