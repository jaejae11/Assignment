package com.example.assignment;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import static com.example.assignment.R.id.btnSi;

public class MainActivity extends AppCompatActivity {

    Button signin ;
    Button signup;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        signin =(Button)findViewById(R.id.btnSi);
        signup = (Button)findViewById(R.id.btnSu);
        signin.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                openSignIn();
            }
        });

        signup.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                openSignUp();
            }
        });

    }

    public void openSignIn(){
        Intent intent = new Intent(this,SignIn.class);
        startActivity(intent);
    }
    public void openSignUp(){
        Intent intent = new Intent(this,SignUp.class);
        startActivity(intent);
    }
}