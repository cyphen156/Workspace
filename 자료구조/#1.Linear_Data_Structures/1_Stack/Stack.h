#pragma once
#include <stdexcept>

namespace Linear_Data_Structures
{
	// Stack class definition
	template<typename T>
	class Stack
	{
	public:
		Stack(int initialCapacity = 16) 
			: capacity(initialCapacity),
			top(-1)
		{
			data = new T[capacity];
		}

		// DeepCopy constructor, ensuring a new array is allocated
		Stack(const Stack& other)
			: top(other.top), capacity(other.capacity)
		{
			data = new T[capacity];
			for (int i = 0; i <= top; ++i)
				data[i] = other.data[i];
		}

		Stack& operator=(const Stack& other)
		{
			if (this != &other)
			{
				delete[] data;
				top = other.top;
				capacity = other.capacity;
				data = new T[capacity];
				for (int i = 0; i <= top; ++i)
				{
					data[i] = other.data[i];
				}
			}
			return *this;
		}

		~Stack()
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

		// custom methods
		void Clear();
			
	private:
		T* data;
		int top;
		int capacity;
	};

	template<typename T>
	inline void Stack<T>::Push(const T& value)
	{
		if (top + 1 >= capacity) 
		{
			// reallocate memory
			capacity *= 2;
			T* newData = new T[capacity];
			for (int i = 0; i <= top; ++i) 
			{
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
		}
		data[++top] = value;
	}

	template<typename T>
	inline void Stack<T>::Pop()
	{
		if (top >= 0) 
		{
			--top;
		}
		else 
		{
			throw std::out_of_range("Stack is empty");
		}
	}

	template<typename T>
	inline T& Stack<T>::Top()
	{
		if (!Empty())
		{
			return data[top];
		}
		throw std::out_of_range("Stack is empty");
	}

	template<typename T>
	inline const T& Stack<T>::Top() const
	{
		if (!Empty())
		{
			return data[top];
		}
		throw std::out_of_range("Stack is empty");
	}

	template<typename T>
	inline bool Stack<T>::Empty() const
	{
		return top < 0;
	}

	template<typename T>
	inline int Stack<T>::Size() const
	{
		return top + 1;
	}

	template<typename T>
	inline void Stack<T>::Clear()
	{
		top = -1;
	}
}