#pragma once

#include <iostream>

namespace Linear_Data_Structures
{
	template<typename T>
	struct PriorityQueueNode
	{
		T data;
		int priority;

		// Default constructor
		PriorityQueueNode()
			: priority(0), data(T())
		{}

		// Constructor with parameters
		PriorityQueueNode(int priority, const T& value)
			: priority(priority), data(value)
		{}

		friend bool operator<(const PriorityQueueNode& left, const PriorityQueueNode& right)
		{
			return left.priority < right.priority;
		}

		friend std::ostream& operator<<(std::ostream& os, const PriorityQueueNode& node)
		{
			return os << '{' << node.priority << ", '" << node.data << "'}";
		}
	};

	// PriorityQueue class definition
	template<typename T>
	class PriorityQueue
	{
	public:
		// Default constructor with initial capacity
		PriorityQueue(int initialCapacity = 16)
			: capacity(initialCapacity), size(0)
		{
			data = new PriorityQueueNode<T>[capacity];
		}

		// DeepCopy constructor, ensuring a new array is allocated
		PriorityQueue(const PriorityQueue& other)
			: capacity(other.capacity), size(other.size)
		{
			data = new PriorityQueueNode<T>[capacity];
			for (int i = 0; i < size; ++i)
			{
				data[i] = other.data[i];
			}
		}

		// Destructor
		~PriorityQueue()
		{
			delete[] data;
		}

		// Assignment operator, ensuring a new array is allocated
		PriorityQueue& operator=(const PriorityQueue& other)
		{
			if (this != &other)
			{
				delete[] data;
				size = other.size;
				capacity = other.capacity;
				data = new PriorityQueueNode<T>[capacity];
				for (int i = 0; i < size; ++i)
				{
					data[i] = other.data[i];
				}
			}
			return *this;
		}

		// modified methods
		void Push(int priority = 0, const T& value = T());
		void Pop();

		// accessor methods
		T& Top();
		const T& Top() const;

		// capacity methods
		bool Empty() const;
		int Size() const;

		// Custom methods
		void Clear();

	private:
		PriorityQueueNode<T>* data;
		int size;
		int capacity;
	};

	template<typename T>
	void PriorityQueue<T>::Push(int priority, const T& value)
	{
		if (size >= capacity)
		{
			// Reallocate memory
			int oldCapacity = capacity;
			capacity *= 2;
			PriorityQueueNode<T>* newData = new PriorityQueueNode<T>[capacity];
			for (int i = 0; i < size; ++i)
			{
				newData[i] = data[i]; // Copy existing nodes
			}
			delete[] data;
			data = newData;
		}

		// Insert the new node
		data[size] = PriorityQueueNode<T>(priority, value); // Default priority 0
		int current = size++;

		while (current > 0)
		{
			int parent = (current - 1) / 2;
			if (data[parent] < data[current])
			{
				std::swap(data[parent], data[current]);
				current = parent;
			}
			else
			{
				break;
			}
		}
	};

	template<typename T>
	void PriorityQueue<T>::Pop()
	{
		if (size == 0)
		{
			return;
		}

		int current = 0;
		data[0] = data[--size]; // Move the last element to the root
		
		while (true)
		{
			int leftChild = 2 * current + 1;
			int rightChild = 2 * current + 2;
			int largest = current;

			if (leftChild < size && data[largest] < data[leftChild])
			{
				largest = leftChild;
			}

			if (rightChild < size && data[largest] < data[rightChild])
			{
				largest = rightChild;
			}

			if (largest == current)
			{
				break;
			}

			std::swap(data[current], data[largest]);
			current = largest;
		}
	}

	template<typename T>
	T& PriorityQueue<T>::Top()
	{
		return data[0].data;
	}

	template<typename T>
	const T& PriorityQueue<T>::Top() const
	{
		return data[0].data;
	}

	template<typename T>
	bool PriorityQueue<T>::Empty() const
	{
		return size == 0;
	}

	template<typename T>
	int PriorityQueue<T>::Size() const
	{
		return size;
	}

	template<typename T>
	void PriorityQueue<T>::Clear()
	{
		delete[] data;
		data = new PriorityQueueNode<T>[capacity];
		size = 0;
	}
}