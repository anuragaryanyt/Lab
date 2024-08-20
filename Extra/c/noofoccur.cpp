//count no of occurances of a element 

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector <int> v;
    cout<<"Enter the elements: ";
    for(int i=0;i<6;i++){
        int ele;
        cin>>ele;
        v.push_back(ele);
    }

    int x;
    cout<<"Enter x: ";
    cin>>x;

    int count=0;

    // for(int i=0;i<v.size();i++){
    //     if (v[i]==x){
    //         count++;
    //     }
    // }    

    // "for each" loop example
    for(int elem:v){
        if (elem==x){
            count++;
        }
    }

    cout<<"No of Occurances: "<<count<<endl;
    return 0;

}