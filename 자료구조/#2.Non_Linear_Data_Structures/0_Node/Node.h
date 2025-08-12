#pragma once

namespace Non_Linear_Data_Structures
{
	/// <summary>
	/// struct Node
	/// <param name="data">T</param>
	/// <param name="childCount">int</param>
	/// <param name="capacity">int</param>
	/// <param name="parent">Node*</param>
	/// <param name="children">Node**</param>
	/// </summary>
	template <typename T>
	struct Node
	{
		T data;
		unsigned int childCount;
		unsigned int capacity = 2;

		Node<T>* parent;
		Node<T>** children;
	};

	// create a new Node with initial children capacity
	template <typename T>
	inline Node<T>* CreateNode(const T& value, unsigned int initialCapacity = 2u)
	{
		Node<T>* newNode = new Node<T>{};
		newNode->data = value;
		newNode->childCount = 0u;
		if (initialCapacity == 0)
		{
			initialCapacity = 2; // Ensure a minimum capacity
		}
		newNode->capacity = initialCapacity;
		newNode->parent = nullptr;
		newNode->children = new Node<T>*[initialCapacity] {};
		return newNode;
	}

	// overloaded CreateNode function
	// type casting for initialCapacity
	template <typename T>
	inline Node<T>* CreateNode(const T& value, int initialCapacity)
	{
		if (initialCapacity <= 0)
		{
			initialCapacity = 2; // Ensure a minimum capacity
		}
		return CreateNode<T>(value, static_cast<unsigned int>(initialCapacity));
	}

	// Extend the capacity of the node's children array
	// Use this function when you know the parent node's capacity is not enough
	// 한글설명 : 노드의 자식 배열의 용량을 확장합니다.
	// 이 함수는 부모 노드의 자식 수용력이 충분하지 않을 때 사용합니다.
	// 무조건 부모 노드의 자식 수용력을 두 배로 확장합니다.
	template <typename T>
	inline void ExtendCapacity(Node<T>* parent)
	{
		if (parent == nullptr)
		{ 
			return; 
		}

		unsigned int newCapacity = 2 * parent->capacity;

		Node<T>** newChildren = new Node<T>*[newCapacity] {};
		for (unsigned int i = 0u; i < parent->childCount; ++i)
		{
			newChildren[i] = parent->children[i];
		}
		delete[] parent->children;
		parent->children = newChildren;
		parent->capacity = newCapacity;
	}

	// ensure the node's children array has enough capacity
	// Use this function when you know the required capacity
	// 한글설명 : 노드의 자식 배열을 충분한 용량으로 확보합니다.
	// 이 함수는 필요한 용량을 알고 있을 때 사용합니다.
	template <typename T>
	inline void EnsureCapacity(Node<T>* node, unsigned int required)
	{
		if (node == nullptr || node->capacity >= required)
		{ 
			return; 
		}

		unsigned int newCapacity = node->capacity;
		while (newCapacity < required)
		{
			newCapacity *= 2;
		}
		
		Node<T>** newChildren = new Node<T>*[newCapacity] {};
		for (unsigned int i = 0u; i < node->childCount; ++i)
		{
			newChildren[i] = node->children[i];
		}
		delete[] node->children;
		node->children = newChildren;
		node->capacity = newCapacity;
	}
	
	// overloaded EnsureCapacity function
	// type casting for required capacity
	template <typename T>
	inline void EnsureCapacity(Node<T>* node, int required)
	{
		if (required <= 0)
		{
			required = 2; // Ensure a minimum required capacity
		}
		EnsureCapacity<T>(node, static_cast<unsigned int>(required));
	}

	// AttachChild with value
	// Use this function to create a new node and attach it as a child to the parent node.
	// 한글설명 : 새로운 노드를 생성하고, 부모에게 자식으로 추가합니다.
	// 새로운 노드를 생성하며, 값을 복사합니다.
	// order는 자식 노드를 정렬할지 여부를 지정합니다.
	// 기본값은 false입니다.
	template <typename T>
	inline Node<T>* AttachChild(Node<T>* parent
							, const T& value
							, unsigned int initialCapacity = 2u
							, bool order = false)
	{
		if (parent == nullptr) 
		{
			return nullptr; 
		}

		// Ensure the parent node has enough capacity for a new child
		// 부모 노드가 새로운 자식을 위한 충분한 용량을 가지고 있는지 확인합니다.
		if (parent->childCount >= parent->capacity)
		{
			ExtendCapacity<T>(parent);
		}

		// 하나 생성해서
		Node<T>* child = CreateNode<T>(value, initialCapacity);

		if (order)
		{
			for (unsigned int i = 0u; i < parent->childCount; ++i)
			{
				// If order is true, find the correct position to insert the new child
				// 한글설명 : order가 true인 경우, 새로운 자식을 삽입할 올바른 위치를 찾습니다.
				if (parent->children[i]->data > child->data)
				{
					// Shift existing children to the right
					for (unsigned int j = parent->childCount; j > i; --j)
					{
						parent->children[j] = parent->children[j - 1u];
					}
					parent->children[i] = child;
					child->parent = parent;
					parent->childCount += 1u;
					return child;
				}
			}
		}

		// If order is false or no position found, add to the end
		// 한글설명 : order가 false이거나 위치를 찾지 못한 경우, 끝에 추가합니다.
		child->parent = parent;
		parent->children[parent->childCount] = child;
		parent->childCount += 1u;
		// Return the newly created child node
		// 새로 생성된 자식 노드를 반환합니다.
		return child;
	}

