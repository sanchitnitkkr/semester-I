public class q6 {

       public static int fibonacciRecursive(int n) {
        if (n <= 1) {
            return n;
        }
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }

       public static void fibonacciIterative(int n) {
        int a = 0, b = 1;
        System.out.print("Iterative F.S. : ");
        for (int i = 0; i < n; i++) {
            System.out.print(a + " ");
            int next = a + b;
            a = b;
            b = next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int n = 10; 
                fibonacciIterative(n);

               System.out.print("Recursive F.S.: ");
        for (int i = 0; i < n; i++) {
            System.out.print(fibonacciRecursive(i) + " ");
        }
    }
}