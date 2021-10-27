package midterm;

public class Ex4_20170677 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str;
		while (true) {
			System.out.printf("\n체크할 단어 입력(영문) >> ");
			str = sc.next();
			while (true) {
				push
			}
		}
	}

}

class Palindrome{
	private int ptr, front, rear;
	private String[] stack;
	private String[] queue;
	public Palindrome(int len) {
		stack = new String[len];
		queue = new String[len];
	}
	
	public void push(String str) {
		stack[ptr++] = str;
	}
	public void inQue(String str) {
		queue[rear++] = str;
	}
	
	public String pop() {
		return stack[ptr--];
	}
	
	public String deQue(){
		return queue[++front];
	}
}