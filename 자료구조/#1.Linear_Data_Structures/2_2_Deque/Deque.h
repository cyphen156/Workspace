#pragma once

namespace Linear_Data_Structures
{
	// Deque class definition
	template<typename T>
	class Deque
	{
	public:
		// Default constructor with initial capacity
		Deque(int initialCapacity = 16)
			: capacity(initialCapacity), front(0), back(-1), size(0)
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

		// Destructor to clean up allocated memory
		~Deque()
		{
			delete[] data;
		}

		// Assignment operator, ensuring a new array is allocated
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
		int Size() const;;

		void Clear();
	};

	template<typename T>
	inline void Deque<T>::PushFront(const T& value)
	{
		if (size + 1 >= capacity)
		{
			// reallocate memory
			int oldCapacity = capacity;
			capacity *= 2;
			T* newData = new T[capacity];
			for (int i = 0; i < size; ++i)
			{
				newData[i] = data[(front + i) % oldCapacity];	// front 앞으로 당기기
			}
			front = 0;
			back = size;

			delete[] data;
			data = newData;
		}

		front = (front - 1 + capacity) % capacity;
		data[front] = value;
		size++;
	}

	template<typename T>
	inline void Deque<T>::PushBack(const T& value)
	{
		if (size + 1 >= capacity)
		{
			// reallocate memory
			int oldCapacity = capacity;
			capacity *= 2;
			T* newData = new T[capacity];
			for (int i = 0; i < size; ++i)
			{
				newData[i] = data[(front + i) % oldCapacity];	// front 앞으로 당기기
			}
			front = 0;
			back = size - 1;

			delete[] data;
			data = newData;
		}

		back = (back + 1) % capacity;
		data[back] = value;
		size++;
	}

	template<typename T>
	inline void Deque<T>::PopFront()
	{
		if (!Empty())
		{
			front = (front + 1) % capacity;
			size--;
		}
	}

	template<typename T>
	inline void Deque<T>::PopBack()
	{
		if (!Empty())
		{
			back = (back - 1 + capacity) % capacity;
			size--; 
		}
	}

	template<typename T>
	inline T& Deque<T>::Front()
	{
		return data[front];
	}

	template<typename T>
	inline const T& Deque<T>::Front() const
	{
		return data[front];
	}

	template<typename T>
	inline T& Deque<T>::Back()
	{
		return data[back];
	}

	template<typename T>
	inline const T& Deque<T>::Back() const
	{
		return data[back];
	}

	template<typename T>
	inline bool Deque<T>::Empty() const
	{
		return size == 0;
	}

	template<typename T>
	inline int Deque<T>::Size() const
	{
		return size;
	}

	template<typename T>
	inline void Deque<T>::Clear()
	{
		front = 0;
		back = -1;
		size = 0;
	}
}