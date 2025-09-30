// LC - 45 - Medium - Jump Game II
#include<iostream>
#include<vector>
using namespace std;
class DP{
    int n;
    vector<long long>dp;
    long long solve(vector<int>&nums,int idx){
        if(idx==n-1) return 0;
        
        if(idx>=n) return INT_MAX;

        if(dp[idx]!=-1) return dp[idx];

        long long ans=INT_MAX;

        for(int i=1;i<=nums[idx];i++){
            ans=min(ans,solve(nums,idx+i));
        }

        return dp[idx]=1+ans;
    }
    public:
    int jump(vector<int>&nums){
        n=nums.size();
        dp.resize(n,-1);

        return solve(nums,0);
    }
};
int main(){
    // Output: 2
    vector<int>nums={2,3,1,1,4};
    // Output: 2
    vector<int>nums2={2,3,0,1,4};

    DP sol;
    cout<<sol.jump(nums)<<endl;
    cout<<sol.jump(nums2);
    return 0;
}