#pragma once

#include "../0_Node/Node.h"
#include "../../#1.Linear_Data_Structures/1_Stack/Stack.h"
#include "../../#1.Linear_Data_Structures/2_1_Queue/Queue.h"

namespace Non_Linear_Data_Structures
{
	// Tree class definition
	template <typename T>
	class Tree
	{
	public:
		// Default constructor Empty Tree
		inline Tree()
			: root(nullptr)
			, nodeCount(0)
		{}

		// Constructor with root node
		inline Tree(const Node<T>* node)
			: root(const_cast<Node<T>*>(node))
			, nodeCount(0)
		{
			if (root == nullptr)
			{
				return;
			}

			nodeCount = 1;
		}
		
		// Constructor with value
		// This constructor creates a tree with a single root node containing the given value
		// 한글설명 : 이 생성자는 주어진 값을 가진 단일 루트 노드로 트리를 만듭니다.
		inline Tree(const T& value, unsigned int initialCapacity = 2u)
			: root(nullptr)
			, nodeCount(1)
		{
			if (initialCapacity == 0)
			{
				initialCapacity = 2u; // Ensure a minimum initial capacity
			}
			root = CreateNode<T>(value, initialCapacity);
		}

		// Overloaded constructor with value and initial capacity
		inline Tree(const T& value, int initialCapacity)
			: root(nullptr)
			, nodeCount(1)
		{
			if (initialCapacity <= 0)
			{
				initialCapacity = 2; // Ensure a minimum initial capacity
			}
			root = CreateNode<T>(value, static_cast<unsigned int>(initialCapacity));
		}
		
		// DeepCopy constructor
		// This constructor creates a deep copy of the tree
		// It allocates new memory for the root node and all its children
		// 한글설명 : 이 생성자는 트리의 깊은 복사본을 만듭니다.
		// 루트 노드와 모든 자식 노드에 대해 새로운 메모리를 할당합니다.
		inline Tree(const Tree& other)
			: root(nullptr), nodeCount(0)
		{
			CopyFrom(other);
		}
		
		// move constructor
		inline Tree(Tree&& other) noexcept
			: root(other.root), nodeCount(other.nodeCount)
		{
			other.root = nullptr;
			other.nodeCount = 0;
		}

		// Destructor
		inline ~Tree()
		{ 
			Clear();
		}
		
		// Assignment operator
		inline Tree& operator=(const Tree& other)
		{
			if (this != &other)
			{
				Clear();
				CopyFrom(other);
			}
			return *this;
		}

		// Move assignment operator
		inline Tree& operator=(Tree&& other) noexcept
		{
			if (this != &other)
			{
				Clear();
				root = other.root;
				nodeCount = other.nodeCount;
				other.root = nullptr;
				other.nodeCount = 0;
			}
			return *this;
		}

		// modified methods
		Node<T>* Insert(Node<T>* node, bool order = false);							// Insert a node into the tree
		Node<T>* Insert(const T& value												// Insert a value into the tree
					, unsigned int initialCapacity = 2
					, bool order = false);													
		Node<T>* Insert(const T& value												// Insert a value into the tree
					, int initialCapacity
					, bool order = false);		

		Node<T>* InsertAt(Node<T>* target, Node<T>* node, bool order = false);		// Insert a node at a specific position
		Node<T>* InsertAt(Node<T>* target											// Insert a value at a specific position with order
					, const T& value
					, unsigned int initialCapacity = 2
					, bool order = false);
		Node<T>* InsertAt(Node<T>* target											// Insert a value at a specific position
					, const T& value
					, int initialCapacity
					, bool order = false);
		
		Node<T>* Remove(Node<T>* node);												// Remove a node from the tree
		Node<T>* Remove(const T& value);											// Remove a value from the tree
		Node<T>* RemoveIndex(const int index);										// Remove a node using index from the tree
		Node<T>* RemoveIndex(const unsigned int index);								// Remove a node using index from the tree
		
		Node<T>* RemoveAt(Node<T>* parent, Node<T>* node);							// Remove a node at a specific position
		Node<T>* RemoveAt(Node<T>* parent, const T& value);							// Remove a value at a specific position
		Node<T>* RemoveAtIndex(Node<T>* parent, const int index);					// Remove a node at a specific position using index
		Node<T>* RemoveAtIndex(Node<T>* parent, const unsigned int index);			// Remove a node at a specific position using index

		void Delete();																// Delete the entire tree
		void Delete(Node<T>* node);													// Delete a node from the tree
		void Delete(const T& value);												// Delete a value from the tree
		void DeleteIndex(const int index);											// Delete a node using index from the tree
		void DeleteIndex(const unsigned int index);									// Delete a node using index from the tree

