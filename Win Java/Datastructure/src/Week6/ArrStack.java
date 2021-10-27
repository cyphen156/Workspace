package Week6;

import java.util.Scanner;
public class ArrStack {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println();
		System.out.print("스택의 최대 크기를 입력하세요 : ");
		int stackSize = sc.nextInt();
		int menu;
		String item;
		
		ArrayStack AS = new ArrayStack(stackSize);
		
		while (true) {
			System.out.printf("현재 데이터 수 : %d/%d\n", AS.countStack()+1, stackSize);
			System.out.print("메뉴 선택(1.Push  2.pop  3.Dump  4.초기화  5.종료) ");
			menu = sc.nextInt();
			if (menu == 1) {
				System.out.print("\npush data 입력 : ");
				item = sc.next(); 
				AS.push(item);
			}
			else if (menu == 2) {
				item = AS.pop();
				System.out.println("\npop data : " + item);				
			}				
			else if (menu == 3)	{
				AS.printStack();
			}
			else if (menu == 4) {
				AS.initStack();
			}else
				break;
		}
		
		System.out.println("\n프로그램 종료");
		sc.close();
	}
}

interface Stack{
	boolean isEmpty();
	void push(String item);
	String pop();
	void delete();
}

class ArrayStack implements Stack{
	private int top;
	private int stackSize;
	private String itemArray[];
	
	public ArrayStack(int stackSize) {
		top = -1;
		this.stackSize = stackSize;
		itemArray = new String[this.stackSize];
	}
		
	public boolean isEmpty() {
		return (top == -1);
	}
	
	public boolean isFull() {
		return (top == this.stackSize-1);
	}
	
	public void push(String item) {
		if(isFull()) {
			System.out.println("Inserting fail! Array Stack is full!!");
		}
		else {
			itemArray[++top] = item;
			System.out.println("Inserted Item : " + item);
		}
	}
	
	public String pop() {
		if(isEmpty()) {
			System.out.println("Deleting fail! Array Stack is empty!!");
			return "0";
		}
		else {
			return itemArray[top--];
		}
	}
	
	public void delete() {
		if(isEmpty()) {
			System.out.println("Deleting fail! Array Stack is empty!!");
		}
		else {
			top--;
		}
	}
	
	public String peek() {
		if(isEmpty()) {
			System.out.println("Peeking fail! Array Stack is empty!!");
			return "0";
		}
		else return itemArray[top];
	}
	
	public void printStack() {
		if(isEmpty()) {
			System.out.printf("Array Stack is empty!!\n\n");
		}
		else {
			System.out.printf("Array Stack>> ");
			for(int i = 0; i<=top; i++) {
				System.out.printf("%s", itemArray[i]);
			}
			System.out.println();System.out.println();
		}
	}
	
	public int countStack() {
		int num = 0;
		if(isEmpty()) {
			num = -1;
		}
		else {
			for (int i = 0; i<= top;i++) {
				num++;
			}
			num--;
		}return num;
	}
	
	public void initStack() {
		if(isEmpty()) {
			System.out.println("clearing fail! already clear Stack!!!");
		}
		else {
			System.out.println("Initiating Clearing Stacks!!");
			top = -1;
		}
	}
}