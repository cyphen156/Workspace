#pragma once

namespace Linear_Data_Structures
{
	// Stack class definition
	template<typename T>
	class Stack
	{
	public:
			Stack() : top(-1) {}
			void push(const T& value);
			void pop();
			T peek() const;
			bool isEmpty() const;
			int size() const;

	private:
		T* data;
		int topIndex;
		int capacity;
	};
}