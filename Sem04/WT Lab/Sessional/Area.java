package GeneralProject.WTLab.Sessional;

import java.util.Scanner;

public class Area extends Perimeter{
    void meth(double r){
        System.out.println("Area of Circle : " + (3.14*r*r));
    }
    void meth(int b){
        System.out.println("Area of Square : " + b*b);
    }
    void meth(int b,double h){
        System.out.println("Area of Triangle : " + (0.5*b*h));
    }
    void meth(int a,int b){
        System.out.println("Area of Rectangle : " + (a*b));
    }

    public void process() {
        Scanner sc=new Scanner(System.in);

        System.out.println("1.Circle\n2.Square\n3.Triangle\n4.Rectangle\n");
        System.out.print("Enter choice : ");

        try{
            int ch=sc.nextInt();
            switch (ch){
                case 1:
                    System.out.println("Enter Radius : ");
                    double r=sc.nextDouble();
                    super.meth(r);
                    meth(r);
                    break;

                case 2:
                    System.out.println("Enter Side : ");
                    int b=sc.nextInt();
                    super.meth(b);
                    meth(b);
                    break;

                case 3:
                    System.out.println("Enter 3sides of the triangle and its height : ");
                    int a=sc.nextInt();
                    int d=sc.nextInt();
                    int c=sc.nextInt();
                    double h=sc.nextDouble();

                    super.meth(a,d,c);
                    meth(d,h);
                    break;

                case 4:
                    System.out.println("Enter length and breadth : ");
                    int x=sc.nextInt();
                    int y=sc.nextInt();
                    super.meth(x,y);
                    meth(x,y);
                    break;

                default:
                    System.out.println("Invalid Input");
                    break;

            }
        }catch (Exception e){
            System.out.println(e.getMessage());
        }
    }

    public static void main(String[] args) {
        new Area().process();
    }
}
