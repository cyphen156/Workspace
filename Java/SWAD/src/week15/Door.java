package week15;

public class Door {

    private DoorStatus doorStatus;

    public Door (){
        doorStatus = DoorStatus.CLOSED;
    }
    public DoorStatus getDoorStatus() {
        return doorStatus;
    }

    public void close() {
        doorStatus = DoorStatus.CLOSED;
        System.out.println("문닫기");
    }

    public void open(){
        doorStatus = DoorStatus.OPENED;
        System.out.println("문열기");
    }
}
