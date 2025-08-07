#pragma once

namespace Non_Linear_Data_Structures
{
	// Node structure definition
	template <typename T>
	struct Node
	{
		T data; // Data stored in the node
		int childCount; // Number of children
		int capacity; // Capacity of the children array
		
		Node<T>* parent;
		Node<T>** children;

		Node(const T& value, int initialCapacity = 2)
			: data(value)
			, childCount(0)
			, capacity(initialCapacity)
			, parent(nullptr)
		{
			children = new Node<T>*[capacity];
			
			for (int i = 0; i < capacity; ++i)
			{
				children[i] = nullptr;
			}
		}

		// DeepCopy constructor
		Node(const Node<T>& other)
			: data(other.data)
			, childCount(other.childCount)
			, capacity(other.capacity)
			, parent(nullptr)
		{
			children = new Node<T>*[capacity];
			for (int i = 0; i < childCount; ++i)
			{
				children[i] = new Node<T>(*other.children[i]);
				children[i]->SetParent(this); // Set parent for the copied child
			}

			for (int i = childCount; i < capacity; ++i)
			{
				children[i] = nullptr;
			}
		}

		~Node()
		{
			for (int i = 0; i < childCount; ++i)
			{
				delete children[i];
			}
			delete[] children;
		}

		void SetParent(Node<T>* newParent)
		{
			parent = newParent;
		}

		void AddChild(Node<T>* child)
		{
			if (child == nullptr)
			{
				return;
			}

			if (childCount >= capacity)
			{
				int newCapacity = capacity * 2;
				Node<T>** newChildren = new Node<T>*[newCapacity];

				for (int i = 0; i < childCount; ++i)
				{
					newChildren[i] = children[i];
				}
				for (int i = childCount; i < newCapacity; ++i)
				{
					newChildren[i] = nullptr;
				}

				delete[] children;
				children = newChildren;
				capacity = newCapacity;
			}

			children[childCount++] = child;
			child->SetParent(this);
		}

		void RemoveChild(Node<T>* child)
		{
			if (child == nullptr)
			{
				return;
			}

			for (int i = 0; i < childCount; ++i)
			{
				if (children[i] == child)
				{
					children[i] = children[--childCount];
					children[childCount] = nullptr;
					child->SetParent(nullptr);
					return;
				}
			}
		}

		void DeleteChild(Node<T>* child)
		{
			if (child == nullptr)
			{
				return;
			}

			for (int i = 0; i < childCount; ++i)
			{
				if (children[i] == child)
				{
					delete children[i];
					children[i] = children[--childCount];
					children[childCount] = nullptr;
					return;
				}
			}
		}

		void Clear()
		{
			for (int i = 0; i < childCount; ++i)
			{
				DeleteChild(children[childCount - 1]);
			}
			childCount = 0;
		}
	};
}