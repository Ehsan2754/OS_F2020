package com.example.ehsanshaghaei_todolist;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.support.annotation.NonNull;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ListView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    public static ArrayList<String> taskList = new ArrayList<String>();
    ListView taskListView = (ListView) findViewById(R.id.item_list);
    ArrayAdapter<String> adapter = new ArrayAdapter<String>(
            this,
            R.layout.todo_item,
            R.id.item_des,
            taskList);


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
//        taskListView = (ListView) findViewById(R.id.item_list);
//        ArrayAdapter<String> adapter = new ArrayAdapter<String>(
//                this,
//                R.layout.todo_item,
//                R.id.item_des,
//                taskList);
        taskListView.setAdapter(adapter);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.main_menu, menu);
        return super.onCreateOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        switch (item.getItemId()) {
            case R.id.add_tsk:
                Log.d("MainClass", " Add a new task ");
                final EditText taskEditText = new EditText(this);
                AlertDialog dialog = new AlertDialog.Builder(this)
                        .setTitle(" Add New Task ")
                        .setMessage(" Enter Your Task ")
                        .setView(taskEditText)
                        .setPositiveButton(" Add ", new DialogInterface.
                                OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                String task = String.valueOf(taskEditText.getText()
                                );
                                Log.d("MainClass", " Task to add : " + task);
                                addItem(task);
                            }
                        })
                        .setNegativeButton(" Cancel ", null)
                        .create();
                dialog.show();
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }
    }

    private void addItem(String itemText) {
        taskList.add(itemText);
        adapter.notifyDataSetChanged();
    }

    private void removeItem(String itemText) {
        taskList.remove(itemText);
        adapter.notifyDataSetChanged();
    }

}