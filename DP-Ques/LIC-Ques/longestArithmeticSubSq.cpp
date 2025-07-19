// LC - 1027 - Medium - Longest Arithmetic Subsequence
// 2 Approaches
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
// Approach 1 - Top Down ( Recursion + Memo )
class DP{
    int n;
    int dp[1001][1003];
    int solve(vector<int>&nums,int i,int diff){
        if(i<0) return 0;

        if(dp[i][diff+501]!=-1) return dp[i][diff+501];

        int ans=0;

        // Going Left Side
        for(int k=i-1;k>=0;k--){
            if(nums[i]-nums[k]==diff){
                ans=max(ans,1+solve(nums,k,diff));
            }
        }
        return dp[i][diff+501]=ans;
    }
    public:
    int longestArithSeqLength(vector<int>&nums){
        n=nums.size();
        if(n<=2) return n;

        int ans=1;
        memset(dp,-1,sizeof(dp));

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff=nums[j]-nums[i];

                ans=max(ans,2+solve(nums,i,diff));
            }
        }
        return ans;
    }
};
// Approach 2 - Bottom Up LIS
class LIS{
    public:
    int longestArithSeqLength(vector<int>&nums){
        int n=nums.size();
        if(n<=2) return n;

        vector<vector<int>>dp(n,vector<int>(1001,0));
        int ans=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=nums[i]-nums[j]+500;

                dp[i][diff]=dp[j][diff]>0?dp[j][diff]+1:2;

                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};