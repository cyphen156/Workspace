package Week12;

import java.util.ArrayList;
import java.util.List;

public class ScoreRecord extends Subject{
    private List<Integer> scores = new ArrayList<Integer>();
//    DataSheetView dataSheetView;
//
//    public void setDataSheetView(DataSheetView dataSheetView){
//        this.dataSheetView = dataSheetView;
//    }

//    private MinMaxView minMaxView;
//
//    public void setMinMaxView(MinMaxView minMaxView) {
//        this.minMaxView = minMaxView;
//    }

    public void addScore(int score){
        scores.add(score);
        notifyObservers();
    }

    public List<Integer> getScoreRecord(){
        return scores;
    }
}
