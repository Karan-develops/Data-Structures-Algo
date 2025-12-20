// GFG - Easy - Search insert position of K in a sorted array
#include<iostream>
#include<vector>
using namespace std;
int searchInsertK(vector<int>&arr,int k){
    int n=arr.size();
    
    for(int i=0;i<n;i++){
        if(arr[i]>=k) return i;
    }
    
    return n;
}
int main(){
    // Output: 2
    vector<int>arr={1,3,5,6};
    int k=5;
    // Output: 1
    vector<int>arr2={1,3,5,6};
    int k2=2;
    // Output: 5
    vector<int>arr3={2,6,7,10,14};
    int k3=15;
    cout<<searchInsertK(arr,k)<<endl;
    cout<<searchInsertK(arr2,k2)<<endl;
    cout<<searchInsertK(arr3,k3);
    return 0;
}