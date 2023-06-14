package week14.example;

public abstract class ContentDecorator extends Decorator{
	private Decorator content;
	
	public ContentDecorator(Decorator content) {
		this.content = content;
	}
	
	public String getContent(String str) {
		return this.content;
	}

}
