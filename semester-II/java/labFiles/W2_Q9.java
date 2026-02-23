package labFiles;
// WAP to count all substrings of CODING

public class W2_Q9 {
    public static void main(String[] args) {
        String word = "CODING";

        System.out.println("The substrings are: ");
        
        for (int i = 0; i < word.length(); i++) {
            String temp = "";
            for (int j = i; j < word.length(); j++) {
                temp += word.charAt(j);
                System.out.print(temp);
                System.out.print(",");
            }
            System.out.println();
        }
    }
}
