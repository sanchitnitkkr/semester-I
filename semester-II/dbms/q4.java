import java.util.Scanner;

public class q4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

               System.out.print("Enter an integer: ");
        int n = scanner.nextInt();

        System.out.println("Prime numbers up to " + n + " are:");

              for (int i = 2; i <= n; i++) {
            if (isPrime(i)) {
                System.out.print(i + " ");
            }
        }
    }

       public static boolean isPrime(int num) {
        if (num <= 1) {
            return false;
        }
                for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}