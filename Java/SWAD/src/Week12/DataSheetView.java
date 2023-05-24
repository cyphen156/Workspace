package Week12;

import java.util.List;

public class DataSheetView implements Observer{
    private ScoreRecord scoreRecord;
    private int viewCount;

    public DataSheetView(ScoreRecord scoreRecord, int viewCount) {
        this.scoreRecord = scoreRecord;
        this.viewCount = viewCount;
    }

    public void update() {
        List<Integer> record = scoreRecord.getScoreRecord();
        displayScores(record, viewCount);
    }

    private void displayScores(List<Integer> record, int viewCount) {
        System.out.println("List of " + viewCount + " Entries: ");
        for (int i = record.size() ; i <= record.size()-viewCount; i--){
            System.out.print(record.get(i) + " ");
        }
        System.out.println();
    }
}
