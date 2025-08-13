#include "TestFunctions.h"
#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <algorithm>
#include "#1.Linear_Data_Structures/Linear_Data_Structures.h"
#include "#2.Non_Linear_Data_Structures/Non_Linear_Data_Structures.h"

using namespace Linear_Data_Structures;
using namespace Non_Linear_Data_Structures;

static std::vector<int> visit_log;
static void VisitCollect(const Node<int>* n) { visit_log.push_back(n->data); }
static void ResetVisit() { visit_log.clear(); }

// 유틸: 완전-작은 트리 구성
static Tree<int> BuildSmallTree()
{
    Tree<int> t(1, 3);
    Node<int>* r = t.GetRoot();

    Node<int>* n2 = t.InsertAt(r, 2, 3, true);
    Node<int>* n3 = t.InsertAt(r, 3, 3, true);
    Node<int>* n4 = t.InsertAt(n2, 4, 3, true);
    Node<int>* n5 = t.InsertAt(n2, 5, 3, true);
    Node<int>* n6 = t.InsertAt(n3, 6, 3, true);

    assert(r && n2 && n3 && n4 && n5 && n6);
    return t;
}

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
    // 1) 기본 생성/접근자
    {
        Tree<int> t;
        assert(t.Empty());
        assert(t.Size() == 0);
        assert(t.GetRoot() == nullptr);
        assert(t.GetHeight() == -1);
        assert(t.GetDegree() == 0);
    }

    // 2) 값 생성자(capacity 경계 포함)
    {
        Tree<int> t1(10, 0u);  // 0 -> 2로 보정
        assert(!t1.Empty());
        assert(t1.Size() == 1);
        assert(t1.GetRoot()->data == 10);

        Tree<int> t2(20, -5);  // <=0 -> 2로 보정
        assert(!t2.Empty());
        assert(t2.Size() == 1);
        assert(t2.GetRoot()->data == 20);
    }

    // 3) Insert 오버로드들
    {
        Tree<int> t(1, 2);
        assert(t.Size() == 1);

        // Insert(value, unsigned)
        Node<int>* a = t.Insert(2, 2, true);
        assert(a && t.Size() == 2);

        // Insert(value, int)
        Node<int>* b = t.Insert(3, 2, true);
        assert(b && t.Size() == 3);

        // Insert(node*)
        Node<int>* orphan = CreateNode<int>(99, 2);
        Node<int>* c = t.Insert(orphan, true);
        assert(c == orphan && t.Size() == 4);

        // 이미 부모를 가진 노드 삽입 거부
        assert(t.Insert(orphan, true) == nullptr);
    }

    // 4) InsertAt 오버로드들
    {
        Tree<int> t(1, 3);
        Node<int>* r = t.GetRoot();

        Node<int>* n2 = t.InsertAt(r, 2, 3, true);
        Node<int>* n3 = t.InsertAt(r, 3, 3, true);
        assert(t.Size() == 3);

        // InsertAt(node*, node*)
        Node<int>* orphan = CreateNode<int>(4, 3);
        Node<int>* n4 = t.InsertAt(n2, orphan, true);
        assert(n4 && n4->parent == n2 && t.Size() == 4);

        // target nullptr 거부
        assert(t.InsertAt(nullptr, 7, 2, true) == nullptr);
        // node nullptr 거부
        assert(t.InsertAt(n3, (Node<int>*)nullptr, true) == nullptr);
    }

    // 5) Remove 오버로드들 (BFS로 찾은 뒤 RemoveAt 호출)
    {
        Tree<int> t = BuildSmallTree(); // 1,[2,3],2->[4,5],3->[6]
        int before = t.Size();          // 6 노드

        // Remove(Node*)
        Node<int>* n3 = t.GetRoot()->children[1];
        Node<int>* detached = t.Remove(n3);
        assert(detached == n3);
        assert(t.Size() == before - 2); // n3, n6 분리
        assert(detached->parent == nullptr);

        // Remove(value)
        Node<int>* n2 = t.GetRoot()->children[0];
        Node<int>* d2 = t.Remove(2);
        assert(d2 == n2);
        assert(t.Size() == 1); // 1만 남음
        // 트리에 없는 값
        assert(t.Remove(999) == nullptr);
    }

    // 6) RemoveAt 직계 대상으로만
    {
        Tree<int> t = BuildSmallTree();
        Node<int>* r = t.GetRoot();
        Node<int>* n2 = r->children[0];

        // 잘못된 parent
        assert(t.RemoveAt((Node<int>*)nullptr, n2) == nullptr);
        // parent 불일치
        assert(t.RemoveAt(n2, r) == nullptr);

        // OK
        Node<int>* detached = t.RemoveAt(r, n2);
        assert(detached == n2);
        assert(t.Size() == 6 - 3);

        // RemoveAt(value)
        Node<int>* n3 = t.GetRoot()->children[0]; // 남은 건 3뿐
        Node<int>* d3 = t.RemoveAt(t.GetRoot(), 3);
        assert(d3 == n3);
        assert(t.Size() == 1);
    }

    // 7) RemoveAtIndex
    {
        Tree<int> t = BuildSmallTree();
        Node<int>* r = t.GetRoot();

        // 음수/범위 바깥
        assert(t.RemoveAtIndex(r, -1) == nullptr);
        assert(t.RemoveAtIndex(r, 99u) == nullptr);

        // index 1 -> 노드 3 분리
        Node<int>* n3 = r->children[1];
        Node<int>* out = t.RemoveAtIndex(r, 1u);
        assert(out == n3);
        assert(t.Size() == 4); // 1,2,4,5
    }

    // 8) Delete  메모리 해제 & 카운팅
    {
        Tree<int> t = BuildSmallTree();
        int before = t.Size(); // 6
        // Delete(value)
        t.Delete(2);
        assert(t.Size() == before - 3);

        // DeleteIndex
        t.DeleteIndex(1u);
        assert(t.Size() == 1);

        // Delete(node*)
        Node<int>* r = t.GetRoot();
        t.Delete(r); // 루트 삭제
        assert(t.Size() == 0);
        assert(t.GetRoot() == nullptr);
    }

    // 9) Clear()
    {
        Tree<int> t = BuildSmallTree();
        assert(!t.Empty());
        t.Clear();
        assert(t.Empty());
        assert(t.Size() == 0);
        assert(t.GetRoot() == nullptr);
    }

    // 10) 순회 검증
    {
        Tree<int> t = BuildSmallTree();
        ResetVisit();
        t.LevelOrderTraversal(&VisitCollect);
        assert((visit_log.size() == 6) && visit_log[0] == 1 && visit_log[1] == 2 && visit_log[2] == 3 &&
            visit_log[3] == 4 && visit_log[4] == 5 && visit_log[5] == 6);

        ResetVisit();
        t.PreOrderTraversal(&VisitCollect);
        assert(visit_log.size() == 6 && visit_log[0] == 1 && visit_log[1] == 2);

        ResetVisit();
        t.PostOrderTraversal(&VisitCollect);
        assert(visit_log.size() == 6 && visit_log.back() == 1);
    }

    // 11) GetHeight / GetDegree / GetDepth
    {
        Tree<int> t = BuildSmallTree();
        Node<int>* r = t.GetRoot();
        assert(t.GetHeight() >= 0);
        assert(t.GetDegree() >= 0);
        assert(t.GetDepth(r) == 0);
        assert(t.GetDepth(r->children[0]) == 1);
    }

    // 12) 복사/이동/대입
    {
        Tree<int> t1 = BuildSmallTree();
        Tree<int> t2(t1);
        assert(t2.Size() == t1.Size());

        Tree<int> t3;
        t3 = t1;
        assert(t3.Size() == t1.Size());

        Tree<int> t4(std::move(t1));
        assert(t4.Size() == 6);
        assert(t1.Size() == 0);

        Tree<int> t5;
        t5 = std::move(t2);
        assert(t5.Size() == 6);
        assert(t2.Size() == 0);
    }

    // 13) 경계/방어 로직
    {
        Tree<int> t = BuildSmallTree();
        Node<int>* r = t.GetRoot();
        t.DeleteAt((Node<int>*)nullptr, r->children[0]);
        assert(t.Size() == 6);

        assert(t.RemoveIndex(-1) == nullptr);
        assert(t.RemoveIndex(999u) == nullptr);

        assert(t.Remove((Node<int>*)nullptr) == nullptr);

        t.Delete((Node<int>*)nullptr);
        assert(t.Size() == 6);
    }

    std::cout << "All Tree<T> tests passed.\n";
}