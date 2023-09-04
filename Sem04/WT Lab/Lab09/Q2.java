package GeneralProject.WTLab.Lab09;

import java.util.Scanner;

class NegativeNumberException extends Exception {
    public NegativeNumberException() {
        super("Error: Entered number is negative.");
    }
}

public class Q2 {
    static void process(int num) throws NegativeNumberException {
        if (num < 0) {
            throw new NegativeNumberException();
        }
        System.out.println("Double value of entered number: " + (double)num * 2);
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        try {
            System.out.print("Enter a number: ");
            int num = input.nextInt();
            process(num);
        } catch (NegativeNumberException e) {
            System.out.println(e.getMessage());
        } catch (Exception e) {
            System.out.println("Error: Invalid input.");
        }
    }
}
