package week6.ex1;

public class BookDiscountPricePolicy implements PricePolicy{
    @Override
    public int calcPrice(int price, int n) {
        return (int)(price * n * 0.95);
    }
}
