package awt_test;

import java.awt.BorderLayout;
import java.awt.Checkbox;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.Panel;
import java.awt.TextField;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

/*
Program 3: Write a java program that simulates a traffic light. The program lets the
user select one of three lights: Red, Yellow or Green with radio buttons. 
On selecting a button an appropriate message with “STOP” or “READY” or ”GO” should 
appear above the buttons in selected color. Initially, there is no message shown. */

public class W8_Q3 {

  public static void addFrame() {}

  public static void main(String[] args) {
    Frame frame = new Frame("Traffic Panel");
    frame.setSize(640, 640);

    frame.addWindowListener(
      new WindowAdapter() {
        public void windowClosing(WindowEvent e) {
          frame.dispose();
          System.exit(0);
        }
      }
    );

    Checkbox readyBtn = new Checkbox("Ready");
    Checkbox stopBtn = new Checkbox("Stop");
    Checkbox goBtn = new Checkbox("Go");

    Panel panel = new Panel();
    panel.add(readyBtn);
    panel.add(stopBtn);
    panel.add(goBtn);
    panel.setLayout(new FlowLayout(FlowLayout.CENTER, 20, 40));

    frame.add(panel);

    TextField textField = new TextField("Nothing Selected");
    Panel textFieldPanel = new Panel();
    textFieldPanel.add(textField);
    // textFieldPanel.setBackground(Color.black);
    textFieldPanel.setLayout(new FlowLayout(FlowLayout.CENTER, 0, 30));

    frame.add(textFieldPanel, BorderLayout.SOUTH);

    readyBtn.addItemListener(
      new ItemListener() {
        public void itemStateChanged(ItemEvent e) {
          if (readyBtn.getState()) {
            textField.setText("Ready");
            textField.setForeground(Color.yellow);

            stopBtn.setState(false);
            goBtn.setState(false);
          } else {
            textField.setText("Nothing selected");
            textField.setForeground(Color.BLACK);
          }
        }
      }
    );

    stopBtn.addItemListener(
      new ItemListener() {
        public void itemStateChanged(ItemEvent e) {
          if (stopBtn.getState()) {
            textField.setText("STOP");
            textField.setForeground(Color.RED);

            readyBtn.setState(false);
            goBtn.setState(false);
          } else {
            textField.setText("Nothing selected");
            textField.setForeground(Color.BLACK);
          }
        }
      }
    );

    goBtn.addItemListener(
      new ItemListener() {
        public void itemStateChanged(ItemEvent e) {
          if (goBtn.getState()) {
            textField.setText("GO");
            textField.setForeground(Color.GREEN);

            readyBtn.setState(false);
            stopBtn.setState(false);
          } else {
            textField.setText("Nothing selected");
            textField.setForeground(Color.BLACK);
          }
        }
      }
    );

    frame.setVisible(true);
  }
}
