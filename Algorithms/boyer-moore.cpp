// Boyer-Moore Voting Algorithm
/*
This algorithm is used to find the majority element (an element that appears more than n/2 times) in an array in O(n) time and O(1) space.
*/
// Question - Majority element 1 & 2
#include<iostream>
#include<vector>
using namespace std;
int boyerMoore(vector<int>&nums){
    int n=nums.size();
    int count=1;
    int ans=nums[0];
    for(int i=1;i<n;i++){
        if(nums[i]!=ans && count==0){
            ans=nums[i];
            count++;
        }
        else if(nums[i]!=ans) count--;
        else count++;
    }
    return ans;
}
// With Verification
int boyerMooreMajority(vector<int> &nums) {
    int ans=-1,count=0;
    // Step 1: Find the ans
    for(int num:nums){
        if(count==0) ans=num;
        count+=(num==ans)?1:-1;
    }
    // Step 2: Verify the ans
    count = 0;
    for(int num:nums){
        if(num==ans) count++;
    }
    return (count>nums.size()/2)?ans:-1;
}
int main(){
    // Output: 3
    vector<int>nums={3,2,3};
    // Output: 2
    vector<int>nums2={2,2,1,1,1,2,2};
    cout<<boyerMoore(nums)<<endl;
    cout<<boyerMoore(nums2);
    return 0;
}