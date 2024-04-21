package GeneralProject.WTLab.Lab08.Q2;

public interface Motor {
    int capacity = 100;

    void run();
    void consume();
}

class WashingMachine implements Motor{

    @Override
    public void run() {
        System.out.println("Run Capacity : "+capacity);
    }

    @Override
    public void consume() {
        System.out.println("Consume Capacity : "+capacity);
    }
}

class inter{
    public static void main(String[] args) {
        Motor obj=new WashingMachine();
        obj.run();
        obj.consume();
    }
}
