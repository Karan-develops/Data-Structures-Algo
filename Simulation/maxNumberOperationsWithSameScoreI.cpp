// LC - 3038 - Easy - Maximum Number of Operations With the Same Score I
#include<iostream>
#include<vector>
using namespace std;
int maxOperations(vector<int>&nums){
    int n=nums.size();

    int diff=nums[0]+nums[1];
    int ans=1;

    for(int i=2;i<n-1;i+=2){
        if((nums[i]+nums[i+1])!=diff) return ans;

        ans++;
    }
    return ans;
}
int main(){
    // Output: 2
    vector<int>nums={3,2,1,4,5};
    // Output: 2
    vector<int>nums2={1,5,3,3,4,1,3,2,2,3};
    cout<<maxOperations(nums)<<endl;
    cout<<maxOperations(nums2);
    return 0;
}