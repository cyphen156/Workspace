package Week1;

public class Account { //ex1_8
	private int id;
	private String owner;
	private double balance;
	
	public Account(int id, String owner, double balance) {
		this.id = id;
		this.owner = owner;
		this.balance = balance;
	}
	public void deposit(double balance) {
		this.balance += balance;
	}
	public void withdraw(double balance) {
		this.balance -= balance;
	}
	protected double getBalance() {
		return this.balance;
	}
}
