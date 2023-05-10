package week10;

public class Main {
    public static void main(String[] args) {
        TV tv = new TV();

        TwoButtonController rc = new TwoButtonController();

        Command PoewerCommand = new PowerCommand(tv);
        Command MuteCommand = new MuteCommand(tv);


    }
}
