import java.util.Scanner;

class Q3 {
    public static void main(String s[]) {
        Scanner sc = new Scanner(System.in);
        int day;
        System.out.println("Enter Day : ");
        day = sc.nextInt();

        day = day % 7;

        switch (day) {
            case 1:
                System.out.println("Wednesday");
                break;
            case 2:
                System.out.println("Thursday");
                break;
            case 3:
                System.out.println("Friday");
                break;
            case 4:
                System.out.println("Saturday");
                break;
            case 5:
                System.out.println("Sunday");
                break;
            case 6:
                System.out.println("Monday");
                break;
            case 7:
                System.out.println("Tuesday");
                break;

        }
        sc.close();
    }
}