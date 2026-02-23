package labFiles;

import java.util.Scanner;

public class Q4 {
    public static boolean isPrime(int x) {
        for (int i = 2; i < Math.sqrt(x); i++) {
            if (x % i == 0)
                return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the first number: ");
        int startingNumber = sc.nextInt();

        System.out.println("Enter the last number: ");
        int lastNumber = sc.nextInt();

        sc.close();
        
        System.out.println("The prime numbers b/w " + startingNumber + " and " + lastNumber + " are: ");

        for (int i = startingNumber; i <= lastNumber; i++) {
            if (isPrime(i))
                System.out.println(i);
        }
    }
}
