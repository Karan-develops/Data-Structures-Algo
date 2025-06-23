// GFG - Perfect Sum Problem
#include<iostream>
#include<vector>
using namespace std;
class DP{
    int n;
    int solve(vector<vector<int>>&dp,vector<int>&nums,int target,int idx){
        if(idx>=n){
            return target==0?1:0;
        }

        if(dp[idx][target]!=-1) return dp[idx][target];

        int take=0;
        if(nums[idx]<=target){
            take=solve(dp,nums,target-nums[idx],idx+1);
        }
        int skip=solve(dp,nums,target,idx+1);

        return dp[idx][target]=take+skip;
    }
    public:
    int perfectSum(vector<int>&nums,int target){
        n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));

        return solve(dp,nums,target,0);
    }
};
int main(){
    // Output: 3
    vector<int>nums={5,2,3,10,6,8};
    int target=10;
    // Output: 3
    vector<int>nums2={2,5,1,4,3};
    int target2=10;
    // Output: 0
    vector<int>nums3={5,7,8};
    int target3=3;
    // Output: 1
    vector<int>nums4={35,2,8,22};
    int target4=0;

    DP sol;
    cout<<sol.perfectSum(nums,target)<<endl;
    cout<<sol.perfectSum(nums2,target2)<<endl;
    cout<<sol.perfectSum(nums3,target3)<<endl;
    cout<<sol.perfectSum(nums4,target4);
    return 0;
}