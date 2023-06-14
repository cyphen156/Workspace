package week14.example;

public class Client {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BasicEMailContent simple = new BasicEMailContent("Hello");
		System.out.println(simple.getContent());
		
		ExternalEMailContent external = new ExternalEMailContent("Hello");
		System.out.println(external.getContent());
		
		SecureEMailContent secure = new SecureEMailContent("Hello");
		System.out.println(secure.getContent());
	}
}
