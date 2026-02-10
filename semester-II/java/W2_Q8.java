import java.util.Scanner;

public class W2_Q8 {

    static boolean palindrome(String myStr, int fp, int sp) {
        if (fp > sp)
            return true;
        if (myStr.charAt(fp) != myStr.charAt(sp)) {
            return false;
        }
        return palindrome(myStr, fp + 1, sp - 1);
    }

    public static void main(String[] args) {
        System.out.println("Enter the string you want to check if is palindrome or not");
        Scanner sc = new Scanner(System.in);
        String inputStr = sc.nextLine();
        sc.close();

        boolean isPalindrome = palindrome(inputStr.toLowerCase(), 0, inputStr.length() - 1);
        if (isPalindrome) {
            System.out.println("Palindrome");
            return;
        }
        System.out.println("Not Palindrome");
        return;
    }
}
