package kr.ac.uhs.ce.menu;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.SubMenu;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        menu.add(Menu.NONE, 1, Menu.NONE, "메뉴 1");
        menu.add(Menu.NONE, 2, Menu.NONE, "메뉴 2");
        SubMenu subMenu = menu.addSubMenu("하위 메뉴");
        subMenu.add(Menu.NONE, 3, Menu.NONE, "하위 메뉴3");
        subMenu.add(Menu.NONE, 4, Menu.NONE, "하위 메뉴4");
        return super.onCreateOptionsMenu(menu);
    }
    /*인플레이터 메뉴 xml추가
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.menu_main, menu);
        return super.onCreateOptionsMenu(menu);
    }
     */
    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        switch (item.getItemId()){
            case 1://==R.id.item1
                Toast.makeText(this, "메뉴 1 선택", Toast.LENGTH_SHORT).show();
                return true;
            case 2:
                Toast.makeText(this, "메뉴 2 선택", Toast.LENGTH_SHORT).show();
                return true;
            case 3:
                Toast.makeText(this, item.getTitle() + " 선택", Toast.LENGTH_SHORT).show();
                return true;
            case 4:
                Toast.makeText(this, item.getTitle() + " 선택", Toast.LENGTH_SHORT).show();
                return true;
        }
        return super.onOptionsItemSelected(item);
    }

}