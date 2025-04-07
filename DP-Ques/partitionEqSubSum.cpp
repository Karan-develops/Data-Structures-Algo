// LC - 416 - Medium - Partition Equal Subset Sum
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
class Solution{
    int n;
    bool solve(vector<int>&nums,vector<vector<int>>&dp,int target,int currSum,int i){
        if(currSum==target) return true;
        if(i>=n || currSum>target) return false;

        if(dp[i][currSum]!=-1) return dp[i][currSum];

        bool take=solve(nums,dp,target,currSum+nums[i],i+1);
        bool skip=solve(nums,dp,target,currSum,i+1);

        return dp[i][currSum]=take||skip;
    }
    public:
    bool canPartition(vector<int>&nums){
        n=nums.size();
        int sum=accumulate(begin(nums),end(nums),0);
        if(sum%2!=0) return false;

        // If we achieve one half obv other half can be partitioned
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(nums,dp,target,0,0);
    }
};
int main(){
    // Output: true
    vector<int>nums={1,5,11,5};
    // Output: false
    vector<int>nums2={1,2,3,5};
    Solution sol;
    cout<<sol.canPartition(nums)<<endl;
    cout<<sol.canPartition(nums2);
    return 0;
}