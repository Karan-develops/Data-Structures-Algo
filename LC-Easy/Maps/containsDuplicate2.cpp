// LC - 219 - Easy - Contains Duplicate II
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int n=nums.size();
    unordered_map<int,int>mp;
    
    for(int i=0;i<n;i++){
        if(mp.count(nums[i])){
            if(i-mp[nums[i]]<=k) return true;
        }
        mp[nums[i]]=i;
    }
    return false;
}
int main(){
    // Output: true
    vector<int>nums={1,2,3,1};
    int k=3;
    // Output: true
    vector<int>nums2={1,0,1,1};
    int k2=1;
    // Output: false
    vector<int>nums3={1,2,3,1,2,3};
    int k3=2;
    cout<<containsNearbyDuplicate(nums,k)<<endl;
    cout<<containsNearbyDuplicate(nums2,k2)<<endl;
    cout<<containsNearbyDuplicate(nums3,k3);
    return 0;
}