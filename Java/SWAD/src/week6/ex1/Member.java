package week6.ex1;

public class Member {
    private String Name;
    private int accPrice;

    public Member(String name) {
        this.Name = name;
        accPrice = 0;
    }

    public String getName() {
        return Name;
    }

    public void addAccPrice(int accPrice) {
        accPrice += accPrice;
    }

    public int getAccPrice() {
        return accPrice;
    }
}
