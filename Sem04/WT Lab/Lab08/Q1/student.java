package GeneralProject.WTLab.Lab08.Q1;

import java.util.Scanner;

public abstract class student {
    int roll_no, reg_no;

    abstract void course(String c);

    abstract void branch(String b);
}

class generic extends student {
    @Override
    void course(String c) {
        System.out.println("Course : " + c);
    }

    @Override
    void branch(String b) {
        System.out.println("Roll : " + roll_no);
        System.out.println("Reg No : " + reg_no);
        System.out.println("Branch : " + b);
    }
}

class absCl {
    public static void main(String[] args) {
        String c, b;
        Scanner sc = new Scanner(System.in);
        student ob = new generic();
        System.out.print("Enter Roll : ");
        ob.roll_no = sc.nextInt();
        System.out.print("Enter Reg. No : ");
        ob.reg_no = sc.nextInt();

        sc.nextLine();
        System.out.print("Enter Branch : ");
        b = sc.nextLine();
        System.out.print("Enter Course : ");
        c = sc.nextLine();

        ob.branch(b);
        ob.course(c);
    }
}