		void DeleteAt(Node<T>* parent, Node<T>* node);								// Delete a node at a specific position
		void DeleteAt(Node<T>* parent, const T& value);								// Delete a value at a specific position
		void DeleteAtIndex(Node<T>* parent, const int index);						// Delete a node at a specific position using index
		void DeleteAtIndex(Node<T>* parent, const unsigned int index);				// Delete a node at a specific position using index
		
		void Clear();								// Clear the tree
	
		// accessor methods
		Node<T>* GetRoot();							// Get the root node of the tree
		const Node<T>* GetRoot() const;				// Get the root node of the tree (const version)
		int GetHeight() const;						// Get the height of the tree
		int GetHeight(const Node<T>* node) const;	// Get the height of a specific node
		int GetDegree() const;						// Get the degree of the root node
		int GetDegree(const Node<T>* node) const;	// Get the degree of a specific node
		int GetDepth(const Node<T>* node) const;	// Get the depth of a specific node
		bool Empty() const;							// Check if the tree is empty
		int Size() const;							// Get the size of the tree

		int CountSubtreeNodes(const Node<T>* n);	// Count the number of nodes in a subtree rooted at node n

		// Tree traversal methods
		// These methods take a function pointer to visit each node
		// DFS (Depth-First Search) Traversal methods
		void PreOrderTraversal(void (*visit)(const Node<T>*)) const;	// Pre-order traversal == Root -> Left -> Right
		void InOrderTraversal(void (*visit)(const Node<T>*)) const;		// In-order traversal == Left -> Root -> Right remains
		void PostOrderTraversal(void (*visit)(const Node<T>*)) const;	// Post-order traversal == Left -> Right -> Root

		// BFS (Breadth-First Search) Traversal methods
		void LevelOrderTraversal(void (*visit)(const Node<T>*)) const;	// Level-order traversal == Level by Level
	
	private:
		Node<T>* root;		// Root node of the tree
		int nodeCount;		// Count of nodes in the tree

		inline void CopyFrom(const Tree& other)
		{
			if (other.root == nullptr)
			{
				root = nullptr;
				nodeCount = 0;
				return;
			}

			// 루트 생성
			root = CreateNode<T>(other.root->data, other.root->capacity);
			nodeCount = 1;

			// other: BFS로 순회, this: 동일 구조 재구성
			Linear_Data_Structures::Queue<const Node<T>*> otherQueue;
			Linear_Data_Structures::Queue<Node<T>*> copyQueue;

			otherQueue.Push(other.root);
			copyQueue.Push(root);

			while (!otherQueue.Empty())
			{
				const Node<T>* ocur = otherQueue.Front(); otherQueue.Pop();
				Node<T>* current = copyQueue.Front(); copyQueue.Pop();

				for (unsigned int i = 0; i < ocur->childCount; ++i)
				{
					const Node<T>* otherCurrent = ocur->children[i];
					if (otherCurrent == nullptr) continue;

					Node<T>* child = CreateNode<T>(otherCurrent->data, otherCurrent->capacity);
					// order=true: 단순 append(혹은 네 AttachChild가 정렬 고려하면 그 정책 유지)
					if (AttachChild<T>(current, child, /*order=*/true))
					{
						++nodeCount;
						otherQueue.Push(otherCurrent);
						copyQueue.Push(child);
					}
					// Attach 실패 시: 정책상 생략(메모리 부족 같은 예외 상황). 필요하면 assert나 실패 처리 추가 가능.
				}
			}
		}
	};

	/// <summary>
	/// 트리에 새 노드를 삽입합니다.
	/// 루트부터 시작해서 자식의 빈 자리를 찾아서 삽입합니다.
	/// 만약 빈자리가 없다면, 트리의 레벨을 확장하고 새 노드를 삽입합니다.
	/// </summary>
	/// <typeparam name="T">트리와 노드에 저장되는 데이터의 타입입니다.</typeparam>
	/// <param name="node">트리에 삽입할 노드입니다. nullptr이면 삽입이 수행되지 않습니다.</param>
	/// <param name="order">삽입 시 사용할 정렬 기준입니다.</param>
	/// <returns>삽입된 노드의 포인터를 반환합니다. 삽입에 실패하면 nullptr를 반환합니다.</returns>
	template <typename T>
	inline Node<T>* Tree<T>::Insert(Node<T>* node, bool order)
	{
		// 노드가 없거나 이미 부모를 가지고 있다면 삽입할 수 없습니다.
		if (node == nullptr || node->parent != nullptr)
		{
			return nullptr;
		}

		// 트리가 비어있는 경우, 새 노드를 루트로 설정합니다.
		if (root == nullptr)
		{
			root = node;
			root->parent = nullptr;
			nodeCount = 1;
			return root;
		}

		// 트리가 비어있지 않은 경우, 루트부터 시작하여 노드를 삽입합니다.
		// 순회 방식은 너비 우선 탐색(BFS)으로 구현합니다.
		Linear_Data_Structures::Queue<Node<T>*> queue;
		queue.Push(root);
		Node<T>* current;

		while (!queue.Empty())
		{
			current = queue.Front();
			queue.Pop();
			// 현재 노드에 자식 노드가 있는지 확인합니다.
			if (current->childCount < current->capacity)
			{
				// 현재 노드에 자식 노드를 추가할 수 있는 공간이 있다면
				if (AttachChild<T>(current, node, order))
				{
					nodeCount++;
					return node; // 삽입된 노드를 반환합니다.
				}
			}
			// 현재 노드의 자식들을 큐에 추가합니다.
			for (unsigned int i = 0; i < current->childCount; ++i)
			{
				if (current->children[i] != nullptr)
				{
					queue.Push(current->children[i]);
				}
			}
		}

		// 트리의 모든 노드를 순회했지만 빈 자리를 찾지 못한 경우
		// 그런 경우는 없다
		// 만약 있다면 버그다

		return nullptr;
	}

