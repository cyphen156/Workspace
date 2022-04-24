package Week2;

public class NamedCircle extends Circle{
	
	private String name;

	public NamedCircle (int radious, String name) {
		super(radious);
		this.name = name;
	}
	
	public void show() {
		System.out.println(name + ", ¹ÝÁö¸§ = " + getRadius());
	}

	public static void main(String[] args) {
		NamedCircle w = new NamedCircle(5, "Waffle");
		w.show();
	}

}
