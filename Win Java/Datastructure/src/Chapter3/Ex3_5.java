package Chapter3;

public class Ex3_5 {

	public static void main(String[] args) {
	}
}

class Triangle implements shape {//삼각형
	int x, y;
	double area;
	Triangle(int x, int y){
		this.x = x;
		this.y = y;
	}
	public void getArea() {
		this.area = this.x*this.y*0.5;
	}
}


class Rectangle implements shape{//사각형
	int x, y;
	double area;
	Rectangle(int x, int y){
		this.x = x;
		this.y = y;
	}
	public void getArea() {
		this.area = this.x*this.y;
	}
}