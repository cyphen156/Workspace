package week4;

public class Employee {
    private String id;
    private String Name;
    private int workHours;
    private int overTimeHours;
    private PayManager payManager;

    void workHours(int workHours){
        this.workHours = workHours;
    }
    void overTimeHours(int overTimeHours){
        this.overTimeHours = overTimeHours;
    }
    public int getWorkHours() {
        return this.workHours;
    }
    public int getOverTimeHours() {
        return this.overTimeHours;
    }
    public void setPaymentManager(PayManager payManager) {
        this.payManager = payManager;
    }
    public int calculatePay() {
        return payManager.calcPay(this);
    }
}
