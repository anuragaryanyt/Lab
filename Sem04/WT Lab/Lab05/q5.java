class q5
{
    static int count = 0;
    q5()
    {
        count++;
    }
    static void display()
    {
        System.out.println("Number of Objects: " + count);
    }
    public static void main(String[] args) {
        q5 ob1 = new q5();
        q5 ob2 = new q5();
        q5 ob3 = new q5();
        display();
    }
}