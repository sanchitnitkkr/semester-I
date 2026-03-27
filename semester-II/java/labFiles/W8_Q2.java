package awt_test;

import java.awt.Frame;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

public class W8_Q2 {

  public static void main(String[] args) {
    Frame frame = new Frame("Test Frame");
    frame.setSize(300, 500);

    frame.addKeyListener(
      new KeyListener() {
        public void keyPressed(KeyEvent e) {
          System.out.println("Key pressed: " + e.getKeyChar());
        }

        public void keyReleased(KeyEvent e) {
          System.out.println("Key released: " + e.getKeyChar());
        }

        public void keyTyped(KeyEvent e) {
          System.out.println("Key typed: " + e.getKeyChar());
        }
      }
    );

    frame.addWindowListener(new WindowAdapter() {
        public void windowClosing(WindowEvent e){
            frame.dispose();
            System.exit(0);
        }
    });
    frame.setVisible(true);
  }
}
