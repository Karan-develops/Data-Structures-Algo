// Helps to find minimum element using Binary Search
#include<iostream>
#include<vector>
using namespace std;
int findPivot(vector<int>&nums){
    int l=0,r=nums.size()-1;

    while(l<r){
        int mid=l+(r-l)/2;
        // Chote elements right side h
        if(nums[mid]>nums[r]) l=mid+1;
        else r=mid;
    }
    
    return r;
}
int main(){
    vector<int>nums={4,5,6,7,0,1,2};
    cout<<findPivot(nums);
    return 0;
}