	template <typename T>
	inline Node<T>* Tree<T>::Insert(const T& value
		, unsigned int initialCapacity
		, bool order)
	{
		if (initialCapacity == 0)
		{
			initialCapacity = 2;
		}

		// 트리가 비어있는 경우, 새 노드를 루트로 설정합니다.
		if (root == nullptr)
		{
			root = CreateNode<T>(value, initialCapacity);
			if (root != nullptr)
			{
				root->parent = nullptr;
				nodeCount = 1;
			}
			return root;
		}

		// 트리가 비어있지 않은 경우, 루트부터 시작하여 노드를 삽입합니다.
		// 순회 방식은 너비 우선 탐색(BFS)으로 구현합니다.
		Linear_Data_Structures::Queue<Node<T>*> queue;
		queue.Push(root);
		Node<T>* current;
		while (!queue.Empty())
		{
			current = queue.Front();
			queue.Pop();
			// 현재 노드에 자식 노드가 있는지 확인합니다.
			if (current->childCount < current->capacity)
			{
				// 현재 노드에 자식 노드를 추가할 수 있는 공간이 있다면
				Node<T>* newNode = AttachChild<T>(current, value, initialCapacity, order);
				if (newNode != nullptr)
				{
					nodeCount++;
					return newNode; // 삽입된 노드를 반환합니다.
				}
			}
			// 현재 노드의 자식들을 큐에 추가합니다.
			for (unsigned int i = 0; i < current->childCount; ++i)
			{
				if (current->children[i] != nullptr)
				{
					queue.Push(current->children[i]);
				}
			}
		}
		// 트리의 모든 노드를 순회했지만 빈 자리를 찾지 못한 경우
		// 그런 경우는 없다
		// 만약 있다면 버그다
		return nullptr; // 삽입에 실패한 경우 nullptr 반환
	}
	
	template <typename T>
	inline Node<T>* Tree<T>::Insert(const T& value
		, int initialCapacity
		, bool order)
	{
		if (initialCapacity <= 0)
		{
			initialCapacity = 2; // Ensure a minimum initial capacity
		}

		if (root == nullptr)
		{
			root = CreateNode<T>(value, initialCapacity);
			if (root != nullptr)
			{
				root->parent = nullptr;
				nodeCount = 1;
			}
			return root; 
		}
		// 트리가 비어있지 않은 경우, 루트부터 시작하여 노드를 삽입합니다.
		// 순회 방식은 너비 우선 탐색(BFS)으로 구현합니다.
		Linear_Data_Structures::Queue<Node<T>*> queue;
		queue.Push(root);
		Node<T>* current;
		while (!queue.Empty())
		{
			current = queue.Front();
			queue.Pop();
			// 현재 노드에 자식 노드가 있는지 확인합니다.
			if (current->childCount < current->capacity)
			{
				// 현재 노드에 자식 노드를 추가할 수 있는 공간이 있다면
				Node<T>* newNode = AttachChild<T>(current, value, initialCapacity, order);
				if (newNode != nullptr)
				{
					nodeCount++;
					return newNode; // 삽입된 노드를 반환합니다.
				}
			}
			// 현재 노드의 자식들을 큐에 추가합니다.
			for (unsigned int i = 0; i < current->childCount; ++i)
			{
				if (current->children[i] != nullptr)
				{
					queue.Push(current->children[i]);
				}
			}
		}
		return nullptr; 

	}

