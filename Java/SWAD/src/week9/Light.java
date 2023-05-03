package week9;

public class Light {
    private State state;
    private static Light light = new Light();

    public Light() {
      state = OFF.getInstance();
    }

    public static Light getInstance() {
        return light;
    }

    public void setState(State state) {
        this.state = state;
    }

    public void on_button_pushed() {
        state.on_button_pushed(this);
    }
    public void off_button_pushed() {
        state.off_button_pushed(this);
    }
}
