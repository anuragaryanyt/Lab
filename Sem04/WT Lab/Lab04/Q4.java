import java.util.Scanner;

public class Q4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num;
        System.out.println("Enter Number : ");
        num = sc.nextInt();

        int copy = num;
        int rev = 0;

        while (num > 0) {
            rev = (rev * 10) + (num % 10);
            num /= 10;
        }
        if (rev == copy) {
            System.out.println("Palindrome Succesfully Detected");
        } else
            System.out.println("The input no is not a palindrome");
        sc.close();
    }

}
