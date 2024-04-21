import java.util.Scanner;

public class Q5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String first, last;
        System.out.print("Enter first name: ");
        first = sc.nextLine();
        System.out.print("Enter last name: ");
        last = sc.nextLine();

        System.out.println(last + " " + first);
        sc.close();
    }

}
