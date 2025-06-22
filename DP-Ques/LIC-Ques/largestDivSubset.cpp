// GFG - Largest Divisible Subset
// Two Approach - Bottom-up - Top-Down
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class DP{
    void solve(vector<int>&nums,vector<int>&ans,vector<int>&temp,int prev,int idx){
        if(idx>=nums.size()){
            // Replace if strictly larger, or same size but lexicographically greater
            if(temp.size()>ans.size() || (temp.size()==ans.size() && temp>ans)){
                ans=temp;
            }
            return;
        }

        if(prev==-1 || nums[idx]%prev==0){
            temp.push_back(nums[idx]);
            solve(nums,ans,temp,nums[idx],idx+1);
            temp.pop_back();
        }
        // Skip nums[idx]
        solve(nums,ans,temp,prev,idx+1);
    }
    public:
    vector<int> bottomUp(vector<int>&nums){
        int n=nums.size();
        sort(nums.begin(), nums.end(),greater<int>());
        
        vector<int>dp(n,1);
        vector<int>prev(n,-1);
        int maxIdx=0;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]%nums[i]==0 && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
            if(dp[i]>dp[maxIdx]){
                maxIdx=i;
            }
        }
        
        vector<int>ans;
        while(maxIdx!=-1){
            ans.push_back(nums[maxIdx]);
            maxIdx=prev[maxIdx];
        }
        return ans;
    }
    vector<int> topDown(vector<int>&nums){
        sort(nums.begin(), nums.end());

        vector<int>ans,temp;

        solve(nums,ans,temp,-1,0);
        return ans;
    }
};
int main(){
    // Output: [1, 4, 8, 16]
    vector<int>nums={1,16,7,8,4};
    // Output: [2, 4, 8]
    vector<int>nums2={2,4,3,8};
    return 0;
}