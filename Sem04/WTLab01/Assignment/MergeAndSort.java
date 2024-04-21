import java.util.Scanner;

class MergeAndSort {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int[] A = new int[50];
        int[] B = new int[50];
        int[] C = new int[100];
        System.out.println("Enter length of array A: ");
        int a = sc.nextInt();
        System.out.println("Enter length of array B: ");
        int b = sc.nextInt();
        System.out.println("ENTER THE ELEMENTS FOR Array A: ");
        for (int i = 0; i < a; i++) {
            A[i] = sc.nextInt();
        }
        System.out.println("ENTER THE ELEMENTS FOR Array B: ");
        for (int i = 0; i < b; i++) {
            B[i] = sc.nextInt();
        }
        sc.close();
        int i = 0, j = 0, k = 0;
        while (i < a) {
            C[k++] = A[i++];
        }
        while (j < b) {
            C[k++] = B[j++];
        }
        for (i = 0; i < a + b; i++) {
            for (j = i + 1; j < a + b; j++) {
                if (C[i] > C[j]) {
                    int temp = C[i];
                    C[i] = C[j];
                    C[j] = temp;
                }
            }
        }
        System.out.println("ELEMENTS OF ARRAY A :");
        for (i = 0; i < a; i++) {
            System.out.print(A[i] + " ");
        }
        System.out.println("\n");
        System.out.println("ELEMENTS OF ARRAY B :");
        for (i = 0; i < b; i++) {
            System.out.print(B[i] + " ");
        }
        System.out.println("\n");
        System.out.println("ELEMENTS OF ARRAY C :");
        for (i = 0; i < a + b; i++) {
            System.out.print(C[i] + " ");
        }
    }
}
