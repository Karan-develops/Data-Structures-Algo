// LC - 540 - Medium - Single Element in a Sorted Array
#include<iostream>
#include<vector>
using namespace std;
// Approach 1 - Bit Manipulation
int singleNonDuplicateBit(vector<int>&nums){
    int ans=0;
    for(int &i:nums) ans^=i;
    return ans;
}
// Approach 2 - Binary Search
int singleNonDuplicate(vector<int>&nums){
    int l=0,r=nums.size()-1;
    while(l<r){
        int mid=l+(r-l)/2;
        if(mid%2==1) mid--;
        if(nums[mid]==nums[mid+1]) l=mid+2;
        else r=mid;
    }
    return nums[l];
}
int main(){
    // Output: 2
    vector<int>nums={1,1,2,3,3,4,4,8,8};
    // Output: 10
    vector<int>nums2={3,3,7,7,10,11,11};
    cout<<singleNonDuplicate(nums)<<endl;
    cout<<singleNonDuplicate(nums2);
    return 0;
}