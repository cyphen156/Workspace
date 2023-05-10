package week10;

public class TwoButtonController {
    private Command command1;
    private Command command2;

    public void setCommand(Command newCommand1, Command newCommand2) {
        this.command1 = newCommand1;
        this.command2 = newCommand2;
    }

    public void Button1pressed() {
        command1.execute();
    }

    public void Button2pressed() {
        command2.execute();
    }
}
