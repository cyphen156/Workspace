package week7.ex1;

public class Printer {
    private static Printer printer = new Printer();
    private int cnt = 0;
    private Printer() {}

    public static synchronized Printer getPrinter () {
        return printer;
    }

    public void print(String str) {
        cnt ++;
        System.out.println(str);
    }
}