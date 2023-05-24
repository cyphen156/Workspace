package Week12;

public class Client {
    public static void main (String[] args) {
        ScoreRecord scoreRecord = new ScoreRecord();

        DataSheetView dataSheetView3 = new DataSheetView(scoreRecord, 3);
        DataSheetView dataSheetView5 = new DataSheetView(scoreRecord, 5);
        MinMaxView minMaxView = new MinMaxView(scoreRecord);

        scoreRecord.attach(dataSheetView3);
        scoreRecord.attach(dataSheetView5);
        scoreRecord.attach(minMaxView);
        scoreRecord.detach(minMaxView);

        for (int index = 1; index <= 5; index++) {
            int score = index * 10;
            System.out.println("ADD " + score);

            scoreRecord.addScore(score);
        }
    }
}
