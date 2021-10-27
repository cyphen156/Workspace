package Week7;

public class ArrayCQueue implements Queue{
	private int front;
	private int rear;
	private int qSize;
	private char itemArr[];

	
	public ArrayCQueue (int qSize) {
		front = 0;
		rear = 0;
		this.qSize = qSize;
		itemArr = new char[this.qSize];
	}
	
	public boolean isEmpty() {
		return (front == rear);
	}

	public boolean isFull() {
		return (((rear+1)%this.qSize) == front);
	}
	
	public void enQueue(string item) {
		if(isFull()) 
			System.out.println("Inserting fail! Array Circular Queue is full!!");
		else {
			rear = (rear+1)%this.qSize;
			itemArr[rear] = item;
			System.out.println("Inserted item : " + item);
		}
	}

	public char deQueue() {
		if (isEmpty()) {
			System.out.println("Deleting fail! Array Circular Queue is empty!!");
			return 0;
		}
		else {
			front = (front+1)%this.qSize;
			return itemArr[front];
		}
		
	}

	public void delete() {
		if (isEmpty()) 
			System.out.println("Deleting fail! Array Circular Queue is empty!!");
		else
			front = (front+1)%this.qSize;
	}

	public char peek() {
		if (isEmpty()) {
			System.out.println("Peeking fail! Array Circular Queue is empty!!");
			return 0;
		}
		else
			return itemArr[(front+1)%this.qSize];
	}

	public void printQueue() {
		if (isEmpty()) 
			System.out.println("Array Circular Queue is empty!!");
		else {
			System.out.printf("Array Circular Queue>> ");
			for(int i = (front+1)%this.qSize; i != (rear+1)%this.qSize; i = ++i % this.qSize) 
				System.out.printf("%c", itemArr[i]);
			System.out.println();
			System.out.println();
		}
	}
}
