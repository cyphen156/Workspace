package week6.ex1;

public class MemberDiscountPricePolicy implements PricePolicy{
    @Override
    public int calcPrice(int price, int n) {
        return (int)(price * n * 0.90);
    }
}
