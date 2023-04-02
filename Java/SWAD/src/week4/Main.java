package week4;

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        //TODO Auto-generated method stub
        Employee emp = new Employee();
        PaymentOnConsole poc = new PaymentOnConsole();
        PaymentOnFile pof = new PaymentOnFile();
        PayManager PayLogic1 = new PayLogic1();
        emp.setPaymentManager(PayLogic1);
        emp.workHours(10);
        emp.overTimeHours(5);
        System.out.println("[1]" + emp.calculatePay());
        System.out.println("[2]");
        poc.writePayment(emp.calculatePay());
        System.out.println("[3]");
        pof.writePayment(emp.calculatePay());
    }
}
