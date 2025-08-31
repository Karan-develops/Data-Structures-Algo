// LC - 3396 - Easy - Minimum Number of Operations to Make Elements in Array Distinct
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int minimumOperations(vector<int>&nums){
    int n=nums.size();
    unordered_map<int,int>mp;

    int size_left=0;
    
    for(int i=n-1;i>=0;i--){
        if(mp.count(nums[i])){
            size_left=i+1;
            break;
        }
        mp[nums[i]]++;
    }
    
    int ans=size_left/3;
    if(size_left%3!=0) ans++;
    
    return ans;
}
int main(){
    // Output: 2
    vector<int>nums={1,2,3,4,2,3,3,5,7};
    // Output: 2
    vector<int>nums2={4,5,6,4,4};
    // Output: 0
    vector<int>nums3={6,7,8,9};
    cout<<minimumOperations(nums)<<endl;
    cout<<minimumOperations(nums2)<<endl;
    cout<<minimumOperations(nums3);
    return 0;
}