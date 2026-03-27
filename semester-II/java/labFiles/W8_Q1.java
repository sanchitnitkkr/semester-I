package awt_test;

import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseWheelEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class W8_Q1 {

  public static void main(String[] args) {
    Frame frame = new Frame("Mouse Events");
    frame.setSize(400, 300);
    frame.setLayout(new FlowLayout());

    frame.addMouseListener(
      new MouseAdapter() {
        public void mouseClicked(MouseEvent e) {
          System.out.println("Clicked at " + e.getX() + ", " + e.getY());
        }

        public void mousePressed(MouseEvent e) {
            System.out.println("Mouse is being held");
        }
        
        public void mouseReleased(MouseEvent e) {
            System.out.println("Mouse is released");
            
        }
        
        public void mouseEntered(MouseEvent e) {
            System.out.println("Mouse entered");
            
        }
        
        public void mouseExited(MouseEvent e) {
            System.out.println("Mouse exited");
            
        }
        
        public void mouseWheelMoved(MouseWheelEvent e) {
            System.out.println("Mouse wheel moved");
            
        }
        
        public void mouseDragged(MouseEvent e) {
            System.out.println("Mouse dragged");
            
        }
        
        public void mouseMoved(MouseEvent e) {
            System.out.println("Mouse moved");
            
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
