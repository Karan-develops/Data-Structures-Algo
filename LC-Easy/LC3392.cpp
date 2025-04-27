// LC - 3392 - Easy - Count Subarrays of Length Three With a Condition
#include<iostream>
#include<vector>
using namespace std;
int countSubarrays(vector<int>& nums) {
    int n=nums.size();
    int ans=0;
    for(int i=1;i<n-1;i++){
        if(nums[i]==(nums[i-1]+nums[i+1])*2) ans++;
    }
    return ans;
}
int main(){
    // Output: 1
    vector<int>nums={1,2,1,4,1};
    // Output: 0
    vector<int>nums2={1,1,1};
    cout<<countSubarrays(nums)<<endl;
    cout<<countSubarrays(nums2);
    return 0;
}