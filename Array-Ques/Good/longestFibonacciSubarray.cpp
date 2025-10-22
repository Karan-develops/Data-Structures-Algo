// LC - 3708 - Medium - Longest Fibonacci Subarray
#include<iostream>
#include<vector>
using namespace std;
int longestSubarray(vector<int>&nums){
    int n=nums.size();
    if(n<=2) return n;

    int ans=2;
    int curr=2;

    for(int i=2;i<n;i++){
        if(nums[i]==nums[i-1]+nums[i-2]){
            curr++;
        } else{
            curr=2;
        }
        ans=max(ans,curr);
    }
    return ans;
}
int main(){
    // Output: 5
    vector<int>nums={1,1,1,1,2,3,5,1};
    // Output: 5
    vector<int>nums2={5,2,7,9,16};
    // Output: 2
    vector<int>nums3={1000000000,1000000000,1000000000};
    cout<<longestSubarray(nums)<<endl;
    cout<<longestSubarray(nums2)<<endl;
    cout<<longestSubarray(nums3);
    return 0;
}