// LC - 153 - Medium - Find Minimum in Rotated Sorted Array
#include<iostream>
#include<vector>
using namespace std;
int findMin(vector<int>&nums){
    int ans=-1;
    int l=0,r=nums.size()-1;

    while(l<r){
        int mid=l+(r-l)/2;
        // Mid Can't Be Ans Bcoz it is > than nums[r]
        if(nums[mid]>nums[r]) l=mid+1;
        // Mid Can be Answer
        else r=mid;
    }
    return nums[r];
}
int main(){
    // Output: 1
    vector<int>nums={3,4,5,1,2};
    // Output: 0
    vector<int>nums2={4,5,6,7,0,1,2};
    // Output: 11
    vector<int>nums3={11,13,15,17};
    cout<<findMin(nums)<<endl;
    cout<<findMin(nums2)<<endl;
    cout<<findMin(nums3);
    return 0;
}