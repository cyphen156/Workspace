package week14.example;

public class Basic extends Decorator{
	
	public Basic(Stirng content) {
		super(content);
		this.content = content;
	}
	public String getContent() {
		return this.content;
	}
}
