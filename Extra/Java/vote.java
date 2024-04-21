import java.util.*;

public class vote {
    public static void voting(int age) {
        if (age >= 18) {
            System.out.println("ELigible to vote!");
        } else if (age >= 0 && age < 18) {
            System.out.println("Not Eligible to vote!");

        } else {
            System.out.println("Invalid choice");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the age: ");
        int age = sc.nextInt();
        sc.close();

        voting(age);
    }
}
