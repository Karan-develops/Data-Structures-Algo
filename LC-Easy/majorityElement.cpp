// LC - 169 - Easy - Majority Element
// 2 Approaches - Map - Boyer Moore Algo
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int majorityElement(vector<int>&nums){
    int n=nums.size();
    unordered_map<int,int>mp;
    for(int &i:nums) mp[i]++;
    
    for(auto it:mp){
        if(it.second*2>n) return it.first;
    }
    return -1;
}
// Boyer Moore
int majorityElement2(vector<int>&nums){
    int n=nums.size();
    int count=1;
    int ans=nums[0];
    for(int i=1;i<n;i++){
        if(nums[i]!=ans && count==0){
            ans=nums[i];
            count++;
        }
        else if(nums[i]!=ans) count--;
        else count++;
    }
    return ans;
}
int main(){
    // Output: 3
    vector<int>nums={3,2,3};
    // Output: 2
    vector<int>nums2={2,2,1,1,1,2,2};
    cout<<majorityElement2(nums)<<endl;
    cout<<majorityElement2(nums2);
    return 0;
}