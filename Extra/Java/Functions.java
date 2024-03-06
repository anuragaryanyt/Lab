import java.util.*;

public class Functions {
    public static int calculateSumofOddNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            int oddNumber = 2 * i - 1;
            sum = sum + oddNumber;
        }
        return sum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the value of n");
        int n = sc.nextInt();
        sc.close();

        int sumOfOddNumbers = calculateSumofOddNumber(n);
        System.out.println("The sum of all odd numbers from 1 to " + n + " is: " + sumOfOddNumbers);
    }
    
}

