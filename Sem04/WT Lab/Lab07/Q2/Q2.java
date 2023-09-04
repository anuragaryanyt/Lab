package GeneralProject.WTLab.Lab07.Q2;

import java.util.Scanner;

public class Q2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter length,breadth,height and thickness : ");
        int l = sc.nextInt();
        int b = sc.nextInt();
        int h = sc.nextInt();
        int t = sc.nextInt();

        wood_box wood_box = new wood_box(l, b, h, t);
        System.out.printf("Length : %d\nBreadth : %d\nHeight : %d\nThickness : %d",
                wood_box.length, wood_box.breadth, wood_box.height, wood_box.thick);
    }

}
