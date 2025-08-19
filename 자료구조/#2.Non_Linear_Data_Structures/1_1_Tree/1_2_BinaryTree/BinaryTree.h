#pragma once

#include "../Tree.h"

namespace Non_Linear_Data_Structures
{
	// BinaryTree class definition
	/// <summary>
	/// BinaryTree class
	/// this class is Adapter of Tree class
	/// 이진 트리 클래스는 Tree 클래스를 어댑터로 사용하여 이진 트리 구조를 구현합니다.
	/// 자식 노드의 수를 2개로 제한하며,
	/// 0번 인덱스는 왼쪽 자식, 1번 인덱스는 오른쪽 자식을 나타냅니다.
	/// <typeparam name="T">Type of data stored in the tree</typeparam>
	/// </summary>
	
	template <typename T>
	class BinaryTree : public Tree<T>
	{
	public:
		// Default constructor
		// 빈 이진 트리 생성자
		inline BinaryTree() : Tree<T>() {}
		
		// Constructor with value
		// 이진 트리 생성자, 주어진 값을 가진 루트 노드를 생성합니다.
		inline explicit BinaryTree(const T& value)
			: Tree<T>(value, 2u) 
		{}
		// Constructor with initial capacity
		// must be deleted
		inline BinaryTree(const T& value, unsigned int /*initialCapacity*/) = delete;
		inline BinaryTree(const T& value, int /*initialCapacity*/) = delete;
		
		// Constructor with root node
		// 이진 트리 생성자, 루트 노드를 지정합니다.
		// 만약 루트 노드의 자식 수가 2개 이상이면
		// 최대 2개로 제한합니다.
		// 만약 주어진 자식 노드가 3개 이상이면
		// 자식노드의 자식노드로 이전합니다.
		// 깊은 복사로 구현한다.
		inline explicit BinaryTree(const Node<T>* node) 
			: Tree<T>() 
		{ 
			// Ensure the node is a valid binary tree node
			// 자식 노드 스플릿 작업 필요
			if (node == nullptr) 
			{ 
				return; 
			}	

			// Create a temporary tree to convert the node to a binary tree
			// 임시 트리를 생성하여 노드를 이진 트리로 변환합니다.
			Tree<T> temp = Tree<T>(node);

			temp.convertToBinaryTree();
			this->root = temp.GetRoot();
			this->nodeCount = temp.GetNodeCount();
 		}

		// deep copy constructor
		// 깊은 복사 생성자
		// 트리 자체를 깊은 복사합니다.
		inline explicit BinaryTree(const BinaryTree& other)
			: Tree<T>(other) 
		{
			// Ensure the node is a valid binary tree node
			// 자식 노드 스플릿 작업 필요
			if (other.root == nullptr) 
			{ 
				return; 
			}

			other.ExportAsBinary(other.root, this->root, this->nodeCount);
		}
		
		// Move constructor with value
		// 이진 트리 이동 생성자
		// 트리 자체를 이동합니다.
		inline explicit BinaryTree(BinaryTree&& other) noexcept 
			: Tree<T>(/*std::move(other)*/) 
		{
			// Ensure the node is a valid binary tree node
			
		}

		// Assignment operators
		BinaryTree& operator=(const BinaryTree&) = default;

		// Move assignment operator
		BinaryTree& operator=(BinaryTree&&) noexcept = default;
		
		// Destructor
		~BinaryTree() = default;

		// modify methods
		// Insert methods
		// Base Insert method is not available
		// use overloaded Insert methods
		// overloaded Insert methods
		
	private:
	};
}