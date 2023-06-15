package week14.example;

public class Basic extends Decorator{
    private String content;

	public Basic(String content) {
		this.content = content;
	}
	public String getContent() {
		return content;
	}
}
