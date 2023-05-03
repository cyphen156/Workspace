package week9;

public class Main {
    public static void main(String[] args) {
        Light light1 = new Light();
        Light light2 = new Light();
        light1.on_button_pushed();
        light1.on_button_pushed();
        light1.off_button_pushed();
        light2.on_button_pushed();
        light2.on_button_pushed();
        light2.off_button_pushed();
        System.out.println(ON.getInstance());
        System.out.println(OFF.getInstance());
        System.out.println(SLEEPING.getInstance());
        System.out.println(light1.getInstance().toString());
        System.out.println(light2.getInstance().toString());
    }
}
