package kr.ac.uhs.ce.explicitintents2;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private EditText mEditNum1;
    private EditText mEditNum2;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mEditNum1 = (EditText) findViewById(R.id.editNum1);
        mEditNum2 = (EditText) findViewById(R.id.editNum2);
    }

    public void mOnClick (View v) {
        Intent intent = new Intent();
        switch (v.getId()) {
            case R.id.btnTest1:
                intent = new Intent(this, SubActivity.class);
                startActivity(intent);
                break;
            case R.id.btnTest2:
                intent.setClassName("com.android.settings", "com.android.settings.Settings");
                startActivity(intent);
                break;
            case R.id.btnTest4:
                intent.setAction("andbook.example.implicitintents.Test1");
                break;
            case R.id.btnTest5:
                intent.setAction("andbook.example.implicitintents.Test2");
                intent.setType("image/png");
                break;
            case R.id.btnTest6:
                intent.setAction(Intent.ACTION_MAIN);
                break;
            case R.id.btnTest7:
                intent.setAction(Intent.ACTION_DIAL);
                intent.setData(Uri.parse("tel:010-2222-3333"));
                break;
            case R.id.btnTest8:
                intent.setAction(Intent.ACTION_VIEW);
                intent.setData(Uri.parse("http://www.android.com"));
                break;
            case R.id.btnTest9:
                intent.setAction(Intent.ACTION_MAIN);
                intent.addCategory(Intent.CATEGORY_HOME);
                break;
            case R.id.btnClac:
                intent = new Intent(this, SubActivity.class);
                intent.putExtra("num1", Integer.parseInt(mEditNum1.getText().toString()));
                intent.putExtra("num2", Integer.parseInt(mEditNum2.getText().toString()));
                startActivityForResult(intent, 0);
        }
        startActivity(intent);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        if (requestCode == 0 && resultCode == RESULT_OK) {
            int result = data.getIntExtra("result", 0);
            Toast.makeText(this, "두 숫자의 곱 : " + result, Toast.LENGTH_SHORT).show();
        }
        super.onActivityResult(requestCode, resultCode, data);
    }
}