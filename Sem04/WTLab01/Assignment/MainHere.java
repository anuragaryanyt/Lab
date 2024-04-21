import java.util.Scanner;

class Vehicle {
    int regnNumber;
    double speed;
    String color;
    String ownerName;

    void showData() {
        System.out.println("This is a vehicle class.");
    }
}

class Bus extends Vehicle {
    int routeNumber;

    void showData() {
        super.showData();q
        System.out.println("This is a bus.");
        System.out.println("Regn No : " + regnNumber);
        System.out.println("Speed : " + speed);
        System.out.println("Color : " + color);
        System.out.println("Owner Name: " + ownerName);
        System.out.println("Route Number: " + routeNumber);
    }
}

class Car extends Vehicle {
    String manufacturerName;

    void showData() {
        super.showData();
        System.out.println("This is a car.");
        System.out.println("Regn No : " + regnNumber);
        System.out.println("Speed : " + speed);
        System.out.println("Color : " + color);
        System.out.println("Owner Name: " + ownerName);
        System.out.println("Manufacturer Name:" + manufacturerName);
    }
}

class MainHere {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Bus mybus = new Bus();
        System.out.println("Enter reg no: ");
        mybus.regnNumber = sc.nextInt();
        System.out.println("Enter speed: ");
        mybus.speed = sc.nextDouble();
        System.out.println("Enter color: ");
        mybus.color = sc.next();
        System.out.println("Enter owner name: ");
        mybus.ownerName = sc.next();
        System.out.println("Enter route no: ");
        mybus.routeNumber = sc.nextInt();
        mybus.showData();

        Car mycar = new Car();
        System.out.println("Enter reg no: ");
        mycar.regnNumber = sc.nextInt();
        System.out.println("Enter speed: ");
        mycar.speed = sc.nextDouble();
        System.out.println("Enter color: ");
        mycar.color = sc.next();
        System.out.println("Enter owner name: ");
        mycar.ownerName = sc.next();
        System.out.println("Enter manufacturer name: ");
        mycar.manufacturerName = sc.next();
        mycar.showData();
        sc.close();
    }
}
