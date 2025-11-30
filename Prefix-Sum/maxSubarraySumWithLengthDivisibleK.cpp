// LC - 3381 - Medium - Maximum Subarray Sum With Length Divisible by K
#include<iostream>
#include<vector>
using namespace std;
long long maxSubarraySum(vector<int>&nums,int k){
    int n=nums.size();

    vector<long long>prefix(n);
    prefix[0]=nums[0];

    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+nums[i];
    }

    long long ans=LLONG_MIN;

    for(int start=0;start<k;start++){
        long long currSum=0;
        int i=start;

        while(i<n && i+k-1<n){
            int j=i+k-1;

            long long subSum=prefix[j]-((i>0)?prefix[i-1]:0);

            currSum=max(subSum,currSum+subSum);
            ans=max(ans,currSum);

            i+=k;
        }
    }

    return ans;
}
int main(){
    // Output: 3
    vector<int>nums={1,2};
    int k=1;
    // Output: -10
    vector<int>nums2={-1,-2,-3,-4,-5};
    int k2=4;
    // Output: 4
    vector<int>nums3={-5,1,2,-3,4};
    int k3=2;
    cout<<maxSubarraySum(nums,k)<<endl;
    cout<<maxSubarraySum(nums2,k2)<<endl;
    cout<<maxSubarraySum(nums3,k3);
    return 0;
}