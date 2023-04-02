package week4;

public class PayLogic3 implements PayManager{

    @Override
    public int calcPay(Employee emp){
        return 10000*emp.getWorkHours() + 20000*emp.getOverTimeHours();
    }
}

