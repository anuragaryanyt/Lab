#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    cout<<"Enter the elements: ";
    for(int i =0; i<6;i++){
        int ele;
        cin >> ele;
        v.push_back(ele);
    }

    bool sortflag= true;
    for(int i=1;i<v.size();i++){
        if(v[i]<=v[i-1]){
            sortflag=false;
        }
    }
    cout<<sortflag<<endl;
    return 0;
}

