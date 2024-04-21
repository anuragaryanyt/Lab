package GeneralProject.WTLab.Sessional;

public class Perimeter {
    void meth(double r){
        System.out.println("Perimeter of Circle : " + (2*3.14*r));
    }
    void meth(int b){
        System.out.println("Perimeter of Square : " + 4*b);
    }
    void meth(int a,int b,int c){
        System.out.println("Perimeter of Triangle : " + (a+b+c));
    }
    void meth(int a,int b){
        System.out.println("Perimeter of Rectangle : " + (2*(a+b)));
    }
}
