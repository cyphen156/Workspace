package week15.ex1;

import java.util.List;

public abstract class ReportGenerator {
    public String generate(List<Customer> customers) {
        customers = renew(customers);
        String report = String.format("고객 수: %d명\n",  customers.size());
        for (int i = 0; i < customers.size(); i++) {
            Customer customer = customers.get(i);
            report += String.format("%s: %d\n", customer.getName(), customer.getPoint());
        }
        return report;
    }

    protected abstract List<Customer> renew(List<Customer> customers);
}
