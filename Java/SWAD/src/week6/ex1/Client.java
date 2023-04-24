package week6.ex1;

public class Client {
    public static void main(String[] args){
        Member member1 = new Member("Tom");
        Member member2 = new Member("Jane");

        Book book1 = new Book("Operating System Conceptw", 2005, 25000);
        Book book2 = new Book("Introduction to SoftWare Testing", 2019, 34000);

        Rental rental1 = new Rental(member1, book1, 2);
        Rental rental2 = new Rental(member2, book2, 4);

        rental1.summary();
        rental2.summary();
    }
}
