package week6.ex2;
public class DiagonalMoveStrategy extends DirectionStrategy {
	public void move(Ball ball) {
		ball.setIntervals(Ball.INTERVAL, Ball.INTERVAL);
		while (true) {
			ball.setX(ball.getX() + ball.getxInterval());
			ball.setY(ball.getY() + ball.getyInterval());
			if ((ball.getX() < 0 && ball.getxInterval() < 0)	//X이동 방향 결정
					|| ball.getX() + Ball.SIZE > BallFrame.WIDTH - 15 && ball.getxInterval() > 0) {
				ball.setIntervals(-ball.getxInterval(), ball.getyInterval());
			}
			if ((ball.getY() < 0 && ball.getyInterval() < 0)	//Y이동 방향 결정
					|| ball.getY() + Ball.SIZE > BallFrame.HEIGHT - 40 && ball.getyInterval() > 0) {
				ball.setIntervals(ball.getxInterval(), -ball.getyInterval());
			}
			// X와 Y가 동시에 움직이므로 공이 대각선 방향으로 이동한다.
			try {
				Thread.sleep(30);
			} catch (InterruptedException e) {

			}

		}
	}
}
