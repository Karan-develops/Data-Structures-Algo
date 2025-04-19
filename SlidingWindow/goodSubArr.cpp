// LC - 2537 - Medium - Count the Number of Good Subarrays
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
long long countGood(vector<int>&nums,int k){
    int n=nums.size();
    int i=0;
    int j=0;
    long long ans=0;
    unordered_map<int, int> mp;
    long long pairs=0;
    while(j<n){
        //isse pehle kitni baar nums[j] dekha hai humne
        pairs+=mp[nums[j]];
        mp[nums[j]]++;
        while(pairs>=k){
            ans+=(n-j);
            mp[nums[i]]--;
            pairs-=mp[nums[i]];
            i++;
        }
        j++;
    }
    return ans;
}
int main(){
    // Output: 1
    vector<int>nums={1,1,1,1,1};
    int k=10;
    // Output: 4
    vector<int>nums2={3,1,4,3,2,2,4};
    int k2=2;
    cout<<countGood(nums,k)<<endl;
    cout<<countGood(nums2,k2);
    return 0;
}