	// overloaded AttachChild function
	// type casting for initial capacity
	template <typename T>
	inline Node<T>* AttachChild(Node<T>* parent
							, const T& value
							, int initialCapacity
							, bool order = false)
	{
		if (initialCapacity <= 0)
		{
			initialCapacity = 2; // Ensure a minimum initial capacity
		}
		return AttachChild<T>(parent, value, static_cast<unsigned int>(initialCapacity), order);
	}

	// AttachChild with existing Node
	// Use this function to attach an existing node as a child to the parent node.
	// 한글설명 : 기존 노드를 부모에게 자식으로 추가합니다.
	// 기존 노드를 그대로 사용하며, 값을 복사하지 않습니다.
	template <typename T>
	inline Node<T>* AttachChild(Node<T>* parent, Node<T>* child, bool order = false)
	{
		if (parent == nullptr || child == nullptr) 
		{
			return nullptr; 
		}

		if (parent->childCount >= parent->capacity)
		{
			ExtendCapacity<T>(parent);
		}

		if (order)
		{
			for (unsigned int i = 0u; i < parent->childCount; ++i)
			{
				if (parent->children[i]->data > child->data)
				{
					for (unsigned int j = parent->childCount; j > i; --j)
					{
						parent->children[j] = parent->children[j - 1u];
					}
					parent->children[i] = child;
					child->parent = parent;
					parent->childCount += 1u;
					return child; // Return the newly attached child node
				}
			}
		}

		child->parent = parent;
		parent->children[parent->childCount] = child;
		parent->childCount += 1u;

		// Return the newly attached child node
		return child;
	}

	

	// DetachChild with target Child Node
	// Use this function to detach a specific child node from the parent node.
	// The detached child node will not be deleted.
	// Remaining child nodes will be shifted to the left to fill the gap.
	// 한글설명 : 부모 노드에서 특정 자식 노드를 분리합니다.
	// 분리된 자식 노드가 삭제되지 않습니다.
	// 남은 자식 노드를 왼쪽으로 이동하여 빈 공간을 채웁니다.
	template <typename T>
	inline Node<T>* DetachChild(Node<T>* parent, Node<T>* target)
	{
		if (parent == nullptr || target == nullptr)
		{
			return nullptr; // 부모 노드나 대상 노드가 nullptr인 경우
		}

		int index = -1;
		for (unsigned int i = 0u; i < parent->childCount; ++i)
		{
			if (parent->children[i] == target)
			{
				index = static_cast<int>(i);
				break;
			}
		}

		// Target not found in parent's children
		// 타겟을 못찾았음
		if (index < 0)
		{
			return nullptr;
		}

		// Shift remaining children to the left
		// 남은 자식 노드를 왼쪽으로 이동합니다.
		for (unsigned int j = static_cast<unsigned int>(index); j < parent->childCount - 1u; ++j)
		{
			parent->children[j] = parent->children[j + 1u];
		}

		parent->childCount -= 1u;	// Decrease the child count
		parent->children[parent->childCount] = nullptr; // Clear the last child
		target->parent = nullptr;	// Detach the target node from its parent
		return target;
	}

	// DetachChild with Node
	// Use this function to detach a child node from the parent node.
	// // The detached child node will not be deleted.
	// Remaining child nodes will be shifted to the left to fill the gap.
	// 한글설명 : 노드를 부모 노드에서 분리합니다.
	// 분리된 노드가 삭제되지 않습니다.
	// 부모노드에게서 남은 자식 노드를 왼쪽으로 이동하여 빈 공간을 채웁니다.
	template <typename T>
	inline Node<T>* DetachNode(Node<T>* target)
	{
		if (target == nullptr || target->parent == nullptr)
		{
			return nullptr;
		}

		DetachChild<T>(target->parent, target);
		return target;
	}

