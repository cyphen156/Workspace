package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.os.Handler;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.SeekBar;
import android.widget.TextView;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Timer;
import java.util.TimerTask;

public class MainActivity extends AppCompatActivity {
    Socket socket;
    OutputStream os;
    InputStream is;
    BufferedReader in ;
    PrintWriter out;
    ConnectThread thread;
    Button button01, button02, button05, button03;
    SeekBar sek1;
    EditText input01, input03;
    TextView text01, text02, tvMessage;
    String msg, message;
    Handler handler = new Handler();
    Timer timer;
    boolean threadStop;
    int save=0; //모터를 켜기, 끄기를 한 버튼으로 사용하기 위한 변수
    int save1=0; //led를 켜기, 끄기를 한 버튼으로 사용하기 위한 변수

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        input01 = (EditText) findViewById(R.id.input01); //포트 번호 입력
        input03 = (EditText) findViewById(R.id.input00); // 아이피 주소 입력
        text01 = (TextView) findViewById(R.id.text01);  // 속도가 몇인지
        button01 = (Button) findViewById(R.id.button01); //서버 연결하는 버튼
        button02 = (Button) findViewById(R.id.button02); //모터 버튼
        button05 = (Button) findViewById(R.id.button05); //연결 종료 버튼
        button03 = (Button) findViewById(R.id.button03); //LED 버튼
        sek1 = (SeekBar) findViewById(R.id.sek1); //모터 조절 SeekBar


        button02.setEnabled(false); //처음 앱을 시작하면 서버와 연결이 안되어 있기 때문에
        button05.setEnabled(false);// 모터 버튼과 연결 종료 버튼, seekbar, led버튼을 사용 할 수 없게 한다.
        sek1.setEnabled(false);
        button03.setEnabled(false);


        button01.setOnClickListener(new View.OnClickListener() {  //서버 연결을 클릭했을 때의 함수.
            public void onClick(View v) {
                String addr = input01.getText().toString().trim(); //input01에 들어오는 포트 4자리 숫자를 형변환 하여 변수 addr에 넣어준다.
                thread = new ConnectThread(addr);
                thread.start();
                input01.setEnabled(false); //연결이 되었으니 아이피와 포트 입력창은 비활성화.
                input03.setEnabled(false);
                button02.setEnabled(true); //서버 연결 버튼은 비활성화 나머지는 활성화 시킴.
                button01.setEnabled(false);
                button05.setEnabled(true);
                button03.setEnabled(true);



            }
        });
        button02.setOnClickListener(new View.OnClickListener() { //모터 버튼을 눌렀을 때 함수

            public void onClick(View v) {
                new Thread() {
                    public void run() {
                        out.println("MTOn");  //모터를 켜는 쓰레드
                        out.flush();
                    }
                }.start();

                if(save==0) { //save 변수가 0이면 버튼 텍스트를 모터 끄기와 led off로 바꾼다.
                    sek1.setEnabled(true); // 시크바 활성화
                    button02.setText("모터 끄기");
                    button03.setText("LED OFF");
                    save1=1; //led버튼 변수 값 1설정
                    save=1;//모터버튼 변수 값 1설정


                    sek1.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() { //시크바 함수
                        int speed;

                        @Override
                        public void onProgressChanged(SeekBar seekBar, int i, boolean b) { //시크바를 움직일 때 마다 실행되는 함수

                            text01.setText(String.format("모터 속도: %d", sek1.getProgress())); //시크바를 조정하면 아래에 조정한 만큼의 숫자를 출력
                            speed = sek1.getProgress(); //그 시크바의 정도를 스피드 변수에 넣어준다.
                            new Thread() {
                                public void run() {
                                    out.println(speed); //모터의 빠르기를 전달.
                                    out.flush();
                                }
                            }.start();



                        }

                        @Override
                        public void onStartTrackingTouch(SeekBar seekBar) {

                        }

                        @Override
                        public void onStopTrackingTouch(SeekBar seekBar) {


                        }
                    });
                }

                else if(save==1){ //모터버튼 변수가 1일때(모터끄기 버튼일때)
                    button03.setEnabled(true); //led버튼 활성화
                    sek1.setEnabled(false); //시크바 꺼줌
                    sek1.setProgress(0,true); //시크바의 진행도를 0으로 바꾸는 애니메이션 처리
                    button02.setText("모터 켜기"); //모터끄기의 텍스트를 모터켜기로 바꿈
                    save=0; //모터버튼 변수 0으로 바꿈
                    button03.setText("LED ON"); //led버튼의 텍스트를 LED ON으로 바꾼다.

                    new Thread() {
                        public void run() {
                            thread.setStop(); //모터 끄기 쓰레드, 쓰레드도 스탑한다.
                            out.println("MTOff");
                            out.flush();
                        }
                    }.start();

                }
            }
        });
        button05.setOnClickListener(new View.OnClickListener() { //연결종료 버튼을 누를 시 실행되는 함수
            @Override
            public void onClick(View view) {

                thread.setStop(); //쓰레드를 종료시킨다.

                save=0; //모터 버튼 변수 0으로 바꿈
                save1=0; //led 버튼 변수 0으로 바꾼다.
                button02.setText("모터 켜기");// 연결이 종료되었으니 모터버튼 텍스트도 다시 원상태로
                sek1.setEnabled(false); //시크바 비활성화
                sek1.setProgress(0,true);
                button01.setEnabled(true); // 처음 앱을 시작했을 때와 똑같이 버튼과 인풋텍스트들을 활성화 및 비활성화로 바꿔줌.
                button02.setEnabled(false);
                button05.setEnabled(false);
                input01.setEnabled(true);
                input03.setEnabled(true);

            }
        });
        button03.setOnClickListener(new View.OnClickListener() { //LED버튼 클릭 시 발생하는 함수.
            @Override
            public void onClick(View view) {
                if(save1==0) { //led버튼 변수가 0일때
                    save1=1; // 버튼 변수를 1로 바꿔줌
                    button03.setText("led off"); //버튼 텍스트를 led off로 바꿈
                    new Thread() { //led on 쓰레드 시작
                        public void run() {
                            out.println("LEDOn");
                            out.flush();
                        }
                    }.start();
                }
                else if(save1==1){ // led버튼 변수가 1일때

                    save1=0; //버튼 변수를 0으로 바꿔줌
                    button02.setEnabled(true); //모터버튼 활성화
                    button03.setText("led on");//led버튼 텍스트 led on으로 바꿔줌
                    new Thread() {
                        public void run() { //ledoff 쓰레드 시작
                            out.println("LEDOff");
                            out.flush();
                        }
                    }.start();

                }

            }
        });


    }

    class ConnectThread extends Thread {
        String hostname;
        public ConnectThread(String addr) {
            hostname = addr;
        }
        public void run() {
            try {
                String port1 = input03.getText().toString().trim();
                int port = Integer.parseInt(port1);
                socket = new Socket(hostname, port);
                os = socket.getOutputStream();
                is = socket.getInputStream();
                in = new BufferedReader(new InputStreamReader(is));
                out = new PrintWriter(os);
            } catch (Exception ex) {
                ex.printStackTrace();
                try {
                    socket.close();
                }catch (Exception e){
                    e.printStackTrace();
                }
            }
        }
        public void readServer(){
            try {
                while (!threadStop) {
                    String msg1 = in.readLine();
                    handler.post(new Runnable() {
                        @Override
                        public void run() {
                        }
                    });
                }
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
        public void setStop() {
            if(socket.isConnected()) {
                try {
                    timer.cancel();
                    threadStop = true;
                    socket.close();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }
}