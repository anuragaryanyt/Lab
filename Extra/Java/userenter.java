import java.util.*;

public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int positiveCount = 0;
    int negativeCount = 0;
    int zeroCount = 0;
    char choice;

    do {
        System.out.print("Enter a number: ");
        int number = sc.nextInt();

        if (number > 0) {
            positiveCount++;
        } else if (number < 0) {
            negativeCount++;
        } else {
            zeroCount++;
        }

        System.out.print("Do you want to continue? (y/n): ");
        choice = sc.next().charAt(0);

    } while (choice == 'y' || choice == 'Y');

    System.out.println("Positive numbers count: " + positiveCount);
    System.out.println("Negative numbers count: " + negativeCount);
    System.out.println("Zeros count: " + zeroCount);

    sc.close();
}