	// DetachChild with value
	// 자식 노드가 삭제되지 않습니다.
	template <typename T>
	inline Node<T>* DetachChild(Node<T>* parent, const T& value)
	{
		if (parent == nullptr)
		{
			return nullptr; // 부모 노드가 nullptr인 경우
		}

		int index = -1;
		for (unsigned int i = 0u; i < parent->childCount; ++i)
		{
			if (parent->children[i] && parent->children[i]->data == value)
			{
				index = static_cast<int>(i);
				break;
			}
		}

		if (index < 0)
		{
			return nullptr; // Value not found in parent's children
		}

		Node<T>* target = parent->children[index];
		// Shift remaining children to the left
		for (unsigned int j = static_cast<unsigned int>(index); j < parent->childCount - 1u; ++j)
		{
			parent->children[j] = parent->children[j + 1u];
		}
		parent->childCount -= 1u; // Decrease the child count
		parent->children[parent->childCount] = nullptr; // Clear the last child
		target->parent = nullptr; // Detach the target node from its parent
		return target;
	}

	// DetachChild with index
	// Use this function to detach a child node at a specific index from the parent node.
	// The detached child node will not be deleted.
	// Remaining child nodes will be shifted to the left to fill the gap.
	// 한글설명 : 부모 노드에서 특정 인덱스의 자식 노드를 분리합니다.
	// 분리된 자식 노드가 삭제되지 않습니다.
	// 남은 자식 노드를 왼쪽으로 이동하여 빈 공간을 채웁니다.
	template <typename T>
	inline Node<T>* DetachChild(Node<T>* parent, unsigned int index)
	{
		if (parent == nullptr || index >= parent->childCount)
		{
			return nullptr; // 부모 노드가 nullptr이거나 인덱스가 범위를 벗어난 경우
		}
		
		Node<T>* target = parent->children[index];

		if (target == nullptr)
		{
			return nullptr; // 해당 인덱스에 자식 노드가 없는 경우
		}
		
		// Shift remaining children to the left
		for (unsigned int j = index; j < parent->childCount - 1u; ++j)
		{
			parent->children[j] = parent->children[j + 1u];
		}

		parent->childCount -= 1u; // Decrease the child count
		parent->children[parent->childCount] = nullptr; // Clear the last child
		target->parent = nullptr; // Detach the target node from its parent
		return target;
	}

	// overloaded DetachChild function
	template <typename T>
	inline Node<T>* DetachChild(Node<T>* parent, int index)
	{
		if (index < 0)
		{
			return nullptr; // 인덱스가 음수인 경우
		}
		return DetachChild<T>(parent, static_cast<unsigned int>(index));
	}

	// Detach All Children
	// Detach all children from the parent node
	// 모든 자식 노드를 부모 노드에서 분리합니다.
	// 자식 노드가 삭제되지 않습니다.
	template <typename T>
	inline bool DetachAllChildren(Node<T>* parent)
	{
		if (parent == nullptr)
		{
			return false; // 부모 노드가 nullptr인 경우
		}

		for (unsigned int i = 0u; i < parent->childCount; ++i)
		{
			if (parent->children[i] != nullptr)
			{
				parent->children[i]->parent = nullptr; // Detach each child node from its parent
				parent->children[i] = nullptr;
			}
		}
		
		parent->childCount = 0u; // Reset child count

		return true; // Return true to indicate successful detachment
	}

	// Delete Node
	// Use this function to delete a specific node and all its children.
	// The node will be deleted, and all its children will also be deleted recursively.
	// 한글설명 : 처음 만난 특정 노드와 그 자식 노드를 모두 삭제합니다.
	template <typename T>
	inline void DeleteNode(Node<T>*& target)
	{
		if (target == nullptr)
		{
			return; // 노드가 nullptr인 경우
		}

		// Recursively delete all children
		for (unsigned int i = 0u; i < target->childCount; ++i)
		{
			if (target->children[i] != nullptr)
			{
				DeleteNode<T>(target->children[i]); // 자식 서브트리 재귀 삭제
				target->children[i] = nullptr;
			}
		}
		delete[] target->children;	// Delete the children array
		target->children = nullptr; // Clear the pointer to children
		delete target;				// Delete the target node itself
		target = nullptr;			// Clear the target node pointer
	}


