package week14.example;

public abstract class ContentDecorator extends Decorator{
	private Decorator decorator;

	public ContentDecorator(Decorator content) {
		this.decorator = content;
	}

	public String getContent() {
		return decorator.getContent();
	}
}
