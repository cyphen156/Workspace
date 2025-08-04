#pragma once

namespace Linear_Data_Structures
{
	// Queue class definition
	template<typename T>
	class Queue
	{
	public:
		Queue() : front(0), rear(-1), size(0) {}
		void enqueue(const T& value);
		void dequeue();
		T peek() const;
		bool isEmpty() const;
		int getSize() const;

	private:
		T* data;
		int front;
		int rear;
		int size;
		int capacity;
	};
}