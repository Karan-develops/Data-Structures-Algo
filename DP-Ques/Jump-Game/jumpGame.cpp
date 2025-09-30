// LC - 55 - Medium - Jump Game
// 3 Approaches
#include<iostream>
#include<vector>
using namespace std;
// Approach 1 - Top Down (Rec+Memo)
class DP{
    int n;
    vector<int>dp;
    bool solve(vector<int>&nums,int idx){
        if(idx==n-1) return true;

        if(dp[idx]!=-1) return dp[idx];
        
        for(int i=1;i<=nums[idx];i++){
            if(solve(nums,idx+i)==true){
                return dp[idx]=true;
            }
        }

        return dp[idx]=false;
    }
    public:
    bool canJump(vector<int>&nums){
        n=nums.size();
        dp.resize(n,-1);

        return solve(nums,0);
    }
};
// Approach 2 - Bottom Up
class BottomUp{
    public:
    bool canJump(vector<int>&nums){
        int n=nums.size();

        vector<bool>dp(n,false);
        dp[0]=true;

        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]==true && nums[j]+j>=i){
                    dp[i]=true;
                    break;
                }
            }
        }

        return dp[n-1];
    }
};
// Approach 3 - Optimal
class Optimized{
    public:
    bool canJump(vector<int>&nums){
        int n=nums.size();
        int maxReachable=0;

        for(int i=0;i<n;i++){
            if(i>maxReachable) return false;

            maxReachable=max(maxReachable,i+nums[i]);
        }

        return true;
    }
};
int main(){
    // Output: true
    vector<int>nums={2,3,1,1,4};
    // Output: false
    vector<int>nums2={3,2,1,0,4};

    BottomUp sol;
    cout<<sol.canJump(nums)<<endl;
    cout<<sol.canJump(nums2);
    return 0;
}