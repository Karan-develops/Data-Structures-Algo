// LC - 3364 - Easy - Minimum Positive Sum Subarray
// Topic --> Array, Sliding Window, Prefix Sum
// 2 Approaches
#include<iostream>
#include<vector>
using namespace std;
// Approach 1 - Brute Force
int minimumSumSubarray(vector<int>&nums,int l,int r){
    int n=nums.size();
    
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            
            if(j-i+1>=l && j-i+1<=r && sum>0){
                ans=min(ans,sum);
            }
        }
    }
    return ans==INT_MAX?-1:ans;
}
// Approach 2 - Prefix Sum - Sliding Window
int minimumSumSubarray2(vector<int>&nums,int l,int r){
    int n=nums.size();

    vector<int> prefixSum(n+1,0);
    for(int i=0;i<n;i++){
        prefixSum[i+1]=prefixSum[i]+nums[i];
    }

    int ans=INT_MAX;

    for(int window=l;window<=r;window++){
        for(int i=0;i+window<=n;i++){
            int sum=prefixSum[i+window]-prefixSum[i];

            if(sum>0) ans=min(ans,sum);
        }
    }
    return ans==INT_MAX?-1:ans;
}
int main(){
    // Output: 1
    vector<int>nums={3,-2,1,4};
    int l=2,r=3;
    // Output: -1
    vector<int>nums2={-2,2,-3,1};
    int l2=2,r2=3;
    // Output: 3
    vector<int>nums3={1,2,3,4};
    int l3=2,r3=4;
    cout<<minimumSumSubarray(nums,l,r)<<endl;
    cout<<minimumSumSubarray(nums2,l2,r2)<<endl;
    cout<<minimumSumSubarray(nums3,l3,r3);
    return 0;
}