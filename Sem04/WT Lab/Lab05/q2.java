public class q2 {
    public static void main(String[] args) {
        int[] arr = new int[10];
        int count = 0;

        for (int i = 0; i < args.length; i++) {
            arr[i] = Integer.parseInt(args[i]);
            count++;
        }

        System.out.println("Even : ");
        for (int i : arr) {
            if (i % 2 == 0)
                System.out.println(i);
        }
        
        System.out.println("Odd : ");
        for (int i : arr) {
            if (i % 2 == 1)
                System.out.println(i);
        }

        System.out.println("\nNumber count : "+count);

    }
}
