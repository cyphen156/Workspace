package composite.after1;

public class Client {
	public static void main(String[] args) {
		Computer computer = new Computer() ;
		Body body = new Body(100, 70) ;
		Keyboard keyboard = new Keyboard(5, 2) ;
		Monitor monitor = new Monitor(20, 30) ;
		
		computer.addComponent(body) ;
		computer.addComponent(keyboard) ;
		computer.addComponent(monitor) ;
		
		int computerPrice = computer.getPrice() ;
		int computerPower = computer.getPower() ;
		
		System.out.println("Computer Power: " + computerPower + " W") ;
		System.out.println("Computer Price: " + computerPrice + " ����") ;	
	}
}
