package week15;

public class Client {
    public static void main(String args[]) {
        Door door = new Door();
        Motor HyundaiMotor = new HyundaiMotor(door);
        Motor LGMotor = new LGMotor(door);

        HyundaiMotor.moveMotor(Direction.DOWM);
        LGMotor.moveMotor(Direction.UP);

    }
}
