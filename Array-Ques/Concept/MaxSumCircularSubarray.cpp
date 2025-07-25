// LC - 918 - Medium - Maximum Sum Circular Subarray
#include<iostream>
#include<vector>
using namespace std;
int maxSubarraySumCircular(vector<int>&nums){
    int n=nums.size();
    int total=0;
    
    int currMin=0,minSum=INT_MAX;
    
    int currMax=0,maxSum=INT_MIN;
    
    for(int &i:nums){
        total+=i;

        currMin=min(i+currMin,i);
        minSum=min(minSum,currMin);
        
        currMax=max(i+currMax,i);
        maxSum=max(maxSum,currMax);
    }
    
    int circular_sum=total-minSum;
    
    if(maxSum>0) return max(maxSum,circular_sum);
    
    return maxSum;
}
int main(){
    // Output: 3
    vector<int>nums={1,-2,3,-2};
    // Output: 10
    vector<int>nums2={5,-3,5};
    // Output: -2
    vector<int>nums3={-3,-2,-3};
    cout<<maxSubarraySumCircular(nums)<<endl;
    cout<<maxSubarraySumCircular(nums2)<<endl;
    cout<<maxSubarraySumCircular(nums3);
    return 0;
}