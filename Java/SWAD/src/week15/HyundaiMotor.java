package week15;

public class HyundaiMotor extends Motor{
    public HyundaiMotor(Door door) {
        super(door);
    }

    @Override
    protected void moveMotor(Direction direction) {
        System.out.println("현대모터 " + direction + " 움직이기");
    }
}
