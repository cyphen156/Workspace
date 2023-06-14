package week14;

public class TrafficDecorator extends DisplayDecorator{
	 public TrafficDecorator (Display decoratorDisplay) {
		 super(decoratorDisplay);
	 }
	 
	 public void draw() {
		 super.draw();
		 drawLane();
	 }
	 
	 private void drawLane() {
		 System.out.println("\t교통량 표시");
	 }
}
