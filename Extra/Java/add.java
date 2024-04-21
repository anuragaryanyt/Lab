import java.util.Scanner;

public class add {
    public static void main(String[] args) {
        System.out.println("Add of float");
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the 1st no:");
        float a = in.nextFloat();
        System.out.println("Enter the 2nd no: ");
        float b = in.nextFloat();
        float sum = a + b;
        float mul=a*b;

        System.out.print("the sum is: ");
        System.out.println(sum);
        System.out.print("the multipliaction is:");
        System.out.println(mul);

        in.close();

    }

}
