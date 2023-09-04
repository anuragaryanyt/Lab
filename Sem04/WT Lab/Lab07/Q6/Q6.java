package GeneralProject.WTLab.Lab07.Q6;

import java.util.Scanner;

public class Q6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter values of a,b and c : ");
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        Derived obj = new Derived(a, b, c);
        System.out.printf("a : %d\nb : %d\nc : %d", obj.a, obj.b, obj.c);
    }
}
