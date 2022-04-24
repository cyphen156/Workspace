package Week2;

class StringStack implements StackInterface{
	private int top;
	private int size;
	private String Array[];
	
	public StringStack() {
		size = 10;
		top = -1;
		Array = new String[this.size];
	}
	
	
	public boolean isEmpty() {
		return (top == -1);
	}
	
	public boolean isFull() {
		return (top == this.size-1);
	}
	
	public String pop() {
		if (isEmpty()) {
			System.out.println("Stack is empty!");
			return "false";
		}
		else {
			System.out.print(Array[top] + " ");
			return Array[top--];
		}		
	}
	 
	public boolean push(String ob) {
		if (isFull()) {
			System.out.print("Stack is full!");
			return false;
		}
		else {
			Array[++top] = ob;
			System.out.print(Array[top] + " ");
			return true;
		}
	}
}
public class StackManager{

	public static void main(String[] args) {
		StringStack s1 = new StringStack();
		System.out.print(">>");
		s1.push("Yonsei");
		s1.push("Sejong");
		s1.push("Kyunghee");
		s1.push("Hyupsung");
		s1.push("Hoseo");
		System.out.println();
		for(int i = 0; i < 5; i++) {
			s1.pop();
		}
	}

}
