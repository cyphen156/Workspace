package week4;

public class PayLogic1 implements PayManager{

    @Override
    public int calcPay(Employee emp){
        return 10000 * emp.getWorkHours() + 15000 * emp.getOverTimeHours();
    }
}
