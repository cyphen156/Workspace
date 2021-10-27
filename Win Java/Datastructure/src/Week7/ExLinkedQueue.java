package Week7;

import java.util.Scanner;

public class ExLinkedQueue {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int menu, sw;
		String data, deleteItem;
		
		LinkedQueue LQ = new LinkedQueue();
		
		while(true) {
			System.out.print("큐 메뉴 (1.enQueue 2.deQueqe 3.종료) >> ");
			menu = sc.nextInt();
			sw = 0;
			
			switch(menu) {
			case 1:
				System.out.print("데이터 입력>> ");
				data = sc.next();
				LQ.enQueue(data);
				LQ.printQueue();
				break;
			case 2:
				deleteItem = LQ.deQueue();
				if(deleteItem != "0")
					System.out.println("deleted Item : " + deleteItem);
				LQ.printQueue();
				break;
			default:
				sw = 1;
				break;
			}
			if (sw == 1)
				break;
		}
		System.out.println("프로그램 종료");
		sc.close();
	}

}
