// LC - 53 -Medium - Maximum Subarray
// Kadane's Algorithm
#include<iostream>
#include<vector>
using namespace std;
int maxSubArray(vector<int>& nums) {
    int n=nums.size();
    int ans=INT_MIN,curr=0;

    for(int &i:nums){
        curr=max(i,curr+i);
        ans=max(ans,curr);
    }
    return ans;
}
int main(){
    // Output: 6
    vector<int>nums={-2,1,-3,4,-1,2,1,-5,4};
    // Output: 1
    vector<int>nums2={1};
    // Output: 23
    vector<int>nums3={5,4,-1,7,8};
    cout<<maxSubArray(nums)<<endl;
    cout<<maxSubArray(nums2)<<endl;
    cout<<maxSubArray(nums3);
    return 0;
}