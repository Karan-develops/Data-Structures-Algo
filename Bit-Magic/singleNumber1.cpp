// LC - 136 - Easy - Single Number
#include<iostream>
#include<vector>
using namespace std;
int singleNumber(vector<int>& nums) {
    int ans=0;
    for(auto i:nums) ans^=i;
    return ans;
}
int main(){
    // Output: 1
    vector<int>nums={2,2,1};
    // Output: 4
    vector<int>nums2={4,1,2,1,2};
    // Output: 1
    vector<int>nums3={1};
    cout<<singleNumber(nums)<<endl;
    cout<<singleNumber(nums2)<<endl;
    cout<<singleNumber(nums3);
    return 0;
}