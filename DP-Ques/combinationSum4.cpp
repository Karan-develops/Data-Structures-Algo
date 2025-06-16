// LC - 377 - Medium - Combination Sum IV
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
class DP{
    int n;
    int dp[1001];
    int solve(vector<int>&nums,int target){
        if(target==0) return 1;
        if(target<0) return 0;
        
        if(dp[target]!=-1) return dp[target];
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            ans+=solve(nums,target-nums[i]);
        }
        
        return dp[target]=ans;
    }
    public:
    int combinationSum4(vector<int>&nums,int target){
        n=nums.size();
        memset(dp,-1,sizeof(dp));

        return solve(nums,target);
    }
};
int main(){
    // Output: 7
    vector<int>nums={1,2,3};
    int target=4;
    // Output: 0
    vector<int>nums2={9};
    int target2=3;

    DP sol;
    cout<<sol.combinationSum4(nums,target)<<endl;
    cout<<sol.combinationSum4(nums2,target2);
    return 0;
}