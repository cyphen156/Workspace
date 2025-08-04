/**
*
* 스택자료구조 구현하기
* //리스트
* 
* using class
*/

#include <iostream>
#include <string>

using namespace std;

class Node {
public:
	string data;
	Node* next;
	
	Node(string data) : data(data), next(nullptr) {}
};

class Stack {
private:
	Node* top;
	int stackSize;

public:
	// 생성자
	Stack() : top(nullptr), stackSize(0){}

	// 소멸자
	~Stack() {
		freeStack();
	}
	bool isEmpty();
	int push();
	void pop();
	void search();
	void printStack();
	void freeStack();
};

void menu(int n, Stack& stack)
{

	switch(n)
	{
	case 0:
		stack.freeStack();
		cout << "프로그램을 종료합니다." << endl;
		exit(0);
	case 1:
		stack.push();
		break;
	case 2:
		stack.pop();
		break;
	case 3:
		stack.search();
		break;
	case 4:
		stack.printStack();
		break;
	default:
		cout << "잘못된 입력입니다. 다시 입력해주세요" << endl;
	}
}

bool Stack::isEmpty()
{
	if (this->top == nullptr)
	{
		cout << "스택이 비어있습니다. 문장을 저장해주세요." << endl;
		return true;
	}
	else
		return false;
}

int Stack::push()
{
	cout << "저장할 문장을 입력해주세요." << endl;
	string src;
	getline(cin, src);
	Node* newNode = new Node(src);
	newNode->next = top;
	top = newNode;
	stackSize++;
	return 0;
}

void Stack::pop()
{
	if (isEmpty())
	{
		return;
	}
	Node* temp = top;
	cout << "제거된 문장: " << temp->data << endl;
	top = temp->next;
	delete temp;
	stackSize--;
}

void Stack::search()
{
	if (isEmpty())
	{
		return;
	}
	cout << "찾고 싶은 문장을 입력하세요: \n";
	string src;
	getline(cin, src);
	int i;
	Node* temp = top;
	for (i = stackSize; i > 0; --i)
	{
		if (temp->data == src)
		{
			cout << src << "는 스택의" << i << "번째에 있습니다." << endl;
			break;
		}
		temp = temp->next;
	}
	cout << src << "는 스택에 없습니다." << endl;

}

void Stack::printStack()
{
	if (isEmpty())
	{
		return;
	}

	int i;
	Node* temp = top;
	for (i = stackSize; i > 0; --i)
	{
		cout << "스택의 위치 : " << i << 
			", 저장된 단어 : " << temp->data << endl;
		temp = temp->next;
	}
}

void Stack::freeStack()
{
	while (this->top != nullptr)
	{
		pop();
	}
}


int main()
{
	Stack stack;
	while (1)
	{
		int input;
		cout << "1 : stack push , 2 : stack pop, 3 : search data, 4 : print stack, 0 : 프로그램 종료" << endl;
		cin >> input;
		getchar();
		menu(input, stack);
	}
	return 0;
}