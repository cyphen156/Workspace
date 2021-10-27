package midterm;

public class Ex2_20170677 {

	public static void main(String[] args) {
		LinkedList L = new LinkedList();
		L.insertFirstNode("홍길동");
		L.insertFirstNode("이순신");
		L.insertFirstNode("강감찬");
		L.printNode();
	}

}
class Node{
	private String data;
	public Node link;
	public Node() {
		this.data = null;
		this.link = null;
	}
	public Node(String data) {
		this.data = data;
		this.link = null;
	}
	public Node(String data, Node link) {
		this.data = data;
		this.link = link;
	}
	public String getData() {
		return this.data;
	}
}

class LinkedList{
	private Node head;
	public LinkedList() {
		head = null;
	}
	public void insertFirstNode(String data) {
		Node newNode = new Node(data);
		if (head == null)
			this.head = newNode;
		else {
			newNode.link = head;
			head = newNode;
		}
	}
	public void printNode() {
		Node temp = this.head;
		System.out.printf("Linked List >> ");
		while (temp != null) {
			System.out.printf(temp.getData());
			temp = temp.link;
			if(temp != null)
				System.out.printf(" ");
		}
	}
}
	