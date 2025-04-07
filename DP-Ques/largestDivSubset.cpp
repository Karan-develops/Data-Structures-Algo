// LC - 368 - Medium - Largest Divisible Subset
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> largestDivisibleSubset(vector<int>& nums){
    int n=nums.size();
    sort(begin(nums),end(nums));
    vector<int>dp(n,1);
    vector<int>prev(n,-1);
    int last_chosen_idx=0;
    int maxL=1;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]%nums[j]==0){
                if(dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
                if(dp[i]>maxL){
                    maxL=dp[i];
                    last_chosen_idx=i;
                }
            }
        }
    }
    vector<int>ans;
    while(last_chosen_idx!=-1){
        ans.push_back(nums[last_chosen_idx]);
        last_chosen_idx=prev[last_chosen_idx];
    }
    return ans;
}
int main(){
    // Output: [1,2]
    vector<int>nums={1,2,3};
    // Output: [1,2,4,8]
    vector<int>nums2={1,2,4,8};
    vector<int>ans=largestDivisibleSubset(nums2);
    for(int &i:ans) cout<<i<<" ";
    return 0;
}