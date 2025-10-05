// LC - 3701 - Easy - Compute Alternating Sum
#include<iostream>
#include<vector>
using namespace std;
int alternatingSum(vector<int>&nums){
    int n=nums.size();
    int ans=0;

    for(int i=0;i<n;i++){
        if(i&1) ans-=nums[i];
        else ans+=nums[i];
    }
    return ans;
}
int main(){
    // Output: -4
    vector<int>nums={1,3,5,7};
    // Output: 100
    vector<int>nums2={100};
    cout<<alternatingSum(nums)<<endl;
    cout<<alternatingSum(nums2);
    return 0;
}