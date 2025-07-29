// LC - 2044 - Medium - Count Number of Maximum Bitwise-OR Subsets
// 2 Approaches
#include<iostream>
#include<vector>
using namespace std;
// Approach 1 - Without Memoization
class Solution{
    int n;
    int solve(vector<vector<int>>&dp,vector<int>&nums,int &maxOr,int currOr,int idx){
        if(idx>=n){
            if(currOr==maxOr) return dp[idx][currOr]=1;
            return dp[idx][currOr]=0;
        }

        if(dp[idx][currOr]!=-1) return dp[idx][currOr];

        int take=solve(dp,nums,maxOr,nums[idx]|currOr,idx+1);
        int skip=solve(dp,nums,maxOr,currOr,idx+1);

        return dp[idx][currOr]=take+skip;
    }
    public:
    int countMaxOrSubsets(vector<int>&nums){
        n=nums.size();

        int maxOr=0;
        for(int &i:nums) maxOr|=i;

        vector<vector<int>>dp(n+1,vector<int>(maxOr+1,-1));

        return solve(dp,nums,maxOr,0,0);
    }
};
// Approach 2 - Memoization
class DP{
    int n;
    int solve(vector<vector<int>>&dp,vector<int>&nums,int &maxOr,int currOr,int idx){
        if(idx>=n){
            if(currOr==maxOr) return dp[idx][currOr]=1;
            return dp[idx][currOr]=0;
        }

        if(dp[idx][currOr]!=-1) return dp[idx][currOr];

        int take=solve(dp,nums,maxOr,nums[idx]|currOr,idx+1);
        int skip=solve(dp,nums,maxOr,currOr,idx+1);

        return dp[idx][currOr]=take+skip;
    }
    public:
    int countMaxOrSubsets(vector<int>&nums){
        n=nums.size();

        int maxOr=0;
        for(int &i:nums) maxOr|=i;

        vector<vector<int>>dp(n+1,vector<int>(maxOr+1,-1));

        return solve(dp,nums,maxOr,0,0);
    }
};
int main(){
    // Output: 2
    vector<int>nums={3,1};
    // Output: 7
    vector<int>nums2={2,2,2};
    // Output: 6
    vector<int>nums3={3,2,1,5};

    DP sol;
    cout<<sol.countMaxOrSubsets(nums)<<endl;
    cout<<sol.countMaxOrSubsets(nums2)<<endl;
    cout<<sol.countMaxOrSubsets(nums3);
    return 0;
}