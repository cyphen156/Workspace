//// 제네릭 클래스 선언
//#include <iostream>
//
//using namespace std;
//
//template <class T>
//
//class MyStack {
//	T data;
//	MyStack* front;
//	MyStack* top;
//
//public:
//	MyStack();
//	void push(T data);
//	T pop();
//	bool isEmpty();
//};
//
//template<class T>
//MyStack<T>::MyStack()
//{
//	data = NULL;
//	top = nullptr;
//	front = nullptr;
//}
//
//template<class T>
//void MyStack<T>::push(T data)
//{
//	MyStack<T>* newNode = new MyStack<T>;
//	newNode->front = top;
//	top = newNode;
//	top->data = data;
//}
//
//template<class T>
//T MyStack<T>::pop()
//{
//	MyStack<T>* delNode = top;
//	top = top->front;
//	T data = delNode->data;
//	delete(delNode);
//	return data;
//}
//
//template<class T>
//bool MyStack<T>::isEmpty() {
//	if (top->top == nullptr)
//		return false;
//	else 
//		return true;
//}
//
//
// // #template 2
//template <class T2>
//
//T2 biggest(T2 a[], int size) {
//	T2 max = 0;
//	for (int i = 0; i < size; ++i) {
//		if (a[i] > max) {
//			max = a[i];
//		}
//	}
//	return max;
//}
//
//int main() {
//	MyStack<int> mStack;
//	mStack.push(3);
//
//	MyStack<string> sStack;
//
//	sStack.push("hello World!");
//	if (!sStack.isEmpty()) {
//		cout << sStack.pop() << endl;
//	}
//	if (!sStack.isEmpty()) {
//		cout << sStack.pop() << endl;
//	}
//
//
//	return 0;
//}
//
