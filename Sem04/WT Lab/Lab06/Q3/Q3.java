package GeneralProject.WTLab.Lab06.Q3;

import java.util.Scanner;

public class Q3 {
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
        Q3 ob = new Q3();

        System.out.println("Enter radius of Circle : ");
        double radius = sc.nextDouble();
        ob.area(radius);

        System.out.println("Enter base and height of Triangle : ");
        double height = sc.nextDouble();
        double base = sc.nextDouble();
        ob.area(base, height);
        
        System.out.println("Enter side of Square : ");
        int side = sc.nextInt();
        ob.area(side);
        
        sc.close();
    }
}
