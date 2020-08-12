package com.example.assignment;


import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

public class Userdata extends SQLiteOpenHelper {
    public  static final String DATABASE_NAME ="UserDatabase.db";
    public  static final String TABLE_NAME="userdata";
    public  static final String COL_1 ="USER_NAME";
    public  static final String COL_2 ="BIRTH_DATE";
    public  static final String COL_3="PHONE_NO";
    public  static final String COL_4 ="EMAIL";
    public  static final String COL_5 ="PASSWORD";

    public Userdata(Context context) {
        super(context, DATABASE_NAME, null, 1);

    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL("create table " + TABLE_NAME + "(USER_NAME STRING PRIMARY KEY AUTOINCREMENT, BIRTH_DATE INTEGER ,PHONE_NO INTEGER,EMAIL STRING,PASSWORD STRING)");

    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("DROP TABLE IF EXISTS " + TABLE_NAME);
    }
    //inserting in database
    public boolean insert(String nm,String dt,String phn,String mail, String pass){
        SQLiteDatabase db =this.getWritableDatabase();
        ContentValues contentValues = new ContentValues();
        contentValues.put(COL_1,nm);
        contentValues.put(COL_2,dt);
        contentValues.put(COL_3,phn);
        contentValues.put(COL_4,mail);
        contentValues.put(COL_5,pass);
        long ins = db.insert("userdata",null,contentValues);
        if(ins==-1)return false;
        else return true;
    }

    //checking if nm exists;
    public boolean checkemail (String mail){
        SQLiteDatabase db = this.getReadableDatabase();
        Cursor cursor = db.rawQuery("select * from userdata where mail=?",new String[]{mail});
        if (cursor.getCount()>0) return false;
        else return true;
    }

    //checking the user data
    public boolean checkuserdata(String nm,String dt,String phn,String mail, String pass){
        SQLiteDatabase db = this.getReadableDatabase();
        Cursor cursor = db.rawQuery("select * from userdata where nm=? and dt=? and phn=? and mail=? and pass=?",new String[]{nm,dt,phn,mail,pass});
        if (cursor.getCount()>0) return true;
        else return  false;
    }

    // checking email and password
    public boolean cfmdata(String nm,String mail, String pass){
        SQLiteDatabase db = this.getReadableDatabase();
        Cursor cursor = db.rawQuery("select * from userdata where nm=? and mail=? and passw=? ",new String[]{nm,mail,pass});
        if (cursor.getCount()>0) return true;
        else return false;
    }
}
