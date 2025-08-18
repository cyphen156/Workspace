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

		// Constructor with value
		// 이진 트리 생성자, 주어진 값을 가진 루트 노드를 생성합니다.
		inline explicit BinaryTree(const T& value) : Tree<T>(value, 2u) {}

		// Constructor with root node
		// 이진 트리 생성자, 루트 노드를 지정합니다.
		// 만약 루트 노드의 자식 수가 2개 이상이면
		// 최대 2개로 제한합니다.
		// 만약 주어진 자식 노드가 3개 이상이면
		// 서브트리로 분리 저장합니다.
		// 깊은 복사로 구현한다.
		inline explicit BinaryTree(const Node<T>* node) 
			: Tree<T>() 
		{ 
			// Ensure the node is a valid binary tree node
			// 자식 노드 트림 작업 필요
 		}

		// deep copy constructor
		// 깊은 복사 생성자
		// 트리 자체를 깊은 복사합니다.
		inline explicit BinaryTree(const BinaryTree& other)
			: Tree<T>(other) 
		{
			// Ensure the node is a valid binary tree node
			// 자식 노드 트림 작업 필요
		}
		
		// Move constructor with value
		// 이진 트리 이동 생성자
		// 트리 자체를 이동합니다.
		inline explicit BinaryTree(BinaryTree&& other) noexcept 
			: Tree<T>(std::move(other)) 
		{
			// Ensure the node is a valid binary tree node
			// 자식 노드 트림 작업 필요
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
		Node<T>* Insert(Node<T>*, bool = false) override;
		Node<T>* Insert(const T&, unsigned int = 2, bool = false) = delete;
		Node<T>* Insert(const T&, int, bool = false) = delete;
		Node<T>* InsertAt(Node<T>*, Node<T>*, bool = false) = delete;
		Node<T>* InsertAt(Node<T>*, const T&, unsigned int = 2, bool = false) = delete;
		Node<T>* InsertAt(Node<T>*, const T&, int, bool = false) = delete;

		// overloaded Insert methods


		// Remove methods

		// delete methods

		// Clear method



	};
}