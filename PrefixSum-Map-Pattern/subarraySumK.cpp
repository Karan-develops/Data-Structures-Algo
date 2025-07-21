// LC - 560 - Medium - Subarray Sum Equals K
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int subarraySum(vector<int>&nums,int k){
    unordered_map<int,int>mp;
    // There is always 0 prefix sum in start
    mp[0]++;

    int ans=0;
    int prefixSum=0;

    for(int &i:nums){
        prefixSum+=i;

        if(mp.count(prefixSum-k)){
            ans+=mp[prefixSum-k];
        }
        mp[prefixSum]++;
    }
    return ans;
}
int main(){
    // Output: 2
    vector<int>nums={1,1,1};
    int k=2;
    // Output: 2
    vector<int>nums2={1,2,3};
    int k2=3;
    cout<<subarraySum(nums,k)<<endl;
    cout<<subarraySum(nums2,k2);
    return 0;
}