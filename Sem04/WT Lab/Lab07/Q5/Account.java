package GeneralProject.WTLab.Lab07.Q5;

import java.beans.Customizer;
import java.util.Scanner;

public class Account {
    long acc_no;
    double balance;

    Account(long acc_no, double balance) {
        this.acc_no = acc_no;
        this.balance = balance;
    }

    void disp() {
        System.out.printf("\nAccount No : %d\nBalance : %.2f\n\n", acc_no, balance);
    }
}

class Person extends Account {
    String name;
    int aadhar_no;

    Person(long acc_no, double balance, String name, int aadhar_no) {
        super(acc_no, balance);
        this.name = name;
        this.aadhar_no = aadhar_no;
    }

    void disp() {
        System.out.printf("\n\nName : %s\nAadhar No : %d", name, aadhar_no);
        super.disp();
    }
}

class Q5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Person[] arr = new Person[5];

        for (int i = 0; i < 5; i++) {
            System.out.printf("Customer %d :\n",i+1);
            sc.nextLine();
            System.out.print("Enter Name : ");
            String name = sc.nextLine();
            System.out.print("Enter Aadhar no : ");
            int aadhar = sc.nextInt();
            System.out.print("Enter Account No : ");
            long acc = sc.nextLong();
            System.out.print("Enter Balance : ");
            double bal = sc.nextDouble();

            arr[i] = new Person(
                    acc,
                    bal,
                    name,
                    aadhar
            );
        }

        for(Person i:arr){
            i.disp();
        }
    }
}