package week9;

public class ON implements State{
    private static ON on = new ON();
    private ON(){}

    public static ON getInstance() {
        return on;
    }
    @Override
    public void on_button_pushed(Light light) {
        light.setState(SLEEPING.getInstance());
        System.out.println("SLEEPING Mode");
    }

    @Override
    public void off_button_pushed(Light light) {
        light.setState(OFF.getInstance());
        System.out.println("Light Off");
    }
}
