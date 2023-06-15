package week14.example;

public class External extends ContentDecorator{

    public External(Decorator decorator) {
        super(decorator);
    }

    public String getContent() {
        String content = super.getContent();
        String external = addDisClaimer(content);
        return external;
    }

    private String addDisClaimer(String content) {
        return content + " Company Disclaimer";
    }
}
