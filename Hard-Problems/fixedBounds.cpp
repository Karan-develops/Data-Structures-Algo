// LC - 2444 - HARD - Count Subarrays With Fixed Bounds
// Topic --> Sliding Window
#include<iostream>
#include<vector>
using namespace std;
long long countSubarrays(vector<int>&nums,int minK,int maxK){
    int n=nums.size();
    long long ans=0;
    // Culprit Idx is left bound
    int minIdx=-1,maxIdx=-1,culpritIdx=-1;

    for(int i=0;i<n;i++){
        if(nums[i]>maxK || nums[i]<minK) culpritIdx=i;

        if(nums[i]==minK) minIdx=i;
        if(nums[i]==maxK) maxIdx=i;

        int count=min(minIdx,maxIdx)-culpritIdx;

        ans+=count<0?0:count;
    }
    return ans;
}
int main(){
    // Output: 2
    vector<int>nums={1,3,5,2,7,5};
    int minK=1,maxK=5;
    // Output: 10
    vector<int>nums2={1,1,1,1};
    int minK2=1,maxK2=1;
    cout<<countSubarrays(nums,minK,maxK)<<endl;
    cout<<countSubarrays(nums2,minK2,maxK2);
    return 0;
}