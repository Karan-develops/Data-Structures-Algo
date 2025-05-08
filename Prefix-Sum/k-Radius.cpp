// LC - 2090 - Medium - K Radius Subarray Averages
#include<iostream>
#include<vector>
using namespace std;
vector<int> getAverages(vector<int>&nums,int k){
    if(k==0) return nums;

    int n=nums.size();
    vector<int>ans(n,-1);

    if(n<2*k +1) return ans;

    // 1. Calculate Prefix Sum
    vector<long long>prefixSum(n,0);
    for(int i=1;i<n;i++){
        prefixSum[i]=prefixSum[i-1]+nums[i];
    }

    // 2. Operate
    for(int i=k;i<n-k;i++){
        int left_idx=i-k;
        int right_idx=i+k;

        long long sum=prefixSum[right_idx];
        if(left_idx>0) sum-=prefixSum[left_idx];

        ans[i]=sum/(2*k+1);
    }
    return ans;
}
int main(){
    // Output: [-1,-1,-1,5,4,4,-1,-1,-1]
    vector<int>nums={7,4,3,9,1,8,5,2,6};
    int k=3;
    // Output: [100000]
    vector<int>nums2={100000};
    int k2=0;
    // Output: [-1]
    vector<int>nums3={8};
    int k3=100000;
    return 0;
}