// LC - 740 - Medium - Delete and Earn
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class DP{
    int n;
    vector<int>dp;
    unordered_map<int,int>mp;
    int solve(vector<int>&nums,int i){
        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];

        int skip=solve(nums,i+1);

        int j=upper_bound(begin(nums),end(nums),nums[i]+1)-begin(nums);

        int take=nums[i]*mp[nums[i]]+solve(nums,j);

        return dp[i]=max(take,skip);
    }
    public:
    int deleteAndEarn(vector<int>&nums){
        mp.clear();

        for(int &i:nums) mp[i]++;

        nums.clear();
        for(auto &it:mp){
            nums.push_back(it.first);
        }
        
        n=nums.size();
        sort(begin(nums),end(nums));
        dp.assign(n,-1);

        return solve(nums,0);
    }
};
int main(){
    // Output: 6
    vector<int>nums={3,4,2};
    // Output: 9
    vector<int>nums2={2,2,3,3,3,4};

    DP sol;
    cout<<sol.deleteAndEarn(nums)<<endl;
    cout<<sol.deleteAndEarn(nums2);
    return 0;
}