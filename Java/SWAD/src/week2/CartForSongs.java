package week2;

import java.util.ArrayList;
import java.util.Iterator; 

public class CartForSongs {
	ArrayList<Song> cart = new ArrayList<Song>();
	
	public double calculateTotalPrice() {
		double total = 0.0;
		Iterator<Song> itr = cart.iterator();
		
		while (itr.hasNext()) {
			Song s = itr.next();
			
			total = s.getPrice();
		}
		return total;
	}
	
	public void add(Song s) {
		cart.add(s);
	}
}