
import java.util.Scanner;

public class Q6 {

    public static int fibonacciRecursive(int n) {
        if (n == 0 || n == 1)
            return n;

        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }

    public static int fibonacciIterative(int n) {
        if (n == 0 || n == 1)
            return n;

        int prev = 0;
        int curr = 1;

        for (int i = 2; i <= n; i++) {
            int sum = prev + curr;
            prev = curr;
            curr = sum;
        }

        return curr;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int res = fibonacciRecursive(n);
        System.out.println("Sum: " + res);
        int res2 = fibonacciIterative(n);
        System.out.println("Sum iterative: " + res2);
        sc.close();
    }

}
