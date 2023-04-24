package week6.ex2;

import java.util.Random;

public class Client {
    private static int INIT_LOCATION[] = new int[10];

    public static void main(String[] args) {
        Random rd = new Random();
        for(int i=0;i<10;i++) {
            INIT_LOCATION[i] = rd.nextInt(300);
        }
        Ball balls[] = new Ball[10];
        for (int i = 0; i < balls.length; i++) {
            balls[i] = new Ball(INIT_LOCATION[i], INIT_LOCATION[i]);
            balls[i].setDirectionAndDrawStrategy(INIT_LOCATION[i]);
            balls[i].start();
        }

        new BallFrame(balls);
    }
}
