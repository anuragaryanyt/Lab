class ques5
{
    static int count = 0;
    ques5()
    {
        count++;
    }
    static void display()
    {
        System.out.println("Number of Objects: " + count);
    }
    public static void main(String[] args) {
        ques5 ob1 = new ques5();
        ques5 ob2 = new ques5();
        ques5 ob3 = new ques5();
        display();
    }
}
