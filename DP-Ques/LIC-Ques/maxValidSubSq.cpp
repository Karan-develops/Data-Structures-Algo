// LC - 3202 - Medium - Find the Maximum Length of Valid Subsequence II
#include<iostream>
#include<vector>
using namespace std;
int maximumLength(vector<int>&nums,int k){
    int n=nums.size();
    if(n<=2) return n;

    vector<vector<int>>dp(n,vector<int>(k,1));
    int ans=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            int diff=(nums[i]+nums[j])%k;

            dp[i][diff]=dp[j][diff]>0?dp[j][diff]+1:2;

            ans=max(ans,dp[i][diff]);
        }
    }
    return ans;
}
int main(){
    // Output: 5
    vector<int>nums={1,2,3,4,5};
    int k=2;
    // Output: 4
    vector<int>nums2={1,4,2,3,1,4};
    int k2=3;
    cout<<maximumLength(nums,k)<<endl;
    cout<<maximumLength(nums2,k2);
    return 0;
}