package week4;

public class PayLogic2 implements PayManager{

    @Override
    public int calcPay(Employee emp){
        return 10000*emp.getWorkHours() + 17500*emp.getOverTimeHours();
    }
}
