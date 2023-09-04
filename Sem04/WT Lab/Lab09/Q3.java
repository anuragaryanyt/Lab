package GeneralProject.WTLab.Lab09;

import java.util.Scanner;

class HrsException extends Exception {
    HrsException(String s) {
        super(s);
    }
}

class MinException extends Exception {
    MinException(String s) {
        super(s);
    }
}

class SecException extends Exception {
    SecException(String s) {
        super(s);
    }
}

class Q3 {
    int hours;
    int minutes;
    int seconds;

    Q3(int h, int m, int s) throws HrsException, MinException, SecException {
        if (h > 24 || h < 0)
            throw new HrsException("Invalid hours");
        else
            hours = h;
        if (m > 60 || m < 0)
            throw new MinException("Invalid minutes");
        else
            minutes = m;
        if (s > 60 || s < 0)
            throw new SecException("Invalid seconds");
        else
            seconds = s;
    }

    public static void main(String[] args) {
        try {
            Scanner sc=new Scanner(System.in);
            System.out.println("Enter time : ");
            int hr=sc.nextInt();
            int min=sc.nextInt();
            int sec=sc.nextInt();
            Q3 t = new Q3(hr, min, sec);
        } catch (HrsException | MinException | SecException e) {
            System.out.println(e.getMessage());
        }
    }
}