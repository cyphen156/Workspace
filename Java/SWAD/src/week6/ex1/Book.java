package week6.ex1;

public class Book {
    private String name;
    private int publicshYear;
    private int price;

    public Book(String name, int publicshYear, int price) {
        this.name = name;
        this.publicshYear = publicshYear;
        this.price = price;
    }

    public String getName() {
        return this.name;
    }

    public int getPublicshYear() {
        return this.publicshYear;
    }

    public int getPrice() {
        return this.price;
    }
}
