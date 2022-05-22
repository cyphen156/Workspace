package ac.uhs.viewattr1;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private ImageView mImagePic1;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mImagePic1 = (ImageView) findViewById(R.id.imagePic1);
    }

    public void mOnClick(View v){
        Toast.makeText(this, "버튼 클릭!", Toast.LENGTH_SHORT).show();
    }

    public void mOnClick1(View v) {
        mImagePic1.setVisibility(View.INVISIBLE);
    }
}