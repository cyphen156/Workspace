package week6.ex2;

import java.awt.*;
public class YellowDrawStrategy extends DrawStrategy {
	@Override
	public void draw(Ball ball) {
		ball.setColor(Color.yellow);
	}

}
