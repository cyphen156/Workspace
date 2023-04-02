package week4;

import java.io.IOException;

public class PaymentOnFile extends PayrollManager{
    protected void writePayment(int amount) throws IOException {
        System.out.println(amount + "printed on File");
    }

    @Override
    protected void writePayment() {

    }
}
