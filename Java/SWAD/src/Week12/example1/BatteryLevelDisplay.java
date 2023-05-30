package Week12.example1;

public class BatteryLevelDisplay implements Observer{
    private Battery battery;

    public BatteryLevelDisplay (Battery battery) {
        this.battery = battery;
    }

    public void update(){
        int level = battery.getLeve();
        System.out.println("Level: " + level);
    }
}
