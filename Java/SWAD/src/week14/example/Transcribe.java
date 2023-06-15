package week14.example;

public class Transcribe extends ContentDecorator{

    public Transcribe(Decorator content) {
        super(content);
    }

    public String getContent() {
        String content = super.getContent();
        String translate = Translate(content);
        return translate;
    }

    private String Translate(String content) {
        return content + "has been Translated";
    }
}
