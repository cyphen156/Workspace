package ac.uhs.appexample;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private Button mButton;
    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mButton = (Button) findViewById(R.id.button);
    }
    public void mOnClick (View v) {
        Toast.makeText(this, "버튼 클릭!", Toast.LENGTH_SHORT).show();
        mButton.setVisibility(View.GONE);
    }
}
