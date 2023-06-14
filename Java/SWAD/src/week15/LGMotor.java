package week15;

public class LGMotor extends Motor{

    public LGMotor(Door door) {
        super(door);
    }

    @Override
    protected void moveMotor(Direction direction) {
        System.out.println("LG모터 " + direction + " 움직이기");
    }
}
