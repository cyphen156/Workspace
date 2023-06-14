package week15.ex1;

import java.util.List;

public class Simple extends ReportGenerator{
    @Override
    protected List<Customer> renew(List<Customer> customers) {
        return customers;
    }
}
