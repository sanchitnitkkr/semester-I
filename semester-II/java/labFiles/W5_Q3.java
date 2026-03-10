/*
Program 3: Write a Java program for exception handling with
StringIndexOutOfBound exception.
Create an object of the class having StringIndexOutOfBound exception whenever an index is invoked of a string, which is not in the range.
Each character of a string object is stored in a particular index starting from 0.
To get a character present in a particular index of a string you can use a method charAt(int) of java.lang.String where int argument is the index. 
*/

package labFiles;

import java.util.Scanner;

public class W5_Q3 {
    public static void main(String[] args) {
        System.out.println("Enter the string: ");
        Scanner sc = new Scanner(System.in);
        String inputStr = sc.nextLine();

        boolean askAgain = true;
        while (askAgain) {
            System.out.println("Enter the index to be accessed");
            int index = sc.nextInt();

            try {
                char character = inputStr.charAt(index);
                System.out.println("The character is " + character);
                askAgain = false;
            } catch (StringIndexOutOfBoundsException e) {
                System.out.println(
                        "Invalid input: The index " + index + " exceeds the string's range, re-enter the character");
            }
        }

        sc.close();
    }
}
