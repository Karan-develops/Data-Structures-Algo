// LC - 1 - Easy - Two Sum
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> twoSum(vector<int>&nums,int target){
    unordered_map<int,int>mp;
    
    for(int i=0;i<nums.size();i++){
        if(mp.count(target-nums[i])){
            return {mp[target-nums[i]],i};
        }
        mp[nums[i]]=i;
    }
    return {};
}
int main(){
    // Output: [0,1]
    vector<int>nums={2,7,11,15};
    int target=9;
    // Output: [1,2]
    vector<int>nums2={3,2,4};
    int target2=6;
    // Output: [0,1]
    vector<int>nums3={3,3};
    int target3=6;
    return 0;
}