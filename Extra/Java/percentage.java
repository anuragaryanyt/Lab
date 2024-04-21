import java.util.Scanner;

public class percentage {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Name: ");
        String name = sc.nextLine();

        System.out.print("Enter the mmarks of 1st sub: ");
        float m1 = sc.nextFloat();

        System.out.print("Enter the mmarks of 2nd sub: ");
        float m2 = sc.nextFloat();

        System.out.print("Enter the mmarks of 3rd sub: ");
        float m3 = sc.nextFloat();

        float sum = m1 + m2 + m3;
        float perc = (sum * 100) / 300;
        System.out.println("Percentage of "+name+" is " + perc + "%");

        sc.close();

    }
}
