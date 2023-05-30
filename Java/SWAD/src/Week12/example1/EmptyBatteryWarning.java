package Week12.example1;

public class EmptyBatteryWarning implements Observer{
    private static final int empty = 0;
    private Battery battery;

    public EmptyBatteryWarning (Battery battery) {
        this.battery = battery;
    }

    public void update(){
        int level = battery.getLeve();
        if (level == empty){
            System.out.println("<WARNING> Empty Battery: " + level);
        }
    }
}
