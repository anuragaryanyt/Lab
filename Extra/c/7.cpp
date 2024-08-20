//avg of the array

#include<iostream>
using namespace std;

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int size= sizeof(arr)/sizeof(arr[0]);
    float sum=0;
    for ( int i = 0; i<size; i++){
        sum=sum+arr[i];
    }
    float avg= sum/size;

    cout<<"Avg: "<<avg<<endl;
    return 0;
}