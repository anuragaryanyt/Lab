import java.util.*;
public class circle {
    public static void circumference(float r){
        double c = 2*3.14*r;
        System.out.println("Circumference of circle is: "+c);

    }

    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        System.out.print("Enter the radius: ");
        float r = sc.nextFloat();
        sc.close();

        circumference(r);
    }
}

