import java.util.Scanner;

public class W2_Q4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("No of stars input: ");
        int n = sc.nextInt();
        /*
    *
   * *
  * * *
 * * * *
* * * * *
         */
        for (int i = 1; i <= n; i++) {
            int spaces = (n * 2) - i * 2;
            for (int k = 0; k < spaces / 2; k++) {
                System.out.print(" ");
            }
            for (int j = 0; j < i; j++) {
                System.out.print("* ");
            }
            for (int k = 0; k < spaces / 2; k++) {
                System.out.print(" ");
            }
            System.out.println();
        }

        for (int i = n - 1; i >= 0; i--) {
            int spaces = (n * 2) - i * 2;
            for (int k = 0; k < spaces / 2; k++) {
                System.out.print(" ");
            }
            for (int j = 0; j < i; j++) {
                System.out.print("* ");
            }
            for (int k = 0; k < spaces / 2; k++) {
                System.out.print(" ");
            }
            System.out.println();
        }
        sc.close();
    }
}
