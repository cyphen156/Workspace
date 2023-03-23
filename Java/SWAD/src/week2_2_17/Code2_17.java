package week2_2_17;

abstract class Pet {
	// 각각의 자식 클래스들의 상위 클래스인 추상클래스 Pet을 생성하여
	// 추상메소드 talk를 통해 다형성을 형성합니다.
	public abstract void talk();
}

class Dog extends Pet {
	public void talk() {
		System.out.println("Dog said : bark!");
	}
}
class Cat extends Pet {
	public void talk() {
		System.out.println("Cat said : meow!");
	}
}
class Parrot extends Pet {
	public void talk() {
		System.out.println("Parrot said : sing!");
	}
}

public class Code2_17 {

	public static void groupTalk(Pet[] p) {
		int i;
		
		for (i = 0; i < 3; i++)
			p[i].talk();
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Pet[] p = {new Cat(), new Dog(), new Parrot()};
		groupTalk(p);
		System.out.print("20170677_오융택");
	}

}
