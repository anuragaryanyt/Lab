// finding repeating element

#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr={1,3,3,6,5,4,1,7,8,8,0,2,4};
    for (int i=0;i<arr.size();i++)
    {
        for (int j=i+1;j<arr.size();j++){
            if (arr[i]==arr[j]){
                cout<<arr[j]<<" ";
            }
        }
    }
    cout<<endl;
    return 0;
}