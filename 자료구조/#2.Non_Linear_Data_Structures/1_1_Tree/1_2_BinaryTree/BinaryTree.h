#pragma once

#include "../Tree.h"

namespace Non_Linear_Data_Structures
{
	// BinaryTree class definition
	/// <summary>
	/// BinaryTree class
	/// this class is Adapter of Tree class
	/// 이진 트리 클래스는 Tree 클래스를 어댑터로 사용하여 이진 트리 구조를 구현합니다.
	/// <typeparam name="T">Type of data stored in the tree</typeparam>
	/// </summary>
	
	template <typename T>
	class BinaryTree : public Tree<T>
	{
	public:
		// Default constructor
		// 빈 이진 트리 생성자
		inline BinaryTree() : Tree<T>() {}

		// Constructor with root node
		// 이진 트리 생성자, 루트 노드를 지정합니다.
		// 만약 루트 노드의 자식 수가 2개 이상이면
		// 최대 2개로 제한합니다.
		// 추가되는 자식 노드는 항상 0, 1번 인덱스까지만 추가합니다.
		// 나머지는 버려집니다.
		// 깊은 복사로 구현한다.
		inline explicit BinaryTree(const NodeT* node) 
			: Tree<T>() 
		{ 
			// Ensure the node is a valid binary tree node
			// 자식 노드 트림 작업 필요
 		}

		// Constructor with value
		// 이진 트리 생성자, 주어진 값을 가진 루트 노드를 생성합니다.
		inline explicit BinaryTree(const T& value) : Tree<T>(value, 2u) {}

		// deep copy constructor
		BinaryTree(const BinaryTree&) = default;
		
		// Move constructor
		BinaryTree(BinaryTree&&) noexcept = default;

		// Assignment operators
		BinaryTree& operator=(const BinaryTree&) = default;

		// Move assignment operator
		BinaryTree& operator=(BinaryTree&&) noexcept = default;
		
		// Destructor
		~BinaryTree() = default;

	};
}