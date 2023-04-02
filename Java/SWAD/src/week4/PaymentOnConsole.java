package week4;

public class PaymentOnConsole extends PayrollManager{
    protected void writePayment(int amount) {
        System.out.println(amount + "printed on Console");
    }

    @Override
    protected void writePayment() {

    }
}
