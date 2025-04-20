// LC - 2563 - Medium - Count the Number of Fair Pairs
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long countFairPairs(vector<int>&nums,int lower,int upper){
    long long ans=0;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-1;i++){
        auto up=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i]);
        auto low=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i]);
        ans+=(up-low);
    }
    return ans;
}
int main(){
    // Output: 6
    vector<int>nums={0,1,7,4,4,5};
    int lower=3,upper=6;
    // Output: 1
    vector<int>nums2={1,7,9,2,5};
    int lower2=11,upper2=11;
    cout<<countFairPairs(nums,lower,upper)<<endl;
    cout<<countFairPairs(nums2,lower2,upper2);
    return 0;
}