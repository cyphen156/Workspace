package week6.ex2;
public class VerticalMoveStrategy extends DirectionStrategy {
	public void move(Ball ball) {
		ball.setIntervals(0, Ball.INTERVAL);
		while (true) {
			ball.setY(ball.getY()+ball.getyInterval());
			if ((ball.getY() < 0 && ball.getyInterval() < 0)
					|| ball.getY() + Ball.SIZE > BallFrame.HEIGHT - 10 && ball.getyInterval() > 0){
				//만약 공의 Y좌표가 0보다 작고 interval이 0보다 작은 경우 또는
				// 공의 크기 + 좌표의 값이 화면의 높이 - 10보다 크고 공의 interval이 0보다 큰 경우
				ball.setIntervals( 0, -ball.getyInterval()); // 공의 이동 방향을 180도 변경한다 (-interval)
			}
			try {
				Thread.sleep(30);
			}catch (InterruptedException e){

			}
		}
	}
}
