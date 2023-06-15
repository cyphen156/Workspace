package week14.example;

public class Secure extends ContentDecorator{

    public Secure(Decorator decorator) {
        super(decorator);
    }

    public String getContent() {
        String content = super.getContent();
        String encryptContent = encrypt(content);
        return encryptContent;
    }

    private String encrypt(String content) {
        return content + " Encryped";
    }
}
