package midterm;

import java.util.Scanner;
public class Ex1_20170677 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[][] arr = new int[][] {{73400, 84400, 92900}, {56900, 65400, 71900}, {49900, 57900, 63400}};
		int arr1[] = new int[] {2530, 1960, 1730};
		while (true) {
			int data1, data2, sum;
			System.out.print("1) 출발지 선택 (1.김포/2.부산/3.광주) : ");
			int num1 = sc.nextInt();
			System.out.print("2) 기간 선택 (1.할인/2.기본/3.성수기) : ");
			int num2 = sc.nextInt();
			System.out.print("3) 초과 수화물 량(kg) : ");
			int num3 = sc.nextInt();
			for (int i = 0; i < num1; i++) {
				for(int j = 0;j < num2; j++) {
				}
				data1 = arr[i][j];
			}
			System.out.println();
		}
	}

}
