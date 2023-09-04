package Q7;

import java.util.Scanner;

public class Number {
    int[] arr;

    Number(int n) {
        arr = new int[n];
    }

    void read() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Elements : ");
        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextInt();
        }
        sc.close();
    }

    void swap() {
        int max = 0;
        int min = 0;

        for (int i = 1; i < arr.length; i++) {
            {
                if (arr[i] > arr[max])
                    max = i;
                if (arr[i] < arr[min])
                    min = i;
            }
        }
        int temp = arr[max];
        arr[max] = arr[min];
        arr[min] = temp;

    }

    void display() {
        for (int i : arr)
            System.out.print(i + "\t");
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter value of n : ");
        int n = sc.nextInt();

        Number obj = new Number(n);
        obj.read();
        obj.swap();
        obj.display();
        sc.close();
    }
}