	// DeleteChild
	// Use this function to delete a specific child node from the parent node.
	// The child node will be deleted, and remaining child nodes will be shifted to the left to fill the gap.
	// 한글설명 : 부모 노드에서 처음 만난 특정 자식 노드를 삭제합니다.
	// 자식 노드가 삭제되며, 남은 자식 노드를 왼쪽으로 이동하여 빈 공간을 채웁니다.
	template <typename T>
	inline void DeleteChild(Node<T>* parent, Node<T>* target)
	{
		if (parent == nullptr || target == nullptr)
		{
			return; // 부모 노드나 대상 노드가 nullptr인 경우
		}
		int index = -1;
		for (unsigned int i = 0u; i < parent->childCount; ++i)
		{
			if (parent->children[i] == target)
			{
				index = static_cast<int>(i);
				break;
			}
		}
		if (index < 0) 
		{
			return; // Target not found in parent's children
		}

		DeleteNode<T>(target);

		// Shift remaining children to the left
		for (unsigned int j = static_cast<unsigned int>(index); j < parent->childCount - 1u; ++j)
		{
			parent->children[j] = parent->children[j + 1u];
		}
		parent->childCount -= 1u; // Decrease the child count
		parent->children[parent->childCount] = nullptr; // Clear the last child
	}

	// DeleteChild with value
	// Use this function to delete a specific child node with the given value from the parent node.
	// The child node will be deleted, and remaining child nodes will be shifted to the left to fill the gap.
	// 한글설명 : 부모 노드에서 처음 만난 특정 값의 자식 노드를 삭제합니다.
	// 자식 노드가 삭제되며, 남은 자식 노드를 왼쪽으로 이동하여 빈 공간을 채웁니다.
	template <typename T>
	inline void DeleteChild(Node<T>* parent, const T& value)
	{
		if (parent == nullptr)
		{
			return; // 부모 노드가 nullptr인 경우
		}
		int index = -1;
		for (unsigned int i = 0u; i < parent->childCount; ++i)
		{
			// Find the index of the child with the given value 
			if (parent->children[i] && parent->children[i]->data == value)
			{
				index = static_cast<int>(i);
				break;
			}
		}

		if (index < 0)
		{
			return; // Value not found in parent's children
		}
		
		Node<T>* target = parent->children[index];
		DeleteNode<T>(target); // Delete the target node

		// Shift remaining children to the left
		for (unsigned int j = index; j < parent->childCount - 1u; ++j)
		{
			parent->children[j] = parent->children[j + 1u];
		}
		parent->childCount -= 1u; // Decrease the child count
		parent->children[parent->childCount] = nullptr; // Clear the last child
	}

	// DeleteChild with index
	// Use this function to delete a child node at a specific index from the parent node.
	// The child node will be deleted, and remaining child nodes will be shifted to the left to fill the gap.
	// 한글설명 : 부모 노드에서 특정 인덱스의 자식 노드를 삭제합니다.
	// 자식 노드가 삭제되며, 남은 자식 노드를 왼쪽으로 이동하여 빈 공간을 채웁니다.
	template <typename T>
	inline void DeleteChild(Node<T>* parent, unsigned int index)
	{
		if (parent == nullptr || index >= parent->childCount)
		{
			return; // 부모 노드가 nullptr이거나 인덱스가 범위를 벗어난 경우
		}
		
		if (parent->children[index] == nullptr)
		{
			return; // 해당 인덱스에 자식 노드가 없는 경우
		}
		
		Node<T>* target = parent->children[index];
		DeleteNode<T>(target); // Delete the target node
		// Shift remaining children to the left
		for (unsigned int j = index; j < parent->childCount - 1u; ++j)
		{
			parent->children[j] = parent->children[j + 1u];
		}

		parent->childCount -= 1u; // Decrease the child count
		parent->children[parent->childCount] = nullptr; // Clear the last child
	}

	// overloaded DeleteChild function
	template <typename T>
	inline void DeleteChild(Node<T>* parent, int index)
	{
		if (index < 0)
		{
			return; // 인덱스가 음수인 경우
		}
		DeleteChild<T>(parent, static_cast<unsigned int>(index));
	}

	// DeleteAllChildren
	// Use this function to delete all child nodes of a given node.
	// The node itself will not be deleted, only its children will be deleted recursively.
	// 한글설명 : 주어진 노드의 모든 자식 노드를 삭제합니다.
	// 노드 자체는 삭제되지 않으며, 자식 노드만 재귀적으로 삭제됩니다.
	template <typename T>
	inline bool DeleteAllChildren(Node<T>* node)
	{
		if (node == nullptr)
		{
			return false; // 노드가 nullptr인 경우
		}

		for (unsigned int i = 0u; i < node->childCount; ++i) 
		{
			if (node->children[i])
			{
				DeleteNode<T>(node->children[i]); // 하위 전체 삭제
				node->children[i] = nullptr;
			}
		}
		node->childCount = 0u;   // 부모는 유지
		return true; // 모든 자식 노드를 성공적으로 삭제했음을 나타냅니다.
	}
}