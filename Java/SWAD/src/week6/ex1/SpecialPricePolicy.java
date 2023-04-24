package week6.ex1;

public class SpecialPricePolicy implements PricePolicy{

    @Override
    public int calcPrice(int price, int n) {
        return price * ((n+2)/2);
    }
}
