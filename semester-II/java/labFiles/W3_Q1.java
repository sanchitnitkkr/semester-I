package labFiles;

import java.util.Scanner;

class Rectangle {
    private int length;
    private int breadth;

    Rectangle(int length, int breadth) {
        this.length = length;
        this.breadth = breadth;
    };

    public int area() {
        return this.length * this.breadth;
    }
}

public class W3_Q1 {
    public static void main(String[] args) {
        int len, breadth;
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter length: ");
        len = sc.nextInt();
        breadth = sc.nextInt();

        Rectangle r1 = new Rectangle(len, breadth);
        System.out.println("Area => " + r1.area());
        sc.close();
    }
}
