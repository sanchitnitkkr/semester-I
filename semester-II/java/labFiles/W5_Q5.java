/*
Program 5: Write a suitable program for the following conditions:
a) A try block followed by multiple catch blocks
b) Catching multiple type of exceptions
c) Using throws/throw keywords
d) Using finally block
e) Using try-with-resources
f) User-defined exceptions */
package labFiles;

import java.util.Scanner;

class GenericException extends RuntimeException {
    GenericException() {
        System.out.println("An error occured!");
    }

    GenericException(Exception e) {
        System.out.println("An error occured!\nError: " + e.getMessage());
    }
};

class PinInputException extends GenericException {
    PinInputException() {
        System.out.println("Invalid 4 digit PIN");
    }
}

class InputValidation {
    public static String validatePinInput(String pin) throws PinInputException {
        if (!pin.matches("^\\d{4}$")) {
            throw new PinInputException();
        }
        return pin;
    }
}

public class W5_Q5 {
    public static void main(String[] args) {

        int retryCount = 3;

        try (Scanner sc = new Scanner(System.in)) {

            while (retryCount > 0) {
                System.out.println("Starting process...");
                System.out.println("Enter your pin: ");

                try {
                    String pin = sc.nextLine();

                    InputValidation.validatePinInput(pin);

                    System.out.println("PIN accepted");
                    break;

                } catch (PinInputException e) {
                    retryCount--;
                    System.out.println("Invalid PIN. Attempts left: " + retryCount);

                    if (retryCount == 0) {
                        System.out.println("System locked for 24 hours!");
                        throw e;
                    }
                } catch (Exception e) {
                    System.out.println("Some unknown error occured");
                    break;
                } finally {
                    System.out.println("Ending process...");
                }
            }
        }
    }
}
