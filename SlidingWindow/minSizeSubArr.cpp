// LC - 209 - Medium - Minimum Size Subarray Sum
#include<iostream>
#include<vector>
using namespace std;
int minSubArrayLen(int target,vector<int>&nums){
    int n=nums.size();
    int minLength=INT_MAX;
    int i=0,j=0,sum=0;
    while(j<n){
        sum+=nums[j];
        // Window choti kr rhe h
        while(sum>=target){
            minLength=min(minLength,j-i+1);
            sum-=nums[i];
            i++;
        }
        j++;
    }
    return minLength==INT_MAX?0:minLength;
}
int main(){
    // Output: 2
    int target=7;
    vector<int>nums={2,3,1,2,4,3};
    // Output: 1
    int target2=4;
    vector<int>nums2={1,4,4};
    // Output: 0
    int target3=11;
    vector<int>nums3={1,1,1,1,1,1,1,1};
    cout<<minSubArrayLen(target,nums)<<endl;
    cout<<minSubArrayLen(target2,nums2)<<endl;
    cout<<minSubArrayLen(target3,nums3);
    return 0;
}