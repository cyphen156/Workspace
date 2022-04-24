package Week2;

import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.Map.Entry;

public class HashMapClass {

	public static void main(String[] args) {
		Entry<String, Integer> maxEntry = null;
		Scanner scan = new Scanner(System.in);
		HashMap<String, Integer> nations = new HashMap<String, Integer>();
		System.out.println("나라 이름과 인구를 3개 입력하세요. (예: Korea 5000)");
		System.out.print("나라 이름, 인구 >> ");
		nations.put(scan.next(), scan.nextInt());
		System.out.println();
		System.out.print("나라 이름, 인구 >> ");
		nations.put(scan.next(), scan.nextInt());
		System.out.println();
		System.out.print("나라 이름, 인구 >> ");
		nations.put(scan.next(), scan.nextInt());
		System.out.println();
	    Set<Entry<String, Integer>> entrySet = nations.entrySet();
	    for (Entry<String, Integer> entry : entrySet) {
	    	if ( maxEntry == null || entry.getValue() > maxEntry.getValue() )
	    		maxEntry = entry;
	    }
		System.out.print("제일 인구가 많은 나라는 (" + maxEntry.getKey() + maxEntry.getValue() + ")");
		scan.close();
	}

}

