//min element in an array

#include<iostream>
using namespace std;

int main(){
    int arr[]={10,3,4,5,2,61,3,1};
    int size= sizeof(arr)/sizeof arr[0];
    int min = arr[0];

    for (int i=0;i<size;i++){
        if (min>arr[i]){
            min=arr[i];
        }
    }
    cout<<"min element is: "<<min<<endl;
    return 0;
}