	/// <summary>
	/// 트리에서 지정된 노드에 새 자식 노드를 삽입합니다.
	/// 자식 노드의 수용력이 부족한 경우, 자동으로 확장합니다.
	/// </summary>
	/// <typeparam name="T">노드에 저장되는 데이터의 타입입니다.</typeparam>
	/// <param name="target">노드를 삽입할 기준이 되는 대상 노드입니다.</param>
	/// <param name="node">삽입할 노드입니다.</param>
	/// <param name="order">자식 노드를 삽입할 위치(순서)를 지정하는 불리언 값입니다.</param>
	/// <returns>삽입에 성공하면 새로 삽입된 노드의 포인터를 반환하고, 실패하면 nullptr를 반환합니다.</returns>
	template <typename T>
	inline Node<T>* Tree<T>::InsertAt(Node<T>* target, Node<T>* node, bool order)
	{
		if (target == nullptr || node == nullptr)
		{
			return nullptr;
		}

		if (AttachChild<T>(target, node, order))
		{
			nodeCount++;
			return node; // Return the newly inserted node
		}
		
		// If insertion failed, return nullptr
		return nullptr;
	}

	template <typename T>
	inline Node<T>* Tree<T>::InsertAt(Node<T>* target
		, const T& value
		, unsigned int initialCapacity
		, bool order)
	{
		if (target == nullptr)
		{
			return nullptr;
		}
		
		Node<T>* newNode = AttachChild<T>(target, value, initialCapacity, order);

		if (newNode != nullptr)
		{
			nodeCount++;
		}

		return newNode; 
	}

	template <typename T>
	inline Node<T>* Tree<T>::InsertAt(Node<T>* target
		, const T& value
		, int initialCapacity
		, bool order)
	{
		if (target == nullptr)
		{
			return nullptr;
		}

		Node<T>* newNode = AttachChild<T>(target, value, initialCapacity, order);
		if (newNode != nullptr)
		{
			nodeCount++;
		}
		return newNode;
	}

	/// <summary>
	/// 트리에서 지정된 노드를 찾아 제거합니다
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="node"></param>
	/// <returns></returns>
	template <typename T>
	inline Node<T>* Tree<T>::Remove(Node<T>* node)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		
		if (node == nullptr || node->parent == nullptr)
		{
			return nullptr;
		}

		// 트리가 비어있지 않은 경우, 루트부터 시작하여 노드를 삽입합니다.
		// 순회 방식은 너비 우선 탐색(BFS)으로 구현합니다.
		Linear_Data_Structures::Queue<Node<T>*> queue;
		queue.Push(root);
		Node<T>* current;
		
