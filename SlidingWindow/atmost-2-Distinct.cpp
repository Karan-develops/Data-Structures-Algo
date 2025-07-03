// GFG - Longest subarray with Atmost two distinct integers
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int totalElements(vector<int>&nums){
    int n=nums.size();
    unordered_map<int,int>mp;
    
    int ans=0;
    int i=0,j=0;
    
    while(j<n){
        mp[nums[j]]++;
        
        while(mp.size()>=3){
            mp[nums[i]]--;
            if(mp[nums[i]]==0){
                mp.erase(nums[i]);
            }
            i++;
        }
        ans=max(ans,j-i+1);
        j++;
    }
    return ans;
}
int main(){
    // Output: 3
    vector<int>nums={2,1,2};
    // Output: 5
    vector<int>nums2={3,1,2,2,2,2};
    cout<<totalElements(nums)<<endl;
    cout<<totalElements(nums2);
    return 0;
}