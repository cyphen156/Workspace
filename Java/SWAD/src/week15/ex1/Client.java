package week15.ex1;

import java.util.ArrayList;
import java.util.List;

public class Client {
    public static void main(String args[]) {
        List<Customer> customers = new ArrayList<Customer>();

        customers.add(new Customer("홍길동", 150));
        customers.add(new Customer("우수한", 350));
        customers.add(new Customer("부족한", 50));
        customers.add(new Customer("훌륭한", 450));
        customers.add(new Customer("최고의", 500));

        ReportGenerator simple = new Simple();
        System.out.println(simple.generate(customers));

        ReportGenerator complex = new Complex();
        System.out.println(complex.generate(customers));
    }
}
