package Week13;

public class Ex13_2 {

	public static void main(String[] args) {
		BinarySearchTree bsT = new BinarySearchTree();
		bsT.insertBST('G');
		bsT.insertBST('I');
		bsT.insertBST('H');
		bsT.insertBST('D');
		bsT.insertBST('B');
		bsT.insertBST('M');
		bsT.insertBST('N');
		bsT.insertBST('A');
		bsT.insertBST('J');
		bsT.insertBST('E');
		bsT.insertBST('Q');
		
		System.out.printf("\nBinary Tree >>> ");
		bsT.printBST();
		
		System.out.printf("Is There \"A\" ? >>>");
		TreeNode p1 = bsT.searchBST('A');
		if(p1 != null)
			System.out.printf("Searching Success! Searched key : %c \n", p1.data);
		else
			System.out.printf("Searching fail!! \n");
		
		System.out.printf("Is There \"Z\"? >>>");
		TreeNode p2 = bsT.searchBST('Z');
		if(p2 != null)
			System.out.printf("Searching Success! Searched key : %c \n", p2.data);
		else
			System.out.printf("Searching fail!! \n");
	}
}

class TreeNode{
	char data;
	TreeNode left;
	TreeNode right;
}

class BinarySearchTree{
	private TreeNode root = new TreeNode();
	
	public TreeNode insertKey(TreeNode root, char x) {//키로받은 x값을 이진트리안에 삽입합니다.
		TreeNode p = root; //루트값을 p에 저장해놓고서
		TreeNode newNode = new TreeNode();//새로운 노드를 생성합니다
		newNode.data = x; //생성한 노드에 x값을 저장하고
		newNode.left = null; //일단 좌측 자식노드를 null,
		newNode.right = null; //우측 자식노드도 null로 지정합니다
		if (p == null) //만약 루트가 null이면 새 노드를 루트로 저장하고,
			return newNode;
		else if(newNode.data < p.data) {//만약 새로 생성된 노드의 값이 루트의 값보다 작으면 루트의 왼쪽 자식노드에 새 노드를 저장하고, 
			p.left = insertKey(p.left, x);
			return p;
		}
		else if(newNode.data > p.data) {//새로 생성된 노드의 값이 루트의 값보다 크면 루트의 오른쪽 자식노드에 새 노드를 저장합니다.
			p.right = insertKey(p.right, x);
			return p;
		}
		else return p;// 새 노드 값이 저장된 이진트리를 리턴해줍니다.
	}
	
	public void insertBST(char x) {//생성된 이진 트리에 x라는 값을 삽입합니다.
		root = insertKey(root, x);//insertKey메소드를 불러와 이진트리 루트밑에 x라는 노드를 생성해서 삽입합니다.
	}
	
	public TreeNode searchBST(char x) {// x 값을 이진트리 내부에 존재하는지 탐색합니다.
		TreeNode p = root;//탐색할 트리의 노드값을 가져와서
		while (p != null) {//트리의 노드가 null이 될 때까지 탐색하는데
			if(x < p.data)//탐색할 값이 현재 위치한 루트노드값보다 작을 경우
				p = p.left; //루트의 위치를 루트 왼쪽 자식 노드로 옮깁니다.
				else if(x > p.data)//탐색할 값이 현재 위치한 루트노드값보다 클 경우
					p = p.right; //루트의 위치를 루트 오른쪽 자식 노드로 옮깁니다.
			else return p;//루트노드의 값과 탐색할 값이 같은 경우 노드 값을 그대로 리턴해줍니다. 
		}
		return p;//찾은 노드의 값을 리턴해줍니다.
	}
	
	public void inorder(TreeNode root) {//순서를 정렬합니다.
		if(root != null) {//이진 트리의 루트값이 null이 아닌 경우
			inorder(root.left);//이진트리의 맨 왼쪽 값부터 찾아서
			System.out.printf(" %c", root.data);//노드의 값을 출력해주고
			inorder(root.right);//루트 오른 쪽 값을 찾아서 출력해줍니다.
		}
	}
	
	public void printBST() {//이진 트리 전체를 출력해줍니다.
		inorder(root);
		System.out.println();
	}
}
