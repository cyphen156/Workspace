package week15.ex1;

public class Customer {
    private String name;
    private int point;

    public Customer(String name, int point) {
        this.setName(name);
        this.setPoint(point);
    }

    public int getPoint() {
        return this.point;
    }

    public String getName() {
        return this.name;
    }
    private void setPoint(int point) {
        this.point = point;
    }

    private void setName(String name) {
        this.name = name;
    }
}
