// LC - 2654 - Medium - Minimum Number of Operations to Make All Array Elements Equal to 1
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
int minOperations(vector<int>&nums){
    int n=nums.size();

    int count1=0;
    for(int i=0;i<n;i++){
        if(nums[i]==1) count1++;
    }

    if(count1>0) return n-count1;

    int minStepsTo1=INT_MAX;
    
    for(int i=0;i<n;i++){
        int GCD=nums[i];
        for(int j=i+1;j<n;j++){
            GCD=gcd(GCD,nums[j]);
            
            if(GCD==1){
                minStepsTo1=min(minStepsTo1,j-i);
                break;
            }
        }
    }

    if(minStepsTo1==INT_MAX) return -1;

    return minStepsTo1+(n-1);
}
int main(){
    // Output: 4
    vector<int>nums={2,6,3,4};
    // Output: -1
    vector<int>nums2={2,10,6,14};
    cout<<minOperations(nums)<<endl;
    cout<<minOperations(nums2);
    return 0;
}