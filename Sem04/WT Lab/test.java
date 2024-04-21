package GeneralProject.WTLab;
class Student

{

 int rollno;

 String name;

 float fee;

 Student(int rollno,String name,float fee)

 {

  rollno=rollno;

  name=name;

  fee=fee;

 }

 void display()

 {

  System.out.print(rollno+" "+name+" "+fee+":");

 }

}

class test

{

 public static void main(String args[ ])

 {

  Student s1=new Student(111,"ankit",5000f);

  Student s2=new Student(112,"sumit",6000f);

  s1.display();

  s2.display();

 }

}