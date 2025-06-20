// LC - 852 - Medium - Peak Index in a Mountain Array
#include<iostream>
#include<vector>
using namespace std;
int peakIndexInMountainArray(vector<int>&arr){
    int l=0,r=arr.size()-1;

    while(l<=r){
        int mid=l+(r-l)/2;

        if(arr[mid]<arr[mid+1]){
            l=mid+1;
        } else r=mid-1;
    }
    // Return l or r anything
    return l;
}
int main(){
    // Output: 1
    vector<int>arr={0,1,0};
    // Output: 1
    vector<int>arr2={0,2,1,0};
    // Output: 1
    vector<int>arr3={0,10,5,2};
    cout<<peakIndexInMountainArray(arr)<<endl;
    cout<<peakIndexInMountainArray(arr2)<<endl;
    cout<<peakIndexInMountainArray(arr3);
    return 0;
}