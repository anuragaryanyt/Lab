/*Write a program in Java that asks the user to enter his/her first name and last
name as input and then print both in one line in the following format: the last
name followed by the first name */

import java.util.Scanner;
public class ques5 {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter the first name:");
        String f=sc.nextLine();
        System.out.println("Enter the Last name:");
        String l=sc.nextLine();

        System.out.println(l + " "+ f);
        sc.close();

    }
    
}
