// LC - 3487 - Easy - Maximum Unique Subarray Sum After Deletion
// Acceptance Rate - 26%
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int maxSum(vector<int>& nums) {
    unordered_map<int,int>mp;
    int ans=0;
    int mini=INT_MIN;
    for(int &i:nums){
        if(i<=0) mini=max(mini,i);
        if(i>0){
            if(mp.count(i)) continue;
            mp[i]++;
            ans+=i;
        }
    }
    return ans==0?mini:ans;
}
int main(){
    // Output: 15
    vector<int>nums={1,2,3,4,5};
    // Output: 1
    vector<int>nums2={1,1,0,1,1};
    // Output: 3
    vector<int>nums3={1,2,-1,-2,1,0,-1};
    cout<<maxSum(nums)<<endl;
    cout<<maxSum(nums2)<<endl;
    cout<<maxSum(nums3);
    return 0;
}