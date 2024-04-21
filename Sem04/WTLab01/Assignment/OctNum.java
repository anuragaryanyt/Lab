import java.util.Scanner;
import java.lang.Math;

class Num {
    int num = 0;

    void shownum() {
        System.out.println("THE NUMBER IS: " + num);
    }
}

class OctNum extends Num {
    void shownum() {
        System.out.println("THE OCTAL NUMBER IS: " + num);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Num obj = new Num();
        obj = new OctNum();
        System.out.println("Enter Number: ");
        int x = sc.nextInt();
        obj.num = x;
        int[] octNum = new int[100];
        int i = 0;
        int z = 0;
        while (obj.num != 0) {
            octNum[i] = obj.num % 8;
            obj.num = obj.num / 8;
            i++;
        }
        for (int j = i - 1; j >= 0; j--) {
            z += octNum[j] * Math.pow(10, j);
        }
        obj.num = z;
        obj.shownum();
        sc.close();
    }
}
