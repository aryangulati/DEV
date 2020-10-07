package com.example.higherorlower;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import java.util.Random;

public class MainActivity extends AppCompatActivity {
    int randomNumber;
    public void generateRandom() {

        Random rand = new Random();
        randomNumber = rand.nextInt(20) + 1;

    }
    public void guess(View v) {
        EditText editText = (EditText) findViewById(R.id.editText);

        int guessValue = Integer.parseInt(editText.getText().toString());

        String msg;
        if (guessValue > randomNumber)
            msg = "Lower!";
        else if (guessValue < randomNumber)
            msg = "Higher!";
        else {
            msg = "You got it right";
            generateRandom();
        }

        Toast.makeText(this, msg, Toast.LENGTH_SHORT).show();
        Log.i("Entered Value", editText.getText().toString());
        Log.i("Random Number", Integer.toString(randomNumber));
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        generateRandom();
    }
}
