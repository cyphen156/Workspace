package Week7;

public class ArrayQueue implements Queue{
	private int front;
	private int rear;
	private int qSize;
	private char itemArr[];
	
	public ArrayQueue(int qSize) {
		front = -1;
		rear = -1; 
		this.qSize = qSize;
		itemArr = new char[this.qSize];
	}

	public boolean isEmpty() {
		return (front == rear);
	}

	public boolean isFull() {
		return (rear == this.qSize-1);
	}
	
	public void enQueue(char item) {
		if(isFull())
			System.out.println("Inserting fail! Array Queue is full!!");
		else {
			itemArr[rear++] = item;
			System.out.println("Inserted Item :" + item);
		}
	}


	public char deQueue() {
		if (isEmpty()) {
			System.out.println("Deleting fail! Array Queue is empty!!");
			return 0;
		}
		else
			return itemArr[++front];
	}

	public void delete() {
		if(isEmpty()) {
			System.out.println("Deleting fail! Array Queue is empty!!");
		}
		else
			++front;
	}


	public char peek() {
		if (isEmpty()) {
			System.out.println("Peeking fail! Array Queue is empty!!");
			return 0;
		}
		else
			return itemArr[front+1];
	}
	
	public void printQueue() {
		if (isEmpty())
			System.out.println("Array is Empty!!\n\n");
		else {
			{
				System.out.printf("Array Queue >> ");
				for(int i = front + 1; i < rear; i++) {
					System.out.printf("%c ", itemArr[i]);
				}
				System.out.println();
				System.out.println();
			}
		}
	}
}