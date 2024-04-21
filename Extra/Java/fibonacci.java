import java.util.*;
public class fibonacci {
    public static void fibonacciseries(int x){
        int a=0, b=1, next_term;
        System.out.print("Fibonacci series upto " + x + " terms: ");
        System.out.print(a + ", " + b);

        for (int i = 2; i < x; i++) {
            next_term = a + b;
            System.out.print(", " + next_term);
            a = b;
            b = next_term;
        }

        System.out.println();
    }

    public static void main(String[] args) {

        Scanner sc= new Scanner(System.in);
        System.out.print("Enter the n term: ");
        int x = sc.nextInt();
        sc.close();
        fibonacciseries(x);

    }
}











// void fibonacci(int n) {
//     int a = 0, b = 1, next_term;
//     printf("Fibonacci series up to %d terms: ", n);
//     printf("%d, %d", a, b); // Print first two terms
    
//     for (int i = 2; i < n; i++) {
//         next_term = a + b;
//         printf(", %d", next_term);
//         a = b;
//         b = next_term;
//     }
//     printf("\n");
// }

