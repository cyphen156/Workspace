#pragma once

namespace Linear_Data_Structures
{
	// Deque class definition
	template<typename T>
	class Deque
	{
	public:
		Deque(int initialCapacity = 16)
			: capacity(initialCapacity), front(0), back(0), size(0)
		{
			data = new T[capacity];
		}
		// DeepCopy constructor, ensuring a new array is allocated
		Deque(const Deque& other)
			: capacity(other.capacity), front(other.front), back(other.back), size(other.size)
		{
			data = new T[capacity];
			for (int i = 0; i < size; ++i)
				data[(front + i) % capacity] = other.data[(other.front + i) % other.capacity];
		}
		Deque& operator=(const Deque& other)
		{
			if (this != &other)
			{
				delete[] data;
				capacity = other.capacity;
				size = other.size;
				front = other.front;
				back = other.back;
				data = new T[capacity];
				for (int i = 0; i < size; ++i)
				{
					data[(front + i) % capacity] = other.data[(other.front + i) % other.capacity];
				}
			}
			return *this;
		}
		~Deque()
		{
			delete[] data;
		}
	private:
		T* data;
		int capacity;
		int front;
		int back;
		int size;
	public:
		void PushFront(const T& value);
		void PushBack(const T& value);
		
		void PopFront();
		void PopBack();
		T& Front();
		const T& Front() const;
		T& Back();
		const T& Back() const;
		bool Empty() const;
		
		int Size() const;
	private:
		void Resize();
	};
}