import java.util.Scanner;

public class ques1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = scanner.nextInt();
        scanner.close();

        if (isPalindrome(num)) {
            System.out.println(num + " is a palindrome.");
        } else {
            System.out.println(num + " is not a palindrome.");
        }
    }

    public static boolean isPalindrome(int num) {
        String str = Integer.toString(num);
        int len = str.length();
        if (len <= 1) {
            return true;
        } else {
            char firstChar = str.charAt(0);
            char lastChar = str.charAt(len - 1);
            if (firstChar != lastChar) {
                return false;
            } else {
                String subStr = str.substring(1, len - 1);
                int subNum = Integer.parseInt(subStr);
                return isPalindrome(subNum);
            }
        }
    }
}


