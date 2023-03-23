package week2;

public class NonDiscounted extends DiscountMode{
    @Override
    public double getDiscountRate() {
        return 0.0;
    }
}
