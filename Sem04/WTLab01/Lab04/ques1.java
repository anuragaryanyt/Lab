// Write a program in java to ask three different users to enter their:
// a. Name
// b. roll no
// c. section,
// d. and branch
// Followed by printing the details of each user in separate lines.

import java.util.Scanner;

public class ques1 {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        for (int i = 0; i < 3; i++) {
            System.out.println("Enter the name:");
            String name = sc.nextLine();
            System.out.println("Enter the Roll:");
            int roll = sc.nextInt();
            sc.nextLine();
            System.out.println("Enter the Sec:");
            String sec = sc.nextLine();
            System.out.println("Enter the Branch:");
            String br = sc.nextLine();

            System.out.println("Name: " + name);
            System.out.println("Roll: " + roll);
            System.out.println("SEc: " + sec);
            System.out.println("Branch: " + br);

        }
        sc.close();
    }
}
