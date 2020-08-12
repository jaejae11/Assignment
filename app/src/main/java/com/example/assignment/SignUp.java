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

public class SignUp extends AppCompatActivity {


    //declear variables
    TextView backfirst;
    EditText name,date,phone,email,password,cpassowrd;
    Button su;
    Userdata db;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sign_up);
        db = new Userdata(this);

        name=(EditText)findViewById(R.id.su_name);
        date=(EditText)findViewById(R.id.su_date);
        phone=(EditText)findViewById(R.id.su_phone);
        email=(EditText)findViewById(R.id.su_email);
        password=(EditText)findViewById(R.id.su_pass);
        cpassowrd=(EditText)findViewById(R.id.su_cpass);
        backfirst=(TextView)findViewById(R.id.backfst);
        su=(Button)findViewById(R.id.sign_up);
        su.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view){
                String nm = name.getText().toString();
                String dt = date.getText().toString();
                String phn = phone.getText().toString();
                String mail = email.getText().toString();
                String pass = password.getText().toString();
                String cpass= cpassowrd.getText().toString();

                //checking with UI
                if (nm.equals("")||dt.equals("")||phn.equals("")||mail.equals((""))||pass.equals("")||cpass.equals("")){
                    Toast.makeText(getApplicationContext(),"Please field are empty", Toast.LENGTH_SHORT).show();
                }
                else {
                    if (pass == cpass) {
                        Boolean checkmail = db.checkemail(mail);
                        if (checkmail == true) {
                            Boolean insert = db.insert(nm, dt, phn, mail, pass);
                            if (insert == true) {
                                Toast.makeText(getApplicationContext(), "Sign Up successfully", Toast.LENGTH_SHORT).show();
                            }
                        }else {
                            Toast.makeText(getApplicationContext(), "This email already existed", Toast.LENGTH_SHORT).show();
                        }
                    } else {
                        Toast.makeText(getApplicationContext(),"Confrim password didn't matching with Password ",Toast.LENGTH_SHORT).show();
                    }
                }
            }

        });
        backfirst.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                openFirst();
            }
        });

    }
    public void openFirst() {
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
    }

}