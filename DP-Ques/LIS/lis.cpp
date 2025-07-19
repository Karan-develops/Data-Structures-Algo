// LC - 300 - Medium - Longest Increasing Subsequence
#include<iostream>
#include<vector>
using namespace std;
int lengthOfLIS(vector<int>&nums){
    int n=nums.size();
    vector<int>dp(n,1);
    int ans=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                dp[i]=max(dp[j]+1,dp[i]);
                ans=max(ans,dp[i]);
            }
        }
    }
    return ans;
}
int main(){
    // Output: 4
    vector<int>nums={10,9,2,5,3,7,101,18};
    // Output: 4
    vector<int>nums2={0,1,0,3,2,3};
    // Output: 1
    vector<int>nums3={7,7,7,7,7,7,7};
    cout<<lengthOfLIS(nums)<<endl;
    cout<<lengthOfLIS(nums2)<<endl;
    cout<<lengthOfLIS(nums3);
    return 0;
}