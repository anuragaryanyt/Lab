package Q4;

import java.util.Scanner;

public class Rectangle {
    double length;
    double breadth;
    double area;
    double perimeter;

    void input() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter length & breadth : ");
        length = sc.nextDouble();
        breadth = sc.nextDouble();
        sc.close();
    }

    void calculate() {
        area = length * breadth;
        perimeter = 2 * (length + breadth);
    }

    void display() {
        System.out.println("Area : " + area);
        System.out.println("Perimeter : " + perimeter);
    }

    public static void main(String[] args) {
        Rectangle obj = new Rectangle();
        obj.input();
        obj.calculate();
        obj.display();
    }
}
