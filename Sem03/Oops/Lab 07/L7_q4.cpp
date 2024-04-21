// Extend the program ii. of inheritance to include a class sports, which stores the marks in
// sports activity. Derive the result class from the classes ‘test’ and ‘sports’. Create objects
// using parameterized constructors .Calculate the total marks and percentage of a student

#include <iostream>
using namespace std;
class student
{
public:
    int total;
    float percent;

    student()
    {
        total = 0;
        percent = 0;
    }
};
class test : public student
{
public:
    int subj1, subj2, subj3;
    test(int s1, int s2, int s3)
    {
        subj1 = s1;
        subj2 = s2;
        subj3 = s3;
    }
};
class sports
{
public:
    int sport;
    sports(int s)
    {
        sport = s;
    }
};
class result : public test, public sports
{
public:
    result(int s1, int s2, int s3, int s) : test(s1, s2, s3), sports(s)
    {
    }

    void calc()
    {
        total = subj1 + subj2 + subj3 + sport;
        percent = ((float)total / 400) * 100;
        cout << "Total Marks : " << total << "\nTotal Percentage : " << percent << "%" << endl;
    }
};

int main()
{
    int s1, s2, s3, s;
    cout << "Enter 3 Subject Marks : ";
    cin >> s1 >> s2 >> s3;
    cout << "Enter Sports Marks :";
    cin >> s;

    result res(s1, s2, s3, s);
    res.calc();
}
