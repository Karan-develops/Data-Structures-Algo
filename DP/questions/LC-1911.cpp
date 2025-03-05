// Top-Down
/*#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
class LC1911{
    public:
    int n;
    int dp[100][2]; // long long t[1000001][2];
    int solve(vector<int>&nums,int idx,bool flag){
        if(idx>=n) return 0;
        if(dp[idx][flag]!=-1) return dp[idx][flag];
        int skip=solve(nums,idx+1,flag);
        int val=nums[idx];
        if(flag==false) val=-val;
        int take=solve(nums,idx+1,!flag)+val;
        return dp[idx][flag]=max(skip,take);
    }
    int maxAlternatingSum(vector<int>&nums){
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,true);
    }
};
int main(){
    vector<int>nums={4,2,5,3};
    LC1911 lc;
    cout<<lc.maxAlternatingSum(nums);
    return 0;
}*/
// Bottom-Up
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>nums={4,2,5,3};
    int n=nums.size();
    vector<vector<int>>dp(n,vector<int>(2,0));
    dp[0][0]=max(-nums[0],0);
    dp[0][1]=max(nums[0],0);
    for(int i=1;i<n;i++){
        dp[i][0]=max(dp[i-1][1]-nums[i],dp[i-1][0]);
        dp[i][1]=max(dp[i-1][0]+nums[i],dp[i-1][1]);
    }
    cout<<max(dp[n-1][0],dp[n-1][1]);
    return 0;
}