// LC - 2799 - Medium - Count Complete Subarrays in an Array
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
int countCompleteSubarrays(vector<int>&nums){
    int n=nums.size();
    unordered_set<int>st(begin(nums),end(nums));
    int unique=st.size();
    int i=0,j=0,ans=0;
    unordered_map<int,int>mp;
    while(j<n){
        mp[nums[j]]++;
        while(mp.size()==unique){
            ans+=(n-j);
            mp[nums[i]]--;
            if(mp[nums[i]]==0){
                mp.erase(nums[i]);
            }
            i++;
        }
        j++;
    }
    return ans;
}
int main(){
    // Output: 4
    vector<int>nums={1,3,1,2,2};
    // Output: 10
    vector<int>nums2={5,5,5,5};
    cout<<countCompleteSubarrays(nums)<<endl;
    cout<<countCompleteSubarrays(nums2);
    return 0;
}