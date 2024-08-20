#include <iostream>
#include <string>
#include<algorithm>
#include <string.h>
using namespace std;
int main()
{
    // // ascii value

    // char ch='A';
    // cout<<int(ch)<<endl;

    string str;
    cout << "Enter the name: ";
    getline(cin, str);
    cout <<"original String: "<< str << endl;

    //Indexing
    cout<<"Inedxing: ";
    cout << str[2]<<endl;

    //reverse function
    string str2= str;
    cout<<"reverse Func: ";
    reverse(str2.begin(),str2.end());
    cout<<str2<<endl;

    //sub string
    cout<<"substring: ";
    cout<<str.substr(4,5)<<endl;  //(strating index, length)
    // cout<<str.substr(2)<<endl;    //(strating fromindex 3 to end till null value is not found)

    //concat string
    cout<<"concat string: ";
    cout<<str+str2<<endl;

    //strcat basically it is used for concating in char array 
    char s1[10]="Anurag";
    char s2[10]="Tiwary";
    strcat(s1,s2); //s2 is being concatinate in s1
    cout<<"strcat: "<<s1<<endl;

    //push_back
    string str3 = str;
    char ch = 'A';
    str3.push_back(ch);
    cout<<"push_bck: "<<str3<<endl;

    //size of string
    cout<<"Size of str: "<<str.size()<<endl;
    // cout<<"Size of str: "<<str.length()<<endl;
    char ab[10] = "fdsfesf";
    cout<<"Lenght of char array: "<<strlen(ab)<<endl;

    //to_string func it converts number into string
    int a= 1234;
    string str4= to_string(a);
    cout<<"num to str: "<<str4<<endl;

    //add number 5 to it
    char b ='5';
    str4+="5";
    // str4.push_back(b);
    cout<<"appending num: "<<str4<<endl;
    cout<<str4[2]<<endl;

    








    return 0;
}