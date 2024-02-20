/**
*
* 큐 자료구조 구현하기
* // 단일연결리스트
* 
* using class
*/
/*

#include <iostream>
#include <string>

using namespace std;

class Node {
public:
	string data;
	Node* next;
	
	Node(string data) : data(data), next(nullptr) {}
};

class Queue {
private:
	Node* front;
	Node* rear;

public:
	// 생성자
	Queue() : front(nullptr), rear(nullptr){}

	// 소멸자
	~Queue() {
		freeQueue();
	}
	bool isEmpty();
	int enQueue();
	int deQueue();
	void search();
	void printQueue();
	void freeQueue();
};

void menu(int n, Queue& queue)
{

	switch(n)
	{
	case 0:
		queue.freeQueue();
		cout << "프로그램을 종료합니다." << endl;
		exit(0);
	case 1:
		queue.enQueue();
		break;
	case 2:
		queue.deQueue();
		break;
	case 3:
		queue.search();
		break;
	case 4:
		queue.printQueue();
		break;
	default:
		cout << "잘못된 입력입니다. 다시 입력해주세요" << endl;
	}
}

bool Queue::isEmpty()
{
	if (this->front == nullptr)
	{
		cout << "스택이 비었습니다." << endl;
		return true;
	}
	return false;
}

int Queue::enQueue()
{
	cout << "저장할 문장을 입력해주세요.\n";
	string data;
	getline(cin, data);
	Node* newNode = new Node(data);
	if (this->front == nullptr)
	{
		printf("첫번째 데이터를 입력합니다.\n");
		front = rear = newNode;
	}
	else
	{
		rear->next = newNode;	// 새 노드로 가는 길뚫기
		rear = newNode;			// 뚫은 길에 할당하기
	}
	return 1;
}

int Queue::deQueue()
{
	if (isEmpty())
	{
		printf("단어를 저장해주세요.\n");
		return 0;
	}
	Node* temp = this->front;
	this->front = this->front->next;
	if (front == nullptr)
	{
		rear = nullptr;
	}
	cout << "제거된 문장 : " << temp->data << endl;	
	delete temp;
	return 1;
}

void Queue::search()
{
	if (isEmpty())
	{
		printf("단어를 저장해주세요.\n");
		return;
	}
	cout << "찾고싶은 문장을 입력해주세요.\n";
	string str;
	getline(cin, str);
	Node* temp = front;
	int i = 1;
	while (temp != nullptr)
	{
		if (temp->data == str)
		{
			cout << str << "의 위치는 " << i << "입니다." << endl;
			return;
		}
		++i;
		temp = temp->next;
	}
	cout << "찾으시는 문장은 큐에 없습니다.\n";

}

void Queue::printQueue()
{
	if (isEmpty())
	{
		printf("단어를 저장해주세요.\n");
		return;
	}
	int i = 1;
	Node* temp = front;
	while (temp != nullptr)
	{
		
		cout << temp->data << "의 위치는 " << i << "입니다." << endl;		
		++i;
		temp = temp->next;
	}
}

void Queue::freeQueue()
{
	while (!isEmpty())
	{
		deQueue();
	}
}


int main()
{
	Queue queue;
	while (1)
	{
		int input;
		cout << "1 : enQueue, 2 : deQueue, 3 : search data, 4 : print Queue, 0 : 프로그램 종료" << endl;
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		menu(input, queue);
	}
	return 0;
}

*/