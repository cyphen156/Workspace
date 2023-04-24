package week6.ex1;

public class Rental {
    private Member member;
    private Book book;
    private PricePolicy pricePolicy;
    int n;

    public Rental(Member member, Book book, int n) {
        this.member = member;
        this.book = book;
        this.n = n;
        if (n > 3){
            setStrategy(new SpecialPricePolicy());
        }
        else if(this.member.getAccPrice() >= 10000)
            setStrategy(new MemberDiscountPricePolicy());
        else if ((2023 - this.book.getPublicshYear()) >= 10)
            setStrategy(new BookDiscountPricePolicy());
        else
            setStrategy(new OrdinaryPricePolicy());
        this.member.addAccPrice(pricePolicy.calcPrice(book.getPrice(), n));
    }

    public int getPrice() {
        return pricePolicy.calcPrice(book.getPrice(), n);
    }

    public void setStrategy(PricePolicy pricePolicy) {
        this.pricePolicy = pricePolicy;
    }

    public PricePolicy getPricePolicy() { return this.pricePolicy; }
    public void summary() {
        System.out.println(this.member.getName() + " rented " + this.n + this.book.getName() + " :: " + this.getPricePolicy() + " :: " + getPrice() + " ACC :: " + member.getAccPrice());
    }
}
