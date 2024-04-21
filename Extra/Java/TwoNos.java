import java.util.*;

public class TwoNos {
    public static void greater(int a, int b) {
        if (a > b) {
            System.out.println(a + " is greater number");
        } else if (b > a) {
            System.out.println(b + " is greater number");
        } else {
            System.out.println("Both are equal!!");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("1st no: ");
        int a = sc.nextInt();

        System.out.print("2nd no: ");
        int b = sc.nextInt();

        sc.close();
        greater(a, b);

    }
}


// import java.util.*;

// public class TwoNos {
//     public static void greaterthantwonumbers(int a, int b) {
//         if (a>b) {
//         System.out.println("A  is greater");}
//         else{
//             System.out.println("B is greater");
//         }
// }


// public static void main(String[] args) {
//     Scanner sc=new Scanner(System.in);
//     System.out.println("Enter the value of first number");
//     int a= sc.nextInt();
//     System.out.println("Enter the value of second number");
//     int b = sc.nextInt();
//     greaterthantwonumbers(a,b);
// }
// }