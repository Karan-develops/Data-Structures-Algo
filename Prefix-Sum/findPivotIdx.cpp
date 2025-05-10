// LC - 724 - Easy - Find Pivot Index
#include<iostream>
#include<vector>
using namespace std;
int pivotIndex(vector<int>&nums){
    int n=nums.size();
    int ans=0;

    int totalSum=0;
    for(int &i:nums) totalSum+=i;

    int leftSum=0;
    for(int i=0;i<n;i++){
        int rightSum=totalSum-leftSum-nums[i];
        if(leftSum==rightSum) return i;
        leftSum+=nums[i];
    }
    return -1;
}
int main(){
    // Output: 3
    vector<int>nums={1,7,3,6,5,6};
    // Output: -1
    vector<int>nums2={1,2,3};
    // Output: 0
    vector<int>nums3={2,1,-1};
    cout<<pivotIndex(nums)<<endl;
    cout<<pivotIndex(nums2)<<endl;
    cout<<pivotIndex(nums3);
    return 0;
}