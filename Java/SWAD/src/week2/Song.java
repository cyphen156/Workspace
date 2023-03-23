package week2;

public class Song {
	private DiscountMode mode;
	
	public void setMode(DiscountMode mode) {
		this.mode = mode;
	}
	
	public double getPrice(){return 10.0 - (10.0 * this.mode.getDiscountRate());}
}