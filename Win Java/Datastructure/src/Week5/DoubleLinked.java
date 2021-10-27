package Week5;

public class DoubleLinked {

	public static void main(String[] args) {
		DblLinkedList dL = new DblLinkedList();
		System.out.println("\n(1) 공백 리스트에 노드 3개 삽입하기");
		dL.addLast("월");
		dL.addLast("수");
		dL.addLast("일");
		dL.printList();
		
		System.out.println("\n(2) 수 노드 뒤에 금 노드 삽입하기");
		ListNode pre = dL.searchNode("수");
		if(pre == null)
			System.out.println("검색실패 >> 찾는 데이터가 없습니다.");
		else {
			dL.add("금");
			dL.printList();
		}
		
		System.out.println("\n(3) 마지막 노드 뒤에 화 노드 삽입하기");
		dL.addLast("화");
		dL.printList();
		
		System.out.println("\n(4) 특정 데이터(일)가 있는 노드 삭제하기");
		ListNode temp = dL.searchNode("일");
		if(temp == null)
			System.out.println("검색실패 >> 찾는 데이터가 없습니다.");
		else {
			dL.deleteNode(temp);
			dL.printList();
		}		
	}
}

class ListNode{
	private String data;
	public ListNode llink, rlink;
	public ListNode(){
		this.data = null;
		this.llink = this.rlink = this;
	}
	public ListNode(String data) {
		this.data = data;
		this.llink = this.rlink = null;
	}
	public ListNode(String data, ListNode llink, ListNode rlink) {
		this.data = data;
		this.llink = llink;
		this.rlink = rlink;
	}
	public String getData() {
		return this.data;
	}
}

class DblLinkedList{
	private ListNode head;
	private ListNode crnt;
	public DblLinkedList() {
		head = crnt = new ListNode();
	}
	
	public void add(String data) {
		ListNode node = new ListNode(data, crnt, crnt.rlink);
		crnt.rlink = crnt.rlink.llink = node;
		crnt = node;
	}
	
	public void addFirst(String data) {
		crnt = head;
		add(data);
	}
	
	public void addLast(String data) {
		crnt = head.llink;
		add(data);
	}
	
	public void deleteNode(ListNode node) {
		ListNode tmpLlink, tmpRlink;
		tmpLlink = node.llink;
		tmpRlink = node.rlink;
		node.rlink.llink = tmpLlink;
		node.llink.rlink = tmpRlink;
	}
	
	public ListNode searchNode(String data) {
		ListNode temp = head.rlink;
		while (temp != head) {
			if (data == temp.getData()) {
				crnt = temp;
				return temp;
			} else
				temp = temp.rlink;
		}
		return null;
	}
	
	public void printList() {
		ListNode temp = head.rlink;
		System.out.print("doubleList = (");
		while (temp != head) {
			System.out.print(temp.getData());
			temp = temp.rlink;
			if (temp != null)
				System.out.print(" ");
		}
		System.out.print(")");
	}
}