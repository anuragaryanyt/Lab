/*Write a program in Java that first asks the user to input any number, followed by
checking if the number entered by the user is a palindrome or not. If the number is
a palindrome, then output the message “Palindrome successfully detected” or else
“The input number is not a palindrome” on the console.*/

import java.util.Scanner;

public class ques4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num;
        System.out.println("Enter Number : ");
        num = sc.nextInt();

        int cp = num;
        int rev = 0;

        while (num > 0) {
            rev = (rev * 10) + (num % 10);
            num /= 10;
        }
        if (rev == cp) {
            System.out.println("Palindrome no");
        } else
            System.out.println("not a palindrome no");
        sc.close();
    }

}
