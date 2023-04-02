package week4;

import java.util.ArrayList;
import java.util.Iterator;

abstract class PayrollManager {
    private ArrayList<Employee> employees = new ArrayList<Employee>();
    protected abstract void writePayment();

    public void writeEmployeePay() {
        Iterator<Employee> iter = employees.iterator();

        while (iter.hasNext()) {
            Employee curEmp = iter.next();
            System.out.println(curEmp.calculatePay());
        }
    }
}
