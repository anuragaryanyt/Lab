/* Write a program in Java that asks as input the marks secured by him/her in
chemistry out of 100. Next, using the marks entered by the user, generate the
corresponding grade of the student using the following chart with the help of
if..else statements in Java.
 */

import java.util.Scanner;

public class ques2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the marks:");
        int mark = sc.nextInt();

        if (mark >= 90) {
            System.out.print("A-excellent");
        } else if (mark >= 80) {
            System.out.print("B-Very good");
        } else if (mark >= 70) {
            System.out.print("c-good");
        } else if (mark >= 60) {
            System.out.print("D-Satisfactory");
        } else if (mark >= 50) {
            System.out.print("E-Work Hard");
        } else if (mark >= 40) {
            System.out.print("f-just passed");
        } else {
            System.out.print("Failed");
        }

        sc.close();
    }
}
