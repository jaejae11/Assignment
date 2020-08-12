package com.example.assignment;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

public class SignIn extends AppCompatActivity {

    //declare variable
    TextView gofirst;
    EditText name,email,password;
    Button si;
    Userdata db;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sign_in);

        name=(EditText)findViewById(R.id.si_name);
        email=(EditText)findViewById(R.id.si_email);
        password=(EditText)findViewById(R.id.si_password);
        gofirst=(TextView)findViewById(R.id.backmain);
        si=(Button)findViewById(R.id.sign_in);

        gofirst.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                openMain();
            }
        });
        si.setOnClickListener(new View.OnClickListener() {;
            @Override
            public void onClick(View view) {
                String nm = name.getText().toString();
                String mail = email.getText().toString();
                String pass = password.getText().toString();

                boolean logincfm = db.cfmdata(nm,mail,pass);
                if (logincfm == true)
                    Toast.makeText(getApplicationContext(),"Successfully Login",Toast.LENGTH_SHORT).show();
                else
                    Toast.makeText(getApplicationContext(),"Invalid input data",Toast.LENGTH_SHORT).show();

            }
        });

    }
    public void openMain() {
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
    }
}