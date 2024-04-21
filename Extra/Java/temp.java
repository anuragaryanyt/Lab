// package DTypes;
import java.util.Scanner;

public class temp {
    public static void main(String[] args) {
        
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter the temp in farenheit:");
        float f=sc.nextFloat();

        float cel= (f-32)*5/9;
        System.out.println("Temp oin celcius is "+ cel+"deg");

        sc.close();

    }
    
}
