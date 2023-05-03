package week9;

public class SLEEPING implements State{
    private static SLEEPING sleeping = new SLEEPING();
    private SLEEPING(){}

    public static SLEEPING getInstance() {
        return sleeping;
    }
    @Override
    public void on_button_pushed(Light light) {
        System.out.println("Light On");
        light.setState(ON.getInstance());
    }

    @Override
    public void off_button_pushed(Light light) {
        System.out.println("Light Off");
        light.setState(OFF.getInstance());
    }
}
