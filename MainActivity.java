package com.example.staglag17;// Edit this line to match your project name.


import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.example.staglag17.R;

import org.w3c.dom.Text;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;

public class MainActivity extends AppCompatActivity {
    public String message;

    Button conn;
    EditText txtAddress;
    public static String wifiModuleIp="";
    public static int wifModulePort =0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final EditText inputtext = (EditText)findViewById(R.id.editText3);
        final TextView textViewTemp = (TextView)findViewById(R.id.textViewTemp);
        final TextView textViewHum = (TextView)findViewById(R.id.textViewHum);
        final TextView textViewLight = (TextView)findViewById(R.id.textViewLight);
        final TextView textViewSoil = (TextView)findViewById(R.id.textViewSoil);
        txtAddress =(EditText) findViewById(R.id.ipAddress);

        conn= (Button) findViewById(R.id.button2);
        txtAddress =(EditText) findViewById(R.id.ipAddress);
        conn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                getIPandPort();
                send sendcode = new send();
                sendcode.execute();
                if(message != null) {
                    String data[]=message.split(":");
                    textViewTemp.setText(data[0]);
                    textViewHum.setText(data[1]);
                    textViewLight.setText(data[2]);
                    textViewSoil.setText(data[3]);
                }
            }
        });
    }

    public void getIPandPort()
    {
        String iPandPort=txtAddress.getText().toString();
        Log.d("MYTEST","IP String: "+ iPandPort);
        String temp[]=iPandPort.split(":");
        wifiModuleIp =temp[0];
        wifModulePort = Integer.valueOf(temp[1]);
        Log.d("MY TEST","IP:" +wifiModuleIp);
        Log.d("MY TEST","PORT:"+wifModulePort);
    }


    class send extends AsyncTask<Void,Void,Void> {
        Socket s;
        BufferedReader br;
        @Override
        protected Void doInBackground(Void...params){
            try {
                Log.d("MY TEST","TIMEIS");
                s = new Socket(wifiModuleIp,wifModulePort);
                br = new BufferedReader(new InputStreamReader(s.getInputStream()));
                Log.d("MY TEST","TIMEISO");
                message = br.readLine();
                Log.d("MY TEST","TIMEISOVER");

                br.close();
                s.close();

            } catch (UnknownHostException e) {
                System.out.println("Fail1");
                e.printStackTrace();
            } catch (IOException e) {
                System.out.println("Fail2");
                e.printStackTrace();
            }
            Log.d("MY TEST","TIMEISOVER");
            return null;

        }
    }
}
