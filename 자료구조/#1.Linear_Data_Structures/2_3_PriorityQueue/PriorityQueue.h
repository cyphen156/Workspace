#pragma once

#include <stdexcept>

namespace Linear_Data_Structures
{
	// PriorityQueue class definition
	template<typename T>
	class PriorityQueue
	{
	public:
		PriorityQueue(int initialCapacity = 16)
			: capacity(initialCapacity), size(0)
		{
			data = new T[capacity];
		}
		// DeepCopy constructor, ensuring a new array is allocated
		PriorityQueue(const PriorityQueue& other)
			: size(other.size), capacity(other.capacity)
		{
			data = new T[capacity];
			for (int i = 0; i < size; ++i)
				data[i] = other.data[i];
		}
		PriorityQueue& operator=(const PriorityQueue& other)
		{
			if (this != &other)
			{
				delete[] data;
				size = other.size;
				capacity = other.capacity;
				data = new T[capacity];
				for (int i = 0; i < size; ++i)
				{
					data[i] = other.data[i];
				}
			}
			return *this;
		}
		~PriorityQueue()
		{
			delete[] data;
		}
		// modified methods
		void Push(const T& value);
		void Pop();
		// accessor methods
		T& Top();
		const T& Top() const;
		// capacity methods
		bool Empty() const;
		int Size() const;
	private:
		T* data;
		int size;
		int capacity;
		void Resize();
	};
}