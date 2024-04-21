import java.util.*;

class Q1
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name, branch;
        char sec;
        int roll;
        for (int i = 1; i <= 3; i++) {
            System.out.print("\nEnter Name: ");
            name = sc.nextLine();
            System.out.print("Enter Roll: ");
            roll = sc.nextInt();
            System.out.print("Enter Section: ");
            sec = sc.next().charAt(0);
            sc.nextLine();
            System.out.print("Enter Branch: ");
            branch = sc.nextLine();

            user ob = new user(name, roll, sec, branch);
            System.out.println("\nUser " + i);
            ob.display();
        }
        sc.close();
    }
}

class user
{
    String name;
    int roll;
    char sec;
    String branch;

    user(String name, int roll, char sec, String branch)
    {
        this.name = name;
        this.roll = roll;
        this.sec = sec;
        this.branch = branch;
    }

    void display()
    {
        System.out.println("Name: " + this.name);
        System.out.println("Roll: " + this.roll);
        System.out.println("Section: " + this.sec);
        System.out.println("Branch: " + this.branch);
    }
}