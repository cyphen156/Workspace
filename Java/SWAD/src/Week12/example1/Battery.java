package Week12.example1;

public class Battery extends Subject {
    private int level = 100;

    public void consume(int amount) {
        level -= amount;
        notifyObservers();
    }

    public void charge(int amount) {
        level += amount;
        notifyObservers();
    }

    public int getLeve(){
        return level;
    }
}