		while (!queue.Empty())
		{
			current = queue.Front();
			queue.Pop();
			// 현재 노드가 제거할 노드와 일치하는지 확인합니다.
			if (current == node)
			{
				return RemoveAt(current->parent, current);
			}
			// 현재 노드의 자식들을 큐에 추가합니다.
			for (unsigned int i = 0; i < current->childCount; ++i)
			{
				if (current->children[i] != nullptr)
				{
					queue.Push(current->children[i]);
				}
			}
		}
		// 트리의 모든 노드를 순회했지만 제거할 노드를 찾지 못한 경우
		return nullptr; // 제거할 노드를 찾지 못한 경우 nullptr 반환
	}

	template <typename T>
	inline Node<T>* Tree<T>::Remove(const T& value)
	{
		if (root == nullptr)
		{
			return nullptr;
		}

		// 트리가 비어있지 않은 경우, 루트부터 시작하여 노드를 삽입합니다.
		// 순회 방식은 너비 우선 탐색(BFS)으로 구현합니다.
		Linear_Data_Structures::Queue<Node<T>*> queue;
		queue.Push(root);
		Node<T>* current;

		while (!queue.Empty())
		{
			current = queue.Front();
			queue.Pop();
			// 현재 노드가 제거할 노드와 일치하는지 확인합니다.
			if (current->data == value)
			{
				return RemoveAt(current->parent, value);
			}
			// 현재 노드의 자식들을 큐에 추가합니다.
			for (unsigned int i = 0; i < current->childCount; ++i)
			{
				if (current->children[i] != nullptr)
				{
					queue.Push(current->children[i]);
				}
			}
		}
		// 트리의 모든 노드를 순회했지만 제거할 노드를 찾지 못한 경우
		return nullptr; // 제거할 노드를 찾지 못한 경우 nullptr 반환
	}

	// overloaded RemoveIndex methods
	template <typename T>
	inline Node<T>* Tree<T>::RemoveIndex(const int index)
	{
		return RemoveIndex(static_cast<unsigned int>(index));
	}
	
	/// <summary>
	/// 트리에서 지정된 인덱스에 해당하는 노드를 제거합니다.
	/// 루트부터 시작하여 인덱스에 해당하는 노드를 찾아 제거합니다.
	/// 레벨 순회 방식으로 구현되어 있습니다.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="index"></param>
	/// <returns></returns>
	template <typename T>
	inline Node<T>* Tree<T>::RemoveIndex(const unsigned int index)
	{
		if (root == nullptr || index >= static_cast<unsigned int>(nodeCount))
		{
			return nullptr;
		}

		// 트리가 비어있지 않은 경우, 루트부터 시작하여 노드를 삽입합니다.
		// 순회 방식은 너비 우선 탐색(BFS)으로 구현합니다.
		Linear_Data_Structures::Queue<Node<T>*> queue;
		queue.Push(root);
		Node<T>* current;
		unsigned int currentIndex = 0;
		while (!queue.Empty())
		{
			current = queue.Front();
			queue.Pop();
			if (currentIndex == index)
			{
				return RemoveAt(current->parent, current);
			}
			currentIndex++;
			for (unsigned int i = 0; i < current->childCount; ++i)
			{
				if (current->children[i] != nullptr)
				{
					queue.Push(current->children[i]);
				}
			}
		}
		return nullptr; 
	}

	/// <summary>
	/// 특정 부모 노드에서 지정된 노드를 제거합니다.
	/// 부모 노드는 이미 특정되어 있어야 한다.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="parent"></param>
	/// <param name="node"></param>
	/// <returns></returns>
	template <typename T>
	inline Node<T>* Tree<T>::RemoveAt(Node<T>* parent, Node<T>* node)
	{
		if (node == nullptr) 
		{
			return nullptr;
		}
		
		if (parent == nullptr && node != root)
		{
			return nullptr;
		}

		if (node != root && node->parent != parent)
		{
			return nullptr;
		}

		Node<T>* target = DetachChild<T>(parent, node);     // 1) 분리 먼저
		if (target == nullptr)
		{
			return nullptr;
		}

		// 노드가 제거된 후 남는 노드 수를 재계산합니다.
		int removed = CountSubtreeNodes(target);
		
		// 음수가 발생한다면 에러입니다.
		int temp = nodeCount - removed;

		if (temp < 0)
		{
			// 노드가 제거된 후 남는 노드 수가 음수라면
			// 다시 부모 노드에 붙입니다.
			AttachChild<T>(parent, target, /*order=*/true);
			return nullptr;
		}

		nodeCount = temp;
		return target;
	}

	template <typename T>
	inline Node<T>* Tree<T>::RemoveAt(Node<T>* parent, const T& value)
	{
		if (parent == nullptr)
		{
			return nullptr;
		}

		Node<T>* target = DetachChild<T>(parent, value);
		if (target == nullptr)
		{
			return nullptr;
		}

		int removed = CountSubtreeNodes(target);

		int temp = nodeCount - removed;

		if (temp < 0)
		{
			AttachChild<T>(parent, target, /*order=*/true);
			return nullptr;
		}

		nodeCount = temp;
		return target;
	}
		
	/// <summary>
	/// 특정 부모 노드에서 지정된 인덱스에 해당하는 노드를 제거합니다.
	/// 항상 직계 자식 노드만을 대상으로 합니다.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="parent"></param>
	/// <param name="index"></param>
	/// <returns></returns>
	template <typename T>
	inline Node<T>* Tree<T>::RemoveAtIndex(Node<T>* parent, const int index)
	{
		if (parent == nullptr || index < 0 || index >= static_cast<int>(parent->childCount))
		{
			return nullptr;
		}
		
		Node<T>* target = DetachChildAtIndex<T>(parent, index);

		if (target == nullptr)
		{
			return nullptr;
		}

		int removed = CountSubtreeNodes(target);

		int temp = nodeCount - removed;

		if (temp < 0)
		{
			AttachChild<T>(parent, target, /*order=*/true);
			return nullptr;
		}

		nodeCount = temp;
		return target;
	}

	template <typename T>
	inline Node<T>* Tree<T>::RemoveAtIndex(Node<T>* parent, const unsigned int index)
	{
		if (parent == nullptr || index >= parent->childCount)
		{
			return nullptr;
		}
		
		Node<T>* target = DetachChildAtIndex<T>(parent, index);

		if (target == nullptr)
		{
			return nullptr;
		}

		int removed = CountSubtreeNodes(target);

		int temp = nodeCount - removed;

		if (temp < 0)
		{
			AttachChild<T>(parent, target, /*order=*/true);
			return nullptr;
		}

		nodeCount = temp;
		return target;
	}

	/// <summary>
	/// 트리를 삭제합니다.
	/// </summary>
	template <typename T>
	inline void Tree<T>::Delete()
	{
		delete this; // 트리 객체를 삭제합니다.
	}

	/// <summary>
	/// 트리에서 지정된 노드를 삭제합니다.
	/// Remove와 달리, 이 함수는 노드와 그 자식 노드를 모두 메모리에서 제거합니다.
	/// </summary>
	/// <typeparam name="T">트리와 노드에 저장되는 데이터의 타입입니다.</typeparam>
	/// <param name="node">삭제할 노드를 가리키는 포인터입니다.</param>
	template <typename T>
	inline void Tree<T>::Delete(Node<T>* node)
	{
		// 트리에서 지정된 노드를 찾아 삭제합니다.
		if (node == nullptr)
		{
			return; // 노드가 nullptr이면 아무 작업도 하지 않습니다.
		}
		
		// 트리가 비어있지 않은 경우, 루트부터 시작하여 노드를 삽입합니다.
		// 순회 방식은 너비 우선 탐색(BFS)으로 구현합니다.
		Linear_Data_Structures::Queue<Node<T>*> queue;
		queue.Push(root);
		Node<T>* current;
		while (!queue.Empty())
		{
			current = queue.Front();
			queue.Pop();
			// 현재 노드가 삭제할 노드와 일치하는지 확인합니다.
			if (current == node)
			{
				DeleteAt(current->parent, current);
				return; // 삭제 후 함수 종료
			}
			// 현재 노드의 자식들을 큐에 추가합니다.
			for (unsigned int i = 0; i < current->childCount; ++i)
			{
				if (current->children[i] != nullptr)
				{
					queue.Push(current->children[i]);
				}
			}
		}
	}

	template <typename T>
	inline void Tree<T>::Delete(const T& value)
	{
		// 트리에서 지정된 값을 가진 노드를 찾아 삭제합니다.
		if (root == nullptr)
		{
			return; // 트리가 비어있으면 아무 작업도 하지 않습니다.
		}

		// 트리가 비어있지 않은 경우, 루트부터 시작하여 노드를 삽입합니다.
		// 순회 방식은 너비 우선 탐색(BFS)으로 구현합니다.
		Linear_Data_Structures::Queue<Node<T>*> queue;
		queue.Push(root);
		Node<T>* current;
		while (!queue.Empty())
		{
			current = queue.Front();
			queue.Pop();
			// 현재 노드가 삭제할 노드와 일치하는지 확인합니다.
			if (current->data == value)
			{
				DeleteAt(current->parent, current);
				return; // 삭제 후 함수 종료
			}
			// 현재 노드의 자식들을 큐에 추가합니다.
			for (unsigned int i = 0; i < current->childCount; ++i)
			{
				if (current->children[i] != nullptr)
				{
					queue.Push(current->children[i]);
				}
			}
		}
	}
	
	// overloaded DeleteIndex methods
	template <typename T>
	inline void Tree<T>::DeleteIndex(const int index)
	{
		DeleteIndex(static_cast<unsigned int>(index));
	}

	/// <summary>
	/// 트리의 전체 노드중 지정된 인덱스에 해당하는 노드를 삭제합니다.
	/// BFS(너비 우선 탐색) 방식으로 트리를 순회하여 인덱스에 해당하는 노드를 찾아 삭제합니다.
	/// 전체 노드 수를 기준으로 인덱스를 계산합니다.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="index"></param>
	template <typename T>
	inline void Tree<T>::DeleteIndex(const unsigned int index)
	{
		if (root == nullptr || index >= static_cast<unsigned int>(nodeCount))
		{
			return;
		}
		// 트리가 비어있지 않은 경우, 루트부터 시작하여 노드를 삽입합니다.
		// 순회 방식은 너비 우선 탐색(BFS)으로 구현합니다.
		Linear_Data_Structures::Queue<Node<T>*> queue;
		queue.Push(root);
		Node<T>* current;
		unsigned int currentIndex = 0;
		
		while (!queue.Empty())
		{
			current = queue.Front();
			queue.Pop();
			if (currentIndex == index)
			{
				DeleteAt(current->parent, current);
				return; // 삭제 후 함수 종료
			}
			currentIndex++;
			for (unsigned int i = 0; i < current->childCount; ++i)
			{
				if (current->children[i] != nullptr)
				{
					queue.Push(current->children[i]);
				}
			}
		}
	}

	template <typename T>
	inline void Tree<T>::DeleteAt(Node<T>* parent, Node<T>* node)
	{
		if (node == nullptr)
		{
			return; // 잘못된 입력
		}

		if (parent == nullptr && node != root)
		{
			return;
		}

		// 노드가 루트가 아니면서 부모를 갖지 않은 경우
		if (node != root && node->parent != parent)
		{
			return; 
		}

		int removed = CountSubtreeNodes(node);
		int temp = nodeCount - removed;

		if (temp < 0)
		{
			return;
		}

		nodeCount = temp;
		DeleteChild<T>(parent, node);

		if (node == root)
		{
			root = nullptr;
		}
	}

	template <typename T>
	inline void Tree<T>::DeleteAt(Node<T>* parent, const T& value)
	{
		if (parent == nullptr)
		{
			return; // 잘못된 입력
		}

		Node<T>* target = nullptr;
		for (int i = 0; i < parent->childCount; ++i)
		{
			if (parent->children[i] != nullptr && parent->children[i]->data == value)
			{
				target = parent->children[i];
				break; 
			}
		}

		int removed = CountSubtreeNodes(target);
		int temp = nodeCount - removed;

		if (temp < 0)
		{
			return;
		}

		nodeCount = temp;
		DeleteChild<T>(parent, value);
	}

	template <typename T>
	inline void Tree<T>::DeleteAtIndex(Node<T>* parent, const int index)
	{
		if (parent == nullptr || index < 0 || index >= static_cast<int>(parent->childCount))
		{
			return; // 잘못된 입력
		}

		int removed = CountSubtreeNodes(parent->children[index]);
		int temp = nodeCount - removed;
		if (temp < 0)
		{
			return; // 노드 제거 후 남는 노드 수가 음수인 경우
		}

		nodeCount = temp;

		DeleteChildAtIndex<T>(parent, index);
	}

	template <typename T>
	inline void Tree<T>::DeleteAtIndex(Node<T>* parent, const unsigned int index)
	{
		if (parent == nullptr || index >= parent->childCount)
		{
			return; // 잘못된 입력
		}
		int removed = CountSubtreeNodes(parent->children[index]);
		int temp = nodeCount - removed;
		if (temp < 0)
		{
			return; // 노드 제거 후 남는 노드 수가 음수인 경우
		}
		nodeCount = temp;
		DeleteChildAtIndex<T>(parent, index);
	}

	template <typename T>
	inline void Tree<T>::Clear()
	{
		if (root == nullptr)
		{ 
			nodeCount = 0; 
			return; 
		}

		Delete(root);
		root = nullptr; // 트리의 루트를 nullptr로 설정하여 트리를 비웁니다.
		nodeCount = 0; // 노드 수를 0으로 초기화합니다.
	}
	template <typename T>
	inline Node<T>* Tree<T>::GetRoot()
	{
		return root;
	}
	
	template <typename T>
	inline const Node<T>* Tree<T>::GetRoot() const
	{
		return root;
	}

	template <typename T>	
	inline int Tree<T>::GetHeight() const
	{
		return GetHeight(root);
	}

	template <typename T>	
	inline int Tree<T>::GetHeight(const Node<T>* node) const
	{
		if (node == nullptr)
		{
			return -1; // Height of an empty node is -1
		}

		int maxHeight = -1;
		for (unsigned int i = 0; i < node->childCount; ++i)
		{
			const Node<T>* child = node->children[i];
			if (child)
			{
				int h = GetHeight(child);

				if (h > maxHeight)
				{
					maxHeight = h;
				}
			}
		}

		return maxHeight + 1; // Add 1 for the current node
	}

	template <typename T>	
	inline int Tree<T>::GetDegree() const
	{
		if (root == nullptr)
		{
			return 0;
		}

		int maxDegree = 0;

		Linear_Data_Structures::Queue<const Node<T>*> queue;
		queue.Push(root);
		while (!queue.Empty())
		{
			const Node<T>* current = queue.Front();
			queue.Pop();
			int degree = static_cast<int>(current->childCount);
			if (degree > maxDegree)
			{
				maxDegree = degree; 
			}

			// Add children to the queue for further processing
			for (unsigned int i = 0; i < current->childCount; ++i)
			{
				if (current->children[i] != nullptr)
				{
					queue.Push(current->children[i]);
				}
			}
		}
		return maxDegree; // Return the maximum degree found
	}

	template <typename T>	
	inline int Tree<T>::GetDegree(const Node<T>* node) const
	{
		return node ? static_cast<int>(node->childCount) : 0;
	}

	template <typename T>	
	inline int Tree<T>::GetDepth(const Node<T>* node) const
	{
		if (node == nullptr)
		{
			return -1;
		}
		int depth = 0;
		const Node<T>* current = node->parent;

		while (current != nullptr)
		{
			depth++;
			current = current->parent;
		}
		return depth; // Return the depth of the node
	}

	template <typename T>	
	inline bool Tree<T>::Empty() const	
	{
		return root == nullptr; // If root is null, the tree is empty
	}

	template <typename T>	
	inline int Tree<T>::Size() const
	{
		return nodeCount;
	}

	/// <summary>
	/// 
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="n"></param>
	/// <returns></returns>
	template <typename T>
	inline int Tree<T>::CountSubtreeNodes(const Node<T>* node)
	{
		if (node == nullptr)
		{
			return 0;
		}

		int count = 0;
		Linear_Data_Structures::Queue<const Node<T>*> queue;
		queue.Push(node);
		while (!queue.Empty()) 
		{
			const Node<T>* current = queue.Front();
			queue.Pop();
			++count;
			for (unsigned i = 0; i < current->childCount; ++i)
			{
				if (current->children[i])
				{
					queue.Push(current->children[i]);
				}
			}
		}

		return count;
	}

	/// <summary>
	/// 트리의 모든 노드를 전위 순회(Pre-order Traversal) 방식으로 방문합니다.
	/// </summary>
	/// <typeparam name="T">트리 노드에 저장되는 데이터의 타입입니다.</typeparam>
	/// <param name="visit">각 노드를 방문할 때 호출되는 함수 포인터입니다. 인자로 현재 노드의 포인터(const Node<T>*)를 받습니다.</param>
	template <typename T>
	inline void Tree<T>::PreOrderTraversal(void (*visit)(const Node<T>*)) const
	{
		if (root == nullptr || visit == nullptr)
		{
			return;
		}

		Linear_Data_Structures::Stack<const Node<T>*> stack;
		stack.Push(root);

		while (!stack.Empty())
		{
			const Node<T>* current = stack.Top();
			stack.Pop();
			visit(current); // Visit the current node

			// Push children onto the stack in reverse order to maintain left-to-right order
			for (int i = static_cast<int>(current->childCount) - 1; i >= 0; --i)
			{
				const Node<T>* child = current->children[i];
				if (child != nullptr)
				{
					stack.Push(child);
				}
			}
		}
	}

	/// <summary>
	/// Warning : This function only works for binary trees.
	/// 경고 : 이 함수는 이진 트리에만 사용하시오.
	/// 이진 트리의 중위 순회(In-order traversal)를 수행하며, 각 노드에 대해 지정된 함수를 호출합니다.
	/// </summary>
	/// <typeparam name="T">트리 노드에 저장되는 데이터의 타입입니다.</typeparam>
	/// <param name="visit">각 노드를 방문할 때 호출되는 함수 포인터입니다. 인자로 노드의 포인터(const Node<T>*)를 받습니다.</param>
	template <typename T>
	inline void Tree<T>::InOrderTraversal(void (*visit)(const Node<T>*)) const
	{
		if (root == nullptr || visit == nullptr)
		{
			return; // If the tree is empty or visit function is null, do nothing
		}

		Linear_Data_Structures::Stack<const Node<T>*> stack;
		const Node<T>* current = root;

		while (current != nullptr || !stack.Empty())
		{
			while (current != nullptr)
			{
				stack.Push(current);

				current = (current->childCount > 0) ? current->children[0] : nullptr;
			}
			current = stack.Top();
			stack.Pop();
			visit(current); // Visit the current node

			current = current->childCount > 1 ? current->children[1] : nullptr; // Move to the right child
		}
	}

	/// <summary>
	/// 트리의 모든 노드를 후위 순회(post-order traversal) 방식으로 방문합니다.
	/// </summary>
	/// <typeparam name="T">트리 노드에 저장되는 데이터의 타입입니다.</typeparam>
	/// <param name="visit">각 노드를 방문할 때 호출되는 함수 포인터입니다. 이 함수는 const Node<T>* 타입의 인자를 받아야 합니다.</param>
	template <typename T>
	inline void Tree<T>::PostOrderTraversal(void (*visit)(const Node<T>*)) const
	{
		if (root == nullptr || visit == nullptr)
		{
			return;
		}

		Linear_Data_Structures::Stack<const Node<T>*> stack;
		Linear_Data_Structures::Stack<const Node<T>*> outputStack;
		stack.Push(root);

		while (!stack.Empty())
		{
			const Node<T>* current = stack.Top();
			stack.Pop();
			outputStack.Push(current); // Push the current node to output stack

			// Push children onto the stack
			for (unsigned int i = 0; i < current->childCount; ++i)
			{
				const Node<T>* child = current->children[i];
				if (child != nullptr)
				{
					stack.Push(child);
				}
			}
		}

		while (!outputStack.Empty())
		{
			const Node<T>* child = outputStack.Top();
			outputStack.Pop();
			visit(child);
		}
	}

	/// <summary>
	/// 트리의 레벨 순회(너비 우선 탐색)를 수행하며 각 노드에 대해 지정된 함수를 호출합니다.
	/// </summary>
	/// <typeparam name="T">트리 노드에 저장되는 데이터의 타입입니다.</typeparam>
	/// <param name="visit">각 노드를 방문할 때 호출되는 함수 포인터입니다. 이 함수는 const Node<T>* 타입의 인자를 받아야 합니다.</param>
	template <typename T>
	inline void Tree<T>::LevelOrderTraversal(void (*visit)(const Node<T>*)) const
	{
		if (root == nullptr || visit == nullptr)
		{
			return;
		}

		Linear_Data_Structures::Queue<const Node<T>*> queue;
		queue.Push(root);

		while (!queue.Empty())
		{
			const Node<T>* current = queue.Front();
			queue.Pop();
			visit(current); // Visit the current node

			// Enqueue all children of the current node
			for (unsigned int i = 0; i < current->childCount; ++i)
			{
				const Node<T>* child = current->children[i];
				if (child != nullptr)
				{
					queue.Push(child);
				}
			}
		}
	}
}