// LC - 2348 - Medium - Number of Zero-Filled Subarrays
#include<iostream>
#include<vector>
using namespace std;
long long zeroFilledSubarray(vector<int>& nums) {
    int n=nums.size();
    long long ans=0;

    int i=0;
    while(i<n){
        long long count=0;
        while(i<n && nums[i]==0){
            count++;
            i++;
        }
        ans+=(count*(count+1))/2;
        i++;
    }
    return ans;
}
int main(){
    // Output: 6
    vector<int>nums={1,3,0,0,2,0,0,4};
    // Output: 9
    vector<int>nums2={0,0,0,2,0,0};
    // Output: 0
    vector<int>nums3={2,10,2019};
    cout<<zeroFilledSubarray(nums)<<endl;
    cout<<zeroFilledSubarray(nums2)<<endl;
    cout<<zeroFilledSubarray(nums3);
    return 0;
}