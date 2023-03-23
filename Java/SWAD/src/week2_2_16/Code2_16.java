package week2_2_16;

class Dog {
	public void bark() {
		System.out.println("Dog said : bark!");
	}
}
class Cat {
	public void meow() {
		System.out.println("Cat said : meow!");
	}
}
class Parrot {
	public void sing() {
		System.out.println("Parrot said : sing!");
	}
}

public class Code2_16 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Dog d = new Dog();
		Cat c = new Cat();
		Parrot p = new Parrot();
		
		d.bark();
		c.meow();
		p.sing();
		
		System.out.print("20170677_오융택");
	}

}
