package Example;

public class linked {

	public static void main(String[] args) {
		LinkedList L = new LinkedList();
		System.out.println("(1) 공백 리스트에 노드 3개 삽입하기");
		L.insertLastNode("월");
		L.insertLastNode("수");
		L.insertLastNode("일");
		L.printListNode();
		
		System.out.println("(2) 수 노드 뒤에 금 노드 삽입하기");
		ListNode pre = L.searchNode("수");
		if(pre == null)
			System.out.println("검색실패 >> 찾는 데이터가 없습니다.");
		else {
			L.insertMiddleNode(pre, "금");
			L.printListNode();
		}
		
		System.out.println("(3) 리스트의 노드를 역순으로 바꾸기");
		L.reverseList();
		L.printListNode();
		
		System.out.println("(4) 리스트의 마지막 노드 삭제하기");
		L.deleteLastNode();
		L.printListNode();
		
		System.out.println("(5) 첫번째 노드 삽입하기");
		L.insertFirstNode("첫번째");
		L.printListNode();

		System.out.println("(6) 특정 노드 (금) 삭제하기");
		L.deleteNode("금");
		L.printListNode();
	}

}

class LinkedList{
	private ListNode head;
	public LinkedList() {
		head = null;
	}
	//마지막 노드 삽입
	public void insertLastNode(String data) {
		ListNode newNode = new ListNode(data);
		if (head == null)
			this.head = newNode;
		else {
			ListNode temp = head;
			while (temp.link != null) 
				temp = temp.link;
			temp.link = newNode;
		}
	} 
	//첫번째에 노드 삽입
	public void insertFirstNode(String data) {
		ListNode newNode = new ListNode(data);
		if (head == null)
			this.head = newNode;
		else {
			newNode.link = head;
			head = newNode;
		}
	}
	//중간에 노드 삽입
	public void insertMiddleNode(ListNode pre, String data) {
		ListNode newNode = new ListNode(data);
		if (head == null)
			this.head = newNode;
		else {
			newNode.link = pre.link;
			pre.link = newNode;
		}
	}
	//특정 노드 삭제
	public void deleteNode(String data) {
		ListNode temp = this.head;
		ListNode pre = null;
		while (temp != null) {
			if(data.equals(temp.getData()))
				break;
			else {
				pre = temp;
				temp = temp.link;
			}
		}
		if(temp == null) {
			System.out.println("찾는 데이터가 없습니다.");
			return;
		}
		if (pre == null)
			this.head = head.link;
		else
			pre.link = temp.link;
	}
	//마지막 노드 삭제
	public void deleteLastNode() {
		ListNode pre, temp;
		if (head == null) 
			return;
		if (head.link == null)
			head = null;
		else {
			pre = head;
			temp = head.link;
			while (temp.link != null) {
				pre = temp;
				temp = temp.link;
			}
			pre.link = null;
		}
	}
	//특정 노드 검색
	public ListNode searchNode(String data) {
		ListNode temp = this.head;
		while(temp != null) {
			if (data == temp.getData())
				return temp;
			else
				temp = temp.link;
		}
		return temp;
	}
	//노드 순서 뒤집기
	public void reverseList() {
		ListNode next = head;
		ListNode current = null;
		ListNode pre = null;
		while (next !=null) {
			pre = current;
			current = next;
			next = next.link;
			current.link = pre;
		}
		head = current;
	}
	//리스트노드 출력하기
	public void printListNode() {
		ListNode temp = this.head;
		System.out.printf("L = (");
		while (temp != null) {
			System.out.printf(temp.getData());
			temp = temp.link;
			if(temp != null)
				System.out.printf(", ");
		}
		System.out.printf(")");
	}
}
	//노드생성자
class ListNode{
	private String data;
	public ListNode link;
	public ListNode() {
		this.data = null;
		this.link = null;
	}
	public ListNode(String data) {
		this.data = data;
		this.link = null;
	}
	public ListNode(String data, ListNode link) {
		this.data = data;
		this.link = link;
	}
	public String getData() {
		return this.data;
	}
}