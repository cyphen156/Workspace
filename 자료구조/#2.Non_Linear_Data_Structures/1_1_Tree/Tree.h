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
			, height(-1)
		{}

		// Constructor with root node
		inline Tree(const Node<T>* node)
			: root(const_cast<Node<T>*>(node))
			, nodeCount(0)
			, height(-1)
		{
			if (root == nullptr)
			{
				return;
			}

			// Initialize nodeCount and height based on the root node
			nodeCount = 1;	// Start with the root node
			height = 0;		// Start with height 0 for the root node
			// Use a stack to perform a depth-first traversal to count nodes and calculate height
			
			if (PreOrderTraversal() != nullptr)
			{
				nodeCount++;
			}
		}
		
		// Constructor with value
		// This constructor creates a tree with a single root node containing the given value
		// 한글설명 : 이 생성자는 주어진 값을 가진 단일 루트 노드로 트리를 만듭니다.
		inline Tree(const T& value, unsigned int initialCapacity = 2u)
			: root(nullptr)
			, nodeCount(1)
			, height(0)
		{
			if (initialCapacity == 0)
			{
				initialCapacity = 2; // Ensure a minimum initial capacity
			}
			root = CreateNode<T>(value, initialCapacity);
		}

		// Overloaded constructor with value and initial capacity
		inline Tree(const T& value, int initialCapacity)
			: root(nullptr)
			, nodeCount(1)
			, height(0)
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
			: root(nullptr)
			, nodeCount(0)
			, height(-1)
		{
			if (other.root == nullptr)
			{
				return;
			}

			root = CreateNode<T>(other.root->data, other.root->capacity);
			nodeCount = 1;
			height = 0;
			
			// Use a stack to perform a depth-first traversal and copy nodes
			if (PreOrderTraversal(other))
			{
				nodeCount++;
			}
		}
		
		// Destructor
		inline ~Tree()
		{ 
			//Clear();
		}
		
		// Assignment operator
		inline Tree& operator=(const Tree& other)
		{
		}

		inline Tree& operator=(Tree&& other) noexcept
		{
		}

		// modified methods
		void Insert(const Node<T>* node);											// Insert a node into the tree
		Node<T>* Insert(const T& value													// Insert a value into the tree
					, unsigned int initialCapacity = 2
					, bool order = false);													
		Node<T>* Insert(const T& value													// Insert a value into the tree
					, int initialCapacity
					, bool order = false);		

		void InsertAt(const Node<T>* node, Node<T>* target);						// Insert a node at a specific position
		Node<T>* InsertAt(const T& value												// Insert a value at a specific position with order
					, unsigned int initialCapacity = 2
					, bool order = false
					, Node<T>* taeget);
		Node<T>* InsertAt(const T& value												// Insert a value at a specific position
					, int initialCapacity
					, bool order = false
					, Node<T>* taeget);
		
		Node<T>* Remove(const Node<T>* node);										// Remove a node from the tree
		Node<T>* Remove(const T& value);											// Remove a value from the tree
		Node<T>* Remove(const int index);											// Remove a node using index from the tree
		
		Node<T>* RemoveAt(const Node<T>* node, Node<T>* parent);					// Remove a node at a specific position
		Node<T>* RemoveAt(const T& value, Node<T>* parent);							// Remove a value at a specific position
		Node<T>* RemoveAt(const int index, Node<T>* parent);						// Remove a node at a specific position using index
		
		void Delete();																// Delete the entire tree
		void Delete(const Node<T>* node);											// Delete a node from the tree
		void Delete(const T& value);												// Delete a value from the tree
		void Delete(const int index);												// Delete a node using index from the tree

		void DeleteAt(const Node<T>* node, Node<T>* parent);						// Delete a node at a specific position
		void DeleteAt(const T& value, Node<T>* parent);								// Delete a value at a specific position
		void DeleteAt(const int index, Node<T>* parent);							// Delete a node at a specific position using index
		
		void Clear();								// Clear the tree
	
		// accessor methods
		Node<T>* GetRoot() const;					// Get the root node of the tree
		const Node<T>* GetRoot() const;				// Get the root node of the tree
		int GetHeight() const;						// Get the height of the tree
		int GetHeight(const Node<T>* node) const;	// Get the height of a specific node
		int GetDegree() const;						// Get the degree of the root node
		int GetDegree(const Node<T>* node) const;	// Get the degree of a specific node
		int GetDepth(const Node<T>* node) const;	// Get the depth of a specific node
		bool Empty() const;							// Check if the tree is empty
		int Size() const;							// Get the size of the tree

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
		int height;			// Height of the tree
	};
	

	template <typename T>	
	inline Node<T>* Tree<T>::GetRoot() const
	{
		return root;
	}

	template <typename T>	
	inline int Tree<T>::GetHeight() const
	{
		return height;
	}

	template <typename T>	
	inline int Tree<T>::GetHeight(const Node<T>* node) const
	{
		if (node == nullptr)
		{
			return -1; // Height of an empty node is -1
		}

		int maxHeight = -1;
		if (node->children[0] != nullptr)
		{
			maxHeight = GetHeight(node->children[0]);
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
		return GetDegree(root);
	}

	template <typename T>	
	inline int Tree<T>::GetDegree(const Node<T>* node) const
	{
		if (node == nullptr)
		{
			return 0;
		}
		int maxDegree = 0;
		for (unsigned int i = 0; i < node->childCount; ++i)
		{
			if (node->children[i] != nullptr)
			{
				int degree = GetDegree(node->children[i]);
				if (degree > maxDegree)
				{
					maxDegree = degree;
				}
			}
		}
		return maxDegree + 1; // Add 1 for the current node
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