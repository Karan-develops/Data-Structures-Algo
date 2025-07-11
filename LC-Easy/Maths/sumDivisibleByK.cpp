// LC - 3512 - Easy - Minimum Operations to Make Array Sum Divisible by K
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
int minOperations(vector<int>&nums, int k){
    int sum=accumulate(begin(nums),end(nums),0);
    return sum%k;
}
int main(){
    // Output: 4
    vector<int>nums={3,9,7};
    int k=5;
    // Output: 0
    vector<int>nums2={4,1,3};
    int k2=4;
    // Output: 5
    vector<int>nums3={3,2};
    int k3=6;
    cout<<minOperations(nums,k)<<endl;
    cout<<minOperations(nums2,k2)<<endl;
    cout<<minOperations(nums3,k3);
    return 0;
}