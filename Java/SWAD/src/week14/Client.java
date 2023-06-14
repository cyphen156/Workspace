package week14;

public class Client {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Display road = new RoadDisplay();
		road.draw();
		
		Display lane = new LaneDecorator(road);
		lane.draw();
		
		Display traffic = new TrafficDecorator(road);
		traffic.draw();
		
		Display cross = new CrossingDisplay(road);
		cross.draw();
		
		Display all = new CrossingDisplay(new LaneDecorator(new TrafficDecorator(road)));
		all.draw();
	}

}
