package week7.ex2;

public class TicketManager {
    private static TicketManager ticketManager = new TicketManager();
    private int cnt = 0;
    private TicketManager() {}

    public static TicketManager getTicketManager{
        return ticketManager;
    }
}
