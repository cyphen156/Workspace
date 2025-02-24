package week6.ex2;

import java.awt.Color;

public class Ball extends Thread {
	public static final int SIZE = 20;
	public static final int INTERVAL = 10;
	private int x, y;
	private int xInterval, yInterval;
	private DirectionStrategy directionStrategy;
	private DrawStrategy drawStrategy;
	private Color color;

	public Ball(int x, int y) {
		this.x = x;
		this.y = y;
		this.xInterval = this.yInterval = 0;
	}

	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}

	public int getxInterval() {
		return xInterval;
	}

	public int getyInterval() {
		return yInterval;
	}

	public void setX(int x) {
		this.x = x;
	}

	public void setY(int y) {
		this.y = y;
	}

	public void setIntervals(int xInterval, int yInterval) {	//시작점 설정하기
		this.xInterval = xInterval;
		this.yInterval = yInterval;
	}

	public void setColor(Color color) {
		this.color = color;
	}

	public Color getColor() {
		return this.color;
	}

	public void setDirectionAndDrawStrategy(int i){
		if(i%3 == 1){
			setDrawStrategy(new YellowDrawStrategy());
		} else if (i%3 == 2) {
			setDrawStrategy(new BlueDrawStrategy());
			setDirectionStrategy(new VerticalMoveStrategy());
		} else{
			setDrawStrategy(new RedDrawStrategy());
			setDirectionStrategy(new HorizonalMoveStrategy());
		}
		if(i%4 == 1){
			setDirectionStrategy(new DiagonalMoveStrategy());
		} else if (i%4 == 2) {
			setDirectionStrategy(new VerticalMoveStrategy());
		} else if (i%4 == 3){
			setDirectionStrategy(new HorizonalMoveStrategy());
		} else {
			setDirectionStrategy(new NewMoveStrategy());
		}
	}

	public void setDirectionStrategy(DirectionStrategy directionStrategy) {
		this.directionStrategy = directionStrategy;
	}

	public void setDrawStrategy(DrawStrategy drawStrategy) {
		this.drawStrategy = drawStrategy;
	}


//	public void setDirectionAndDrawStrategy(int i) {
//
//		if(i%3 == 1){
//			this.drawStrategy = new RedDrawStrategy();
//			this.directionStrategy = new DiagonalMoveStrategy();
//		} else if (i%3 == 2) {
//			this.drawStrategy = new BlueDrawStrategy();
//			this.directionStrategy = new VerticalMoveStrategy();
//		} else{
//			this.drawStrategy = new YellowDrawStrategy();
//			this.directionStrategy = new HorizonalMoveStrategy();
//		}
//	}

	public void draw() {
		drawStrategy.draw(this);
	}

	public void move() {
		directionStrategy.move(this);
	}

	public void run() {

		draw();
		move();
	}
}