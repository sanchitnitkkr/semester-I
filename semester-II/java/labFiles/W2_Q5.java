package labFiles;

public class W2_Q5 {
    static int factorial(int N) {
        int result = 1;

        for (int i = N; i >= 1; i--) {
            result *= i;
        }
        return result;
    }

    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("No number entered");
            return;
        }

        System.out.println("Factorial is => " + factorial(Integer.parseInt(args[0])));

    }
}
