// LC - 713 - Medium - Subarray Product Less Than K
#include<iostream>
#include<vector>
using namespace std;
int numSubarrayProductLessThanK(vector<int>&nums,int k){
    int n=nums.size();
    int ans=0;

    int i=0,j=0;
    long long mul=1;
    while(j<n){
        mul*=nums[j];
        while(i<=j && mul>=k){
            mul/=nums[i];
            i++;
        }
        ans+=j-i+1;
        j++;
    }
    return ans;
}
int main(){
    // Output: 8
    vector<int>nums={10,5,2,6};
    int k=100;
    // Output: 0
    vector<int>nums2={1,2,3};
    int k2=0;
    cout<<numSubarrayProductLessThanK(nums,k)<<endl;
    cout<<numSubarrayProductLessThanK(nums2,k2);
    return 0;
}