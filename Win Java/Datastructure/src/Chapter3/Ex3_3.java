package Chapter3;

public class Ex3_3 {//포인트 XY

	public static void main(String[] args) {
	}

}

class PointXY{
	int x, y;
	PointXY(int x, int y){//생성자 메소드
		this.x = x;
		this.y = y; 
	}
	void setX(int x) {
		this.x = x;
	}
	void setY(int y) {
		this.y = y;
	}
	void moveXY(int x, int y) {
		this.x += x;
		this.y += y;
	}
}