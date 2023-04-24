package week6.ex2;
public class NewMoveStrategy extends DirectionStrategy {
    @Override
    public void move(Ball ball) {
        int i = 0;
        ball.setIntervals(Ball.INTERVAL, Ball.INTERVAL);
        while (true) {
            ball.setX(ball.getX() + ball.getxInterval());
            ball.setY(ball.getY() + ball.getyInterval());
            if ((ball.getX() < 0 && ball.getxInterval() < 0) || ball.getX() + Ball.SIZE > BallFrame.WIDTH - 15 && ball.getxInterval() > 0) {
                ball.setIntervals(-ball.getxInterval(), ball.getyInterval());
            }
            if ((ball.getY() < 0 && ball.getyInterval() < 0) || ball.getY() + Ball.SIZE > BallFrame.HEIGHT - 40 && ball.getyInterval() > 0) {
                ball.setIntervals(ball.getxInterval(), -ball.getyInterval());
            }
            try {
                Thread.sleep(5 + i);
            } catch (InterruptedException e) {

            }
            i += 10;
            if(i >= 200){
                i = 0;
            }
        }
    }
}
