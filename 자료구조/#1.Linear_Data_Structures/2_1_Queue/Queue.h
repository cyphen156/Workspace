#pragma once

namespace Linear_Data_Structures
{
	// Queue class definition
	template<typename T>
	class Queue
	{
	public:
		// Default constructor with initial capacity
		Queue(int initialCapacity = 16) 
			: front(0), back(-1), size(0), capacity(initialCapacity)
		{
			data = new T[capacity];
		}

		// DeepCopy constructor, ensuring a new array is allocated
		Queue(const Queue& other)
			: front(other.front), back(other.back), size(other.size), capacity(other.capacity)
		{
			data = new T[capacity];
			for (int i = 0; i < size; ++i)
				data[i] = other.data[(front + i) % capacity];
		}
		
		// Destructor to clean up allocated memory
		~Queue()
		{
			delete[] data;
		}

		// Assignment operator to handle deep copy
		Queue& operator=(const Queue& other)
		{
			if (this != &other)
			{
				delete[] data;
				front = other.front;
				back = other.back;
				size = other.size;
				capacity = other.capacity;
				data = new T[capacity];
				for (int i = 0; i < size; ++i)
				{
					data[i] = other.data[(front + i) % capacity];
				}
			}
			return *this;
		}

		// modified methods
		void Push(const T& value);	// Enqueue
		void Pop();					// Dequeue

		// accessor methods
		T& Front();
		const T& Front() const;
		T& Back();
		const T& Back() const;

		// capacity methods
		bool Empty() const;
		int Size() const;

		// custom methods
		void Clear();

	private:
		T* data;
		int front;
		int back;
		int size;
		int capacity;
	};

	template<typename T>
	inline void Queue<T>::Push(const T& value)
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
	inline void Queue<T>::Pop()
	{
		if (size > 0)
		{
			front = (front + 1) % capacity;
			size--;
		}
	}

	template<typename T>
	inline T& Queue<T>::Front()
	{
		return data[front];
	}

	template<typename T>
	inline const T& Queue<T>::Front() const
	{
		return data[front];
	}

	template<typename T>
	inline T& Queue<T>::Back()
	{
		return data[back];
	}

	template<typename T>
	inline const T& Queue<T>::Back() const
	{
		return data[back];
	}

	template<typename T>
	inline bool Queue<T>::Empty() const
	{
		return size == 0;
	}

	template<typename T>
	inline int Queue<T>::Size() const
	{
		return size;
	}

	template<typename T>
	inline void Queue<T>::Clear()
	{
		front = 0;
		back = -1;
		size = 0;
	}
}