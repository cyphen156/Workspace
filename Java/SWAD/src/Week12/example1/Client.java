package Week12.example1;

public class Client {
    public static void main(String[] args) {
        Battery battery = new Battery();
        Observer display = new BatteryLevelDisplay(battery);
        Observer warning = new LowBatteryWarning(battery);
        Observer empty = new EmptyBatteryWarning(battery);

        battery.attach(display);
        battery.attach(warning);
        battery.attach(empty);

        battery.consume(20);
        battery.consume(50);
        battery.consume(10);
        battery.consume(20);
        battery.charge(50);
    }
}
