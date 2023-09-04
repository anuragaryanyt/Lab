package Q1;
import java.util.Scanner;

class Box {
    double length;
    double width;
    double height;

    Box(double length, double width, double height) {
        this.length = length;
        this.width = width;
        this.height = height;
    }

    void volume() {
        System.out.println("Volume: " + (length * width * height));
    }
}

class Demo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter length, breadth & height : ");
        double length = sc.nextDouble();
        double breadth = sc.nextDouble();
        double height = sc.nextDouble();

        Box box = new Box(length, breadth, height);
        box.volume();
        sc.close();
    }
}