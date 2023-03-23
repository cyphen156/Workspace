package week2_84;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Animal[] animals = { new Cat(), new Dog(), new Lion(), new Snake()};
		((Cat)animals[0]).printName();
		((Dog)animals[1]).printName();
		((Lion)animals[2]).printName();
		((Lion) animals[2]).ride();
		animals[3].printName();

	}

}
