package week14;

public class CrossingDisplay extends DisplayDecorator{
	 public CrossingDisplay (Display decoratorDisplay) {
		 super(decoratorDisplay);
	 }
	 
	 public void draw() {
		 super.draw();
		 drawLane();
	 }
	 
	 private void drawLane() {
		 System.out.println("\t교차로 표시");
	 }
}
