package GeneralProject.WTLab.Lab07.Q4;

import java.util.Scanner;

public class Shape {
    double area;

    void showArea() {
        System.out.println("Area : " + area);
    }
}

class Circle extends Shape {
    double radius;

    Circle(double radius) {
        this.radius = radius;
    }

    void calcArea() {
        area = 3.14 * radius * radius;
    }
}

class Rectangle extends Shape {
    int length;
    int breadth;

    Rectangle(int length, int breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    void calcArea() {
        area = length * breadth;
    }
}

class Q4{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Radius : ");
        double radius=sc.nextDouble();
        Circle circle=new Circle(radius);
        circle.calcArea();
        circle.showArea();

        System.out.print("Enter Length & Breadth : ");
        int length=sc.nextInt();
        int breadth=sc.nextInt();
        Rectangle rectangle=new Rectangle(length,breadth);
        rectangle.calcArea();
        rectangle.showArea();
    }
}
