import java.util.Scanner;

public class Number {
    private int[] numbers;
    private int n;

    public void read() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of integers: ");
        n = scanner.nextInt();

        numbers = new int[n];
        System.out.println("Enter " + n + " integers:");
        for (int i = 0; i < n; i++) {
            numbers[i] = scanner.nextInt();
        }
        scanner.close();
    }

    public void swap() {
        int minIndex = 0;
        int maxIndex = 0;
        for (int i = 1; i < n; i++) {
            if (numbers[i] < numbers[minIndex]) {
                minIndex = i;
            }
            if (numbers[i] > numbers[maxIndex]) {
                maxIndex = i;
            }
        }
        int temp = numbers[minIndex];
        numbers[minIndex] = numbers[maxIndex];
        numbers[maxIndex] = temp;
    }

    public void display() {
        System.out.println("After swapping the biggest and smallest elements:");
        for (int i = 0; i < n; i++) {
            System.out.print(numbers[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Number number = new Number();
        number.read();
        number.swap();
        number.display();
    }
}
