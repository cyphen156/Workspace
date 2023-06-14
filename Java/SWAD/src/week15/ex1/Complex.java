package week15.ex1;

import java.util.ArrayList;
import java.util.List;

public class Complex extends ReportGenerator{
    @Override
    protected List<Customer> renew(List<Customer> customers) {
        List<Customer> renewedCustomers = new ArrayList<>();
        for (int i = 0; i < customers.size(); i++) {
            Customer customer = customers.get(i);
            if (customer.getPoint() >= 100) {
                renewedCustomers.add(customer);
            }
        }
        return renewedCustomers;
    }
}
