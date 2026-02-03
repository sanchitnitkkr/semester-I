import java.util.Scanner;

public class Q3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String inputString = sc.nextLine();

        int wordCount = 0;
        boolean inWord = false;

        for (int i = 0; i < inputString.length(); i++) {
            char c = inputString.charAt(i);

            if (c != ' ' && !inWord) {
                wordCount++;
                inWord = true;
            } else if (c == ' ') {
                inWord = false;
            }
        }

        System.out.println("Total no of words => " + wordCount);
        sc.close();
    }
}
