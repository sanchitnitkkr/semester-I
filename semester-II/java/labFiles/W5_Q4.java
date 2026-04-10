/*
Program 4: An array is declared with 5 elements. Then the code tries to access the 6th
element of the array which throws an exception. Write the program for this.
*/
package labFiles;


import java.util.Scanner;

class CustomArrayException extends ArrayIndexOutOfBoundsException {
    CustomArrayException(Exception e) {
        System.out.println("You entered an element which is out of bounds. Please enter a proper index!");
    }
}

public class W5_Q4 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the array values comma separated: ");
        String inputLine = sc.nextLine();

        String[] arr = inputLine.split(",");

        try {
            System.out.println("Enter the element you wish to access: ");
            int index = sc.nextInt();
            System.out.println("You selected " + arr[index]);
        } catch (ArrayIndexOutOfBoundsException e) {
            throw new CustomArrayException(e);
        } finally {
            sc.close();
        }

    }

}
