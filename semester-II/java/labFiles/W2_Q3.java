package labFiles;

public class W2_Q3 {

    public static boolean isPrime(int n) {
        if (n == 1)
            return false;
        if (n == 2)
            return true;

        for (int i = 2; i < Math.sqrt(n); i++) {
            if (n % i == 0)
                return true;
        }
        return false;
    }

    public static void main(String[] args) {
        // While loops
        System.out.println("Prime numbers are: ");
        int i = 1;
        while (i <= 50) {
            if (isPrime(i)) {
                System.out.print(i + " ");
            }
            i++;
        }

        System.out.println("\nPrime numbers are: ");
        i = 1;
        do {
            if (isPrime(i)) {
                System.out.print(i + " ");
            }
            i++;
        } while (i <= 50);

    }
}
