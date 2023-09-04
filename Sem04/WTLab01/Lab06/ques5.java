import java.util.Scanner;

public class ques5 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of students: ");
        int n = scanner.nextInt();
        
        Student[] students = new Student[n];

        for (int i = 0; i < n; i++) {
            System.out.println("\nEnter details for student " + (i+1) + ":");
            System.out.print("Roll number: ");
            int roll = scanner.nextInt();
            System.out.print("Name: ");
            String name = scanner.next();
            System.out.print("CGPA: ");
            double cgpa = scanner.nextDouble();
            students[i] = new Student(roll, name, cgpa);
        }

        System.out.println("\nDetails of all students:");
        for (Student student : students) {
            System.out.println(student);
        }

        Student lowestCGPAStudent = students[0];
        for (int i = 1; i < n; i++) {
            if (students[i].getCgpa() < lowestCGPAStudent.getCgpa()) {
                lowestCGPAStudent = students[i];
            }
        }

        System.out.println("\nStudent with the lowest CGPA:");
        System.out.println(lowestCGPAStudent.getName());
        scanner.close();
    }
}

class Student {
    private int roll;
    private String name;
    private double cgpa;
    
    public Student(int roll, String name, double cgpa) {
        this.roll = roll;
        this.name = name;
        this.cgpa = cgpa;
    }
    
    public int getRoll() {
        return roll;
    }
    
    public String getName() {
        return name;
    }
    
    public double getCgpa() {
        return cgpa;
    }
    
    @Override
    public String toString() {
        return "Roll Number: " + roll + ", Name: " + name + ", CGPA: " + cgpa;
    }
}

