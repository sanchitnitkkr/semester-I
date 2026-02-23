package labFiles;


import java.util.Scanner;

class Cuboid {
    private int length;
    private int breadth;
    private int height;

    Cuboid(int length, int breadth, int height) {
        this.length = length;
        this.breadth = breadth;
        this.height = height;
    }

    int volume() {
        return this.length * this.breadth * this.height;
    }
}

public class W2_Q6 {
    public static void main(String[] args) {
        int length, breadth, height;
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter dimensions (Length): ");
        length = sc.nextInt();

        System.out.println("Enter dimensions (Breadth): ");
        breadth = sc.nextInt();

        System.out.println("Enter dimensions (Height): ");
        height = sc.nextInt();

        Cuboid cuboid = new Cuboid(length, breadth, height);

        System.out.println("The volume is => " + cuboid.volume());

        sc.close();
    }
}
