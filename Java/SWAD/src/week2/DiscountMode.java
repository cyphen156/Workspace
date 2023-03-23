package week2;

public class DiscountMode extends Song{
    private DiscountMode mode;

    @Override
    public void setMode(DiscountMode mode) {
        this.mode = mode;
    }

    public double getDiscountRate(){
        return 10.0;
    }
}
