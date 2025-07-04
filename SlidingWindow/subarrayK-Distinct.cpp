// GFG - Subarrays With At Most K Distinct Integers
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int countAtMostK(vector<int>&nums,int k){
    int n=nums.size();
    unordered_map<int,int>mp;
    
    int ans=0;
    int i=0,j=0;
    
    while(j<n){
        mp[nums[j]]++;
        
        while(mp.size()>k){
            mp[nums[i]]--;
            if(mp[nums[i]]==0){
                mp.erase(nums[i]);
            }
            i++;
        }
        ans+=j-i+1;
        j++;
    }
    return ans;
}
int main(){
    // Output: 9
    vector<int>nums={1,2,2,3};
    int k=2;
    // Output: 6
    vector<int>nums2={1,1,1};
    int k2=1;
    // Output: 24
    vector<int>nums3={1,2,1,1,3,3,4,2,1};
    int k3=2;
    cout<<countAtMostK(nums,k)<<endl;
    cout<<countAtMostK(nums2,k2)<<endl;
    cout<<countAtMostK(nums3,k3);
    return 0;
}