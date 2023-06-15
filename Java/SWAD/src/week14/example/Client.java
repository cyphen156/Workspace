package week14.example;

public class Client {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Decorator simple = new Basic("Hello");
		System.out.println(simple.getContent());

		Decorator external = new External(simple);
		System.out.println(external.getContent());

		Decorator secure = new Secure(simple);
		System.out.println(secure.getContent());

		Decorator translate = new Transcribe(simple);
		System.out.println(translate.getContent());
	}
}
