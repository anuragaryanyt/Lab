package GeneralProject.WTLab.Lab09;

public class Q1 {
    public static void main(String[] args) {
        int[] arr={1,2,3,4,5};
        try {
            System.out.println(arr[10]);
        }
        catch (Exception e){
            System.out.println("Array index out of bounds");
        }
    }
}
