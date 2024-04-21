package Q2;
import java.util.Scanner;

public class PrgQ2 {
    void subtract() {
        System.out.println("5 - 2 = " + (5 - 2));
    }

    void subtract(int n) {
        System.out.printf("5 - %d = %d\n", n, (5 - n));
    }

    void subtract(int n, int m) {
        System.out.printf("%d - %d = %d\n", m, n, (m - n));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter values of m & n :");
        int m = sc.nextInt();
        int n = sc.nextInt();

        PrgQ2 ob = new PrgQ2();
        ob.subtract();
        ob.subtract(n);
        ob.subtract(n, m);
        sc.close();
    }
}
