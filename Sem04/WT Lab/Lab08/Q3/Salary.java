package GeneralProject.WTLab.Lab08.Q3;

import java.util.Scanner;

public interface Salary {
    void earnings(int basic);
    void deductions(int basic);
    void bonus(int basic);
}

class Manager implements Salary{

    @Override
    public void earnings(int basic) {
        double earning=basic+(0.8*basic)+(0.15*basic);
        System.out.println("Earning : "+earning);
    }

    @Override
    public void deductions(int basic) {
        System.out.println("Deduction PF : "+(0.12*basic));
    }

    @Override
    public void bonus(int basic) {

    }
}

class SubStaff extends Manager{
    @Override
    public void bonus(int basic) {
        super.bonus(basic);
        System.out.println("Bonus : "+(0.5*basic));
    }
}

class Emp{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter basic : ");
        int basic=sc.nextInt();

        Salary obj=new SubStaff();
        obj.earnings(basic);
        obj.deductions(basic);
        obj.bonus(basic);
    }
}