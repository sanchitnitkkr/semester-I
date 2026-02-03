import java.util.Scanner;

class A {
    public static int add(int i, int j) {
        return i + j;
    }
}

public class W2_Q2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter i: ");
        int i = sc.nextInt();
        System.out.print("Enter j: ");
        int j = sc.nextInt();

        System.out.println("Sum is: " + A.add(i, j));

        sc.close();
    }
}
