import java.util.*;
public class power {
    public static void powerfunc(int x, int y){
        double c = Math.pow(x, y);
        System.out.println(c);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the no: ");
        int x= sc.nextInt();

        System.out.println("ENter the power: ");
        int y=sc.nextInt();
        sc.close();

        powerfunc(x, y);
        
    }
}

