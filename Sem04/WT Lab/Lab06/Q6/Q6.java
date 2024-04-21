package Q6;

import java.util.Scanner;

public class Q6 {
    void area(double radius) {
        System.out.println("Area of Circle: " + (3.14 * radius * radius));
    }

    void area(double base, double height) {
        System.out.println("Area of Triangle: " + (0.5 * base * height));
    }

    void area(int side) {
        System.out.println("Area of Square: " + (side * side));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Q6 ob = new Q6();

        System.out.println("1. Area of Circle ");
        System.out.println("2. Area of Triangle ");
        System.out.println("3. Area of Square ");
        System.out.print("Enter your Choice :  ");
        int ch = sc.nextInt();

        switch (ch) {
            case 1:
                System.out.println("Enter radius of Circle : ");
                double radius = sc.nextDouble();
                ob.area(radius);
                break;

            case 2:
                System.out.println("Enter base and height of Triangle : ");
                double height = sc.nextDouble();
                double base = sc.nextDouble();
                ob.area(base, height);
                break;

            case 3:
                System.out.println("Enter side of Square : ");
                int side = sc.nextInt();
                ob.area(side);
                break;

            default:
                System.out.println("Invalid Choice");

        }

        sc.close();
    }
}
