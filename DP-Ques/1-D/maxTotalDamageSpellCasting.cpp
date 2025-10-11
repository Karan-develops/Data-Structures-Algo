// LC - 3186 - Medium - Maximum Total Damage With Spell Casting
// 2 Approaches
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
// Approach 1 - Top Down (Rec+Memo)
class DP{
    int n;
    typedef long long ll;
    vector<ll>dp;
    unordered_map<ll,ll>mp;
    ll solve(vector<ll>&nums,int i){
        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];

        ll skip=solve(nums,i+1);

        int j=lower_bound(begin(nums)+i+1,end(nums),nums[i]+3)-begin(nums);
        
        ll take=nums[i]*mp[nums[i]]+solve(nums,j);

        return dp[i]=max(take,skip);
    }
    public:
    long long maximumTotalDamage(vector<int>&power){
        mp.clear();

        for(int &i:power) mp[i]++;

        vector<ll>nums;

        for(auto &it:mp){
            nums.push_back(it.first);
        }

        sort(begin(nums),end(nums));
        n=nums.size();
        dp.assign(n,-1);

        return solve(nums,0);
    }
};
// Approach 2 - Bottom Up
class BottomUp{
    typedef long long ll;
    public:
    long long maximumTotalDamage(vector<int>&power){
        unordered_map<ll,ll>mp;

        for(int &i:power) mp[i]++;

        vector<int>nums;
        for(auto &it:mp){
            nums.push_back(it.first);
        }

        sort(begin(nums),end(nums));
        
        int n=nums.size();
        vector<ll>dp(n,0);
        
        ll ans=0;

        for(int i=n-1;i>=0;i--){
            ll skip=(i+1<n)?dp[i+1]:0;

            int j=lower_bound(begin(nums)+i+1,end(nums),nums[i]+3)-begin(nums);
            
            ll take=nums[i]*mp[nums[i]]+(j<n?dp[j]:0);

            dp[i]=max(take,skip);
            ans=max(ans,dp[i]);
        }

        return ans;
    }
};
int main(){
    // Output: 6
    vector<int>power={1,1,3,4};
    // Output: 13
    vector<int>power2={7,1,6,6};

    DP sol;
    cout<<sol.maximumTotalDamage(power)<<endl;
    cout<<sol.maximumTotalDamage(power2);
    return 0;
}